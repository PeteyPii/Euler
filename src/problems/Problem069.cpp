#include "SourcePrefix.h"

#include "Common.h"

int32 problem69(int32 n) {
  // Consider a prime factorization of x and it's ratio x/phi(x) = r.
  // The resulting ratio of x multiplied by one of its prime factors is
  // no different. Thus, consider x with only unique prime factors. Changing
  // one of x's factors to be a lower, but still unique, prime factor increases
  // its ratio x/phi(x). Thus, consider x which is a product of the first z
  // primes. Multiplying x by the (z+1)th prime increases its ratio. Thus, the
  // value of x that maximizes its ratio is the product of the most sequential
  // primes beginning at 2 that does not exceed n.

  if (n < 1) {
    throw string("The phi function must be well defined for values of within "
                 "the interval and the interval must be non-empty");
  }

  if (n == 1) {
    return 1;
  }

  int32 product = 2;
  int32 i = 3;
  while (product * i <= n) {
    if (isNumberPrime(i)) {
      product *= i;
    }

    i += 2;
  }

  return product;
}

#include "SourceSuffix.h"
