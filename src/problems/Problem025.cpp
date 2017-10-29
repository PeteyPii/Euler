#include "SourcePrefix.h"

#include "BigInteger.h"
#include "Common.h"

int32 problem25(int32 n) {
  if (n < 1) {
    throw string("A number cannot be less than one digit long");
  }

  if (n == 1) {
    return 1;
  }

  int32 c = 2;
  BigInteger a(1);
  BigInteger b(1);
  BigInteger temp;

  while (b.numberOfDigits() < n) {
    temp = b;
    b = a + b;
    a = temp;
    c++;
  }

  return c;
}

#include "SourceSuffix.h"
