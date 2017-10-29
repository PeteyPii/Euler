#include "SourcePrefix.h"

#include "Common.h"

int64 problem43() {
  class Substringifier {
  public:
    int32 operator()(char* start) {
      // Just hard-code it as a 3-digit substring. This is
      // pretty niche and better performance is nice.
      return start[0] * 100 + start[1] * 10 + start[2];
    }
  };

  Substringifier substringifier;

  // Use integers instead of ASCII codes to make taking numerical substrings
  // easier
  char permutation[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  int64 sum = 0;

  do {
    if ((substringifier(permutation + 1) % 2 == 0) &&
        (substringifier(permutation + 2) % 3 == 0) &&
        (substringifier(permutation + 3) % 5 == 0) &&
        (substringifier(permutation + 4) % 7 == 0) &&
        (substringifier(permutation + 5) % 11 == 0) &&
        (substringifier(permutation + 6) % 13 == 0) &&
        (substringifier(permutation + 7) % 17 == 0)) {
      // Need to have LL constants, otherwise the multiplication
      // might overflow before being added. I'm doing it this way instead of
      // a loop since a loop would be a little slower.
      sum += permutation[0] * 1000000000LL;
      sum += permutation[1] * 100000000LL;
      sum += permutation[2] * 10000000LL;
      sum += permutation[3] * 1000000LL;
      sum += permutation[4] * 100000LL;
      sum += permutation[5] * 10000LL;
      sum += permutation[6] * 1000LL;
      sum += permutation[7] * 100LL;
      sum += permutation[8] * 10LL;
      sum += permutation[9];
    }
  } while (next_permutation(permutation, permutation + 10));

  return sum;
}

#include "SourceSuffix.h"
