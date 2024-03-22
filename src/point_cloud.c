#include <stdlib.h>
#include <stdio.h>
//
#include "include/point_cloud.h"
#include "include/point_world.h"

bool point_cloud_init( POINT_CLOUD *cloud, int point_c, MATERIAL mater ) {
  #ifdef DEBUG
    #include <stdio.h>
    puts("INFO: point_cloud creating...");
  #endif
  cloud->point_c = point_c;
  cloud->points = malloc( sizeof(POINT) * point_c );
  cloud->material = mater;
  if (point_world_add_cloud(cloud))
    return 1;
  #ifdef DEBUG
    #include <stdio.h>
    puts("INFO: point_cloud create");
  #endif
  return 0;
}

bool point_world_add_cloud( POINT_CLOUD *cloud ) {
  printf("%d\n", point_world_len);
  if (!realloc(point_world, sizeof(POINT_CLOUD**) * (point_world_len + 1)))
  {
    puts("l1");
    return 1;
  }
  puts("l2");
  point_world[point_world_len] = cloud;
  puts("l3");
  cloud->id = point_world_len;
  puts("l4");
  point_world_len++;
  return 0;
}

bool point_cloud_resize( POINT_CLOUD *cloud, int point_c ) {
  if (!realloc(cloud->points, sizeof(POINT) * point_c ))
    return 1;
  return 0;
}

void point_cloud_destroy( POINT_CLOUD *cloud ) {
  free(cloud->points);
  point_world[cloud->id] = NULL;
  voxel_destroy(cloud->voxels, &(cloud->voxel_c));
}
