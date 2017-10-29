#include "SourcePrefix.h"

#include "Common.h"

int64 problem48(int32 n) {
  if (n < 1) {
    return 0;
  }

  const int64 modulus = 1e10;
  int64 sum = 0;

  // Do a boring O(n^2) solution since doing a logarithmic time
  // modulus exponent requires an integral type with more than
  // 64 bits (we need to be able to multiply two 10 digit numbers
  // together with the ideal way and 64 bits is not enough).
  for (int64 i = 1; i <= static_cast<int64>(n); i++) {
    int64 product = i;
    for (int64 j = 1; j < i; j++) {
      product *= i;
      product %= modulus;
    }

    sum += product;
    sum %= modulus;
  }

  return sum;
}

#include "SourceSuffix.h"
