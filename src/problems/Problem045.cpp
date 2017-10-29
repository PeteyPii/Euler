#include "SourcePrefix.h"

#include "Common.h"

int64 problem45(int32 n) {
  if (n < 0) {
    throw string("There are no matching triangle, pentagonal, hexagonal "
                 "numbers before 40755");
  }

  int64 t = 285;
  int64 p = 165;
  int64 h = 143;

  int64 vt;
  int64 vp;
  int64 vh;
  vt = vp = vh = 40755;

  // Simple brute force solution of manually keeping track of three different numbers for each
  // respective type (triangle, pentagonal, and hexagonal). If all three are equal then
  // we've found one number satisfying the property. If not, take the smallest number(s)
  // and find their next terms. The terms monotonically increase so this method will always
  // find any numbers that satisfy this property.
  while (true) {
    if (vt < vp) {
      t++;
      vt = t * (t + 1) / 2;
    } else if (vt > vp) {
      p++;
      vp = p * (3 * p - 1) / 2;
    } else {
      if (vt < vh) {
        t++;
        p++;
        vt = t * (t + 1) / 2;
        vp = p * (3 * p - 1) / 2;
      } else if (vt > vh) {
        h++;
        vh = h * (2 * h - 1);
      } else {
        n--;
        if (n < 0) {
          break;
        }

        t++;
        p++;
        h++;
        vt = t * (t + 1) / 2;
        vp = p * (3 * p - 1) / 2;
        vh = h * (2 * h - 1);
      }
    }
  }

  return vt;
}

#include "SourceSuffix.h"
