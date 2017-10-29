#include "SourcePrefix.h"

#include "Common.h"

int32 problem14(int32 n) {
  if (n < 1) {
    throw string("Can't do Collatz sequence starting from a number less than 1");
  }

  if (n == 1) {
    return 1;
  }

  if (n == 2) {
    return 2;
  }

  int32 maxLength = 0;
  int32 maxNumber = 0;

  for (int32 i = 2; i < n; i++) {
    int64 term = i;
    int32 c = 1;
    while (term != 1) {
      if (term % 2 == 0) {
        term /= 2;
      } else {
        term = 3 * term + 1;
      }
      c++;
    }

    if (c > maxLength) {
      maxLength = c;
      maxNumber = i;
    }
  }

  return maxNumber;
}

#include "SourceSuffix.h"
