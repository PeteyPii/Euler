#include "SourcePrefix.h"

#include "Common.h"

int32 problem88(int32 n) {
  if (n < 2) {
    return 0;
  }

  struct FactorizationHasher;
  class Factorization {
  public:
    Factorization(const map<int32, int32>& factors) : m_factors(factors), m_factorCount(0), m_factorSum(0) {
      for (auto x : factors) {
        m_factorCount += x.second;
        m_factorSum += x.first * x.second;
      }
    }

    Factorization(map<int32, int32>&& factors, int32 factorCount, int32 factorSum)
        : m_factors(factors), m_factorCount(factorCount), m_factorSum(factorSum) {
    }

    Factorization(const Factorization& other) = default;
    Factorization& operator=(const Factorization& other) = default;
    Factorization(Factorization&& other) = default;
    Factorization& operator=(Factorization&& other) = default;

    bool operator==(const Factorization& other) const {
      return m_factors == other.m_factors;
    }

    vector<Factorization> nextFactorizations() {
      vector<Factorization> newFactorizations;
      for (auto first = m_factors.begin(); first != m_factors.end(); ++first) {
        for (auto second = first; second != m_factors.end(); ++second) {
          if ((first->first == second->first && first->second >= 2) || first->first != second->first) {
            map<int32, int32> factors = m_factors;

            factors[first->first] -= 1;
            factors[second->first] -= 1;
            factors[first->first * second->first] += 1;

            auto it = factors.find(first->first);
            if (it->second == 0) {
              factors.erase(it);
            }

            it = factors.find(second->first);
            if (it != factors.end() && it->second == 0) {
              factors.erase(it);
            }

            newFactorizations.emplace_back(
                move(factors),
                m_factorCount - 1,
                m_factorSum - first->first - second->first + first->first * second->first);
          }
        }
      }

      return newFactorizations;
    }

    const map<int32, int32>& getFactors() const {
      return m_factors;
    }
    int32 factorCount() {
      return m_factorCount;
    }
    int32 factorSum() {
      return m_factorSum;
    }

  private:
    map<int32, int32> m_factors;
    int32 m_factorCount;
    int32 m_factorSum;
  };

  struct FactorizationHasher {
    size_t operator()(const Factorization& factorization) const {
      return hash<map<int32, int32>>()(factorization.getFactors());
    }
  };

  vector<bool> isPrime;
  sieveOfErotosthenes(n, isPrime);
  vector<int32> primes;
  for (int32 i = 2; i <= n; i++) {
    if (isPrime[i]) {
      primes.push_back(i);
    }
  }

  vector<bool> isFound(n + 1, false);
  set<int32> productSumNumbers;
  int32 remaining = n - 2 + 1;
  int32 minNotFound = 2;

  int32 candidate = 4;
  while (remaining > 0) {
    map<int32, int32> primeFactorization;
    int32 remainder = candidate;
    for (auto prime : primes) {
      while (remainder % prime == 0) {
        primeFactorization[prime] += 1;
        remainder /= prime;
      }
    }

    unordered_set<Factorization, FactorizationHasher> examinedFactorizations;
    deque<Factorization> searchQueue;
    searchQueue.emplace_back(primeFactorization);
    while (!searchQueue.empty()) {
      Factorization& factorization = searchQueue.front();
      if (examinedFactorizations.count(factorization)) {
        searchQueue.pop_front();
        continue;
      }
      examinedFactorizations.insert(factorization);

      int32 setSize = factorization.factorCount() + candidate - factorization.factorSum();
      if (setSize < minNotFound) {
        searchQueue.pop_front();
        continue;
      }

      if (setSize <= n && !isFound[setSize]) {
        isFound[setSize] = true;
        productSumNumbers.insert(candidate);
        remaining -= 1;
        if (remaining == 0) {
          break;
        }

        while (isFound[minNotFound]) {
          minNotFound++;
        }
      }

      vector<Factorization> nextFactorizations = factorization.nextFactorizations();
      for (auto& nextFactorization : nextFactorizations) {
        searchQueue.emplace_back(move(nextFactorization));
      }

      searchQueue.pop_front();
    }

    candidate++;
  }

  int32 sum = setSum(productSumNumbers);
  return sum;
}

#include "SourceSuffix.h"
