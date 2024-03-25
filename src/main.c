#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
//
#include "include/point_cloud.h"
#include "include/point_world.h"
#include "include/core.h"

#define POINT_C 10

int main() {
  voxel_world = malloc(sizeof(CHUNK*));
  chunk_init(&(voxel_world[0]));
  POINT_CLOUD cloud;
  if (point_cloud_init(&cloud, POINT_C, LOL))
    puts("ERROR: point_cloud_init");
  for (int i = 0; i < POINT_C; i++) {
    cloud.points[i].pos.x = rand()%100;
    cloud.points[i].pos.y = rand()%100;
    cloud.points[i].pos.z = rand()%100;
  }
  point_cloud_update(&cloud);
  point_cloud_destroy(&cloud);
}
