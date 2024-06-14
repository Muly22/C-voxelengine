#include <stdio.h>
#include <stdlib.h>

#include "include/point_world.h"
#include "include/voxel_world.h"
#include "include/core.h"

int point_world_len;
POINT_CLOUD **point_world;
CHUNK voxel_world;

int point_world_init( void ) {
  if (point_world)
    free(point_world);
  point_world = (POINT_CLOUD**) malloc(sizeof(POINT_CLOUD**));
  if (!point_world)
    return -1;
  point_world_len = 0;
  return 0;
}

int point_world_destroy( void ) {
  for (int i = 0; i < point_world_len; i++) {
    point_cloud_destroy(point_world[i]);
  }
  point_world_len = 0;
  if (point_world)
    free(point_world);
  return 0;
}
