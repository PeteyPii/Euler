#include "SourcePrefix.h"

#include "Common.h"

int32 problem4(int32 n) {
  int32 low = pow((double)10, n - 1);
  int32 high = pow((double)10, n);
  int32 max = 0;
  int32 product;

  for (int32 x = low; x < high; x++) {
    for (int32 y = low; y < high; y++) {
      product = x * y;
      if (product > max && isPalindrome(product)) {
        max = product;
      }
    }
  }

  return max;
}

#include "SourceSuffix.h"
