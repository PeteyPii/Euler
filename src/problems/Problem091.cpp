#include "SourcePrefix.h"

#include "Common.h"

int32 problem91(int32 n) {
  if (n < 1) {
    throw string("Invalid grid size");
  }

  int32 total = 3 * n * n;
  for (int32 x1 = 1; x1 <= n; x1++) {
    for (int32 y1 = 1; y1 <= n; y1++) {
      for (int32 x2 = 0; x2 <= n; x2++) {
        for (int32 y2 = 0; y2 <= n; y2++) {
          if (x1 == x2 && y1 == y2) {
            continue;
          }

          if (x1 * (x2 - x1) + y1 * (y2 - y1) == 0) {
            total += 1;
          }
        }
      }
    }
  }

  return total;
}

#include "SourceSuffix.h"
