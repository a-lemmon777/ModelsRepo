#include <stdio.h>
#include <stdlib.h>

void baz(void) {
  char a;
  char* b;
  char* c;
  char* d;
  int i;

  b = &a;
  /* b = 5896320; */
  printf("The address of a = %u.\n", &a);
  printf("The value of b = %u.\n", b);

  printf("The value of a = %c.\n", a);
  printf("The value pointed to by b = %c.\n", *b);

  c = malloc(100 * sizeof(char));
  for (i=0; i<100; ++i) {
    c[i] = 'x';
  }
  printf("The string at c = %s.\n", c);
  free(c);

  d = malloc(100 * sizeof(char));
  d[0] = 'N';
  d[1] = 'i';
  d[2] = 'c';
  /* d[3] = '\0'; */
  printf("The string at d = %s.\n", d);
}

void biz(void) {
  int* a;
  int i;

  for (i=0; i<100; ++i) {
    a[i] = i;
  }
  
  printf("The address for the array = %u.\n", a);
  printf("The first five values in a and their addresses are:\n");
  for (i=0; i<5; ++i) {
    printf("\t%d\t%u\n", a[i], &(a[i]));
  }
}

int main(void) {
  baz();
  biz();
}
