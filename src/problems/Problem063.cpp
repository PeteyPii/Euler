#include "SourcePrefix.h"

#include "BigInteger.h"
#include "Common.h"

int32 problem63() {
  // Numbers greater than 9 cannot work since 10^1 is two digits, 10^2 is three digits,
  // and so on. We can figure out the numbers that work by calculating powers of 1 digit numbers.
  // Starting from one, once a number's power does not have the correct amount of digits, it will
  // always be that way since the required number will get 10 times greater while the power will
  // only get k <= 9 times greater.

  set<BigInteger> successes;
  for (int32 i = 1; i <= 9; i++) {
    BigInteger n(i);
    BigInteger bound(1);
    while (n >= bound) {
      successes.insert(n);
      n *= i;
      bound *= 10;
    }
  }

  return successes.size();
}

#include "SourceSuffix.h"
