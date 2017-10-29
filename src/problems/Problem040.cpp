#include "SourcePrefix.h"

#include "Common.h"

int32 problem40(int32 n) {
  if (n < 0) {
    throw string("10^n must be a postive integer");
  }

  int32 i = 0;
  int32 digit = 1;

  int32 bracketStart = 1;
  int32 bracketEnd = 10;
  int32 bracketWidth = 1;
  int32 powerOfTen = 1;

  int32 product = 1;
  while (i <= n) {
    while (digit >= bracketEnd) {
      bracketWidth++;
      powerOfTen *= 10;
      bracketStart = bracketEnd;
      bracketEnd += powerOfTen * bracketWidth * 9;
    }

    int32 x = (digit - bracketStart) / bracketWidth;
    int32 y = bracketWidth - 1 - ((digit - bracketStart) % bracketWidth);

    int32 number = powerOfTen + x;
    while (y > 0) {
      number /= 10;
      y--;
    }

    product *= number % 10;

    i++;
    digit *= 10;
  }

  return product;
}

#include "SourceSuffix.h"
