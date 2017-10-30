#include "SourcePrefix.h"

#include "Common.h"

int64 problem100(int64 n) {
  if (n < 21) {
    return 15;
  }

  // Solved by using methods on https://alpertron.com.ar/QUAD.HTM
  // to solve general bivarite quadratic Diophantine equations.
  // We start with given soltuions so we can jump directly to contructing
  // a recurrence.
  int64 x = 15;
  int64 y = 21;
  while (y <= n) {
    int64 nextX = 3 * x + 2 * y - 2;
    int64 nextY = 4 * x + 3 * y - 3;
    x = nextX;
    y = nextY;
  }

  return x;
}

#include "SourceSuffix.h"
