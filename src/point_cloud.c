#include <stdlib.h>
#include <stdio.h>
//
#include "include/point_cloud.h"
#include "include/point_world.h"

bool point_cloud_init( POINT_CLOUD *cloud, int point_c, MATERIAL mater ) {
  #ifdef DEBUG
    puts("INFO: point_cloud creating...");
  #endif
  cloud->point_c = point_c;
  cloud->points = malloc( sizeof(POINT) * point_c );
  cloud->material = mater;
  if (point_world_add_cloud(cloud))
    return 1;
  #ifdef DEBUG
    puts("INFO: point_cloud create");
  #endif
  return 0;
}

bool point_world_init() {
  if (point_world)
    return 1;
  point_world = malloc(sizeof(POINT_CLOUD**));
  point_world_len = 0;
  #ifdef DEBUG
    puts("INFO: point_world init");
  #endif
  return 0;
}

bool point_world_add_cloud( POINT_CLOUD *cloud ) {
  //if (!realloc(point_world, sizeof(POINT_CLOUD**) * (point_world_len + 1))) {
  //  puts("ERROR: realloc");
  //  return 1;
  //}
  if (!point_world) {
    puts("ERROR: point_world == NULL");
    return 1;
  }
  printf("%x\n", point_world);
  point_world[point_world_len] = cloud;
  cloud->id = point_world_len;
  point_world_len++;
  return 0;
}

bool point_cloud_resize( POINT_CLOUD *cloud, int point_c ) {
  if (!realloc(cloud->points, sizeof(POINT) * point_c )) {
    puts("ERROR: realloc");
    return 1;
  }
  return 0;
}

void point_cloud_destroy( POINT_CLOUD *cloud ) {
  free(cloud->points);
  point_world[cloud->id] = NULL;
  voxel_destroy(cloud->voxels, &(cloud->voxel_c));
}
