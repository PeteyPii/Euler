#include "SourcePrefix.h"

#include "BigInteger.h"
#include "Common.h"

int32 problem16(int32 n) {
  if (n < 0) {
    throw string("Negative exponent not implemented yet");
  }

  BigInteger x(1);
  for (int32 i = 0; i < n; i++) {
    x = x + x;
  }

  return x.sumOfDigits();
}

#include "SourceSuffix.h"
