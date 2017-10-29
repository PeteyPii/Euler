#include "SourcePrefix.h"

#include "BigInteger.h"
#include "Common.h"

int32 problem66(int32 n) {
  if (n < 2) {
    throw string("Cannot find minimum of an empty set");
  }

  BigInteger largestX(0);
  int32 maxD = 0;

  // Minimal solution in x is found by getting a specific convergent
  // for the continued fraction of the square root of D.
  int32 root = 1;
  for (int32 i = 2; i <= n; i++) {
    if (i == (root + 1) * (root + 1)) {
      root++;
      continue;
    }

    vector<int32> ai;
    ai.push_back(root);

    int32 s = root;
    int32 t = 1;

    while (ai.back() != ai.front() * 2) {
      t = (i - s * s) / t;
      ai.push_back((s + root) / t);
      s = ai.back() * t - s;
    }

    vector<BigInteger> pi;
    pi.push_back(BigInteger(ai[0]));
    pi.push_back(BigInteger(ai[0] * ai[1] + 1));

    int32 r = ai.size() - 2;
    if (r % 2 == 1) {
      for (int32 j = 2; j <= r; j++) {
        pi.push_back(pi[j - 1] * ai[j] + pi[j - 2]);
      }

      if (pi[r] > largestX) {
        largestX = pi[r];
        maxD = i;
      }
    } else {
      for (int32 j = 2; j <= r + 1; j++) {
        pi.push_back(pi[j - 1] * ai[j] + pi[j - 2]);
      }

      for (int32 j = 1; j < r + 1; j++) {
        pi.push_back(pi[j + r] * ai[j] + pi[j + r - 1]);
      }

      if (pi[2 * r + 1] > largestX) {
        largestX = pi[2 * r + 1];
        maxD = i;
      }
    }
  }

  return maxD;
}

#include "SourceSuffix.h"
