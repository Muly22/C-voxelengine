#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//
#include "include/octree.h"

static POINT point_orig( const POINT *points, int point_c ) {
  POINT res = {0};
  for (int i = 0; i < point_c; i++) {
    res.pos.x += points[i].pos.x;
    res.pos.y += points[i].pos.y;
    res.pos.z += points[i].pos.z;
  }
  res.pos.x /= point_c;
  res.pos.y /= point_c;
  res.pos.z /= point_c;
  return res;
}

static void point_norm( POINT *points, const POINT *orig, int point_c) {
  for (int i = 0; i < point_c; i++){
    points[i].pos.x -= orig->pos.x;
    points[i].pos.y -= orig->pos.y;
    points[i].pos.z -= orig->pos.z;
  }
}

static int point_ln( POINT *points, int point_c ) {
  int res = -1;
  double max = fabs(points[0].pos.x);
  for (int i = 0; i < point_c; i++) {
    if (fabs(points[i].pos.x) > max) {
      max = points[i].pos.x;
    }
    if (fabs(points[i].pos.y) > max) {
      max = points[i].pos.y;
    }
    if (fabs(points[i].pos.z) > max) {
      max = points[i].pos.z;
    }
  }
  if (!(int)max)
    return -1;
  res = (int)log2(max) + 1;
  return res;
}

static void octree( VOXEL_OBJ *voxobj, POINT *points, POINT *orig, int point_c, int depth, int x, int y, int z, int l, int b, int h) {
  //printf("%d %d %f %f\n", depth, x, orig->pos.x, points[0].pos.x);
  //printf("%d %d %d %d %d %d\n", x,y,z,l,b,h); 
  int count = 0;
  for (int i = 0; i < point_c; i++) {
    if (points[i].pos.x < l &&
        points[i].pos.y < b &&
        points[i].pos.z < h &&
        points[i].pos.x > x &&
        points[i].pos.y > y &&
        points[i].pos.z > z) {
      count++;
      //printf("%d\n", count);
    }
  }
  if (!count)
    return;
  else if (count == 1 || !depth) {
    printf("%d %d %d %d %d %d\n", x,y,z,l,b,h); 
  }
  else {
    int midx = (l + x) / 2;
    int midy = (b + y) / 2;
    int midz = (h + z) / 2;
    octree(voxobj, points, orig, point_c, depth - 1, midx, midy, midz, l, b, h);
    octree(voxobj, points, orig, point_c, depth - 1, x, midy, midz, midx, b, h);
    octree(voxobj, points, orig, point_c, depth - 1, x, y, midz, midx, midy, h);
    octree(voxobj, points, orig, point_c, depth - 1, midx, y, midz, l, midy, h);
    octree(voxobj, points, orig, point_c, depth - 1, midx, midy, z, l, b, midz);
    octree(voxobj, points, orig, point_c, depth - 1, x, midy, z, midx, b, midz);
    octree(voxobj, points, orig, point_c, depth - 1, x, y, z, midx, midy, midz);
    octree(voxobj, points, orig, point_c, depth - 1, midx, y, z, l, midy, midz);
  }
}

void voxel_obj_init( VOXEL_OBJ *voxobj, int point_c ) {
  voxobj->voxel_c = 0;
  voxobj->voxels = malloc( sizeof(VOXEL) * point_c );
}

void voxel_obj_update( VOXEL_OBJ *voxobj, POINT *points, int point_c ) {
  POINT orig = point_orig(points, point_c);
  POINT *copy = malloc(sizeof(POINT) * point_c);
  for (int i = 0; i < point_c; i++) {
    copy[i].pos.x = points[i].pos.x;
    copy[i].pos.y = points[i].pos.y;
    copy[i].pos.z = points[i].pos.z;
  }
  //memcpy(copy, points, point_c);
  point_norm(copy, &orig, point_c);
  for (int i = 0; i < point_c; i++) {
    printf("%f %f %f\n", copy[i].pos.x, copy[i].pos.y, copy[i].pos.z);
  }
  int depth = point_ln(copy, point_c);
  int bord = (int)(powf(2, depth) + 0.5f);
  octree(voxobj, copy, &orig, point_c, depth, -bord, -bord, -bord, bord, bord, bord);
  free(copy);
}

void voxel_obj_destroy( VOXEL_OBJ *voxobj ) {
  free(voxobj->voxels);
}
