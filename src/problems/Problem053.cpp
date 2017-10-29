#include "SourcePrefix.h"

#include "BigInteger.h"
#include "Common.h"

int64 problem53(int32 n, int64 m) {
  if (n < 1) {
    return 0;
  }

  class FactorialMemoizer {
  public:
    BigInteger& operator()(int32 x) {
      if (m_cMemory.count(x) == 0) {
        m_cMemory.insert(make_pair(x, factorial(BigInteger(x))));
      }

      return m_cMemory[x];
    }

  private:
    map<int32, BigInteger> m_cMemory;
  };

  FactorialMemoizer factorialMemoizer;

  int64 count = 0;
  BigInteger limit(m);

  while (n > 0) {
    BigInteger numerator = factorialMemoizer(n);

    int32 left = n / 2;
    int32 right = n - (n / 2);
    while (factorialMemoizer(left) * factorialMemoizer(right) * limit <
           numerator) {
      left--;
      right++;
    }

    if (left != right) {
      count += right - left - 1;
    } else {
      break;
    }

    n--;
  }

  return count;
}

#include "SourceSuffix.h"
