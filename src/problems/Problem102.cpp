#include "SourcePrefix.h"

#include "Common.h"

int32 problem102() {
  ifstream fin("problem_input/p102.txt");
  assertFileOpened(fin);

  int32 count = 0;
  while (fin) {
    int32 x1;
    int32 y1;
    int32 x2;
    int32 y2;
    int32 x3;
    int32 y3;
    fin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int64 d1 = x1 * y2 - x2 * y1;
    int64 d2 = x2 * y3 - x3 * y2;
    int64 d3 = x3 * y1 - x1 * y3;
    if (d1 > 0 && d2 > 0 && d3 > 0) {
      count++;
    } else if (d1 < 0 && d2 < 0 && d3 < 0) {
      count++;
    }
  }

  return count;
}
