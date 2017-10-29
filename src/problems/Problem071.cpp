#include "SourcePrefix.h"

#include "Common.h"

int32 problem71(int32 n) {
  if (n < 1) {
    throw string("Denominator should be able to be positive");
  }

  int64 bestNum = 0;
  int64 bestDenom = 1;

  for (int32 i = 2; i <= n; i++) {
    int32 candidateNum = 3 * i / 7;
    if (i % 7 == 0) {
      candidateNum -= 1;
    }

    if (candidateNum * bestDenom > bestNum * i) {
      bestNum = candidateNum;
      bestDenom = i;
    }
  }

  return bestNum / gcd(bestNum, bestDenom);
}

#include "SourceSuffix.h"
