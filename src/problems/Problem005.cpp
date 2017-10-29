#include "SourcePrefix.h"

#include "Common.h"

int64 problem5(int64 n) {
  vector<bool> table(n, false);

  int64 multiple = 1;

  for (int32 i = 1; i <= n; i++) {
    if (multiple % i == 0) {
      continue;
    }

    for (int32 j = 1; j <= i; j++) {
      if ((j * multiple) % i == 0) {
        multiple *= j;
        break;
      }
    }
  }

  return multiple;
}

#include "SourceSuffix.h"
