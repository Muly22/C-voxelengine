#include <string.h>
//
#include "include/octree.h"
#include "include/macros.h"

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

void voxel_obj_init( VOXEL_OBJ *voxobj, int point_c ) {
  voxobj->voxel_c = 0;
  mempool_init( &(voxobj->pool), sizeof(VOXEL) * point_c );
}

void voxel_obj_update( VOXEL_OBJ *voxobj, POINT *points, int point_c ) {
  POINT orig = point_orig(points, point_c);
  POINT *copy = malloc(sizeof(POINT) * point_c);
  memcpy(copy, points, point_c);
  point_norm(copy, &orig, point_c);
  octree(voxobj, copy, &orig, point_c, );
  free(copy);
}

void voxel_obj_destroy( VOXEL_OBJ *voxobj ) {
  mempool_destroy(&(voxobj->pool));
}
