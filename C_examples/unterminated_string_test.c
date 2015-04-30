#include <stdio.h>
#include <stdlib.h>

int main() {
  char str[4];
  char *s;
  char *t = "Fred";
  
  printf("t = <%s>.\n", t);

  str[0] = 'N';
  str[1] = 'i';
  str[2] = 'c';
  str[3] = '\0';
  printf("Our string = <%s>.\n", str);

  s = (char*) malloc(sizeof(char) * 3);
  s[0] = 'N';
  s[1] = 'i';
  s[2] = 'c';
  // s[3] = '\0';
  printf("Our other string = <%s>.\n", s);

  return 0;
}
