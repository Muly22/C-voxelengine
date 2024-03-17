#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//
#include "include/point_cloud.h"

int main() {
  POINT_CLOUD cloud;
  point_cloud_init(&cloud, 5);
  for (int i = 0; i < 5; i++) {
    cloud.points[i].pos.x = rand()%100;
    cloud.points[i].pos.y = rand()%100;
    cloud.points[i].pos.z = rand()%100;
  }
  point_cloud_update(&cloud);
  point_cloud_destroy(&cloud);
}
