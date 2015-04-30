#include <stdio.h>

int main(void) {
  int* a = 5896320;
  int i;

  for (i=0; i<100; ++i) {
    printf("a[%d] = %d.\n", i, a[i]);
  }
  
  return 0;
}
