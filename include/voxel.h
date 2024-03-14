#ifndef VOXEL_H
#define VOXEL_H

#include "vector.h"
#include "color.h"

typedef struct {
  VECTOR_I xyz;
  VECTOR_I lbh;
  COLOR    clr;
} VOXEL; 

#endif
