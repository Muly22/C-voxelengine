#ifndef MEMPOOL_H
#define MEMPOOL_H

typedef struct {
  unsigned int size; 
  unsigned int freesize;
  char *pool;
} MEMPOOL;

void  mempool_init( MEMPOOL *pool, unsigned int size );

void *mempool_take( MEMPOOL *pool, unsigned int size );

int mempool_resize( MEMPOOL *pool, unsigned int size );

void mempool_destroy( MEMPOOL *pool );

#endif
