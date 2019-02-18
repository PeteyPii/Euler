#include "SourcePrefix.h"

#include "Common.h"

int32 problem107() {
  ifstream fin("problem_input/p107.txt");
  assertFileOpened(fin);

  vector<string> input;
  string temp;
  while (fin >> temp) {
    input.push_back(temp);
  }

  if (input.empty()) {
    return 0;
  }

  int32 oldTotal = 0;
  vector<map<int32, int32>> adjList;
  auto it = input.begin();
  uint32 n = lround(sqrt(input.size()));
  for (uint32 i = 0; i < n; i++) {
    adjList.emplace_back();
    for (uint32 j = 0; j < n; j++) {
      if (*it != "-") {
        int32 weight = stringToNumber<int32>(*it);
        adjList.back()[j] = weight;
        oldTotal += weight;
      }
      it++;
    }
  }

  oldTotal /= 2;

  int32 newTotal = 0;
  set<int32> present;
  present.insert(0);
  map<int32, vector<int32>> candidates;
  for (auto kv : adjList[0]) {
    candidates[kv.second].push_back(kv.first);
  }
  while (present.size() < n) {
    int32 weight;
    int32 node;
    do {
      auto& lowestKv = *candidates.begin();
      weight = lowestKv.first;
      auto& nodes = lowestKv.second;
      node = nodes.back();
      nodes.pop_back();
      if (nodes.empty()) {
        candidates.erase(weight);
      }
    } while (present.find(node) != present.end());
    newTotal += weight;
    present.insert(node);
    for (auto kv : adjList[node]) {
      candidates[kv.second].push_back(kv.first);
    }
  }

  return oldTotal - newTotal;
}

#include "SourceSuffix.h"
