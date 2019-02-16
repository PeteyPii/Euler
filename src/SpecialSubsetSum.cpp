#include "SourcePrefix.h"

#include "SpecialSubsetSum.h"

vector<pair<vector<int32>, vector<int32>>> disjointInequalityChecks(int32 n) {
  vector<pair<vector<int32>, vector<int32>>> result;
  for (int32 i = 1; i < power(3, n); i++) {
    // 0 means not checked, 1 means part of the left subset, 2 means part of the right subset.
    vector<int32> inclusions((uint32)n);
    int32 x = i;
    for (int32 j = 0; j < n; j++) {
      inclusions[j] = x % 3;
      x /= 3;
    }

    vector<int32> left;
    vector<int32> right;
    bool invalid = false;
    bool overlap = false;
    for (int32 j = 0; j < n; j++) {
      int32 inclusion = inclusions[j];
      if (inclusion == 0) {
        continue;
      }

      if (inclusion == 1) {
        left.push_back(j);
      } else {
        if (left.empty()) {
          invalid = true;
          break;
        }
        right.push_back(j);
        if (right.size() > left.size()) {
          overlap = true;
        }
      }
    }

    if (invalid) {
      continue;
    }
    if (left.size() != right.size()) {
      continue;
    }
    if (!overlap) {
      continue;
    }

    result.emplace_back(move(left), move(right));
  }
  return result;
}

bool isValidSpecialSubset(
    const vector<int32>& partition, const vector<pair<vector<int32>, vector<int32>>>& disjointChecks) {
  int32 leftSum = partition.front();
  int32 rightSum = 0;
  for (uint32 i = 1; i < partition.size() - i; i++) {
    leftSum += partition[i];
    rightSum += partition[partition.size() - i];
    if (leftSum <= rightSum) {
      return false;
    }
  }

  for (const auto& disjointCheck : disjointChecks) {
    leftSum = 0;
    rightSum = 0;
    for (const auto& ix : disjointCheck.first) {
      leftSum += partition[ix];
    }
    for (const auto& ix : disjointCheck.second) {
      rightSum += partition[ix];
    }
    if (leftSum == rightSum) {
      return false;
    }
  }

  return true;
}
