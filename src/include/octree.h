#ifndef OCTREE_H
#define OCTREE_H

#include "mempool.h"
#include "point.h"
#include "voxel.h"

typedef struct {
  MEMPOOL pool;
  int voxel_c;
  VOXEL *voxels;
} VOXEL_OBJ;

void voxel_obj_init( VOXEL_OBJ *voxobj, int point_c );

void voxel_obj_update( VOXEL_OBJ *voxobj, POINT *points, int point_c );

void voxel_obj_destroy( VOXEL_OBJ *voxobj );

#endif
