#include "SourcePrefix.h"

#include "Common.h"

int32 problem90() {
  vector<int32> digits(10);
  for (int32 i = 0; i < 10; i++) {
    digits[i] = i;
  }
  vector<vector<int32>> dice = combinations(digits.begin(), digits.end(), 6);
  vector<set<int32>> diceSets;
  for (auto& die : dice) {
    diceSets.emplace_back(die.begin(), die.end());
  }
  vector<bool> has6or9(dice.size());
  for (uint32 i = 0; i < dice.size(); i++) {
    has6or9[i] = diceSets[i].count(6) == 1 || diceSets[i].count(9);
  }
  vector<pair<int32, int32>> requiredPairs = {
      {0, 1},
      {0, 4},
      {0, 9},
      {1, 6},
      {2, 5},
      {3, 6},
      {4, 9},
      {4, 6}, // reversed so we only have to check the second digit
      {8, 1},
  };

  unordered_set<pair<set<int32>, set<int32>>> uniquePairs;
  for (uint32 i = 0; i < diceSets.size(); i++) {
    auto& d1 = diceSets[i];
    for (uint32 j = 0; j < diceSets.size(); j++) {
      auto& d2 = diceSets[j];
      bool valid = true;
      for (auto& pair : requiredPairs) {
        if (pair.second == 6 || pair.second == 9) {
          if (d1.count(pair.first) == 1 && has6or9[j]) {
            continue;
          } else if (d2.count(pair.first) == 1 && has6or9[i]) {
            continue;
          }
          valid = false;
          break;
        } else {
          if (d1.count(pair.first) == 1 && d2.count(pair.second)) {
            continue;
          } else if (d2.count(pair.first) == 1 && d1.count(pair.second)) {
            continue;
          }
          valid = false;
          break;
        }
      }

      if (valid) {
        if (uniquePairs.count(make_pair(d1, d2)) == 0) {
          uniquePairs.insert(make_pair(d2, d1));
        }
      }
    }
  }

  return uniquePairs.size();
}

#include "SourceSuffix.h"
