#include "SourcePrefix.h"

#include "Common.h"

int32 problem86(int32 n) {
  if (n < 0) {
    return 0;
  }

  int32 d = 0;
  int32 cuboids = 0;
  while (cuboids <= n) {
    d++;
    for (int32 sum = 2; sum <= 2 * d; sum++) {
      double root = sqrt(d * d + sum * sum);
      const double epsilon = 0.00001;
      if (root - static_cast<int32>(root) < epsilon) {
        cuboids += (sum > d + 1) ? sum / 2 - sum + d + 1 : sum / 2;
      }
    }
  }

  return d;
}

#include "SourceSuffix.h"
