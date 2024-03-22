#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//
#include "include/point_cloud.h"
#include "include/point.h"

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
      max = fabs(points[i].pos.x);
    }
    if (fabs(points[i].pos.y) > max) {
      max = fabs(points[i].pos.y);
    }
    if (fabs(points[i].pos.z) > max) {
      max = fabs(points[i].pos.z);
    }
  }
  if (!(int)max)
    return -1;
  res = (int)log2(max) + 1;
  return res;
}

static void octree( POINT *points, POINT *orig, int point_c, int depth, int x, int y, int z, int l, int b, int h ) {
  int count = 0;
  for (int i = 0; i < point_c; i++) {
    if (points[i].pos.x < l &&
        points[i].pos.y < b &&
        points[i].pos.z < h &&
        points[i].pos.x > x &&
        points[i].pos.y > y &&
        points[i].pos.z > z) {
      count++;
    }
  }
  if (!count) {
    return;
  }
  else if (count == 1 || !depth) {
    //printf("%d %d %d %d %d %d\n", x,y,z,l,b,h); 
  }
  else {
    int midx = (l + x) >> 1;
    int midy = (b + y) >> 1;
    int midz = (h + z) >> 1;
    octree(points, orig, point_c, depth - 1, midx, midy, midz, l, b, h);
    octree(points, orig, point_c, depth - 1, x, midy, midz, midx, b, h);
    octree(points, orig, point_c, depth - 1, x, y, midz, midx, midy, h);
    octree(points, orig, point_c, depth - 1, midx, y, midz, l, midy, h);
    octree(points, orig, point_c, depth - 1, midx, midy, z, l, b, midz);
    octree(points, orig, point_c, depth - 1, x, midy, z, midx, b, midz);
    octree(points, orig, point_c, depth - 1, x, y, z, midx, midy, midz);
    octree(points, orig, point_c, depth - 1, midx, y, z, l, midy, midz);
  }
}

void point_cloud_update( POINT_CLOUD *cloud ) {
  POINT orig = point_orig(cloud->points, cloud->point_c);
  POINT *copy = malloc(sizeof(POINT) * cloud->point_c);
  for (int i = 0; i < cloud->point_c; i++) {
    copy[i].pos.x = (cloud->points)[i].pos.x;
    copy[i].pos.y = (cloud->points)[i].pos.y;
    copy[i].pos.z = (cloud->points)[i].pos.z;
  }
  //memcpy(copy, points, point_c);
  point_norm(copy, &orig, cloud->point_c);
  int depth = point_ln(copy, cloud->point_c);
  int bord = (int)(powf(2, depth) + 0.5f);
  octree(copy, &orig, cloud->point_c, depth, -bord, -bord, -bord, bord, bord, bord);
  free(copy);
}
