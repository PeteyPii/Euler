#include "SourcePrefix.h"

#include "Common.h"

int32 problem32() {
  string permutation = "123456789";
  sort(permutation.begin(), permutation.end());
  set<int32> pandigitalIdentities;

  // Break up every permutation of "123456789" and check if a product is achieved. The first part will be the
  // product and the second part will be split into two factors. The first factor can always be the smallest since
  // we will eventually check the equivalent permutation where that factor is the second one
  do {
    int32 product;
    int32 multiplicand;
    int32 multiplier;

    for (int32 j : {1, 2}) {
      // Product can only be 4 digits since 5 digits is above what can be multiplied to by a total of 4 digits
      // and 3 digits is below what can be multiplied to with a total of 6 digits
      product = stringToNumber<int32>(permutation.substr(0, 4));
      multiplicand = stringToNumber<int32>(permutation.substr(4, j));
      multiplier = stringToNumber<int32>(permutation.substr(4 + j));

      if (product == multiplicand * multiplier) {
        pandigitalIdentities.insert(product);
      }
    }
  } while (next_permutation(permutation.begin(), permutation.end()));

  return accumulate(pandigitalIdentities.begin(), pandigitalIdentities.end(), 0);
}

#include "SourceSuffix.h"
