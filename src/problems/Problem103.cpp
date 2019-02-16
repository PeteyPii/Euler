#include "SourcePrefix.h"

#include "Common.h"
#include "SpecialSubsetSum.h"

string problem103(int32 n) {
  if (n == 0) {
    return "";
  } else if (n < 0) {
    throw string("Set cardinality must be non-negative.");
  }

  auto disjointChecks = disjointInequalityChecks(n);
  int32 candidate = n >= 7 ? 250 : 1; // tuning guess: sum is at least 250

  while (true) {
    auto partitions = partitionSetsOfSizeN(candidate, n, n >= 7 ? 15 : 1); // tuning guess: all elements are at least 15
    auto it = find_if(partitions.begin(), partitions.end(), [&](const vector<int32>& partition) -> bool {
      return isValidSpecialSubset(partition, disjointChecks);
    });

    if (it != partitions.end()) {
      stringstream ss;
      for (int32 x : *it) {
        ss << x;
      }
      return ss.str();
    }
    candidate++;
  }
}

#include "SourceSuffix.h"
