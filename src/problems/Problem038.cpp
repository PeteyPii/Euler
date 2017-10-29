#include "SourcePrefix.h"

#include "Common.h"

int32 problem38() {
  // We are given that 9 x (1,2,3,4,5) = 918273645, a 1-9 pandigital number.
  // So our number must begin with a 9 if it is larger. One digit numbers other
  // than 9 won't create a concatenated product starting with a 9. A two digit
  // number starting with 9 will have a concatenated product whose size is
  // 2 -> 5 -> 8 -> 11 -> ... so it cannot work. Similarly for 3-digit numbers
  // and 5-digit and larger numbers. So our concatenated product is formed by
  // a 4-digit integer starting with 9 and (1,2) if it is larger than 918273645.
  // Otherwise, 918273645 is the largest. So we check all 4-digit numbers
  // beginning with 9.
  int32 largest = 918273645;
  for (int32 i = 9000; i < 10000; i++) {
    int32 concatenatedProduct = i * 100000 + 2 * i;
    if (concatenatedProduct > largest && isPandigital(concatenatedProduct)) {
      largest = concatenatedProduct;
    }
  }

  return largest;
}

#include "SourceSuffix.h"
