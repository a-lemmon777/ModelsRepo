#include <stdio.h>

int* first() {
  int a[3];
  a[0] = 5;
  a[1] = 8;
  a[2] = 9;
  /* printf("Address for a = %u.\n", a); */
  return a;
}

int second(int p, int q, int r) {
  int x, y, z;
  x = p+q;
  y = q+r;
  z = p+r;
  return x*y*z;
}

void print_array(int a[]) {
  int i;
  printf("The address of i = %u.\n", &i);
  printf("The address for a = %u.\n", a);
  for (i = 0; i < 3; ++i) {
    printf("a[%d] = %d\n", i, a[i]);
    printf("a[0] = %d\n", a[0]);
  }
}

int main(void) {
  int* a;
  int v;
  a = first();
  print_array(a);
  v = second(3, 1, 8);
  printf("v = %d\n", v);
  print_array(a);
}
