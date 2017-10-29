#include "SourcePrefix.h"

#include "Common.h"

int64 problem8(int32 n) {
  ifstream fin("problem_input/p008.txt");
  assertFileOpened(fin);

  string full = "", temp;

  while (fin >> temp) {
    full += temp;
  }

  int64 max = 0;
  for (uint32 i = 0; i <= full.length() - n; i++) {
    int64 x = productOfDigits(stringToNumber<int64>(full.substr(i, n)));
    if (x > max) {
      max = x;
    }
  }

  return max;
}

#include "SourceSuffix.h"
