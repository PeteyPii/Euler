#include "SourcePrefix.h"

#include "BigInteger.h"
#include "Common.h"

int32 problem55() {
  const int32 CHECK_MAX = 10000;
  const int32 ITERATION_LIMIT = 50;

  int32 count = 0;
  for (int32 n = 1; n < CHECK_MAX; n++) {
    int32 i = 0;
    bool isLychrel = true;
    BigInteger candidate(n);
    while (i < ITERATION_LIMIT) {
      candidate = candidate + candidate.reverse();
      if (candidate.isPalindrome()) {
        isLychrel = false;
        break;
      }
      i++;
    }

    if (isLychrel) {
      count++;
    }
  }

  return count;
}

#include "SourceSuffix.h"
