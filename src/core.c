#include <stdio.h>
//
#include "include/point_world.h"
#include "include/core.h"

bool all_static_object_init() {
  if (point_world_init())
    puts("WARNING: point_world init twice");
  return 0;
}
