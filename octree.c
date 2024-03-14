#include "include/octree.h"

void voxel_obj_init( VOXEL_OBJ *voxobj, int point_c, int depth ) {
  voxobj->depth = depth;
  voxobj->voxel_c = 0;
  mempool_init( &(voxobj->pool), sizeof(VOXEL) * point_c );
}

void voxel_obj_destroy( VOXEL_OBJ *voxobj ) {
  mempool_destroy(&(voxobj->pool));
}
