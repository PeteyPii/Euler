#include "SourcePrefix.h"

#include "Common.h"

int32 problem64(int32 n) {
  if (n <= 1) {
    return 0;
  }

  set<int32> perfectSquares;
  int32 i = 2;
  while (i * i <= n) {
    perfectSquares.insert(i * i);
    i++;
  }

  int32 count = 0;
  int32 root = 1;
  for (int32 x = 2; x <= n; x++) {
    if (x == (root + 1) * (root + 1)) {
      root++;
      continue;
    }

    int32 a = root;
    int32 b = 1;
    set<pair<int32, int32>> seen;
    while (true) {
      pair<int32, int32> temp = make_pair(a, b);
      if (seen.count(temp) == 1) {
        count += seen.size() % 2 == 1 ? 1 : 0;
        break;
      }

      seen.insert(temp);

      b = (x - a * a) / b;
      a = (((a + root) / b) * b) - a;
    }
  }

  return count;
}

#include "SourceSuffix.h"
