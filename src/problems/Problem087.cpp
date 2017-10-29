#include "SourcePrefix.h"

#include "Common.h"

int32 problem87(int32 n) {
  if (n <= 28) {
    return 0;
  }

  int32 maxDouble = sqrt(n) + 1;
  // int32 maxTriple = pow(n, 1.0 / 3) + 1;
  // int32 maxFourth = sqrt(sqrt(n) + 1) + 1;

  set<int32> sums;
  vector<bool> isPrime;
  sieveOfErotosthenes(maxDouble, isPrime);
  vector<int32> primes;
  for (uint32 i = 0; i < isPrime.size(); i++) {
    if (isPrime[i]) {
      primes.push_back(i);
    }
  }

  for (uint32 i = 0; i < primes.size(); i++) {
    int32 second = primes[i] * primes[i];
    for (uint32 j = 0; j < primes.size(); j++) {
      int32 third = primes[j] * primes[j] * primes[j];
      int32 twoAndThree = second + third;
      if (twoAndThree >= n) {
        break;
      }

      for (uint32 k = 0; k < primes.size(); k++) {
        int32 fourth = primes[k] * primes[k];
        fourth *= fourth;
        int32 sum = twoAndThree + fourth;
        if (sum >= n) {
          break;
        }

        sums.insert(sum);
      }
    }
  }

  return sums.size();
}

#include "SourceSuffix.h"
