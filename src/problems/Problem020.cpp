#include "SourcePrefix.h"

#include "BigInteger.h"
#include "Common.h"

int32 problem20(int32 n) {
  if (n == 0) {
    return 1;
  }

  if (n < 0) {
    throw string("We shouldn't take the factorial of a negative number");
  }

  BigInteger x(1);
  for (int32 i = 1; i <= n; i++) {
    x *= i;
  }

  return x.sumOfDigits();
}

#include "SourceSuffix.h"
