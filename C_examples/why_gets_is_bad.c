/*
 * Never, ever, ever use gets() (do "man gets" and scroll down the BUGS
 * section) as its a _huge_ security problem. This program exists solely
 * to help demonstrate why gets() is a really bad idea.
 */
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 10

int main(void) {
  char buf[BUF_SIZE];
  double tax_rate = 0.06;
  
  gets(buf);
  while (strlen(buf) > 0) {
    printf("We read <%s>, tax rate = %g.\n", buf, tax_rate);
    gets(buf);
  }

  return 0;
}
