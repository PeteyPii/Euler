#include "SourcePrefix.h"

#include "Common.h"

int32 problem23() {
  vector<int32> abundantNumbers;
  for (int32 i = 1; i <= 28123; i++) {
    if (sumOfDivisors(i) > i) {
      abundantNumbers.push_back(i);
    }
  }

  vector<bool> hasSum(28123 + 1, false);
  for (uint32 i = 0; i < abundantNumbers.size() && abundantNumbers[i] * 2 <= 28123; i++) {
    for (uint32 j = i; j < abundantNumbers.size(); j++) {
      if (abundantNumbers[i] + abundantNumbers[j] > 28123) {
        break;
      }

      hasSum[abundantNumbers[i] + abundantNumbers[j]] = true;
    }
  }

  int32 sum = 0;
  for (int32 i = 1; i <= 28123; i++) {
    if (!hasSum[i]) {
      sum += i;
    }
  }

  return sum;
}

#include "SourceSuffix.h"
