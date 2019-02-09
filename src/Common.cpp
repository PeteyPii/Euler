#include "SourcePrefix.h"

#include "Common.h"

void sieveOfErotosthenes(int64 n, vector<bool>& isPrime) {
  isPrime = vector<bool>(n + 1, true);

  isPrime[0] = false;
  isPrime[1] = false;

  for (int64 i = 0; i * i <= n; i++) {
    if (!isPrime[i]) {
      continue;
    }

    for (int64 j = i * i; j <= n; j += i) {
      isPrime[j] = false;
    }
  }
}

bool verifySieve(int64 n) {
  vector<bool> isPrime;
  sieveOfErotosthenes(n, isPrime);

  for (int64 i = 0; i <= n; i++) {
    if (isPrime[i] != isNumberPrime(i)) {
      throw "Prime check doesn't work on " + numberToString(i);
    }
  }

  return true;
}

bool isPalindrome(int32 n, int32 base) {
  if (base < 2) {
    throw "Base below 2 is invalid";
  }

  const int32 temp = n;
  int32 x = 0;
  while (n != 0) {
    x *= base;
    x += n % base;
    n /= base;
  }

  return temp == x;
}

void assertFileOpened(const ifstream& fin) {
  if (!fin) {
    throw string("Could not open file");
  }
}

bool isLeapYear(int32 year) {
  if (year >= 1752) {
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
  } else {
    return (year % 4 == 0);
  }
}

void printProgress(uint64 current, uint64 total, int32 intervals) {
  if (((current + 1) * intervals) / total != (current * intervals) / total) {
    cout << (double)(current + 1) * 100 / total << "% done..." << endl;
  }
}

double logarithmicIntegralApprox(double x, int32 iterations) {
  const double gamma = 0.57721566490; // Euler-Mascheroni constant
  const double lnx = log(x);

  double sum = gamma + log(lnx);
  for (int32 k = 1; k <= iterations; k++) {
    sum += pow(lnx, k) / (k * factorial(static_cast<double>(k)));
  }

  return sum;
}

void partitionsRecurse(vector<vector<int32>>* result, const vector<int32>& prefix, int32 remaining) {
  if (remaining == 0) {
    result->push_back(prefix);
    return;
  }

  int32 max = remaining;
  if (!prefix.empty()) {
    if (prefix.back() < max) {
      max = prefix.back();
    }
  }
  for (int32 i = max; i >= 1; i--) {
    vector<int32> newPrefix = prefix;
    newPrefix.push_back(i);
    partitionsRecurse(result, newPrefix, remaining - i);
  }
}

vector<vector<int32>> partitions(int32 x) {
  vector<vector<int32>> result;
  partitionsRecurse(&result, {}, x);
  return result;
}

void partitionsOfSizeNRecurse(vector<vector<int32>>* result, const vector<int32>& prefix, int32 remaining, int32 n) {
  if (prefix.size() == (uint32)n) {
    if (remaining == 0) {
      result->push_back(prefix);
    }
    return;
  }

  int32 max = remaining;
  if (!prefix.empty()) {
    if (prefix.back() < max) {
      max = prefix.back();
    }
  }
  for (int32 i = max; i >= 1; i--) {
    vector<int32> newPrefix = prefix;
    newPrefix.push_back(i);
    partitionsOfSizeNRecurse(result, newPrefix, remaining - i, n);
  }
}

vector<vector<int32>> partitionsOfSizeN(int32 x, int32 n) {
  vector<vector<int32>> result;
  partitionsOfSizeNRecurse(&result, {}, x, n);
  return result;
}

void partitionSetsOfSizeNRecurse(
    vector<vector<int32>>* result, const vector<int32>& prefix, int32 remaining, int32 n, int32 startMin) {
  if (prefix.size() == (uint32)n) {
    if (remaining == 0) {
      result->push_back(prefix);
    }
    return;
  }

  int32 min = startMin;
  int32 max = remaining / (n - prefix.size()) + 1;
  if (!prefix.empty()) {
    min = prefix.back() + 1;
  }
  for (int32 i = min; i <= max; i++) {
    vector<int32> newPrefix = prefix;
    newPrefix.push_back(i);
    partitionSetsOfSizeNRecurse(result, newPrefix, remaining - i, n, startMin);
  }
}

vector<vector<int32>> partitionSetsOfSizeN(int32 x, int32 n, int32 startMin) {
  vector<vector<int32>> result;
  partitionSetsOfSizeNRecurse(&result, {}, x, n, startMin);
  return result;
}
