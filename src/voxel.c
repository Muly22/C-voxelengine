#include "include/voxel_world.h"

bool voxel_destroy( VOXEL **voxels, unsigned int voxel_c ) {
  if (!voxel_c)
    return true;
  for (int i = 0; i < voxel_c; i++) {
    (voxels[i])->filled = false;
    (voxels[i])->color = 0;
  }
  return false;
}