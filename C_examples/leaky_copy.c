#include <stdio.h>
#include <stdlib.h>

int* copy(int size, int* data) {
  int i;
  int* result = calloc(size, sizeof(int));
  for (i=0; i<size; ++i) {
    result[i] = data[i];
  }
  return result;
}

int main() {
  int i;
  int a[7] = { 5, 8, 9, 6, 3, 2, 0 };
  int *c = copy(7, a);
  for (i=0; i<7; ++i) {
    printf("c[%d] = %d.\n", i, c[i]);
  }

  return 0;
}
