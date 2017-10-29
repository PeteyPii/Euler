#include "SourcePrefix.h"

#include "Common.h"

int32 problem89() {
  ifstream fin("problem_input/p089.txt");
  assertFileOpened(fin);

  map<char, int32> values = {
      {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000},
  };

  string numeral;
  int32 savings = 0;
  while (fin >> numeral) {
    int32 value = 0;
    if (numeral.find("IV") != string::npos) {
      value += -2;
    }
    if (numeral.find("IX") != string::npos) {
      value += -2;
    }
    if (numeral.find("XL") != string::npos) {
      value += -20;
    }
    if (numeral.find("XC") != string::npos) {
      value += -20;
    }
    if (numeral.find("CD") != string::npos) {
      value += -200;
    }
    if (numeral.find("CM") != string::npos) {
      value += -200;
    }

    for (char c : numeral) {
      value += values[c];
    }

    int32 digitsProcessed = 0;
    int32 digitCount = 0;
    while (value > 0) {
      switch (value % 10) {
        case 0:
          break;
        case 1:
        case 5:
          digitCount += 1;
          break;
        case 2:
        case 4:
        case 6:
        case 9:
          digitCount += 2;
          break;
        case 3:
        case 7:
          digitCount += 3;
          break;
        case 8:
          digitCount += 4;
          break;
      }

      value /= 10;
      digitsProcessed++;
      if (digitsProcessed == 3) {
        digitCount += value;
        break;
      }
    }

    savings += numeral.length() - digitCount;
  }

  return savings;
}

#include "SourceSuffix.h"
