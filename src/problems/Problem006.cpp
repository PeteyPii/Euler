#include "SourcePrefix.h"

#include "Common.h"

int64 problem6(int64 n) {
  int64 sumOfSquares = n * (2 * n + 1) * (n + 1) / 6;
  int64 squareOfSum = n * (n + 1) / 2;
  squareOfSum *= squareOfSum;

  return squareOfSum - sumOfSquares;
}

#include "SourceSuffix.h"
