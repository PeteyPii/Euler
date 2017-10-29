#include "SourcePrefix.h"

#include "Common.h"

int32 problem27(int32 n) {
  if (n < 1) {
    throw string("Bad restrictions on a and b (they belong to an empty set)");
  }

  if (n == 1) {
    return 0;
  }

  if (n == 2) {
    // Every permutation does not generate any primes, so let's say a = b = 0
    return 0;
  }

  vector<bool> isPrime;
  sieveOfErotosthenes(n, isPrime);

  int32 bestA = 0;
  int32 bestB = 0;
  int32 bestPrimeCount = 0;

  for (int32 b = 0; b < n; b++) {
    if (!isPrime[b]) {
      continue;
    }

    for (int32 a = 1 + (b == 2 ? -1 : 0); a < n; a += 2) {
      int32 x = 0;
      while (isNumberPrime(x * x + a * x + b)) {
        x++;
      }

      if (x > bestPrimeCount) {
        bestPrimeCount = x;
        bestA = a;
        bestB = b;
      }
    }

    for (int32 a = 0; a < n; a++) {
      int32 x = 0;
      while (isNumberPrime(x * x - a * x + b)) {
        x++;
      }

      if (x > bestPrimeCount) {
        bestPrimeCount = x;
        bestA = -a;
        bestB = b;
      }
    }
  }

  return bestA * bestB;
}

#include "SourceSuffix.h"
