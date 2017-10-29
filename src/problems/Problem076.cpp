#include "SourcePrefix.h"

#include "Common.h"

int64 problem76(int32 n) {
  if (n < 2) {
    return 0;
  }

  // We can solve this problem dynamically by keeping track of the number of
  // ways we can sum to k using terms no greater than x. In this set up, we consider
  // single term sums to be valid. We can construct a 2D table with growing k and x
  // values by using the relation count(k, x) = count(k - x, x) + count(k, x - 1).
  // Thus, we just need to find the value of count(n, n - 1), since we do not allow
  // "n" to be one of the sums.
  class Counter {
  public:
    Counter(int32 max)
        : m_nSize(max + 1), m_pCounts(new int64[(max + 1) * (max + 1)]), m_pCalced(new bool[(max + 1) * (max + 1)]) {
      for (int32 i = 0; i < m_nSize; i++) {
        for (int32 j = 0; j < m_nSize; j++) {
          m_pCalced[m_nSize * j + i] = false;
        }
      }
    }

    ~Counter() {
      delete[] m_pCounts;
      delete[] m_pCalced;
    }

    int64 operator()(uint32 sum, uint32 maxTerm) {
      if (m_pCalced[m_nSize * sum + maxTerm]) {
        return m_pCounts[m_nSize * sum + maxTerm];
      } else if (maxTerm == 0) {
        m_pCounts[m_nSize * sum + maxTerm] = 0;
        m_pCalced[m_nSize * sum + maxTerm] = true;
        return 0;
      } else if (sum == 0) {
        m_pCounts[m_nSize * sum + maxTerm] = 1;
        m_pCalced[m_nSize * sum + maxTerm] = true;
        return 1;
      } else if (maxTerm > sum) {
        m_pCounts[m_nSize * sum + maxTerm] = (*this)(sum, maxTerm - 1);
        m_pCalced[m_nSize * sum + maxTerm] = true;
        return m_pCounts[m_nSize * sum + maxTerm];
      } else {
        m_pCounts[m_nSize * sum + maxTerm] = (*this)(sum - maxTerm, maxTerm) + (*this)(sum, maxTerm - 1);
        m_pCalced[m_nSize * sum + maxTerm] = true;
        return m_pCounts[m_nSize * sum + maxTerm];
      }
    }

  private:
    const int32 m_nSize; // Max index of counts
    int64* m_pCounts;    // Columns for max sum term, rows for sum value
    bool* m_pCalced;
  };

  return Counter(n)(n, n - 1);
}

#include "SourceSuffix.h"
