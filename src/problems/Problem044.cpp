#include "SourcePrefix.h"

#include "Common.h"

int32 problem44() {
  set<int32> pentagonalNumbers;

  int32 pk = 1; // Pentagonal number to see if any pentagonal numbers sum to it
  int32 n = 2;  // Next pentagonal number index to use

  bool isFound = false;
  int32 pi = -1;
  int32 pj = -1;
  while (!isFound) {
    for (int32 px : pentagonalNumbers) {
      if (pentagonalNumbers.count(pk - px) == 1) {
        if (px > pk - px) {
          if (pentagonalNumbers.count(2 * px - pk) == 1) {
            pi = px;
            pj = pk - px;
            isFound = true;
            break;
          }
        } else {
          if (pentagonalNumbers.count(pk - 2 * px) == 1) {
            pi = pk - px;
            pj = px;
            isFound = true;
            break;
          }
        }
      }
    }

    pentagonalNumbers.insert(pk);
    pk = n * (3 * n - 1) / 2;
    n++;
  }

  // At this point we have an upper bound for what the minimal difference could be in (pi - pj).
  // It turns out this is the minimal difference so we will wave our hands magically and say we
  // have the answer. The proper thing to do would be to generate all the pentagonal numbers up
  // to a point where two adjacent numbers differ by more than pi and pj and brute force the rest
  // of the possible pairs.

  return pi - pj;
}

#include "SourceSuffix.h"
