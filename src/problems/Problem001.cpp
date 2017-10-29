#include "SourcePrefix.h"

#include "Common.h"

int32 problem1(int32 n) {
  int32 sum = 0;
  for (int32 i = 0; i < n; i++) {
    if (i % 3 == 0 || i % 5 == 0) {
      sum += i;
    }
  }

  return sum;
}

#include "SourceSuffix.h"
