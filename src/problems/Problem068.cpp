#include "SourcePrefix.h"

#include "Common.h"

string problem68() {
  // It's easy to permute every possible magic 5-gon filling and then
  // check if it works. Each permutation has 4 other equivalent permutations
  // so we can represent the 5-gon as a 10 element array and assume the string
  // begins with what our representation begins with (so we must check that the
  // first element is the smallest on the outside. We can begin permuting from
  // 6 5 10 4 9 3 8 2 7 1, since 6 is the highest element that can be the minimum
  // on the outer ring and the rest of higher numbers must be on the outer ring.
  // The representation goes clockwise alternating with outside and then inside.
  // The first 2 numbers in the representation are the 2 first digits in the resulting
  // string so once we find a permutation that is successful, we only need to check
  // the remaining permutations in the last 8 digits since lower the first two digits
  // will always result in a string lower than the one that is found.

  int32 ring[10] = {6, 5, 10, 4, 9, 3, 8, 2, 7, 1};

  string max = "0";
  do {
    if (ring[1] == 10) {
      continue;
    }

    do {
      if (ring[3] == 10 || ring[5] == 10 || ring[7] == 10 || ring[9] == 10) {
        continue;
      }

      if (ring[2] < ring[0] || ring[4] < ring[0] || ring[6] < ring[0] ||
          ring[8] < ring[0]) {
        continue;
      }

      int32 sum = ring[0] + ring[1] + ring[3];
      bool sumsGood = true;
      for (int32 i = 2; i < 10; i += 2) {
        if (ring[i] + ring[i + 1] + ring[(i + 3) % 10] != sum) {
          sumsGood = false;
          break;
        }
      }

      if (!sumsGood) {
        continue;
      }

      stringstream ss;
      for (int32 i = 0; i < 10; i += 2) {
        ss << ring[i] << ring[i + 1] << ring[(i + 3) % 10];
      }

      if (ss.str() > max) {
        max = ss.str();
      }
    } while (prev_permutation(ring + 2, ring + 10));
  } while (max == "0" && prev_permutation(ring, ring + 10));

  return max;
}

#include "SourceSuffix.h"
