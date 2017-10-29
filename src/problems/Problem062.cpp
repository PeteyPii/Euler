#include "SourcePrefix.h"

#include "BigInteger.h"
#include "Common.h"

string problem62(int32 n) {
  if (n < 1) {
    throw string("Must be at least one permutation");
  } else if (n == 1) {
    return "0";
  }

  map<string, pair<int32, string>> cubes;
  int32 i = 0;
  while (true) {
    BigInteger x(i);
    string cube = numberToString(x * x * x);
    string sorted = cube;
    sort(sorted.begin(), sorted.end());
    auto it = cubes.find(cube);
    if (it == cubes.end()) {
      it = cubes.insert(make_pair(sorted, make_pair(0, cube))).first;
    }

    it->second.first++;
    if (it->second.first == n) {
      return it->second.second;
    }

    i++;
  }

  throw string("Unable to find enough permutations of a cube that are cube as well");
}

#include "SourceSuffix.h"
