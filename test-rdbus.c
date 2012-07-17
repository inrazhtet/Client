/**
 * test-rdbus.c
 *   A simple C-language test of the RD-Bus library.  And I use the
 *   term "test" loosely.
 */

// +---------+--------------------------------------------------------
// | Headers |
// +---------+

#include <stdio.h>
#include "rdbus.h"


// +------+-----------------------------------------------------------
// | Main |
// +------+

int
main (int argc, char *argv[])
{
  rdbus_init ();
  rdbus_get_object("org.freedesktop.Geoclue.Master", "/org/freedesktop/Geoclue/Master/client0", "org.freedesktop.Geoclue");
  //printf ("SESSION-BUS = %p\n", SESSION_BUS);
  return 0;
} // main
