#include "SourcePrefix.h"

#include "Common.h"

int64 problem101(int64 n) {
  if (n <= 0) {
    return 0;
  }

  vector<vector<int64>> diffs((uint32)n + 1, vector<int64>((uint32)n + 1, -1));
  vector<int64> terms((uint32)n + 1);
  for (int64 x = 1; x <= n; x++) {
    int64 sum = 0;
    for (int64 i = 0; i <= n; i++) {
      if (i % 2 == 0) {
        sum += power(x, i);
      } else {
        sum -= power(x, i);
      }
    }
    diffs[0][x] = sum;
  }

  for (int64 term = 1; term < n; term++) {
    for (int64 x = 1; x <= n - term; x++) {
      diffs[term][x] = diffs[term - 1][x + 1] - diffs[term - 1][x];
    }
  }

  int64 diffResult = 0;
  for (int64 term = 1; term <= n; term++) {
    int64 expectedTerm = diffs[0][term];
    for (int64 i = term - 1; i >= 1; i--) {
      expectedTerm += diffs[term - i][i];
    }
    diffResult += expectedTerm;
  }

  return diffResult;
}

#include "SourceSuffix.h"
