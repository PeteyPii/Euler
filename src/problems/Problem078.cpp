#include "SourcePrefix.h"

#include "Common.h"

int32 problem78(int32 n) {
  if (n < 0) {
    n *= -1;
  } else if (n == 0) {
    return -1;
  } else if (n == 1) {
    return 0;
  }

  // Use the pentagonal number theorem and calculate all numbers under mod n.
  vector<int32> p;
  p.push_back(1);

  int32 number = 0;
  while (p[number] != 0) {
    number++;

    int64 sum = 0;

    int32 k = 1;
    do {
      int32 ix = number - k * (3 * k - 1) / 2;
      if (ix < 0 || ix > number) {
        break;
      }
      sum += p[number - k * (3 * k - 1) / 2];
      k = -k;

      ix = number - k * (3 * k - 1) / 2;
      if (ix < 0 || ix > number) {
        break;
      }
      sum += p[number - k * (3 * k - 1) / 2];
      k = -k + 1;

      ix = number - k * (3 * k - 1) / 2;
      if (ix < 0 || ix > number) {
        break;
      }
      sum -= p[number - k * (3 * k - 1) / 2];
      k = -k;

      ix = number - k * (3 * k - 1) / 2;
      if (ix < 0 || ix > number) {
        break;
      }
      sum -= p[number - k * (3 * k - 1) / 2];
      k = -k + 1;
    } while (true);

    p.push_back(sum % n);
  }

  return number;
}

#include "SourceSuffix.h"
