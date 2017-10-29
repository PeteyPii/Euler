#include "SourcePrefix.h"

#include "Common.h"

int32 problem60(int32 n) {
  if (n < 2) {
    throw string("Need at least two numbers to concatenate");
  }

  // Need to have an upper bound on what prime can be in the set (it's just a guess)
  const int32 MAX_PRIME_BOUND = 10000;

  vector<bool> isPrime;
  sieveOfErotosthenes(MAX_PRIME_BOUND, isPrime);

  struct Node {
    int32 val;
    int32 power;
    set<int32> adjacencies;
  };

  int32 power = 10;
  vector<Node> nodes;
  for (int32 i = 0; i < static_cast<int32>(isPrime.size()); i++) {
    if (i >= power) {
      power *= 10;
    }

    if (isPrime[i]) {
      Node node;
      node.power = power;
      node.val = i;
      nodes.push_back(node);
    }
  }

  for (uint32 i = 0; i < nodes.size() - 1; i++) {
    for (uint32 j = i + 1; j < nodes.size(); j++) {
      if (isNumberPrime(nodes[j].val * nodes[i].power + nodes[i].val) &&
          isNumberPrime(nodes[i].val * nodes[j].power + nodes[j].val)) {
        nodes[i].adjacencies.insert(j);
        nodes[j].adjacencies.insert(i);
      }
    }
  }

// Things tend to have a lot of adjacencies (barring 2 and 5) so this is pretty pointless.
#if 0
  auto it = remove_if(nodes.begin(), nodes.end(), [n](Node& node) -> bool {
    return node.adjacencies.size() < static_cast<uint32>(n - 1);
  });
  nodes.erase(it, nodes.end());

  // Recompute indices of adjacencies
#endif

  class KNFinder {
  public:
    KNFinder(const vector<Node>& graph) : m_vcGraph(graph) {
    }

    vector<set<int32>> operator()(int32 n) {
      m_nN = n;
      m_vsResults = vector<set<int32>>();

      set<int32> placeholder;
      recurse(placeholder, 0);

      return m_vsResults;
    }

  private:
    const vector<Node>& m_vcGraph;
    int32 m_nN;
    vector<set<int32>> m_vsResults;

    void recurse(set<int32>& candidate, int32 minIx) {
      if (candidate.size() == static_cast<uint32>(m_nN)) {
        m_vsResults.push_back(candidate);
        return;
      }

      for (uint32 i = minIx; i < m_vcGraph.size(); i++) {
        bool isValid = true;
        for (int32 ix : candidate) {
          if (m_vcGraph[i].adjacencies.count(ix) == 0) {
            isValid = false;
            break;
          }
        }

        if (isValid) {
          candidate.insert(i);
          recurse(candidate, i + 1);
          candidate.erase(i);
        }
      }
    }
  };

  KNFinder knFinder(nodes);
  vector<set<int32>> validSets = knFinder(n);

  if (validSets.size() == 0) {
    throw string("Prime upper bound not set high enough to find a valid prime family");
  }

  sort(validSets.begin(), validSets.end(), [&nodes](const set<int32>& x, const set<int32>& y) -> bool {
    int32 xSum = 0;
    for (int32 ix : x) {
      xSum += nodes[ix].val;
    }

    int32 ySum = 0;
    for (int32 ix : y) {
      ySum += nodes[ix].val;
    }

    return xSum < ySum;
  });

  int32 sum = 0;
  for (int32 ix : validSets[0]) {
    sum += nodes[ix].val;
  }
  return sum;
}

#include "SourceSuffix.h"
