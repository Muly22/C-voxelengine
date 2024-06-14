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
  POINT_CLOUD *cloud;
  point_world_init();
  if (point_cloud_init(&cloud, POINT_C, LOL) < 0)
    puts("ERROR: point_cloud_init");
  for (int i = 0; i < POINT_C; i++) {
    point_world[0]->points[i].pos.x = rand()%100;
    point_world[0]->points[i].pos.y = rand()%100;
    point_world[0]->points[i].pos.z = rand()%100;
  }
  if (point_cloud_update(cloud) < 0) {
    puts("ERROR: point cloud update");
    return -1;
  }
  point_world_destroy();
  return 0;
}
