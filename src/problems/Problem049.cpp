#include "SourcePrefix.h"

#include "Common.h"

string problem49() {
  const uint32 upperPrime = 9999;
  vector<uint32> primes;
  vector<bool> isPrime;
  sieveOfErotosthenes(upperPrime, isPrime);
  for (uint32 i = 1000; i <= upperPrime; i++) {
    if (isPrime[i]) {
      primes.push_back(i);
    }
  }

  for (uint32 i = 0; i < primes.size(); i++) {
    for (uint32 j = i + 1; j < primes.size(); j++) {
      uint32 prime1 = primes[i];
      uint32 prime2 = primes[j];
      uint32 candidate = 2 * prime2 - prime1;

      if (candidate <= upperPrime && isPrime[candidate]) {
        if (prime1 == 1487 && prime2 == 4817) {
          continue;
        }

        string sPrime1 = numberToString(prime1);
        string sPrime2 = numberToString(prime2);
        string sPrime3 = numberToString(candidate);

        string sequence = sPrime1 + sPrime2 + sPrime3;

        sort(sPrime1.begin(), sPrime1.end());
        sort(sPrime2.begin(), sPrime2.end());
        sort(sPrime3.begin(), sPrime3.end());

        if (sPrime1 == sPrime2 && sPrime2 == sPrime3) {
          return sequence;
        }
      }
    }
  }

  throw string("Couldn't find prime sequence satisfying the requirements");
}

#include "SourceSuffix.h"
