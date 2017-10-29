#include "SourcePrefix.h"

#include "Common.h"

int64 problem7(int64 n) {
  // Li(x) is approximately equal to pi(x) so use trial and
  // error to find a vale where Li(x) >= n.
  double pixUpperBound = 10;
  while (logarithmicIntegralApprox(pixUpperBound) < n) {
    pixUpperBound *= 1.25;
  }

  // Add a bit on to be safe
  int64 sieveSize = static_cast<int64>(pixUpperBound * 1.5);
  vector<bool> isPrime;

  int64 c = 0;
  while (true) {
    sieveOfErotosthenes(sieveSize, isPrime);
    for (int64 i = 0; i <= sieveSize; i++) {
      if (isPrime[i]) {
        c++;
        if (c == n) {
          return i;
        }
      }
    }
    sieveSize *= 3;
    sieveSize /= 2;
  }

  throw string("Sieve too small");
}

#include "SourceSuffix.h"
