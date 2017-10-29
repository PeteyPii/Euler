#include "SourcePrefix.h"

#include "BigInteger.h"
#include "Common.h"

int32 problem56(int32 n) {
  if (n < 1) {
    throw string("Invalid set of integers to create powers");
  }

  int32 maximalSum = 0;
  for (int32 a = 1; a < n; a++) {
    BigInteger bigPower(a);
    for (int32 b = 1; b < n; b++) {
      int32 sum = bigPower.sumOfDigits();
      if (sum > maximalSum) {
        maximalSum = sum;
      }

      bigPower *= a;
    }
  }

  return maximalSum;
}

#include "SourceSuffix.h"
