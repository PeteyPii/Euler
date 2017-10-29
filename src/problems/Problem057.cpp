#include "SourcePrefix.h"

#include "BigInteger.h"
#include "Common.h"

int32 problem57(int32 n) {
  if (n < 1) {
    return 0;
  }

  // Know that convergent terms for 2^(1/2) are [1; 2, ...]
  vector<BigInteger> pi; // convergent numerators
  vector<BigInteger> qi; // convergent denominators

  pi.push_back(BigInteger(1));
  qi.push_back(BigInteger(1));

  pi.push_back(pi[0] * 2 + 1);
  qi.push_back(qi[0] * 2);

  int32 count = 0;
  if (pi[0].numberOfDigits() > qi[0].numberOfDigits()) {
    count++;
  }
  if (pi[1].numberOfDigits() > qi[1].numberOfDigits()) {
    count++;
  }
  for (uint32 i = 2; i <= static_cast<uint32>(n); i++) {
    pi.push_back(pi[i - 1] * 2 + pi[i - 2]);
    qi.push_back(qi[i - 1] * 2 + qi[i - 2]);
    if (pi[i].numberOfDigits() > qi[i].numberOfDigits()) {
      count++;
    }
  }

  return count;
}

#include "SourceSuffix.h"
