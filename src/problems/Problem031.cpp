#include "SourcePrefix.h"

#include "Common.h"

int32 problem31(int32 n) {
  if (n < 0) {
    throw string("Cannot make a negative amount of money with change");
  }

  vector<int32> generatingFunction;
  map<int32, int32> fps;
  fps[0] = 1;
  vector<int32> coinValues = {1, 2, 5, 10, 20, 50, 100, 200};

  // Let generatingFunction represent a formal power series A(x)
  // Let fps be another formal power series B(x)
  // The problem is a composition problem where parts can be 0. Each part corresponds to the
  // number a certain coin to use and we create a generating function for this tuple of coin
  // counts using the respective coin values as the weight. The generating function is simply
  // 1 / ((1 - x)(1 - x^2)(1 - x^5)...) = 1 / B(x) = A(x) where the x powers are distinct
  // coin values. [x^n] A(x) is then the number of different ways to get n value using a
  // number of each coin. The code goes through the evaluation of B(x) and then its inverse,
  // A(x), to get the coefficient values.

  for (uint32 i = 0; i < coinValues.size(); i++) {
    map<int32, int32> tempFps;
    for (auto it = fps.begin(); it != fps.end(); it++) {
      tempFps[it->first] += it->second;
      tempFps[it->first + coinValues[i]] -= it->second;
    }
    fps = tempFps;
  }

  generatingFunction.push_back(1);
  auto last = fps.end();
  last--;
  for (int32 i = 1; i < last->first; i++) {
    int32 sum = 0;
    for (int32 j = 0; j < i; j++) {
      sum += generatingFunction[j] * fps[i - j];
    }
    generatingFunction.push_back(-sum / fps[0]);
  }

  // Note: if n >= sum of all distinct coin values, the function needs to be extended
  // to evalutate the n-th term of a recurrence relation defined by fps
  return generatingFunction[n];
}

#include "SourceSuffix.h"
