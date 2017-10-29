#include "SourcePrefix.h"

#include "Common.h"

int64 problem15(int32 n, int32 m) {
  if (n < 1 || m < 1) {
    throw string("Invalid grid size for lattice paths");
  }

  vector<vector<int64>> paths(n + 1, vector<int64>(m + 1, 0));
  paths[0][0] = 1;

  for (int32 x = 0; x <= n; x++) {
    for (int32 y = 0; y <= m; y++) {
      if (x != 0) {
        paths[x][y] += paths[x - 1][y];
      }
      if (y != 0) {
        paths[x][y] += paths[x][y - 1];
      }
    }
  }

  return paths[n][m];
}

#include "SourceSuffix.h"
