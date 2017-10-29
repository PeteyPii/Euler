#include "SourcePrefix.h"

#include "Common.h"

int32 problem41() {
  // The sum of the digits of a 9-digit pandigital number is 45 so it
  // cannot be prime since it will always be divisible by three. Similarly
  // for 8-digit pandigital numbers. So the largest pandigital number that
  // is prime can be at most 7 digits long.
  string permutation = "7654321";
  do {
    int32 number = stringToNumber<int32>(permutation);
    if (isNumberPrime(number)) {
      return number;
    }
  } while (prev_permutation(permutation.begin(), permutation.end()));

  throw string("No 7-digit pandigital number that is prime exists");
}

#include "SourceSuffix.h"
