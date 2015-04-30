#include <stdio.h>
#include <stdlib.h>

int string_length(char* str) {
  int count;

  for (count = 0; str[count] != '\0'; ++count) {
    // Do nothing
  }
     
  return count;
}

char* copy_string(char* str) {
  int length;
  int i;
  char* result;

  length = string_length(str);

  result = calloc(length, sizeof(char));

  for (i=0; i<length; ++i) {
    result[i] = str[i];
  }

  result[length] = '\0';

  return result;
}

int main() {
  char* str0 = "Nic McPhee";
  char* str1 = "Susan Gilbert";
  char* str2;
  int i;

  str2 = calloc(1000, sizeof(char));
  for (i=0; i<999; ++i) {
    str2[i] = 'a';
  }

  printf("Length of <%s> = %d.\n", str0, string_length(str0));
  printf("Length of <%s> = %d.\n", str1, string_length(str1));
  printf("Length of <%s> = %d.\n", str2, string_length(str2));

  printf("Copy of <%s> = <%s>.\n", str0, copy_string(str0));
  printf("Copy of <%s> = <%s>.\n", str1, copy_string(str1));
  printf("Copy of <%s> = <%s>.\n", str2, copy_string(str2));
}
