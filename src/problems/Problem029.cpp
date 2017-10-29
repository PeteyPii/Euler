#include "SourcePrefix.h"

#include "Common.h"

int32 problem29(int32 n) {
  if (n < 2) {
    throw string("A number cannot be at least 2 and less than 2 at the same time");
  }

  vector<vector<int32>> primeFactor(n + 1, vector<int32>(n + 1, 0));
  for (int32 i = 2; i <= n; i++) {
    int32 remainder = i;
    int32 j = 2;

    while (j <= remainder) {
      if (remainder % j == 0) {
        primeFactor[i][j]++;
        remainder /= j;
        j = 2;
      } else {
        j++;
      }
    }
  }

  unordered_set<vector<int32>> uniqueValues;
  for (int32 a = 2; a <= n; a++) {
    for (int32 b = 2; b <= n; b++) {
      vector<int32> factors = primeFactor[a];
      for (uint32 i = 0; i < factors.size(); i++) {
        factors[i] *= b;
      }

      uniqueValues.insert(factors);
    }
  }

  return uniqueValues.size();
}

#include "SourceSuffix.h"
