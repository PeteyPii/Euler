#include "SourcePrefix.h"

#include "Common.h"

int32 problem9() {
  for (int32 c = 1000; c > 0; c--) {
    for (int32 b = 1000 - c; b > 0; b--) {

      int32 a = 1000 - c - b;

      if (c * c == b * b + a * a && a != 0) {
        return a * b * c;
      }
    }
  }

  throw string("Unable to find a*b*c");
}

#include "SourceSuffix.h"
