 #include <stdio.h>

int main() {
  int a[10];
  int i;

  printf("a = %u.\n", a);
  i = 100;
  printf("4[a] = %d.\n", 4[a]);
  while (0 == 0) {
    printf("a[%d] = %d.\n", i, a[i]);
    a[i] = 0;
    ++i;
  }

  return 0;
}
