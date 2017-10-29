#include "SourcePrefix.h"

#include "Common.h"

int32 problem51() {
  // Of the ten digits we can choose to replace with, in modulus 3, three of them
  // are equivalent to 0, three of them to 1, and three of them to 2. For an eight
  // prime family, we can only choose 2 digits not to use, so we always end up using
  // a digit from each modulus value. If the number of digits we replace is not
  // equivalent to zero mod 3, then the sum of our digits of any of our final number
  // will be x * y + z, where x is the digit we replace with, y is the number of digits
  // we replace and z is the sum of the digits we don't replace. No matter the value of
  // z, and since y =/= 0 mod 3, we will end up having a situation such that
  // x * y + z = 0 (mod 3) thus this number cannot be part of eight prime family since
  // this number will be divisible by 3, thus, composite. Therefore, we must replace
  // 3, 6, 9, ... digits for our eight prime family.

  // We also cannot replace the last digit because will end up having to replace it with
  // an even number which will make the number composite.

  // From above, we must replace at least 3 digits, and we cannot replace the last digit
  // so we must have at least a 4 digit number.

  // At most we can start off by using 2s as the digits we replace numbers with so we only
  // need to look for numbers with a bunch of 0s, 1s, or 2s digits.

  int32 i = 1000;
  while (true) {
    int32 digitCount[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    std::vector<int32> digits;
    int32 n = i / 10; // Skip last digit
    while (n > 0) {
      digitCount[n % 10]++;
      digits.push_back(n % 10);
      n /= 10;
    }

    // This is implicitly checked by the for loop above but it probably
    // eliminates the need to check if numbers are prime a good portion
    // of the time
    if (digitCount[0] >= 3 || digitCount[1] >= 3 || digitCount[2] >= 3) {
      if (isNumberPrime(i)) {
        // Replace 0s, then 1s, then 2s
        for (int32 d = 0; d <= 2; d++) {
          // Replace k digits
          for (int32 k = 3; k <= digitCount[d]; k += 3) {
            // If there's c >= 3 digits and we only replace k of them, we need to try
            // every possible way of replacing k of them
            vector<int32> digitReplacePerm;
            for (int32 x = 0; x < k; x++) {
              digitReplacePerm.push_back(1);
            }
            for (int32 x = k; x < digitCount[d]; x++) {
              digitReplacePerm.push_back(0);
            }

            // Sort the digit replacement permutation
            next_permutation(digitReplacePerm.begin(), digitReplacePerm.end());
            do {
              // Prime family forms an arithmetic sequence so figuring out
              // the next prime to check is as easy as adding a constant
              // number every single time
              int32 difference = 0;
              int32 digitPower = 10;
              uint32 x = 0;
              for (int32 digit : digits) {
                if (digit == d) {
                  difference += digitReplacePerm[x] * digitPower;
                  x++;
                }

                digitPower *= 10;
              }

              // At most 2 numbers we check can be composite and if we start
              // with digits 1 or 2, the prior numbers can be considered
              // invalid/composite
              int32 misses = d;
              bool found = true;
              for (int32 y = 1; y <= 9 - d; y++) {
                if (!isNumberPrime(i + y * difference)) {
                  misses++;
                  if (misses >= 3) {
                    found = false;
                    break;
                  }
                }
              }

              if (found) {
                return i;
              }
            } while (next_permutation(digitReplacePerm.begin(), digitReplacePerm.end()));
          }
        }
      }
    }

    i++;
  }

  throw string("Could not find eight prime family successfully");
}

#include "SourceSuffix.h"
