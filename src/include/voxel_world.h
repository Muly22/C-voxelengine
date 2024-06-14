#ifndef VOXEL_WORLD_H
#define VOXEL_WORLD_H

#include <stdbool.h>
//
#include "vector.h"

#define CHUNK_LEN 256

typedef struct {
  bool filled;
  char color;
} VOXEL;

typedef struct {
  VECTOR_I xyz;
  VOXEL voxels[CHUNK_LEN][CHUNK_LEN][CHUNK_LEN];
} CHUNK;

extern CHUNK voxel_world;

void chunk_init( CHUNK *chunk );

bool chunk_generate();

void voxel_destroy( VOXEL **voxels, unsigned int *voxel_c );

void voxel_fill( VOXEL **voxels, unsigned int *voxel_c, long int x, long int y, long z, long int l, long int b, long int h );

#endif
