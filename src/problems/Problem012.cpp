#include "SourcePrefix.h"

#include "Common.h"

int64 problem12(int32 n) {
  if (n < 1) {
    return 1;
  }

  for (int32 i = 2; i < INT32_MAX; i++) {
    int64 x = i * (i + 1) / 2;
    int32 c = 2;
    for (int32 j = 2; j * j <= x; j++) {
      if (x % j == 0) {
        c += 2;
      }
    }

    if (c >= n) {
      return x;
    }
  }

  throw string("Triangle number too big");
}

#include "SourceSuffix.h"
