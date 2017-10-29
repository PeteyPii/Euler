#include "SourcePrefix.h"

#include "Common.h"

int32 problem17(int32 n) {
  if (n < 0) {
    return 0;
  }

  int32 sum = 0;
  for (int32 i = 1; i <= n; i++) {
    string temp = getEnglishWordFromNumber(i);
    temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
    temp.erase(remove(temp.begin(), temp.end(), '-'), temp.end());
    sum += temp.size();
  }

  return sum;
}

#include "SourceSuffix.h"
