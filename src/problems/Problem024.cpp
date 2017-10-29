#include "SourcePrefix.h"

#include "Common.h"

string problem24(int32 n) {
  if (n < 1) {
    throw string("Can't find the zero-th permutation or a negative permutation");
  }

  if (n > factorial(10)) {
    throw string("Can't find the zero-th permutation or a negative permutation");
  }

  vector<char> digits(10);
  for (int32 i = 0; i < 10; i++) {
    digits[i] = '0' + i;
  }

  n--;

  stringstream ss;
  for (int32 i = 10; i > 0; i--) {
    int32 f = factorial(i - 1);
    ss << digits[n / f];
    digits.erase(digits.begin() + (n / f));
    n %= f;
  }

  return ss.str();
}

#include "SourceSuffix.h"
