#ifndef POINT_WORLD_H
#define POINT_WORLD_H

#include <stdbool.h>
//
#include "point_cloud.h"
#include "point.h"

static int point_world_len = 0;
static POINT_CLOUD **point_world;

bool point_world_add_cloud( POINT_CLOUD *cloud );



#endif
