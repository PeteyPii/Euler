#include "SourcePrefix.h"

#include "Common.h"

int32 problem33() {
  vector<int32> numerators;
  vector<int32> denominators;

  // After removing two digits the fraction will be i/j where i is in [1, 8]
  // and j is in [1, 9]. The digit we remove is from 1 to 9 and it cannot be
  // from both the ones or both the tens or else it is trvial. So we brute force
  // all these combinations and check them
  for (int32 i = 1; i <= 8; i++) {
    for (int32 j = i + 1; j <= 9; j++) {
      for (int32 k = 1; k <= 9; k++) {
        int32 num1 = 10 * k + i;
        int32 den1 = 10 * j + k;
        int32 num2 = 10 * i + k;
        int32 den2 = 10 * k + j;

        if (num1 * j == den1 * i) {
          numerators.push_back(i);
          denominators.push_back(j);
        }

        if (num2 * j == den2 * i) {
          numerators.push_back(i);
          denominators.push_back(j);
        }
      }
    }
  }

  int32 productNumerator = vectorProduct(numerators);
  int32 productDenominator = vectorProduct(denominators);

  return productDenominator / gcd(productNumerator, productDenominator);
}

#include "SourceSuffix.h"
