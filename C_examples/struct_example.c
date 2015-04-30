#include "struct_example.h"

int main(void) {
  struct date d;
  struct date *e;

  d.day = 5;
  d.month = 9;
  d.year = 2010;
  d.weekday = "Wednesday";

  e = malloc(sizeof(struct date));
  e->day = 23;
  e->month = 6;
  e->year = 29834723;

  return 0;
}
