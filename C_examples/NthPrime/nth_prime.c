#include <stdio.h>
#include <stdlib.h>

#include "nth_prime.h"

int prime_count;
int* primes;

bool isPrime(int candidate) {
  int i;
  for (i = 0; i < prime_count; ++i) {
    if (candidate % primes[i] == 0) {
      return FALSE;
    }
  }
  return TRUE;
}

int nth_prime(int n) {
  int candidate, result;
  // Allocate the array to store primes in as they're found
  primes = calloc(n, sizeof(int));
  // If calloc fails it will return 0, which is true.
  // If calloc failed, we'll quit with an exit code of 1.
  if (!primes) {
    exit(1);
  }

  // Put the first two primes in the array
  primes[0] = 2;
  primes[1] = 3;
  prime_count = 2;
  candidate = 5;

  while (prime_count < n) {
    if (isPrime(candidate)) {
      primes[prime_count] = candidate;
      ++prime_count;
    }
    candidate += 2;
  }
  
  result = primes[n-1];

  free(primes);

  return result;
}

