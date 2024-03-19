#ifndef POINT_CLOUD_H
#define POINT_CLOUD_H

#include "octree.h"
#include "point.h"

typedef struct {
  int id;
  MATERIAL material;
  VOXEL_OBJ voxobj;
  int point_c;
  POINT *points;
} POINT_CLOUD;

void point_cloud_init( POINT_CLOUD *cloud, int point_c );

int point_cloud_resize( POINT_CLOUD *cloud, int point_c );

void point_cloud_update( POINT_CLOUD *cloud );

void point_cloud_destroy( POINT_CLOUD *cloud );

#endif
