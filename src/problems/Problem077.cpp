#include "SourcePrefix.h"

#include "Common.h"

int32 problem77(int32 n) {
  if (n < 1) {
    return 4;
  }

  // Same strategy as problem 76 but we can only subtract primes from the sum.
  // Let table[x][y] be the number of ways to sum to x where terms do not exceed
  // y.
  vector<vector<int32>> table;
  table.push_back(vector<int32>());
  table.push_back(vector<int32>());
  table[0].push_back(1);
  table[0].push_back(1);
  table[1].push_back(0);
  table[1].push_back(0);

  vector<bool> isPrime;
  isPrime.push_back(false);
  isPrime.push_back(false);

  int32 sum = 2;
  while (true) {
    for (int32 i = 0; i < sum; i++) {
      table[i].push_back(table[i].back());
    }

    isPrime.push_back(isNumberPrime(sum));

    table.push_back(vector<int32>());
    table.back().push_back(0);
    for (int32 i = 1; i <= sum; i++) {
      if (isPrime[i]) {
        table.back().push_back(table[sum - i][i] + table[sum][i - 1]);
      } else {
        table.back().push_back(table[sum][i - 1]);
      }
    }

    if (table[sum][sum] - (isPrime[sum] ? 1 : 0) > n) {
      break;
    }

    sum++;
  }

  return sum;
}

#include "SourceSuffix.h"
