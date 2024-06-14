#ifndef POINT_CLOUD_H
#define POINT_CLOUD_H

#include "voxel_world.h"
#include "material.h"
#include "point.h"

typedef struct {
  long int id;
  unsigned int voxel_c;
  unsigned int point_c;
  MATERIAL material;
  VOXEL **voxels;
  POINT *points;
} POINT_CLOUD;

int point_cloud_init( POINT_CLOUD **cloud, int point_c, MATERIAL mater );

int point_cloud_resize( POINT_CLOUD *cloud, int point_c );

int point_cloud_update( POINT_CLOUD *cloud );

void point_cloud_destroy( POINT_CLOUD *cloud );

#endif
