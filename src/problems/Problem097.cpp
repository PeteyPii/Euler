#include "SourcePrefix.h"

#include "BigInteger.h"
#include "Common.h"

int64 problem97(int64 n, int64 m) {
  int64 result = stringToNumber<int64>(numberToString(modPower(BigInteger(2, 10), BigInteger(m, 128), 10000000000)));
  result = ((result * n) + 1) % 10000000000;
  return result;
}

#include "SourceSuffix.h"
