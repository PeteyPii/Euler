#include "SourcePrefix.h"

#include "Common.h"

int32 problem36(int32 n) {
  int32 sum = 0;
  for (int32 i = 1; i < n; i++) {
    if (isPalindrome(i, 10) && isPalindrome(i, 2)) {
      sum += i;
    }
  }

  return sum;
}

#include "SourceSuffix.h"
