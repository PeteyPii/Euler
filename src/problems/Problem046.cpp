#include "SourcePrefix.h"

#include "Common.h"

int64 problem46(int32 n) {
  if (n < 1) {
    throw string("N must be at least one since it denotes the nth occurrence");
  }

  set<int64> primes;
  set<int64> squareDoubles;

  squareDoubles.insert(2);
  squareDoubles.insert(8);

  int64 highestSquareDouble = 8;
  int64 highestSquareIx = 2;

  int64 lastNumberFound = -1;

  int64 i = 3;

  while (n > 0) {
    if (i > highestSquareDouble) {
      highestSquareIx++;
      highestSquareDouble = 2 * highestSquareIx * highestSquareIx;
      squareDoubles.insert(highestSquareDouble);
    }

    if (isNumberPrime(i)) {
      primes.insert(i);
    } else {
      bool foundSum = false;
      for (int64 squareDouble : squareDoubles) {
        if (primes.count(i - squareDouble) == 1) {
          foundSum = true;
          break;
        }
      }

      if (!foundSum) {
        n--;
        lastNumberFound = i;
      }
    }

    i += 2;
  }

  return lastNumberFound;
}

#include "SourceSuffix.h"
