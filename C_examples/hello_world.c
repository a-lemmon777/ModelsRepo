#include <stdio.h>
#include "hello_world.h"
#include "fib.h"

int main() {
  print_greeting();
  printf("Fib(30) = %d.\n", fib(30));
  
  return 0;
}

void print_greeting() {
  printf("Hello world!\n");
}
