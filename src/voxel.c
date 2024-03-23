#include "include/voxel_world.h"

void voxel_destroy( VOXEL **voxels, unsigned int *voxel_c ) {
  if (!voxels)
    return;
  for (int i = 0; i < *voxel_c; i++) {
    (voxels[i])->filled = false;
    (voxels[i])->color = 0;
  }
  *voxel_c = 0;
}

void voxel_fill(  ) {

}
