#include "SourcePrefix.h"

#include "Common.h"

int32 problem70(int32 n) {
  if (n < 2) {
    throw string("Cannot compute minimum of an empty set");
  }

  int64 min = 10;   // Ratio should never exceed 10 since the numerator
  int64 minPhi = 1; // and denominator will have the same number of digits
  bool found = false;

  // Biggest phi(i) can be is ceil(sqrt(i) - 1)^2. Once the value of this creates
  // a ratio bigger than one we have already found, there is no way we can find a
  // better ratio, if we start with the largest numbers first.
  int32 root = sqrt(n);
  for (int32 i = n - 1; i >= 2; i--) {
    if (root * root >= i) {
      root--;
    }

    if (root * root * min < minPhi * i) {
      break;
    }

    int32 phi = i;
    int32 x = i;

    if (x % 2 == 0) {
      phi /= 2;
      x /= 2;
    }
    if (phi * min <= minPhi * i) {
      continue;
    }
    while (x % 2 == 0) {
      x /= 2;
    }

    int32 divisor = 3;
    while (divisor * divisor <= x) {
      if (x % divisor == 0) {
        phi /= divisor;
        phi *= divisor - 1;
        if (phi * min <= minPhi * i) {
          break;
        }
        do {
          x /= divisor;
        } while (x % divisor == 0);
      }

      divisor += 2;
    }

    phi /= x;
    phi *= x - 1;

    if (phi == i - 1) {
      continue;
    }

    if (minPhi * i < min * phi) {
      string num = numberToString(i);
      string denom = numberToString(phi);

      sort(num.begin(), num.end());
      sort(denom.begin(), denom.end());

      if (num == denom) {
        min = i;
        minPhi = phi;
        found = true;
      }
    }
  }

  if (!found) {
    throw string("There is no number whose totient value is a permutation of itself in the domain");
  }

  return static_cast<int32>(min);
}

#include "SourceSuffix.h"
