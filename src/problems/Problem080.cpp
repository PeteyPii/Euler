#include "SourcePrefix.h"

#include "BigInteger.h"
#include "Common.h"

int32 problem80(int32 n, int32 m) {
  if (n < 2) {
    return 0;
  }

  if (m < 1) {
    throw string("Cannot have a number with less than 1 digit");
  }

  set<int32> squares;
  int32 i = 0;
  while (i * i <= n) {
    squares.insert(i * i);
    i++;
  }

  BigInteger leftStart(1);
  while (leftStart.numberOfDigits() < m) {
    leftStart *= 10;
  }
  leftStart = leftStart.convertToBase(128);
  BigInteger leftStartSquared = leftStart * leftStart;

  i = 0;
  int32 sum = 0;
  while (i <= n) {
    if (squares.count(i) > 0) {
      i++;
      continue;
    }

    BigInteger left = leftStart;
    BigInteger right = leftStart * 10;
    BigInteger goal(i, 128);
    while (goal < leftStartSquared) {
      goal *= 100;
    }

    while (left < right) {
      BigInteger mid = (left + right) >> 1;
      if (mid * mid < goal) {
        if (mid == left) {
          right = left;
        } else {
          left = mid;
        }
      } else {
        if (mid == right) {
          right = left;
        } else {
          right = mid;
        }
      }
    }

    sum += left.convertToBase(10).sumOfDigits();
    i++;
  }

  return sum;
}

#include "SourceSuffix.h"
