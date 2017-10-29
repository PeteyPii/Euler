#include "SourcePrefix.h"

#include "Common.h"

int32 problem11(int32 n, int32 m) {
  if (n > m) {
    throw string("Grid size is less than number of factors");
    return -1;
  }

  ifstream fin("problem_input/p011.txt");
  assertFileOpened(fin);

  vector<vector<int32>> grid(m, vector<int32>(m, -1));

  for (int32 y = 0; y < m; y++) {
    for (int32 x = 0; x < m; x++) {
      fin >> grid[x][y];
      if (!fin) {
        throw string("Bad file formatting");
      }
    }
  }

  int32 max = 0;
  for (int32 y = 0; y < m; y++) {
    for (int32 x = 0; x < m - n + 1; x++) {
      int32 product = 1;
      for (int32 i = 0; i < n; i++) {
        product *= grid[x + i][y];
      }

      if (product > max) {
        max = product;
      }
    }
  }

  for (int32 x = 0; x < m; x++) {
    for (int32 y = 0; y < m - n + 1; y++) {
      int32 product = 1;
      for (int32 i = 0; i < n; i++) {
        product *= grid[x][y + i];
      }

      if (product > max) {
        max = product;
      }
    }
  }

  for (int32 x = 0; x < m - n + 1; x++) {
    for (int32 y = 0; y < m - n + 1; y++) {
      int32 forwardProduct = 1;
      int32 backwardProduct = 1;

      for (int32 i = 0; i < n; i++) {
        forwardProduct *= grid[x + i][y + n - 1 - i];
        backwardProduct *= grid[x + i][y + i];
      }

      if (forwardProduct > max) {
        max = forwardProduct;
      }

      if (backwardProduct > max) {
        max = backwardProduct;
      }
    }
  }

  return max;
}

#include "SourceSuffix.h"
