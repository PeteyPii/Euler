#include "SourcePrefix.h"

#include "Common.h"

int32 problem96() {
  ifstream fin("problem_input/p096.txt");
  assertFileOpened(fin);

  int32 total = 0;
  while (fin) {
    string rows[9];
    for (int32 i = 0; i < 9; i++) {
      fin >> rows[i];
      if (rows[i].length() != 9) {
        break;
      }
    }
    if (!fin) {
      break;
    }

    array<array<char, 9>, 9> origGrid;
    int32 origUnsolvedCount = 0;
    for (int32 j = 0; j < 9; j++) {
      for (int32 i = 0; i < 9; i++) {
        origGrid[i][j] = rows[j][i] - '0';
        if (origGrid[i][j] == 0) {
          origUnsolvedCount++;
        }
      }
    }

    auto deduce = [](array<array<char, 9>, 9>& grid, int32& unsolvedCount) -> bool {
      int32 prevUnsolvedCount = unsolvedCount;
      do {
        prevUnsolvedCount = unsolvedCount;
        set<char> possibleValues[9][9];
        // Exclusion step.
        for (int32 i = 0; i < 9; i++) {
          for (int32 j = 0; j < 9; j++) {
            if (grid[i][j] != 0) {
              continue;
            }

            possibleValues[i][j] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
            for (int32 row = 0; row < 9; row++) {
              possibleValues[i][j].erase(grid[i][row]);
            }
            for (int32 col = 0; col < 9; col++) {
              possibleValues[i][j].erase(grid[col][j]);
            }
            int32 iRoot = i / 3 * 3;
            int32 jRoot = j / 3 * 3;
            for (int32 iOffset = 0; iOffset < 3; iOffset++) {
              for (int32 jOffset = 0; jOffset < 3; jOffset++) {
                possibleValues[i][j].erase(grid[iRoot + iOffset][jRoot + jOffset]);
              }
            }

            if (possibleValues[i][j].size() == 0) {
              return true; // unsolvable
            }
            if (possibleValues[i][j].size() == 1) {
              grid[i][j] = *possibleValues[i][j].begin();
              unsolvedCount -= 1;
            }
          }
        }

        // Assertion step.
        for (int32 col = 0; col < 9; col++) {
          char valCounts[10];
          for (int32 i = 1; i <= 9; i++) {
            valCounts[i] = 0;
          }
          for (int32 row = 0; row < 9; row++) {
            for (int32 possibleVal : possibleValues[col][row]) {
              valCounts[possibleVal] += 1;
            }
          }
          set<char> found;
          for (int32 i = 1; i <= 9; i++) {
            if (valCounts[i] == 1) {
              found.insert(i);
            }
          }
          for (char valToInsert : found) {
            for (int32 row = 0; row < 9; row++) {
              if (possibleValues[col][row].count(valToInsert) == 1) {
                if (grid[col][row] == 0) {
                  grid[col][row] = valToInsert;
                  unsolvedCount -= 1;
                }
                break;
              }
            }
          }
        }
        for (int32 row = 0; row < 9; row++) {
          char valCounts[10];
          for (int32 i = 1; i <= 9; i++) {
            valCounts[i] = 0;
          }
          for (int32 col = 0; col < 9; col++) {
            for (int32 possibleVal : possibleValues[col][row]) {
              valCounts[possibleVal] += 1;
            }
          }
          set<char> found;
          for (int32 i = 1; i <= 9; i++) {
            if (valCounts[i] == 1) {
              found.insert(i);
            }
          }
          for (char valToInsert : found) {
            for (int32 col = 0; col < 9; col++) {
              if (possibleValues[col][row].count(valToInsert) == 1) {
                if (grid[col][row] == 0) {
                  grid[col][row] = valToInsert;
                  unsolvedCount -= 1;
                }
                break;
              }
            }
          }
        }
        for (int32 iBox = 0; iBox < 9; iBox += 3) {
          for (int32 jBox = 0; jBox < 9; jBox += 3) {
            char valCounts[10];
            for (int32 i = 1; i <= 9; i++) {
              valCounts[i] = 0;
            }
            for (int32 iOffset = 0; iOffset < 3; iOffset++) {
              for (int32 jOffset = 0; jOffset < 3; jOffset++) {
                for (int32 possibleVal : possibleValues[iBox + iOffset][jBox + jOffset]) {
                  valCounts[possibleVal] += 1;
                }
              }
            }
            set<char> found;
            for (int32 i = 1; i <= 9; i++) {
              if (valCounts[i] == 1) {
                found.insert(i);
              }
            }
            for (char valToInsert : found) {
              for (int32 iOffset = 0; iOffset < 3; iOffset++) {
                for (int32 jOffset = 0; jOffset < 3; jOffset++) {
                  if (possibleValues[iBox + iOffset][jBox + jOffset].count(valToInsert) == 1) {
                    if (grid[iBox + iOffset][jBox + jOffset] == 0) {
                      grid[iBox + iOffset][jBox + jOffset] = valToInsert;
                      unsolvedCount -= 1;
                    }
                    break;
                  }
                }
              }
            }
          }
        }
      } while (prevUnsolvedCount != unsolvedCount);
      return false;
    };

    function<bool(array<array<char, 9>, 9>&, int32&, int32)> bruteForce;
    bruteForce = [&deduce, &bruteForce](
                     array<array<char, 9>, 9>& grid, int32& unsolvedCount, int32 remainingRecursions) -> bool {
      deduce(grid, unsolvedCount);
      if (unsolvedCount == 0) {
        return true;
      }
      if (remainingRecursions == 0) {
        return false;
      }
      remainingRecursions -= 1;

      for (int32 i = 0; i < 9; i++) {
        for (int32 j = 0; j < 9; j++) {
          if (grid[i][j] != 0) {
            continue;
          }
          set<char> possibleValues = {1, 2, 3, 4, 5, 6, 7, 8, 9};
          for (int32 row = 0; row < 9; row++) {
            possibleValues.erase(grid[i][row]);
          }
          for (int32 col = 0; col < 9; col++) {
            possibleValues.erase(grid[col][j]);
          }
          int32 iRoot = i / 3 * 3;
          int32 jRoot = j / 3 * 3;
          for (int32 iOffset = 0; iOffset < 3; iOffset++) {
            for (int32 jOffset = 0; jOffset < 3; jOffset++) {
              possibleValues.erase(grid[iRoot + iOffset][jRoot + jOffset]);
            }
          }
          for (char val : possibleValues) {
            array<array<char, 9>, 9> guessGrid = grid;
            guessGrid[i][j] = val;
            int32 guessUnsolvedCount = unsolvedCount - 1;
            if (bruteForce(guessGrid, guessUnsolvedCount, remainingRecursions)) {
              grid = guessGrid;
              unsolvedCount = guessUnsolvedCount;
              return true;
            }
          }
        }
      }

      return false;
    };

    bruteForce(origGrid, origUnsolvedCount, 1);
    if (origUnsolvedCount != 0) {
      throw string("Unsolved Sudoku puzzle");
    }

#if 0
    bool good = true;
    for (int32 col = 0; col < 9; col++) {
      set<char> found;
      for (int32 row = 0; row < 9; row++) {
        found.insert(origGrid[col][row]);
      }
      if (found.count(0) == 1 || found.size() != 9) {
        good = false;
      }
    }
    for (int32 row = 0; row < 9; row++) {
      set<char> found;
      for (int32 col = 0; col < 9; col++) {
        found.insert(origGrid[col][row]);
      }
      if (found.count(0) == 1 || found.size() != 9) {
        good = false;
      }
    }
    for (int32 iBox = 0; iBox < 9; iBox += 3) {
      for (int32 jBox = 0; jBox < 9; jBox += 3) {
        set<char> found;
        for (int32 iOffset = 0; iOffset < 3; iOffset++) {
          for (int32 jOffset = 0; jOffset < 3; jOffset++) {
            found.insert(origGrid[iBox + iOffset][jBox + jOffset]);
          }
        }
        if (found.count(0) == 1 || found.size() != 9) {
          good = false;
        }
      }
    }
#endif

#if 0
    cout << "Unsolved count: " << origUnsolvedCount << endl;
    for (int32 j = 0; j < 9; j++) {
      for (int32 i = 0; i < 9; i++) {
        if (origGrid[i][j] != 0) {
          cout << static_cast<char>(origGrid[i][j] + '0');
        } else {
          cout << ' ';
        }
        if (i % 3 == 2) {
          cout << " ";
        }
      }
      cout << endl;
      if (j % 3 == 2) {
        cout << endl;
      }
    }
#endif

    total += origGrid[0][0] * 100 + origGrid[1][0] * 10 + origGrid[2][0];
  }

  return total;
}

#include "SourceSuffix.h"
