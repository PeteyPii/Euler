#include "SourcePrefix.h"

#include "Common.h"

int32 problem50(int32 n) {
  if (n <= 2) {
    throw string("There are no primes below 2");
  }

  vector<bool> isPrime;
  sieveOfErotosthenes(n, isPrime);

  vector<int64> primes;
  for (uint32 i = 0; i < isPrime.size(); i++) {
    if (isPrime[i]) {
      primes.push_back(i);
    }
  }

  uint32 left = 0;
  uint32 right = primes.size() - 1;
  int64 sum = vectorSum(primes);

  // Slide right index to the maximum number of consecutive primes based on sum
  while (sum >= n) {
    sum -= primes[right];
    right--;
  }

  while (true) { // Break on first find
    int32 nextSum = sum - primes[right];
    while (sum < n) {
      if (isPrime[static_cast<uint32>(sum)]) {
        return sum;
      }

      sum -= primes[left];
      left++;
      right++;
      sum += primes[right];
    }

    right = right - left - 1;
    left = 0;
    sum = nextSum;
  }

  throw string("Could not find prime successfully");
}

#include "SourceSuffix.h"
