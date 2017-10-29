#include "SourcePrefix.h"

#include "Common.h"

int64 problem3(int64 n) {
  int64 div = 3;
  int64 max = 0;

  while (n % 2 == 0) {
    max = 2;
    n /= 2;
  }

  while (div < n) {
    while (n % div != 0) {
      div++;
    }
    max = div;
    n /= div;
  }

  return max;
}

#include "SourceSuffix.h"
