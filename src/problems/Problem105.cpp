#include "SourcePrefix.h"

#include "Common.h"
#include "SpecialSubsetSum.h"

int32 problem105() {
  ifstream fin("problem_input/p105.txt");
  assertFileOpened(fin);

  const uint32 maxSetSize = 12;
  vector<vector<pair<vector<int32>, vector<int32>>>> disjointCheckCache(maxSetSize + 1);

  int32 total = 0;
  for (uint32 i = 1; i < disjointCheckCache.size(); i++) {
    disjointCheckCache[i] = disjointInequalityChecks(i);
  }

  string line;
  while (getline(fin, line) && line.length() > 0) {
    stringstream ss(line);
    vector<int32> sumSet;
    int32 x;
    while (ss >> x) {
      sumSet.push_back(x);
    }

    sort(sumSet.begin(), sumSet.end());
    if (isValidSpecialSubset(sumSet, disjointCheckCache[sumSet.size()])) {
      total += vectorSum(sumSet);
    }
  }

  return total;
}

#include "SourceSuffix.h"
