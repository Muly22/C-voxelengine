#include <stdio.h>
//
#include "include/point_cloud.h"

int main() {
  POINT_CLOUD cloud;
  point_cloud_init(&cloud, 3);
  cloud.points[0].pos.x = 100 + 1;
  cloud.points[0].pos.y = 100 + 2;
  cloud.points[0].pos.z = 100 + 3;
  cloud.points[1].pos.x = 100 + 11;
  cloud.points[1].pos.y = 100 + -2;
  cloud.points[1].pos.z = 100 + 5;
  cloud.points[2].pos.x = 100 + -1;
  cloud.points[2].pos.y = 100 + -2;
  cloud.points[2].pos.z = 100 + -3;
  point_cloud_update(&cloud);
  point_cloud_destroy(&cloud);
}
