#include "SourcePrefix.h"

#include "Common.h"

int32 problem74(int32 n, int32 m) {
  if (n < 1) {
    return 0;
  }

  int32 fact[10];
  fact[0] = 1;
  for (int32 i = 1; i < 10; i++) {
    fact[i] = fact[i - 1] * i;
  }

  // A chain only hits a repeating number if it enters one of the three loops or
  // if the next number is the last number on the chain. Thus, except for
  // loops and when x' = x, chainLength(x) = 1 + chainLength(x')
  unordered_map<int32, int32> lengths;

  lengths[0] = 2;

  lengths[1] = 1;

  lengths[145] = 1;

  lengths[169] = 3;
  lengths[36301] = 3;
  lengths[1454] = 3;

  lengths[871] = 2;
  lengths[45361] = 2;

  lengths[872] = 2;
  lengths[45362] = 2;

  vector<int32> chain;
  for (int32 i = 0; i < n; i++) {
    if (lengths.count(i) == 0) {
      int32 x = i;
      unordered_map<int32, int32>::iterator it;
      do {
        chain.push_back(x);

        int32 sum = 0;
        while (x > 0) {
          sum += fact[x % 10];
          x /= 10;
        }
        x = sum;

        if (x == chain.back()) {
          it = lengths.insert(make_pair(x, 1)).first;
          chain.pop_back();
          break;
        }

        it = lengths.find(x);
      } while (it == lengths.end());

      int32 length = it->second;
      while (!chain.empty()) {
        lengths.insert(make_pair(chain.back(), length + 1));
        length++;
        chain.pop_back();
      }
    }
  }

  int32 count = 0;
  for (auto it = lengths.begin(); it != lengths.end(); it++) {
    if (it->second == m && it->first < n) {
      count++;
    }
  }
  return count;
}

#include "SourceSuffix.h"
