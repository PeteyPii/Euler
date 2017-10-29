#include "SourcePrefix.h"

#include "Common.h"

int32 problem92(int32 n) {
  if (n < 1) {
    return 0;
  }

  unordered_set<int32> bads = {1};
  unordered_set<int32> goods = {89};
  int32 candidate = 1;
  while (candidate < n) {
    int32 sum = candidate;
    int32 value;
    while (true) {
      value = sum;
      sum = 0;

      while (value > 0) {
        sum += (value % 10) * (value % 10);
        value /= 10;
      }

      if (bads.count(sum) == 1) {
        bads.insert(candidate);
        break;
      } else if (goods.count(sum) == 1) {
        goods.insert(candidate);
        break;
      }
    }

    candidate++;
  }

  return goods.size();
}

#include "SourceSuffix.h"
