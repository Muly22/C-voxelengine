#ifndef POINT_WORLD_H
#define POINT_WORLD_H

#include <stdbool.h>
//
#include "point_cloud.h"
#include "point.h"

static POINT **point_world;

bool point_world_add_cloud( POINT_CLOUD *cloud );



#endif