#include "SourcePrefix.h"

#include "Common.h"

int32 problem61() {
  int32 i;

  vector<int32> triangleNumbers;
  i = 0;
  while (i * (i + 1) / 2 < 1000) {
    i++;
  }
  while (i * (i + 1) / 2 < 10000) {
    triangleNumbers.push_back(i * (i + 1) / 2);
    i++;
  }

  vector<int32> squareNumbers;
  i = 0;
  while (i * i < 1000) {
    i++;
  }
  while (i * i < 10000) {
    squareNumbers.push_back(i * i);
    i++;
  }

  vector<int32> pentagonalNumbers;
  i = 0;
  while (i * (3 * i - 1) / 2 < 1000) {
    i++;
  }
  while (i * (3 * i - 1) / 2 < 10000) {
    pentagonalNumbers.push_back(i * (3 * i - 1) / 2);
    i++;
  }

  vector<int32> hexagonalNumbers;
  i = 0;
  while (i * (2 * i - 1) < 1000) {
    i++;
  }
  while (i * (2 * i - 1) < 10000) {
    hexagonalNumbers.push_back(i * (2 * i - 1));
    i++;
  }

  vector<int32> heptagonalNumbers;
  i = 0;
  while (i * (5 * i - 3) / 2 < 1000) {
    i++;
  }
  while (i * (5 * i - 3) / 2 < 10000) {
    heptagonalNumbers.push_back(i * (5 * i - 3) / 2);
    i++;
  }

  vector<int32> octagonalNumbers;
  i = 0;
  while (i * (3 * i - 2) < 1000) {
    i++;
  }
  while (i * (3 * i - 2) < 10000) {
    octagonalNumbers.push_back(i * (3 * i - 2));
    i++;
  }

  static const int32 TYPE_TRIANGLE = 0;
  static const int32 TYPE_SQUARE = 1;
  static const int32 TYPE_PENTAGONAL = 2;
  static const int32 TYPE_HEXAGONAL = 3;
  static const int32 TYPE_HEPTAGONAL = 4;
  static const int32 TYPE_OCTAGONAL = 5;

  vector<vector<pair<int32, int32>>> graph(100);
  for (int32 n : triangleNumbers) {
    graph[n / 100].push_back(make_pair(TYPE_TRIANGLE, n % 100));
  }
  for (int32 n : squareNumbers) {
    graph[n / 100].push_back(make_pair(TYPE_SQUARE, n % 100));
  }
  for (int32 n : pentagonalNumbers) {
    graph[n / 100].push_back(make_pair(TYPE_PENTAGONAL, n % 100));
  }
  for (int32 n : hexagonalNumbers) {
    graph[n / 100].push_back(make_pair(TYPE_HEXAGONAL, n % 100));
  }
  for (int32 n : heptagonalNumbers) {
    graph[n / 100].push_back(make_pair(TYPE_HEPTAGONAL, n % 100));
  }
  for (int32 n : octagonalNumbers) {
    graph[n / 100].push_back(make_pair(TYPE_OCTAGONAL, n % 100));
  }

  class SpecialCycleFinder {
  public:
    SpecialCycleFinder(const vector<vector<pair<int32, int32>>>& graph)
        : m_vcGraph(graph) {}

    vector<int32> operator()() {
      set<int32> usedTypes;
      usedTypes.insert(TYPE_TRIANGLE);

      vector<int32> result;

      for (int32 i = 0; i < 100; i++) {
        for (auto adjacency : m_vcGraph[i]) {
          if (adjacency.first == TYPE_TRIANGLE) {
            result.push_back(i * 100 + adjacency.second);
            if (recurse(result, usedTypes)) {
              return result;
            }
            result.pop_back();
          }
        }
      }

      throw string("Could could find the special cycle");
    }

  private:
    const vector<vector<pair<int32, int32>>>& m_vcGraph;

    bool recurse(vector<int32>& result, set<int32>& usedTypes) {
      if (result.size() == 6 && result.front() / 100 == result.back() % 100) {
        return true;
      }

      for (auto adjacency : m_vcGraph[result.back() % 100]) {
        if (usedTypes.count(adjacency.first) == 0) {
          usedTypes.insert(adjacency.first);
          result.push_back(result.back() % 100 * 100 + adjacency.second);
          if (recurse(result, usedTypes)) {
            return true;
          }
          result.pop_back();
          usedTypes.erase(adjacency.first);
        }
      }

      return false;
    }
  };

  SpecialCycleFinder cycleFinder(graph);
  return vectorSum(cycleFinder());
}

#include "SourceSuffix.h"
