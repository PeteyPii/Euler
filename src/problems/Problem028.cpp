#include "SourcePrefix.h"

#include "Common.h"

int32 problem28(int32 n) {
  if (n < 1) {
    throw string("Cannot have a spiral with a width less than one");
  }

  if (n % 2 == 0) {
    throw string("Spiral with even side length is undefined");
  }

  int32 x = (n - 1) / 2;
  return 4 * (4 * x * x * x + 12 * x * x + 11 * x + 3) / 3 - 6 * x * (x + 1) - 3;
}

#include "SourceSuffix.h"
