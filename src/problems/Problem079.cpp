#include "SourcePrefix.h"

#include "Common.h"

string problem79() {
  ifstream fin("problem_input/p079.txt");

  assertFileOpened(fin);

  vector<string> codes;
  string temp;
  while (fin >> temp) {
    reverse(temp.begin(), temp.end());
    codes.push_back(temp);
  }

  struct Node {
    Node(const vector<string>& codes, string path)
        : m_vsCodes(codes), m_sPath(path) {
      set<char> seen;
      m_nTotal = 0;
      for (string& code : m_vsCodes) {
        for (char c : code) {
          seen.insert(c);
        }
        m_nTotal += code.length();
      }
      m_nH = seen.size();
    }

    bool operator<(const Node& n) const {
      // Need to invert return values since this will be for a priority queue
      // which puts higher values first and we want lower values prioritized.
      int32 cost = m_nH + m_sPath.length();
      int32 otherCost = n.m_nH + n.m_sPath.length();
      if (cost < otherCost) {
        return false;
      } else if (m_nH > n.m_nH) {
        return true;
      } else {
        return m_nTotal > n.m_nTotal;
      }
    }

    vector<string> m_vsCodes;
    string m_sPath;
    int32 m_nH;
    int32 m_nTotal;
  };

  priority_queue<Node> candidates;
  candidates.push(Node(codes, ""));

  while (candidates.top().m_nTotal > 0) {
    Node n = candidates.top();
    candidates.pop();

    set<char> adjacencies;

    for (string& oldCode : n.m_vsCodes) {
      if (oldCode.length() > 0 && adjacencies.insert(oldCode.back()).second) {
        vector<string> newCodes = n.m_vsCodes;
        for (string& newCode : newCodes) {
          if (newCode.length() > 0 && newCode.back() == oldCode.back()) {
            newCode.pop_back();
          }
        }
        candidates.push(Node(newCodes, n.m_sPath + oldCode.back()));
      }
    }
  }

  return candidates.top().m_sPath;
}

#include "SourceSuffix.h"
