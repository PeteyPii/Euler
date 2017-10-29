#include "SourcePrefix.h"

#include "Common.h"

int32 problem26(int32 n) {
  if (n < 1) {
    throw string("Bad number for counting reciprocal decimal digit period");
  }

  if (n == 1) {
    return 1;
  }

  int32 highestRepeater = 1;
  int32 highestPeriod = -1;

  for (int32 i = n; i > highestPeriod; i--) {
    int32 remainder = 1;
    vector<bool> hasSeen(i, false);
    vector<int32> whenSeen(i, -1);

    int32 c = 0;
    while (true) {
      int32 ix = remainder;
      if (hasSeen[ix]) {
        break;
      }

      hasSeen[ix] = true;
      whenSeen[ix] = c;
      c++;
      remainder = (10 * remainder) % i;
    }

    int32 period = c - whenSeen[remainder];
    if (period > highestPeriod) {
      highestPeriod = period;
      highestRepeater = i;
    }
  }

  return highestRepeater;
}

#include "SourceSuffix.h"
