#include "SourcePrefix.h"

#include "Common.h"

int32 problem52() {
  // Number cannot start with any digit but 1 since six times a number starting
  // with 2 will lead to a number that is one digit longer, which will be invalid.
  // We can extend this to the 2nd, 3rd, and 4th digits and so on.
  int32 nextPower = 100;
  int32 i = 10;
  while (true) {
    while (6 * i < nextPower) {
      string candidate = numberToString(i);
      sort(candidate.begin(), candidate.end());
      bool successful = true;
      for (int32 multiplier = 2; multiplier <= 6; multiplier++) {
        string sorted = numberToString(i * multiplier);
        sort(sorted.begin(), sorted.end());

        if (sorted != candidate) {
          successful = false;
          break;
        }
      }

      if (successful) {
        return i;
      }

      i++;
    }

    i = nextPower;
    nextPower *= 10;
  }

  throw string("A number satisfying the conditions could not be found");
}

#include "SourceSuffix.h"
