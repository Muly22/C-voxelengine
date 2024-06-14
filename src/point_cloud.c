#include <stdlib.h>
#include <stdio.h>

#include "include/point_cloud.h"
#include "include/point_world.h"

int point_cloud_init( POINT_CLOUD **cloud, int point_c, MATERIAL mater ) {
  if (!(*cloud))
    *cloud = malloc(sizeof(POINT_CLOUD));
  (**cloud).point_c = point_c;
  (**cloud).points = malloc( sizeof(POINT) * point_c );
  (**cloud).voxel_c = 0;
  (**cloud).voxels = NULL;
  (**cloud).material = mater;
  if (point_world_add_cloud(*cloud) < 0)
    return -1;
  return 0;
}

int point_world_add_cloud( POINT_CLOUD *cloud ) {
  point_world = (POINT_CLOUD**) realloc(point_world, sizeof(POINT_CLOUD**) * (point_world_len + 1));
  if (!point_world) {
    puts("ERROR: point_world == NULL");
    return -1;
  }
  point_world[point_world_len] = cloud;
  cloud->id = point_world_len;
  point_world_len++;
  return 0;
}

int point_cloud_resize( POINT_CLOUD *cloud, int point_c ) {
  cloud->points = (POINT*) realloc(cloud->points, sizeof(POINT) * point_c);
  if (!(cloud->points)) {
    puts("ERROR: realloc");
    return -1;
  }
  return 0;
}

void point_cloud_destroy( POINT_CLOUD *cloud ) {
  free(cloud->points);
  point_world[cloud->id] = NULL;
  voxel_destroy(cloud->voxels, &(cloud->voxel_c));
}
