#include "SourcePrefix.h"

#include "Common.h"

int32 problem99() {
  ifstream fin("problem_input/p099.txt");
  assertFileOpened(fin);

  int32 bestLine = 0;
  double bestValue = 0;
  int32 currentLine = 0;
  while (fin) {
    currentLine += 1;
    int32 base;
    int32 exponent;
    fin >> base >> exponent;
    double currentValue = exponent * log10(base);
    if (currentValue > bestValue) {
      bestValue = currentValue;
      bestLine = currentLine;
    }
  }

  return bestLine;
}

#include "SourceSuffix.h"
