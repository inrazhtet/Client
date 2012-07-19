 /**
 * rdbus.c
 *   A D-bus Implementation for Racket.
 */

// +---------+--------------------------------------------------------
// | Headers |
// +---------+

#include <gio/gio.h>
#include "rdbus.h"
#include <escheme.h>


// +---------+--------------------------------------------------------
// | Globals |
// +---------+

//GDBusType *SESSION_BUS = NULL;
GDBusProxy *Proxyobj = NULL;

// +-----------+------------------------------------------------------
// | Constants |
// +-----------+

/**
 * The maximum number of live objects our program supports.  In the
 * long term, this should be an arbitrary number.
 */
#define MAX_OBJECTS 128


// +--------------------+---------------------------------------------
// | Predeclarations |
// +--------------------+

char * tostring (Scheme_Object *obj);

// +--------------------+---------------------------------------------
// | Exported Functions |
// +--------------------+

/**
 *creates a proxy for accessing interface_name on the remote object at object_path owned by name at connection and synchronously loads.
 *it provides the facilities for registering and managing all fundamental data types, user-defined object and interface types.
 */
void
rdbus_init (void)
{
  g_type_init ();
} // rdbus_init ()

/**
 * Get a new object for a particular service, object, and interface.  Returns
 * an integer used to refer to that object.  If we cannot create the object,
 * returns a negative number.
 */
int 
rdbus_get_object (const gchar *name, const gchar *object_path, const gchar *interface_name)
{
  const GDBusProxy *objects[MAX_OBJECTS];   // The objects we've allocated
  //  const int latest_object = 0;              // The index of the latest object

  GError *error;
  
  error = NULL;
  Proxyobj =  g_dbus_proxy_new_for_bus_sync ( G_BUS_TYPE_SESSION, 
					      G_DBUS_PROXY_FLAGS_NONE,
					      NULL,
					      name,
					      object_path,
					      interface_name,
					      NULL,
					      &error);

  // Check the result
  if ((Proxyobj == NULL) || (error != NULL))
    {
      // Values less than zero signify an error.
      return -1; 
    } // if

  return 0;
} // rdbus_get_object

/**
 *Translating the scheme_object to gvariant type for the client
 */
GVariant *
scheme_obj_to_gvariant (Scheme_Object *list)
{
  GVariant *rvalue = NULL;
  Scheme_Object *firstelement;
  int length;
  gint32 i;
  char* rstring;
  double rdouble;

  length = scheme_list_length (list);

  if (length == 0)
    {
      //  scheme_signal_error("length 0");
      return rvalue ;
    }  // if
 
  else if (length == 1)
    {
    
      // Get the first element of the argument
      firstelement = scheme_car (list);
      // checking the scheme_type to see whether it is an integer or not
      // Eventually see if we can convert this to a switch statement.
      if (SCHEME_INTP (firstelement))
	{
	  // we saved the return value at &i
	   i = SCHEME_INT_VAL(firstelement); 
	   //  scheme_signal_error("%d", i);
	   rvalue = g_variant_new ("(i)", i);
	   return rvalue;
	} // if it's an integer
      else if (SCHEME_BYTE_STRINGP (firstelement)|| SCHEME_CHAR_STRINGP(firstelement))
	{
          //scheme_signal_error ("We are in Character");
	  //getting the string out of the scheme_object
	  fprintf (stderr, "before string type \n");
	  rstring = SCHEME_BYTE_STR_VAL(list);
          fprintf (stderr, "After type \n");
	  // we will convert it to g_variant
	  rvalue = g_variant_new ("(&s)", rstring);
          fprintf (stderr, "G type \n");
	  return rvalue;
	} // if it's a character
      else if (SCHEME_TYPE (firstelement) == scheme_double_type)
	{
	  //getting the double out of the scheme_object
	  rdouble = scheme_real_to_double(list);
	  // we will convert it to g_variant
	  rvalue = g_variant_new_double(rdouble);
	  return rvalue;
	} // if it's a double
    } // if we have a single element
 
  return rvalue;
} // scheme_obj_to_gvariant

/**
 *Translating the gvariant to Scheme Object
 */
Scheme_Object *
gvariant_to_schemeobj (GVariant *ivalue)
{
  gint32 i;
  GVariant *temp;
  Scheme_Object *fvalue = NULL;
  const gchar *fstring;
  gsize length = 0;
  gsize size;
  gint32 r1;
  gdouble r2;
  GVariantType *type;
  gchar *typestring;
  gchar *description;

  //scheme_signal_error ("Not tupal yet");

  //  fprintf (stderr, "Exploring the return value.\n");
  /* if (ivalue == NULL)
    {
      fprintf (stderr, "Return value is <NULL>\n");
    } // if (ivalue == NULL)
  else // if (ivalue != NULL)
    {
      type = g_variant_get_type (ivalue);
      typestring = g_variant_type_dup_string (type);
      fprintf (stderr, "Got type %s\n", typestring);
      g_free (typestring);
      description = g_variant_print (ivalue, TRUE);
      fprintf (stderr, "Got value %s\n", description);
      g_free (description);
      } // if (ivalue != NULL)*/
    
    length = g_variant_n_children(ivalue);
    for(i = 0; i < length; i++)
    { 
      // scheme_signal_error("not returning a Tuple");
      //getting each element of the tuple
      temp = g_variant_get_child_value(ivalue, i);
      
      if (g_variant_is_of_type  (temp, G_VARIANT_TYPE_INT32))
	{
	  r1 = g_variant_get_int32 (temp);
	  fvalue = scheme_make_integer_value(r1);
	  return fvalue;
	}// else if
      else if (g_variant_is_of_type (temp, G_VARIANT_TYPE_STRING))
	{
	  size = g_variant_get_size(temp);
	  fstring  = g_variant_get_string(temp, &size);
	  fvalue = scheme_make_locale_string(fstring);
	  return fvalue;
	}// else if
      else if (g_variant_is_of_type (temp, G_VARIANT_TYPE_BYTESTRING))
	{
	  scheme_signal_error("stringbyeerror");
	  fstring = g_variant_get_bytestring(temp);
	  fvalue = scheme_make_locale_string(fstring);
	  return fvalue;
	}// else if

      else if (g_variant_is_of_type (temp, G_VARIANT_TYPE_DOUBLE))
	{
	  r2 = g_variant_get_double(temp);
	  fvalue = scheme_make_double(r2);
	  return fvalue;
	}// else if

    }// for statement
 

     return fvalue;
	
}//gvariant_to_schemeobj

/**
 * Convert an array of Scheme objects into a list of the same objects.
 */
Scheme_Object *
make_object_list (int n, Scheme_Object *values[])
{
  Scheme_Object *result;  // The result we're building
  int i;                  // Everyone's favorite counter variable
  result = scheme_null;
  // Step through the objects from right to left, adding each to the front
  // of the list.
  for (i = n-1; i >= 0; i--)
    {
      result = scheme_make_pair (values[i], result);
    } // for
  // And we're done.
  return result;
} // make_object_list

/**
 * Calling the procedure through the DBus Proxy
 */

Scheme_Object *
rdbus_call_method (int i, Scheme_Object *proc, Scheme_Object *list )
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
  //Our GDBusProxy Object
  GDBusProxy *proxy;
  //Scheme_Object actual list
  // Scheme_Object *alist;
  
  
  
  if (i == 0)
    { 
      proxy = Proxyobj; 
      ivalue = scheme_obj_to_gvariant (list);
      // the method is converted into string here
      methodname = tostring (proc);
     // scheme_signal_error("callerror");
      fprintf (stderr, "Calling %s\n", methodname);
      //  scheme_signal_error ("methodnamepassed");
      error = NULL;
      frvalue = g_dbus_proxy_call_sync (proxy, methodname, ivalue, 0, -1, NULL, &error);
      /*      if (frvalue == NULL)
        {
	  fprintf (stderr, "Call to %s failed ", methodname);
	  if (error != NULL)
	    fprintf (stderr, "because %s.\n", error->message);
	  else
	    fprintf (stderr, "for an unknown reason.\n");
	  return scheme_void;
	  } // if (frvalue == NULL)*/
      // scheme_signal_error ("calling gimp");
      //scheme_signal_error("newerror");
      fobject = gvariant_to_schemeobj (frvalue);
      //scheme_signal_error ("getting the scheme object back");
      // scheme_signal_error("lasterror");
      return fobject;
    } // if (i == 0)
 
  else // if (i != 0)
    {
      return scheme_make_utf8_string("There is sth wrong with the Proxy Object");
    } // if (i != 0)
} // rdbus_call_method

/**
 * A wrapper for rdbus_call_method that makes it easier to export our function
 * to Scheme.
 */

Scheme_Object *
pardbus_call_method (int argc, Scheme_Object *argv[])
{
  // Verify that we have the appropriate number of arguments.
  if (argc < 2)
    {
      scheme_signal_error ("Call method needs at least two parameters.");
      return NULL;
    } // if there are insufficiently many arguments available.

  // rdbus_call_method does the heavy lifting
  // Hack!  Right now, we are going to assume zeroary procedures
  return rdbus_call_method (SCHEME_INT_VAL (argv[0]), argv[1], 
                            make_object_list (argc-2, argv+2));
} // pardbus_call_method

/**
 * Determine whether we can convert a Scheme_Object to a string.
 */
int
stringp (Scheme_Object *obj)
{
  return SCHEME_BYTE_STRINGP (obj) || SCHEME_CHAR_STRINGP (obj);
} // stringp

/**
 * Convert a Scheme_Object to a string.  Returns NULL if it fails.
 */
char *
tostring (Scheme_Object *obj)
{
  if (SCHEME_BYTE_STRINGP (obj))
    return SCHEME_BYTE_STR_VAL (obj);
  else if (SCHEME_CHAR_STRINGP (obj))
    // (scheme_char_string_to_byte_string) to be able to convert it to byte string
    return SCHEME_BYTE_STR_VAL (scheme_char_string_to_byte_string (obj));
  else
    return NULL;
} // tostring

/**
 * A wrapper for rdbus_get_object.
 */
Scheme_Object *pardbus_get_object (int argc, Scheme_Object *argv[])
{
  char *service;
  char *path;
  char *interface;
  int object;

  // Verify the number of parameters
  if (argc != 3)
    {
      scheme_signal_error ("rdbus-get-object: Requires exactly three parameters.\n");
      return scheme_void;
    } // if we have the wrong number of parameters

  // Verify the type of the parameters
  if ( (! stringp (argv[0]))
       || (! stringp (argv[1]))
       || (! stringp (argv[2])) )
    {
      scheme_signal_error ("rdbus-get-object: All three parameters must be strings");
    } // if one of the parameters is not a string

  // Extract the parameters
  service = tostring (argv[0]);
  path = tostring (argv[1]);
  interface = tostring (argv[2]);

  // Rely on rdbus_get_object to do the real work
  object = rdbus_get_object (service, path, interface);

  // Sanity check.  rdbus_get_object returns a negative number upon error.
  if (object < 0)   
    {
      scheme_signal_error ("Could not create bus object.");
      return scheme_void;
    } // if (object < 0)

  // We're done.  Return the damn integer.
  return scheme_make_integer (object);
} // pardbus_get_object

/**
 * A wrapper for the rdbus_init
 */
Scheme_Object *pardbus_init (int argc, Scheme_Object *argv[])
{
  rdbus_init();
  return scheme_void;
}//pardbus_init

/**
 * Scheme Reload
 */
Scheme_Object *scheme_reload (Scheme_Env *env)
{
  Scheme_Env *menv;
  Scheme_Object *proc1;
  Scheme_Object *proc2;
  Scheme_Object *proc3;
  // Converting a C procedure to a scheme procedure.
  proc1 = scheme_make_prim_w_arity (pardbus_get_object, "rdbus-get-object", 3, -1);
  proc2 = scheme_make_prim_w_arity (pardbus_call_method, "rdbus-call-method", 2,-1);
  proc3 = scheme_make_prim_w_arity (pardbus_init, "rdbus_init", 0,0);

  // Add the new procedures to the shared object for Racket to use
  scheme_add_global ("rdbus-get-object", proc1, env);
  scheme_add_global ("rdbus-call-method", proc2, env);
  scheme_add_global ("rdbus_init", proc3, env);
  
  return scheme_void;
} // scheme_reload
  

Scheme_Object *scheme_initialize(Scheme_Env *env)
{
  /* First load is same as every load: */
  return scheme_reload(env);
}//scheme_initialize

Scheme_Object *
scheme_module_name ()
{
  /* This extension defines a module named `idmodule': */
  return scheme_intern_symbol ("idmodule");
} // scheme_module_name

