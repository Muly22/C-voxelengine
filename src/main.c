#include <stdio.h>
//
#include "include/mempool.h"

int main() {
  MEMPOOL pool;
  mempool_init(&pool, 3);
  int *a = (int*) mempool_take(&pool, 4);
  if (!a)
    printf("память\n");
  *a = 6;
  printf("%d\n", *a);
  mempool_destroy(&pool);
}
