#include "SourcePrefix.h"

#include "Common.h"

int64 problem94(int64 n) {
  if (n < 1) {
    return 0;
  }

  int64 totalPerim = 0;
  int64 m = 1;
  while (true) {
    m += 1;
    int64 m2 = m * m;
    if (4 * m2 > n) {
      break;
    }

    if (m % 3 == 0) {
      continue;
    }
    int64 t = sqrt((m2 - 1) / 3) + 0.5;
    if (m2 - 3 * t * t != 1) {
      continue;
    }
    if ((m + t) % 2 == 0) {
      continue;
    }
    if (gcd(m, t) != 1) {
      continue;
    }

    totalPerim += 4 * m2;
  }

  m = 1;
  while (true) {
    m += 1;
    int64 m2 = m * m;
    if (2 * m2 + 4 * m + 2 > n) {
      break;
    }

    int64 d = sqrt(3 * m2 + 1) + 0.5;

    int64 t = 2 * m - d;
    int64 t2 = t * t;
    if (4 * m * t - m2 - t2 != -1) {
      continue;
    }
    if (gcd(m, t) != 1) {
      continue;
    }

    totalPerim += 2 * (m2 + t2) + 4 * m * t;
  }

  return totalPerim;
}

#include "SourceSuffix.h"
