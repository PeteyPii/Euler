#include "SourcePrefix.h"

#include "Common.h"

int32 problem21(int32 n) {
  if (n < 1) {
    throw string("Cannot find amicable numbers less than 1");
  }

  if (n == 1) {
    return 0;
  }

  int32 sum = 0;
  // start at 2 since 1 isn't an amicable number
  for (int32 i = 2; i < n; i++) {
    int32 x = sumOfDivisors(i);

    if (x != i && sumOfDivisors(x) == i) {
      sum += i;
    }
  }

  return sum;
}

#include "SourceSuffix.h"
