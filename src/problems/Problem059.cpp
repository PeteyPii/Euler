#include "SourcePrefix.h"

#include "Common.h"

int32 problem59() {
  ifstream fin("problem_input/p059.txt");
  assertFileOpened(fin);

  vector<int32> characters;
  int32 temp;
  while (fin >> temp) {
    characters.push_back(temp);
  }

  int32 charCounts[3][256] = {0};
  for (uint32 i = 0; i < characters.size(); i++) {
    charCounts[i % 3][characters[i]]++;
  }

  int32 highestFreq[3] = {0};
  int32 highestFreqChar[3] = {0};
  for (uint32 i = 0; i < 3; i++) {
    for (uint32 j = 0; j < 256; j++) {
      if (charCounts[i][j] > highestFreq[i]) {
        highestFreq[i] = charCounts[i][j];
        highestFreqChar[i] = j;
      }
    }
  }

  int32 encryptionKeys[3];
  for (uint32 i = 0; i < 3; i++) {
    // Space should be the most frequent character
    encryptionKeys[i] = highestFreqChar[i] ^ ' ';
  }

  int32 asciiSum = 0;
  for (uint32 i = 0; i < characters.size(); i++) {
    characters[i] ^= encryptionKeys[i % 3];
    asciiSum += characters[i];
  }

  return asciiSum;
}

#include "SourceSuffix.h"
