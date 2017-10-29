#include "SourcePrefix.h"

#include "Common.h"

int64 problem22() {
  ifstream fin("problem_input/p022.txt");
  assertFileOpened(fin);

  string temp;
  vector<string> names;
  while (fin >> temp) {
    names.push_back(temp);
  }

  sort(names.begin(), names.end());

  int64 totalScore = 0;
  for (uint32 i = 0; i < names.size(); i++) {
    string& name = names[i];
    uint32 sum = 0;
    for (uint32 j = 0; j < name.size(); j++) {
      sum += name[j] - 'A' + 1;
    }

    totalScore += static_cast<int64>(sum * (i + 1));
  }

  return totalScore;
}

#include "SourceSuffix.h"
