#include <stdlib.h>
//
#include "include/point_cloud.h"

void point_cloud_init( POINT_CLOUD *cloud, int point_c, MATERIAL mater ) {
  cloud->point_c = point_c;
  cloud->points = malloc( sizeof(POINT) * point_c );
  voxel_obj_init( &(cloud->voxobj), point_c );
  cloud->id = 0; /* исправить */
  cloud->material = mater;
}

int point_cloud_resize( POINT_CLOUD *cloud, int point_c ) {
  if (!realloc(cloud->points, sizeof(POINT) * point_c ))
    return 1;
  return 0;
}

void point_cloud_update( POINT_CLOUD *cloud ) {
  voxel_obj_update(&(cloud->voxobj), cloud->points, cloud->point_c);
}

void point_cloud_destroy( POINT_CLOUD *cloud ) {
  free(cloud->points);
  voxel_obj_destroy(&(cloud->voxobj));
}
