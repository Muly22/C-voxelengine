#ifndef POINT_CLOUD_H
#define POINT_CLOUD_H

#include "octree.h"
#include "point.h"

typedef struct {
  int id;
  VOXEL_OBJ voxobj;
  MEMPOOL pool;
  int point_c;
  POINT *points;
} POINT_CLOUD;

void point_cloud_init( POINT_CLOUD *cloud, int point_c );

void point_cloud_resize( POINT_CLOUD *cloud, int point_c );

void point_cloud_destroy( POINT_CLOUD *cloud );

#endif
