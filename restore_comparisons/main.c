#include <stdio.h>
#include <stdlib.h>

#include "restore_comparisons.h"

int main(int argc, char* argv[]) {
  char* line;
  int size;
  
  size = 100;
  line = (char*) malloc (size + 1);

  while (getline(&line, (size_t*) &size, stdin) > 0) {
    printf("%s\n", restore_comparisons(line));
  }

  return 0;
}
