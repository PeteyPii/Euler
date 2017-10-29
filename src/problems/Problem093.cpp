#include "SourcePrefix.h"

#include "Common.h"

int32 problem93() {
  vector<int32> digits(10);
  for (int32 i = 0; i < 10; i++) {
    digits[i] = i + 1;
  }
  vector<vector<int32>> combos = combinations(digits.begin(), digits.end(), 4);

  struct ApplyOperator {
    bool operator()(double left, double right, int32 op, double* result, bool isValid = true) {
      if (!isValid) {
        return false;
      }

      switch (op) {
        case 0:
          *result = left + right;
          return true;
        case 1:
          *result = left - right;
          return true;
        case 2:
          *result = left * right;
          return true;
        case 3:
          if (fpEqual(right, 0.0)) {
            return false;
          } else {
            *result = left / right;
            return true;
          }
          break;
        default:
          throw string("Invalid op code");
      }
    }
  };

  vector<int32> bestSet;
  int32 bestLength = 0;
  ApplyOperator applyOperator;
  for (auto& combo : combos) {
    set<int32> possibleTargets;
    do {
      for (int32 op = 0; op < 4 * 4 * 4; op++) {
        int32 op1 = op % 4;
        int32 op2 = (op / 4) % 4;
        int32 op3 = (op / 16) % 4;

        double target;
        bool isValid = true;
        isValid = applyOperator(combo[0], combo[1], op1, &target, isValid);
        isValid = applyOperator(target, combo[2], op2, &target, isValid);
        isValid = applyOperator(target, combo[3], op3, &target, isValid);
        if (isValid && isIntegral(target)) {
          possibleTargets.insert(static_cast<int32>(target + 0.5));
        }

        isValid = true;
        isValid = applyOperator(combo[1], combo[2], op1, &target, isValid);
        isValid = applyOperator(combo[0], target, op2, &target, isValid);
        isValid = applyOperator(target, combo[3], op3, &target, isValid);
        if (isValid && isIntegral(target)) {
          possibleTargets.insert(static_cast<int32>(target + 0.5));
        }

        double intermediate;
        isValid = true;
        isValid = applyOperator(combo[0], combo[1], op1, &target, isValid);
        isValid = applyOperator(combo[2], combo[3], op2, &intermediate, isValid);
        isValid = applyOperator(target, intermediate, op3, &target, isValid);
        if (isValid && isIntegral(target)) {
          possibleTargets.insert(static_cast<int32>(target + 0.5));
        }

        isValid = true;
        isValid = applyOperator(combo[1], combo[2], op1, &target, isValid);
        isValid = applyOperator(target, combo[3], op2, &target, isValid);
        isValid = applyOperator(combo[0], target, op3, &target, isValid);
        if (isValid && isIntegral(target)) {
          possibleTargets.insert(static_cast<int32>(target + 0.5));
        }

        isValid = true;
        isValid = applyOperator(combo[2], combo[3], op1, &target, isValid);
        isValid = applyOperator(combo[1], target, op2, &target, isValid);
        isValid = applyOperator(combo[0], target, op3, &target, isValid);
        if (isValid && isIntegral(target)) {
          possibleTargets.insert(static_cast<int32>(target + 0.5));
        }
      }
    } while (next_permutation(combo.begin(), combo.end()));

    int32 runLength = 0;
    while (possibleTargets.count(runLength + 1) == 1) {
      runLength++;
    }

    if (runLength > bestLength) {
      bestSet = combo;
      bestLength = runLength;
    }
  }

  sort(bestSet.begin(), bestSet.end());

  return 1000 * bestSet[0] + 100 * bestSet[1] + 10 * bestSet[2] + bestSet[3];
}

#include "SourceSuffix.h"
