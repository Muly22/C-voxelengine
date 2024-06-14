#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "include/voxel_world.h"

int voxel_destroy( VOXEL **voxels, unsigned int *voxel_c ) {
  if (!voxels)
    return -1;
  for (int i = 0; i < *voxel_c; i++) {
    (voxels[i])->filled = 0;
    (voxels[i])->color = 0x00;
  }
  *voxel_c = 0;
  return 0;
}

int voxel_fill( VOXEL **voxels, unsigned int *voxel_c, long int x, long int y, long z, long int l, long int b, long int h ) {
  //printf("test %ld %ld %ld %ld %ld %ld\n", x, y, z, l, b, h);
  if (x > l || y > b || z > h)
    return -1;
  /*TODO: исправить как появятся чанки chunk_search */
  if (x < 0 || y < 0 || z < 0 || l < 0 || b < 0 || h < 0)
    return -1;
  for (int i = x; i < l; i++) {
    for (int j = y; j < b; j++) {
      for (int k = z; k < h; k++) {
        /*TODO: исправить как появятся чанки chunk_search */
        //printf("%d %d %d\n", i, j, k);
        VOXEL *vox = &(voxel_world.voxels[i][j][k]);
        vox->filled = 1;
        vox->color  = 0xFF;
        voxels = realloc(voxels, sizeof(VOXEL**) * (*voxel_c + 1));
        if (!voxels)
          return -1;
        voxels[*voxel_c] = vox;
        (*voxel_c)++;
      }
    }
  }
  return 0;
}
