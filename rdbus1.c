/**
 * rdbus.c
 *   A D-bus Implementation for Racket.
 */

// +---------+--------------------------------------------------------
// | Headers |
// +---------+

#include <gio/gio.h>
#include "rdbus.h"
#include "/usr/racket/include/escheme.h"


// +---------+---------------------------------------------------cd-----
// | Globals |
// +---------+

//GDBusType *SESSION_BUS = NULL;
//GDBusProxy *proxy1 = NULL;


// +--------------------+---------------------------------------------
// | Exported Functions |
// +--------------------+

void
rdbus_init (void)
{
 
  // GDBusProxyFlags G_DBUS_PROXY_NONE;
  // we do not know. It's a struct and it has two ** in the API. 
 //it provides the facilities for registering and managing all fundamental data types, user-defined object and interface types. 
  g_type_init ();
   
  //creates a proxy for accessing interface_name on the remote object at object_path owned by name at connection and synchronously loads.  
  
} // rdbus_init ()

GDBusProxy *
rdbus_get_object (const gchar *name, const gchar *object_path, const gchar *interface_name)
{

  GError *error;
  GDBusProxy *Proxyobj;
  // GDBusProxyFlags G_DBUS_PROXY_NONE;
  //gint G_BUS_TYPE_SESSION;
 
      Proxyobj =  g_dbus_proxy_new_for_bus_sync ( G_BUS_TYPE_SESSION, 
                                               G_DBUS_PROXY_FLAGS_NONE,
                                               NULL,
					       name,
					       object_path,
					       interface_name,
					       NULL,
					       &error); 
      if (error == NULL)
	{
	  return Proxyobj;
        }
      else 
	return NULL;
}


GVariant *
scheme_obj_to_gvariant (Scheme_Object *list)
{
 
 GVariant *rvalue = NULL;
 Scheme_Object *firstelement;
 int length = scheme_list_length (list);
 long i;
 char* rstring;
 double rdouble;
 
 // getting the first element of the argument
 firstelement = scheme_car(list);
 
 
  if (length == 0)
    {
      return rvalue ;
    }  
  
  // checking the scheme_type to see whether it is an integer or not
  else if (length == 1 && SCHEME_TYPE(firstelement)== scheme_integer_type)
    {
      // we saved the return value at &i
      scheme_get_int_val (list,&i);
      // we concert it to g_variant
      rvalue = g_variant_new_int64(i);
      return rvalue;
    }
  else if (length == 1 && SCHEME_TYPE(firstelement) == scheme_char_type)
    {
      //getting the string out of the scheme_object
      rstring = SCHEME_BYTE_STR_VAL(list);
      // we will convert it to g_variant
      rvalue = g_variant_new_string(rstring);
      return rvalue;
    }
  else if (length == 1 && SCHEME_TYPE(firstelement) == scheme_double_type)
    {
      //getting the double out of the scheme_object
      rdouble = scheme_real_to_double(list);
      // we will convert it to g_variant
      rvalue = g_variant_new_double(rdouble);
      return rvalue;
    }
	   
    

  return rvalue;

}

Scheme_Object *
gvariant_to_schemeobj (GVariant *ivalue)
{
  Scheme_Object *fvalue = NULL;
  const gchar *fstring;
  gsize length;
  gsize *plength;
  gint64 r1;
  

  length = g_variant_get_size(ivalue);
  plength = &length;

  if (g_variant_is_of_type (ivalue, G_VARIANT_TYPE_INT64))
    { 
      g_variant_get (ivalue,"(i)", &r1);
      fvalue = scheme_make_integer_value(r1);
      return fvalue;
    }

  else if (g_variant_is_of_type (ivalue,G_VARIANT_TYPE_STRING))
    {
      fstring = g_variant_get_string (ivalue, plength);
      fvalue = scheme_make_utf8_string (fstring);
      return fvalue;
    }

  return fvalue;
    
  


}



Scheme_Object *
rdbus_call_method (GDBusProxy *proxy, Scheme_Object *proc, Scheme_Object *list )
{
  //This is the final return value that will be saved in memory after calling Gimp Server 
  GVariant *frvalue;
  // Intermediary return value for helper method return for scheme to gvariant
  GVariant *ivalue;
  // returning the string of the method name
  const char *methodname;
  //saving the error in memory
  GError *error;
  //final Scheme_Object
  Scheme_Object *fobject;
  
  ivalue = scheme_obj_to_gvariant(list);
  // the method is converted into string here
  methodname =SCHEME_BYTE_STR_VAL(proc);
  frvalue = g_dbus_proxy_call_sync(proxy, methodname, ivalue, 0, -1, NULL,&error);
  fobject = gvariant_to_schemeobj(frvalue);

  return fobject;
   
}

Scheme_Object *scheme_initialize(Scheme_Env *env)
{
  /* First load is same as every load: */
  return scheme_reload(env);
}

Scheme_Object *scheme_module_name()
{
  /* This extension defines a module named `idmodule': */
  return scheme_intern_symbol("idmodule");
} 
