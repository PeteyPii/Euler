#include "SourcePrefix.h"

#include "Common.h"

int32 problem98() {
  ifstream fin("problem_input/p098.txt");
  assertFileOpened(fin);

  vector<string> words;
  while (fin) {
    string word;
    fin >> word;
    words.push_back(word);
  }

  int32 maxWordSize = 0;
  for (auto& word : words) {
    maxWordSize = max(maxWordSize, (int32)word.length());
  }

  vector<map<string, vector<string>>> anagrams(maxWordSize + 1);
  for (auto& word : words) {
    string sorted = word;
    sort(sorted.begin(), sorted.end());
    anagrams[word.length()][sorted].push_back(word);
  }

  for (int32 i = 0; i < maxWordSize + 1; i++) {
    vector<string> filter;
    for (auto it : anagrams[i]) {
      if (it.second.size() < 2) {
        filter.push_back(it.first);
      }
    }
    for (auto& s : filter) {
      anagrams[i].erase(s);
    }
  }

  int32 wordSize = maxWordSize;
  while (anagrams[wordSize].size() == 0) {
    anagrams.pop_back();
    wordSize -= 1;
  }

  maxWordSize = wordSize;

  vector<map<string, vector<int64>>> anagramSquares(maxWordSize + 1);
  int64 maxSquare = 1;
  int64 squareRoot = 0;
  for (int32 i = 0; i < maxWordSize; i++) {
    maxSquare *= 10;
    while (squareRoot * squareRoot < maxSquare) {
      int64 square = squareRoot * squareRoot;
      string sorted = numberToString(square);
      sort(sorted.begin(), sorted.end());
      anagramSquares[i + 1][sorted].push_back(square);
      squareRoot += 1;
    }
  }

  for (int32 i = 0; i <= maxWordSize; i++) {
    vector<string> filter;
    for (auto it : anagramSquares[i]) {
      if (it.second.size() < 2) {
        filter.push_back(it.first);
      }
    }
    for (auto& s : filter) {
      anagramSquares[i].erase(s);
    }
  }

  int64 bestSquare = 0;
  for (int32 wordSize = maxWordSize; wordSize >= 0; wordSize--) {
    for (auto wordIt : anagrams[wordSize]) {
      for (uint32 wordI = 1; wordI < wordIt.second.size(); wordI++) {
        for (uint32 wordJ = 0; wordJ < wordI; wordJ++) {
          const string& word1 = wordIt.second[wordI];
          const string& word2 = wordIt.second[wordJ];
          const string& sortedWord = wordIt.first;
          for (auto squareIt : anagramSquares[wordSize]) {
            for (uint32 sqaureI = 1; sqaureI < squareIt.second.size(); sqaureI++) {
              for (uint32 squareJ = 0; squareJ < sqaureI; squareJ++) {
                int64 high = max(squareIt.second[sqaureI], squareIt.second[squareJ]);
                if (high <= bestSquare) {
                  continue;
                }

                string n1 = numberToString(squareIt.second[sqaureI]);
                string n2 = numberToString(squareIt.second[squareJ]);
                const string& sortedN = squareIt.first;

                bool badMap = false;
                for (int32 ix = 1; ix < wordSize; ix++) {
                  if (sortedWord[ix] == sortedWord[ix - 1] && sortedN[ix] != sortedN[ix - 1]) {
                    badMap = true;
                    break;
                  } else if (sortedWord[ix] != sortedWord[ix - 1] && sortedN[ix] == sortedN[ix - 1]) {
                    badMap = true;
                    break;
                  }
                }

                if (badMap) {
                  continue;
                }

                map<char, char> letterToDigit;
                for (int32 ix = 0; ix < wordSize; ix++) {
                  letterToDigit[word1[ix]] = n1[ix];
                }
                for (int32 ix = 0; ix < wordSize; ix++) {
                  if (letterToDigit[word2[ix]] != n2[ix]) {
                    badMap = true;
                    break;
                  }
                }

                if (badMap) {
                  continue;
                }

                bestSquare = high;
              }
            }
          }
        }
      }
    }
  }

  return bestSquare;
}

#include "SourceSuffix.h"
