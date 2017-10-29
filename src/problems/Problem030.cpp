#include "SourcePrefix.h"

#include "Common.h"

int32 problem30(int32 n) {
  if (n <= 1) {
    return 0;
  }

  int32 maxDigits = 1;
  double nLogNine = n * log10(9.0);
  while (nLogNine >= maxDigits - log10(static_cast<double>(maxDigits))) {
    maxDigits++;
  }

  vector<int32> cachedPowers(10);
  for (int32 i = 0; i < 10; i++) {
    cachedPowers[i] = pow(static_cast<double>(i), n);
  }

  int32 iterationCount = 10;
  for (int32 i = 11; i < 10 + maxDigits; i++) {
    iterationCount *= i;
  }

  iterationCount /= factorial(maxDigits);

  vector<int32> goodNumbers;
  vector<int32> sortedNumber(maxDigits, 0);
  for (int32 i = 0; i < iterationCount; i++) {
    int32 sum = 0;
    for (uint32 j = 0; j < sortedNumber.size(); j++) {
      sum += cachedPowers[sortedNumber[j]];
    }

    int32 tempSum = sum;
    if (sum > 1) {
      vector<int32> sortedSum(maxDigits);
      for (uint32 j = 0; j < sortedSum.size(); j++) {
        sortedSum[j] = tempSum % 10;
        tempSum /= 10;
      }

      sort(sortedSum.begin(), sortedSum.end());

      if (sortedNumber == sortedSum) {
        goodNumbers.push_back(sum);
      }
    }

    int32 ix = sortedNumber.size() - 1;
    while (sortedNumber[ix] == 9) {
      ix--;
      if (ix < 0) {
        ix = 0;
        break;
      }
    }

    sortedNumber[ix]++;
    if (sortedNumber[ix] == 10) {
      sortedNumber[ix] = 0;
    }

    for (uint32 j = ix + 1; j < sortedNumber.size(); j++) {
      sortedNumber[j] = sortedNumber[ix];
    }
  }

  return vectorSum(goodNumbers);
}

#include "SourceSuffix.h"
