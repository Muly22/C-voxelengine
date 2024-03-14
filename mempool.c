#include <stdlib.h>
//
#include "include/mempool.h"

void mempool_init( MEMPOOL *mempool, unsigned int size ) {
  mempool->freesize = size;
  mempool->size = size;
  mempool->pool = malloc(size);
}

void *mempool_take( MEMPOOL *mempool, unsigned int size ) {
  if (size <= mempool->freesize) {
    void *res = &((mempool->pool)[mempool->freesize - 1]);
    (mempool->freesize)--;
    return res;
  }
  return NULL;
}

int mempool_resize( MEMPOOL *mempool, unsigned int size ) {
  void *status = realloc(mempool->pool, size);
  if (status == NULL) {
    return 1;
  }
  mempool->freesize += size - mempool->size;
  mempool->size = size;
  return 0;
}

void mempool_destroy( MEMPOOL *mempool ) {
  free(mempool->pool);
  mempool->pool = NULL;
}
