#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//
#include "include/point_cloud.h"

#define POINT_C 10

int main() {
  POINT_CLOUD cloud;
  point_cloud_init(&cloud, POINT_C);
  for (int i = 0; i < POINT_C; i++) {
    cloud.points[i].pos.x = rand()%20;
    cloud.points[i].pos.y = rand()%30;
    cloud.points[i].pos.z = rand()%30;
  }
  point_cloud_update(&cloud);
  point_cloud_destroy(&cloud);
}
