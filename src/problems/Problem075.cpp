#include "SourcePrefix.h"

#include "Common.h"

int32 problem75(int32 n) {
  // Use Euclid's formula to generate all integer sided right triangles
  map<int64, int64> solutionCount;
  for (int64 s = 1; 4 * s < n; s++) {
    int64 t = s + 1;
    while (4 * s * t < n) {
      if (gcd(s, t) == 1) {
        int64 perimeter = 2 * t * (s + t);
        int64 k = 1;
        while (k * perimeter < n) {
          solutionCount[k * perimeter]++;
          k++;
        }
      }

      t += 2;
    }
  }

  int32 count = 0;
  for (auto it = solutionCount.begin(); it != solutionCount.end(); it++) {
    if (it->second == 1) {
      count++;
    }
  }

  return count;
}

#include "SourceSuffix.h"
