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
  int id;
  VECTOR_I xyz;
  VOXEL voxels[CHUNK_LEN][CHUNK_LEN][CHUNK_LEN];
} CHUNK;

static CHUNK *voxel_world;

bool chunk_generate();

bool voxel_destroy( VOXEL **voxels, unsigned int voxel_c );

#endif
