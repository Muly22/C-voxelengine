#include <stdio.h>
//
#include "include/mempool.h"
#include "stdlib.h"

int main() {
  MEMPOOL pool1;
  MEMPOOL *pool2;
  printf("%x %x\n", (void*)&pool1, (void*)pool2);
  mempool_init(&pool1, 10);
  mempool_init(pool2, 10);
  printf("%x %x\n", (void*)&pool1, (void*)pool2);
  int *a, *b;
  a = mempool_take(&pool1, 5);
  if (!a)
    return 1;
  *a = 5;
  printf("%d\n", *a);
  b = mempool_take(pool2, 5);
  if (!b)
    return 1;
  *b = 6;
  printf("%d\n", *b);
}
