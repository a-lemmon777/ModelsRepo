#include <stdio.h>
#include <stdlib.h>

int main() {
  int* a;
  int* b;
  int* c;
  int i;

  a = (int*) calloc(sizeof(int), 10);
  b = (int*) calloc(sizeof(int), 10);

  for (i=0; i<10; ++i) {
    a[i] = i;
    b[i] = i*i+1;
  }

  c = a;
  for (i=0; i<20; ++i) {
    printf("c = %d.\n", c);
    printf("a[%d] = %d.\n", i, *c);
    c += 1;
  }

  for (i=0; i<20; ++i) {
    printf("b[%d] = %d.\n", i, b[i]);
  }
 
  return 0;
}
