#include "include/point_cloud.h"

void point_cloud_init( POINT_CLOUD *cloud, int point_c ) {
  cloud->point_c = point_c;
  mempool_init( &(cloud->pool), sizeof(POINT) * point_c );
  voxel_obj_init( &(cloud->voxobj), point_c );
  cloud->id = 0; /* исправить */
}

void point_cloud_resize( POINT_CLOUD *cloud, int point_c ) {
  mempool_resize( &(cloud->pool), sizeof(POINT) * point_c );
}

void point_cloud_destroy( POINT_CLOUD *cloud ) {
  mempool_destroy(&(cloud->pool));
  voxel_obj_destroy(&(cloud->voxobj));
}
