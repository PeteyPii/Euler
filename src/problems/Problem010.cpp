#include "SourcePrefix.h"

#include "Common.h"

int64 problem10(int64 n) {
  vector<bool> isPrime;
  sieveOfErotosthenes(n, isPrime);
  int64 sum = 0;

  for (int64 i = 0; i <= n; i++) {
    if (isPrime[i]) {
      sum += i;
    }
  }

  return sum;
}

#include "SourceSuffix.h"
