#include "SourcePrefix.h"

#include "Common.h"

int32 problem18() {
  ifstream fin("problem_input/p018.txt");
  assertFileOpened(fin);

  vector<vector<int32>> triangle;
  string temp;
  while (getline(fin, temp)) {
    triangle.push_back(vector<int32>());

    stringstream ss;
    ss << temp;
    int32 number;
    while (ss >> number) {
      triangle.back().push_back(number);
    }
  }

  for (uint32 i = 1; i < triangle.size(); i++) {
    for (uint32 j = 0; j <= i; j++) {
      if (j == 0) {
        triangle[i][0] += triangle[i - 1][0];
      } else if (j == i) {
        triangle[i][j] += triangle[i - 1][j - 1];
      } else {
        triangle[i][j] += maxVal(triangle[i - 1][j - 1], triangle[i - 1][j]);
      }
    }
  }

  int32 max = triangle.back()[0];
  for (uint32 i = 1; i < triangle.back().size(); i++) {
    if (triangle.back()[i] > max) {
      max = triangle.back()[i];
    }
  }

  return max;
}

#include "SourceSuffix.h"
