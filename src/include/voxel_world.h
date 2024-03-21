#ifndef VOXEL_WORLD_H
#define VOXEL_WORLD_H

typedef struct {
  bool filled;
  char color;
} VOXEL;

extern VOXEL **voxel_world;

#endif
