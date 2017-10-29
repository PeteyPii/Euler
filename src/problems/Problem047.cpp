#include "SourcePrefix.h"

#include "Common.h"

int32 problem47(int32 n) {
  if (n < 1) {
    throw string("Cannot have a sequence of length less than one");
  }

  if (n == 1) {
    return 1;
  }

  vector<set<int32>> primeFactors;

  primeFactors.push_back(set<int32>());
  primeFactors.push_back(set<int32>({1}));
  primeFactors.push_back(set<int32>({2}));
  primeFactors.push_back(set<int32>({3}));

  int32 i = 4;
  int32 sequenceLength = 0;

  while (sequenceLength < n) {
    if (i % 2 == 0) {
      set<int32> temp = primeFactors[i / 2];
      temp.insert(2);
      primeFactors.push_back(temp);
    } else {
      bool prime = true;
      int32 factor = 3;
      while (factor * factor <= i) {
        if (i % factor == 0) {
          set<int32> temp = primeFactors[i / factor];
          temp.insert(factor);
          primeFactors.push_back(temp);
          prime = false;
          break;
        }

        factor += 2;
      }

      if (prime) {
        primeFactors.push_back({i});
      }
    }

    if (primeFactors.back().size() == static_cast<uint32>(n)) {
      sequenceLength++;
    } else {
      sequenceLength = 0;
    }

    i++;
  }

  return i - n;
}

#include "SourceSuffix.h"
