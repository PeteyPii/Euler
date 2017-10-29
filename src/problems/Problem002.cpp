#include "SourcePrefix.h"

#include "Common.h"

int32 problem2(int32 n) {
  int32 a = 1;
  int32 b = 2;
  int32 sum = 0;
  int32 temp;

  while (b < n) {
    sum += b;
    temp = 2 * b + a;
    b = 3 * b + 2 * a;
    a = temp;
  }

  return sum;
}

#include "SourceSuffix.h"
