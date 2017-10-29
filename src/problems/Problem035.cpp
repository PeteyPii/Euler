#include "SourcePrefix.h"

#include "Common.h"

int32 problem35(int32 n) {
  if (n < 2) {
    return 0;
  }

  vector<bool> isPrime;
  sieveOfErotosthenes(n, isPrime);

  int32 digits = 1;
  int32 nextBoundary = 10;
  int32 i = 2;
  int32 count = 0;
  while (i < n) {
    if (isPrime[i]) {
      bool isCircular = true;
      int32 rotated = i;

      for (int32 j = 0; j < digits - 1; j++) {
        int32 onesDigit = rotated % 10;
        rotated /= 10;
        rotated += onesDigit * (nextBoundary / 10);

        if (!isPrime[rotated]) {
          isCircular = false;
          break;
        }
      }

      if (isCircular) {
        count++;
      }
    }

    i++;
    if (i == nextBoundary) {
      digits++;
      nextBoundary *= 10;
    }
  }

  return count;
}

#include "SourceSuffix.h"
