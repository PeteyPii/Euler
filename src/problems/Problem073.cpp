#include "SourcePrefix.h"

#include "Common.h"

int32 problem73(int32 n) {
  if (n < 1) {
    throw string("Denominator should be able to be positive");
  }

  int32 count = 0;
  for (int32 d = 1; d <= n; d++) {
    for (int32 i = d / 3 + 1; i * 2 < d; i++) {
      if (gcd(i, d) == 1) {
        count++;
      }
    }
  }

  return count;
}

#include "SourceSuffix.h"
