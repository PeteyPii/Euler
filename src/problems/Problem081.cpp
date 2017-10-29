#include "SourcePrefix.h"

#include "Common.h"

int32 problem81(int32 n, int32 m) {
  if (n < 1 || m < 1) {
    throw string("Matrix must be at least size 1x1");
  }

  static int32 idCounter = 0;
  struct Node {
    Node(int32 weight) : m_nId(idCounter++), m_nWeight(weight), m_nBest(INT32_MAX), m_bVisited(false) {
    }

    bool operator==(Node& other) {
      return m_nId == other.m_nId;
    }

    bool operator<(Node& other) {
      return m_nBest < other.m_nBest;
    }

    int32 m_nId;
    int32 m_nWeight;
    int32 m_nBest;
    bool m_bVisited;
    vector<int32> m_vnAdjacent;
  };

  ifstream fin("problem_input/p081.txt");
  assertFileOpened(fin);

  vector<vector<Node>> nodes;
  for (int32 j = 0; j < m; j++) {
    nodes.push_back(vector<Node>());
    for (int32 i = 0; i < n; i++) {
      int32 weight;
      fin >> weight;
      nodes[j].push_back(Node(weight));
    }
  }

  for (int32 j = 0; j < m; j++) {
    for (int32 i = 0; i < n - 1; i++) {
      nodes[j][i].m_vnAdjacent.push_back(nodes[j][i + 1].m_nId);
    }
  }

  for (int32 j = 0; j < m - 1; j++) {
    for (int32 i = 0; i < n; i++) {
      nodes[j][i].m_vnAdjacent.push_back(nodes[j + 1][i].m_nId);
    }
  }

  Node& initial(nodes.front().front());
  Node& final(nodes.back().back());
  initial.m_nBest = initial.m_nWeight;

  map<int32, Node*> idToNode;
  for (int32 j = 0; j < m; j++) {
    for (int32 i = 0; i < n; i++) {
      idToNode[nodes[j][i].m_nId] = &nodes[j][i];
    }
  }

  map<int32, map<int32, Node*>> bestToIdToNode;
  bestToIdToNode[initial.m_nBest][initial.m_nId] = &initial;
  while (!bestToIdToNode.empty()) {
    // Get an unvisited node that is reachable in a minimal distance
    Node* current = bestToIdToNode.begin()->second.begin()->second;
    if (*current == final) {
      return current->m_nBest;
    }

    for (int32 id : current->m_vnAdjacent) {
      Node* neighbour = idToNode[id];
      if (neighbour->m_bVisited) {
        continue;
      }

      if (bestToIdToNode.count(neighbour->m_nBest) == 1 &&
          bestToIdToNode[neighbour->m_nBest].count(neighbour->m_nId) == 1) {
        bestToIdToNode[neighbour->m_nBest].erase(neighbour->m_nId);
        if (bestToIdToNode[neighbour->m_nBest].empty()) {
          bestToIdToNode.erase(neighbour->m_nBest);
        }
      }

      neighbour->m_nBest = min(neighbour->m_nBest, current->m_nBest + neighbour->m_nWeight);
      bestToIdToNode[neighbour->m_nBest][neighbour->m_nId] = neighbour;
    }

    bestToIdToNode[current->m_nBest].erase(current->m_nId);
    if (bestToIdToNode[current->m_nBest].empty()) {
      bestToIdToNode.erase(current->m_nBest);
    }

    current->m_bVisited = true;
  }

  throw string("No path to end");
}

#include "SourceSuffix.h"
