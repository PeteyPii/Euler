#include "SourcePrefix.h"

#include "Common.h"

int32 problem39(int32 n) {
  if (n <= 12) {
    throw string("There are no right triangles with integer side lengths with "
                 "a perimeter below 12");
  }

  // Use Euclid's formula for generating all unique Pythagorean triplets. It is
  // the following:
  // a = k * (t^2 - s^2)
  // b = k * 2 * s * t
  // c = k * (s^2 + t^2)
  // where s, t, and k are positive integers, gcd(s, t) = 1, t > s, and t - s is
  // odd

  // b < c and b + c < n so 2 * b < n
  map<int32, int32> solutionCount;
  for (int32 s = 1; 4 * s < n; s++) {
    int32 t = s + 1;
    while (4 * s * t < n) {
      if (gcd(s, t) == 1) {
        int32 perimeter = 2 * t * (s + t);
        int32 k = 1;
        while (k * perimeter < n) {
          solutionCount[k * perimeter]++;
          k++;
        }
      }

      t += 2;
    }
  }

  int32 maxCount = -1;
  int32 maxPerimeter = -1;
  for (auto item : solutionCount) {
    if (item.second > maxCount) {
      maxPerimeter = item.first;
      maxCount = item.second;
    }
  }

  return maxPerimeter;
}

#include "SourceSuffix.h"
