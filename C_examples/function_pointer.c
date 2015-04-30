#include <stdio.h>

int dbl(int x) {
  return x*2;
}

int triple(int x) {
  return x*3;
}

int execute(int (*func)(int), int value) {
  return (*func)(value);
}

int main(void) {
  int dbl = 0;
  printf("execute(double, 5) = %d.\n", execute(dbl, 5));
  printf("execute(triple, 5) = %d.\n", execute(triple, 5));
  return 0;
}
