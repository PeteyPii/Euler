#include "SourcePrefix.h"

#include "Common.h"

int32 problem58(int32 n, int32 m) {
  if (n < 0 || m < 1) {
    throw string("Impossible ratio of primes to non-primes");
  }

  int32 numberCount = 5;
  int32 primeCount = 3;
  int32 lastNumber = 9;
  int32 incrementer = 4; // One less than the next spiral side-length

  while (m * primeCount >= n * numberCount) {
    lastNumber += incrementer;
    if (isNumberPrime(lastNumber)) {
      primeCount++;
    }

    lastNumber += incrementer;
    if (isNumberPrime(lastNumber)) {
      primeCount++;
    }

    lastNumber += incrementer;
    if (isNumberPrime(lastNumber)) {
      primeCount++;
    }

    lastNumber += incrementer;
    // Don't have to check the last number number because it's going to be an odd square

    numberCount += 4;
    incrementer += 2;
  }

  return incrementer - 1;
}

#include "SourceSuffix.h"
