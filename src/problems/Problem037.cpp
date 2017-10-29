#include "SourcePrefix.h"

#include "Common.h"

int32 problem37() {
  // Truncatable primes must begin and end with a prime. If an at least
  // 3-digit prime contains an even number or 5 then one truncation
  // will end with such a digit making that truncation composite.
  // We could generate the possible truncatable primes using these
  // ideas but it is simple to just brute force it.
  int32 sum = 0;
  int32 i = 10; // Single digit primes do not count
  int32 count = 0;
  while (count < 11) { // There are eleven truncatable primes
    if (isNumberPrime(i)) {
      bool isTruncatable = true;
      int32 sliderFactor = 10;
      while (i / sliderFactor > 0) {
        if (!isNumberPrime(i / sliderFactor) ||
            !isNumberPrime(i % sliderFactor)) {
          isTruncatable = false;
          break;
        }

        sliderFactor *= 10;
      }

      if (isTruncatable) {
        sum += i;
        count++;
      }
    }

    i++;
  }

  return sum;
}

#include "SourceSuffix.h"
