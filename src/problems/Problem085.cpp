#include "SourcePrefix.h"

#include "Common.h"

int64 problem85(int64 n) {
  if (n <= 1) {
    return 1;
  }

  int64 closestArea = 1;
  int64 closestCount = n - 1;

  int64 L = 1;
  int64 count = -1;
  do {
    L++;
    int64 L2 = L * L;
    int64 L3 = L2 * L;
    int64 L4 = L3 * L;

    count = L4 + 2 * L3 + L2 - L3 * (L + 1) + L2 * (L + 1) * (L + 1) / 4 - L2 * (L + 1);
  } while (count < n);

  int64 upperBound = sqrt(2 * n);
  for (int64 W = 1; W <= L; W++) {
    int64 leftH = 1;
    int64 rightH = upperBound;
    int64 W2 = W * W;
    int64 sumW = W * (W + 1) / 2;
    while (leftH < rightH) {
      int64 H = (leftH + rightH) / 2;
      int64 H2 = H * H;
      int64 sumH = H * (H + 1) / 2;
      count = W2 * H2 + W2 * H + W * H2 + W * H - W2 * sumH - sumW * H2 - sumW * H - W * sumH + sumW * sumH;

      if (count > n || H == leftH) {
        rightH = H;
      } else {
        leftH = H;
      }
    }

    if (n - count < closestCount) {
      closestCount = n - count;
      closestArea = W * leftH;
    }

    int64 H = leftH + 1;
    int64 H2 = H * H;
    int64 sumH = H * (H + 1) / 2;
    count = W2 * H2 + W2 * H + W * H2 + W * H - W2 * sumH - sumW * H2 - sumW * H - W * sumH + sumW * sumH;

    if (count - n < closestCount) {
      closestCount = count - n;
      closestArea = W * H;
    }
  }

  return closestArea;
}

#include "SourceSuffix.h"
