#include "SourcePrefix.h"

#include "Common.h"

int64 problem72(int64 n) {
  if (n < 1) {
    throw string("Denominator should be able to be positive");
  }

  vector<int64> phi;
  totientValues(n, phi);

  return vectorSum(phi) - 1; // Minus 1 from phi(1) which should not be included
}

#include "SourceSuffix.h"
