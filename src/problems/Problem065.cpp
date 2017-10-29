#include "SourcePrefix.h"

#include "BigInteger.h"
#include "Common.h"

int32 problem65(int32 n) {
  if (n < 1) {
    throw string("Cannot have a non-positive indexed convergent of e");
  }

  vector<int32> ai(n);
  ai[0] = 2;
  for (int32 i = 1; i < n; i++) {
    if (i % 3 == 2) {
      ai[i] = (i + 1) / 3 * 2;
    } else {
      ai[i] = 1;
    }
  }

  vector<BigInteger> pi; // convergent numerators
  pi.push_back(BigInteger(1) * ai[0]);
  if (n > 1) {
    pi.push_back(pi[0] * ai[1] + 1);
  }

  for (int32 i = 2; i < n; i++) {
    pi.push_back(pi[i - 1] * ai[i] + pi[i - 2]);
  }

  return pi.back().sumOfDigits();
}

#include "SourceSuffix.h"
