#include "SourcePrefix.h"

#include "Common.h"

int32 problem42() {
  int32 nextAdd = 1;
  int32 maxAdd = 0;
  set<int32> triangleNumbers;

  ifstream fin("problem_input/p042.txt");
  assertFileOpened(fin);

  int32 count = 0;

  string word;
  while (fin >> word) {
    int32 score = 0;
    for (char c : word) {
      score += c - 'A' + 1;
    }

    while (score > maxAdd) {
      maxAdd += nextAdd;
      triangleNumbers.insert(maxAdd);
      nextAdd++;
    }

    if (triangleNumbers.count(score) == 1) {
      count++;
    }
  }

  return count;
}

#include "SourceSuffix.h"
