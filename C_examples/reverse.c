#include <stdio.h>
#include <stdlib.h>

/*
 * A recursive (and fairly odd and inefficient) implementation of
 * array reversal. This is really mostly to illustrate the allocation
 * and de-allocation of memory in function calls.
 *
 * This essentially implements the same algorithm embodied by this
 * (equally ineficient, if less weird) Scheme definition:
 *
 *   (define (rev xs)
 *     (if (null? xs)
 *       '()
 *       (append (rev (cdr xs)) (list (car xs)))))
 *
 * or essentially equivalent Ruby definition:
 *
 *   def rev(xs)
 *     if xs == []
 *       return []
 *     end
 *     return rev(xs[1..-1]) + [xs[0]]
 *   end
 *
 * In each case we're pulling off the first item, reversing the rest, and
 * then tacking the first item onto the end of the result. The problem
 * with this (fairly natural) algorithm is that we end up copying the
 * result when we tack that value onto the end.  If we're reversing
 * a list of length n, that happens O(n) times, with an average cost
 * for copying that's also O(n).  Thus this algorithm is O(n^2).
 *
 * Note here that recursion _isn't_ the problem here, it's using it badly.
 * There are O(n) recursive reversal algorithms that would work just fine.
 * I chose to use this algorithm because it does a ton of allocating
 * and de-allocating, which is what I was trying to demonstrate.
 */
int* reverse_array(int size, int* array) {
  int first;
  int* rest;
  int* result;
  int i;

  if (size == 0) {
    return NULL;
  }
  first = array[0];
  // Adding 1 to a pointer like array actually assumes the pointer points
  // to an array of cells, and moves the pointer ahead to point to the next
  // cell.  So if, for example, an int was a 4 byte type, (array+1) actually
  // moves the pointer ahead 4 bytes, so that it will line up with the next
  // int in the array.
  //
  // All this means that this recursive call sorted the "tail" of the
  // array.
  rest = reverse_array(size-1, array+1);
  
  // Then we allocate some memory for the result, copy rest into that,
  // and put first into the last slot.
  result = calloc(size, sizeof(int));
  for (i=0; i<size-1; ++i) {
    result[i] = rest[i];
  }
  result[size-1] = first;

  // The value is rest is no longer needed, so we can free it up. If we
  // fail to do this, it will hang around until program terminates.  If
  // we have a program that runs for a long time, doing lots of reversals,
  // then failing to free this could lead to a severe memory leak.
  free(rest);

  return result;
}

void print_array(int size, int* array) {
  int i;
  
  printf("[");
  for (i = 0; i < size; ++i) {
    if (i > 0) {
      printf(", ");
    }
    printf("%d", array[i]);
  }
  printf("]\n");
}

int main(int argc, char** argv) {
  int* array;
  int i, size;

  if (argc != 2) {
    printf("usage: %s n, where n is size of array to reverse\n", argv[0]);
    exit(1);
  }
  size = atoi(argv[1]);

  array = calloc(size, sizeof(int));
  for (i = 0; i < size; ++i) {
    array[i] = i;
  }

  print_array(size, array);
  array = reverse_array(size, array);
  print_array(size, array);

  return 0;
}
