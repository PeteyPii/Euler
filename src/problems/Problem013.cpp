#include "SourcePrefix.h"

#include "BigInteger.h"
#include "Common.h"

string problem13(int32 n) {
  ifstream fin("problem_input/p013.txt");
  assertFileOpened(fin);

  BigInteger x(0);
  BigInteger temp;
  while (fin >> temp) {
    x += temp;
  }

  stringstream ss;
  ss << x;
  return ss.str().substr(0, n);
}

#include "SourceSuffix.h"
