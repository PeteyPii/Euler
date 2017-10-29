#include "SourcePrefix.h"

#include "Common.h"

int32 problem95(int32 n) {
  if (n < 1) {
    return 0;
  }

  vector<int32> divSums(n + 1, 1);
  for (int32 div = 2; div <= n; div++) {
    for (int32 multiple = div * 2; multiple <= n; multiple += div) {
      divSums[multiple] += div;
    }
  }

  vector<bool> visited(n + 1, false);
  int32 longestPathLength = 0;
  int32 bestItem = -1;
  for (int32 start = 1; start <= n; start++) {
    if (visited[start]) {
      continue;
    }

    set<int32> chain;
    int32 end = start;
    bool next = false;
    while (!visited[end]) {
      visited[end] = true;
      chain.insert(end);
      end = divSums[end];
      if (end >= n) {
        next = true;
        break;
      }
    }
    if (next) {
      continue;
    }
    if (chain.count(end) == 0) {
      continue;
    }

    int32 cursor = divSums[end];
    int32 pathLength = 1;
    int32 minItem = end;
    while (cursor != end) {
      pathLength += 1;
      if (cursor < minItem) {
        minItem = cursor;
      }
      cursor = divSums[cursor];
    }

    if (pathLength > longestPathLength) {
      longestPathLength = pathLength;
      bestItem = minItem;
    }
  }
  return bestItem;
}

#include "SourceSuffix.h"
