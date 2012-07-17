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


// +---------+--------------------------------------------------------
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
  // GDBusProxyFlags G_DBUS_PROXY_NONE;
  //gint G_BUS_TYPE_SESSION;
      return  g_dbus_proxy_new_for_bus_sync ( G_BUS_TYPE_SESSION, 
                                               G_DBUS_PROXY_FLAGS_NONE,
                                               NULL,
					       name,
					       object_path,
					       interface_name,
					       NULL,
					       &error); 
}


GVariant *
schemeobjtogvariant (Scheme_Object *list)
{
  GVariant *rvalue;
  //Scheme_Object *firstelement;
  // int fe;
  int length = scheme_list_length (list);
  gint64 r;

  if (length == 0)
    {
      return ;
    }  
  else if (length == 0)
    {
      r = 5;
      rvalue = g_variant_new_int64(r);
      return rvalue;
    }

      // needs to be fixed
      // checking if it's an int and length of the parameter is 1
  /*else if (SCHEME_TYPE (firstelement) == scheme_integer_type && length == 1)
    { 
      //extracts the first element of list
      firstelement = scheme_car(list);
      //extracs the first integer
      fe = SCHEME_INT_VAL (firstelement);
      return NULL;
      }  */

  return rvalue = 0;

}

Scheme_Object *
gvarianttoschemeobj (GVariant *ivalue)
{
  Scheme_Object *fvalue;
  const gchar *fstring;
  gsize length;
  gsize *plength;

  length = g_variant_get_size(ivalue);
  plength = &length;

  if (g_variant_is_of_type (ivalue,G_VARIANT_TYPE_STRING))
    { fstring = g_variant_get_string (ivalue, plength);}

  fvalue = scheme_make_utf8_string (fstring);

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
  
  ivalue = schemeobjtogvariant(list);
  methodname =SCHEME_BYTE_STR_VAL(proc);
  frvalue = g_dbus_proxy_call_sync(proxy, methodname, ivalue, 0, -1, NULL,&error);
  fobject = gvarianttoschemeobj(frvalue);

  return fobject;
   
}
Scheme_Object *scheme_reload(Scheme_Env *env)
{
  Scheme_Env *menv;
  Scheme_Object *proc;
  
 
  proc = scheme_make_prim_w_arity(rdbus_call_method, "rdbus_call_method", 3, -1);

  /* All added names are automatically exported by the module: */
  scheme_add_global("rdbus_call_method", proc, env);

  // scheme_finish_primitive_module(menv);

  return scheme_void;
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
