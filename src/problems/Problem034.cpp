#include "SourcePrefix.h"

#include "Common.h"

int32 problem34() {
  // 8 * 9! = 2903040 so less than 7 digits
  // 7 * 9! = 2540160 <-- highest number that could possibly work

  vector<int32> digitFactorials;
  for (int32 i = 0; i < 10; i++) {
    digitFactorials.push_back(factorial(i));
  }

  int32 total = 0;

  // Don't do one digit numbers as per the spec
  for (int32 i = 10; i <= 2540160; i++) {
    int32 n = i;
    int32 sum = 0;
    while (n > 0) {
      sum += digitFactorials[n % 10];
      n /= 10;
    }

    if (sum == i) {
      total += sum;
    }
  }

  return total;
}

#include "SourceSuffix.h"
