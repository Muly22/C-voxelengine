#include <stdlib.h>
//
#include "include/point_cloud.h"
#include "include/point_world.h"

bool point_cloud_init( POINT_CLOUD *cloud, int point_c, MATERIAL mater ) {
  cloud->point_c = point_c;
  cloud->points = malloc( sizeof(POINT) * point_c );
  cloud->material = mater;
  if (point_world_add_cloud(cloud))
    return 1;
  return 0;
}

bool point_world_add_cloud( POINT_CLOUD *cloud ) {
  if (realloc(point_world, sizeof(POINT_CLOUD) * (point_world_len + 1)))
    return 1;
  point_world[point_world_len] = cloud;
  point_world_len++;
  return 0;
}

bool point_cloud_resize( POINT_CLOUD *cloud, int point_c ) {
  if (!realloc(cloud->points, sizeof(POINT) * point_c ))
    return 1;
  return 0;
}

void point_cloud_destroy( POINT_CLOUD *cloud ) {
  free(cloud->points);
  voxel_destroy(cloud->voxels, cloud->voxel_c);
}
