#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//
#include "include/voxel_world.h"

void chunk_init( CHUNK *chunk) {
  //memset(chunk->xyz, 0, sizeof(VECTOR_I));
}

void voxel_destroy( VOXEL **voxels, unsigned int *voxel_c ) {
  if (!voxels)
    return;
  for (int i = 0; i < *voxel_c; i++) {
    (voxels[i])->filled = 0;
    (voxels[i])->color = 0x00;
  }
  *voxel_c = 0;
}

void voxel_fill( VOXEL **voxels, unsigned int *voxel_c, long int x, long int y, long z, long int l, long int b, long int h ) {
  for (int i = x; i < l; x++) {
    for (int j = y; j < b; j++) {
      for (int k = z; k < h; k++) {
        /* исправить как появятся чанки chunk_search */
        VOXEL *vox = &voxel_world->voxels[i][j][k];
        vox->filled = 1;
        vox->color  = 0xFF;
        voxels = realloc(voxels, sizeof(VOXEL**) * (*voxel_c + 1));
        voxels[*voxel_c] = vox;
        (*voxel_c)++;
      }
    }
  }
}
