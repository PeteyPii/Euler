#include "SourcePrefix.h"

#include "BigInteger.h"
#include "Common.h"

int32 problem104() {
  BigInteger f1(1);
  BigInteger f2(1);
  int32 k = 2;
  string front = "123456789";
  string back = "123456789";
  while (true) {
    k++;
    BigInteger temp = f1 + f2;
    f1 = f2;
    f2 = temp;
    if (temp.numberOfDigits() < 18) {
      continue;
    }

    for (int32 i = 0; i < 9; i++) {
      back[i] = temp.getNthDigitFromRight(i) + '0';
    }
    if (isPandigital(back)) {
      for (int32 i = 0; i < 9; i++) {
        front[i] = temp.getNthDigitFromLeft(i) + '0';
      }
      if (isPandigital(front)) {
        return k;
      }
    }
  }
}

#include "SourceSuffix.h"
