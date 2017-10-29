#include "SourcePrefix.h"

#include "Common.h"

string problem84(int32 n) {
  if (n < 1) {
    throw string("Dice must have at least one side");
  }

  const int32 SPACES = 40;
  const int32 MAX_DOUBLES = 3;
  const set<int32> COMMUNITY_CHEST_SPACES = {2, 17, 33};
  const set<int32> CHANCE_SPACES = {7, 22, 36};

  const double rollFrequency = 1.0 / (n * n);

  array<array<double, MAX_DOUBLES * SPACES>, MAX_DOUBLES * SPACES> p;
  for (int32 doubles = 0; doubles < MAX_DOUBLES; doubles++) {
    for (int32 space = 0; space < SPACES; space++) {
      p[doubles * SPACES + space].fill(0.0);
      for (int32 d1 = 1; d1 <= n; d1++) {
        for (int32 d2 = 1; d2 <= n; d2++) {
          const int32 newSpace = (space + d1 + d2) % SPACES;
          if (newSpace == 30 || (doubles + 1 == MAX_DOUBLES && d1 == d2)) {
            p[doubles * SPACES + space][10] += rollFrequency;
          } else {
            int32 doublesOffset = (d1 == d2 ? (doubles + 1) * SPACES : 0);
            if (COMMUNITY_CHEST_SPACES.count(newSpace) == 1) {
              p[doubles * SPACES + space][doublesOffset + newSpace] += rollFrequency * 14 / 16;
              p[doubles * SPACES + space][doublesOffset + 0] += rollFrequency * 1 / 16;
              p[doubles * SPACES + space][10] += rollFrequency * 1 / 16;
            } else if (CHANCE_SPACES.count(newSpace) == 1) {
              int32 nextRailwaySpace = -1;
              int32 nextUtilitySpace = -1;
              int32 backThreeSpace = (newSpace - 3 + SPACES) % SPACES;

              if (newSpace < 5 || newSpace >= 35) {
                nextRailwaySpace = 5;
              } else if (newSpace < 15) {
                nextRailwaySpace = 15;
              } else if (newSpace < 25) {
                nextRailwaySpace = 25;
              } else {
                nextRailwaySpace = 35;
              }

              if (newSpace < 12 || newSpace >= 28) {
                nextUtilitySpace = 12;
              } else {
                nextUtilitySpace = 28;
              }

              p[doubles * SPACES + space][doublesOffset + newSpace] += rollFrequency * 6 / 16;
              p[doubles * SPACES + space][doublesOffset + nextRailwaySpace] += rollFrequency * 2 / 16;
              p[doubles * SPACES + space][doublesOffset + nextUtilitySpace] += rollFrequency * 1 / 16;
              p[doubles * SPACES + space][doublesOffset + 0] += rollFrequency * 1 / 16;
              p[doubles * SPACES + space][doublesOffset + 11] += rollFrequency * 1 / 16;
              p[doubles * SPACES + space][doublesOffset + 24] += rollFrequency * 1 / 16;
              p[doubles * SPACES + space][doublesOffset + 39] += rollFrequency * 1 / 16;
              p[doubles * SPACES + space][doublesOffset + 5] += rollFrequency * 1 / 16;
              p[doubles * SPACES + space][10] += rollFrequency * 1 / 16;

              if (COMMUNITY_CHEST_SPACES.count(backThreeSpace) == 1) {
                p[doubles * SPACES + space][doublesOffset + backThreeSpace] += rollFrequency * 1 / 16 * 14 / 16;
                p[doubles * SPACES + space][doublesOffset + 0] += rollFrequency * 1 / 16 * 1 / 16;
                p[doubles * SPACES + space][10] += rollFrequency * 1 / 16 * 1 / 16;
              } else {
                p[doubles * SPACES + space][doublesOffset + backThreeSpace] += rollFrequency * 1 / 16;
              }
            } else {
              p[doubles * SPACES + space][doublesOffset + newSpace] += rollFrequency;
            }
          }
        }
      }
    }
  }

  array<double, MAX_DOUBLES * SPACES> pi;
  pi.fill(1.0 / (MAX_DOUBLES * SPACES));
  const int32 FIXED_POINT_ITERATIONS = 200;
  for (int32 count = 0; count < FIXED_POINT_ITERATIONS; count++) {
    array<double, MAX_DOUBLES * SPACES> dotProduct;
    dotProduct.fill(0.0);
    for (int32 i = 0; i < MAX_DOUBLES * SPACES; i++) {
      for (int32 j = 0; j < MAX_DOUBLES * SPACES; j++) {
        dotProduct[i] += pi[j] * p[j][i];
      }
    }

    pi = dotProduct;
  }

  array<pair<int32, double>, SPACES> squashedPi;
  for (int32 space = 0; space < SPACES; space++) {
    squashedPi[space].first = space;
    squashedPi[space].second = 0.0;
  }
  for (int32 doubles = 0; doubles < MAX_DOUBLES; doubles++) {
    for (int32 space = 0; space < SPACES; space++) {
      squashedPi[space].second += pi[doubles * SPACES + space];
    }
  }

  sort(squashedPi.begin(), squashedPi.end(), [](const pair<int32, double>& left, const pair<int32, double>& right) -> bool { return left.second > right.second; });

  stringstream ss;
  ss.fill('0');
  ss.width(2);
  ss << squashedPi[0].first;
  ss.width(2);
  ss << squashedPi[1].first;
  ss.width(2);
  ss << squashedPi[2].first;

  return ss.str();
}

#include "SourceSuffix.h"
