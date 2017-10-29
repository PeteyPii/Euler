#include "SourcePrefix.h"

#include "Common.h"

int32 problem54() {
  static int32 cardVals[256];

  cardVals['2'] = 0;
  cardVals['3'] = 1;
  cardVals['4'] = 2;
  cardVals['5'] = 3;
  cardVals['6'] = 4;
  cardVals['7'] = 5;
  cardVals['8'] = 6;
  cardVals['9'] = 7;
  cardVals['T'] = 8;
  cardVals['J'] = 9;
  cardVals['Q'] = 10;
  cardVals['K'] = 11;
  cardVals['A'] = 12;

  // Value of each rank
  static const int32 HIGH_CARD = 0;
  static const int32 PAIR = 1;
  static const int32 TWO_PAIRS = 2;
  static const int32 THREE_KIND = 3;
  static const int32 STRAIGHT = 4;
  static const int32 FLUSH = 5;
  static const int32 FULL_HOUSE = 6;
  static const int32 FOUR_KIND = 7;
  static const int32 STRAIGHT_FLUSH = 8;

  class Card {
  public:
    int32 value;
    char suit;

    Card(string card) {
      value = cardVals[static_cast<int32>(card[0])];
      suit = card[1];
    }

    bool operator<(const Card& other) const { return value < other.value; }
  };

  class PokerHandEval {
  public:
    int32 operator()(const vector<string>& hand) {
      // This is pretty ugly. Basically we try to figure out the hand's best rank
      // (e.g. thrre of a kind) and the value of that rank (e.g. 3 queens). We also try
      // to find the best high card not part of that rank. Then we map those three values
      // we found to a single number in such a way that the higher that number is, the better
      // the hand.

      vector<Card> cards;
      transform(hand.begin(), hand.end(), back_inserter(cards), [](const string& c) -> Card { return Card(c); });
      sort(cards.begin(), cards.end());

      int32 straightStart = cards[0].value;
      char flushSuit = cards[0].value;

      vector<int32> cardCounts(13, 0);
      cardCounts[cards[0].value]++;

      bool hasFlush = true;
      bool hasStraight = true;

      for (uint32 i = 1; i < 5; i++) {
        if (cards[i].suit != flushSuit) {
          hasFlush = false;
        }

        if (cards[i].value != static_cast<int32>(straightStart + i)) {
          hasStraight = false;
        }

        cardCounts[cards[i].value]++;
      }

      int32 highCard = 0;

      bool hasQuad = false;
      bool hasTriple = false;
      bool hasOnePair = false;
      bool hasTwoPair = false;

      int32 rankValue = 0;
      int32 pairValue = 0;
      int32 secondPairValue = 0;

      for (uint32 i = 0; i < 13; i++) {
        switch (cardCounts[i]) {
          case 1:
            highCard = i;
            break;
          case 2:
            hasTwoPair = hasOnePair ? true : false;
            secondPairValue = hasTwoPair ? i : 0;
            pairValue = hasOnePair ? pairValue : i;
            hasOnePair = true;
            break;
          case 3:
            hasTriple = true;
            rankValue = i;
            break;
          case 4:
            hasQuad = true;
            rankValue = i;
            break;
        }
      }

      int32 rank = 0;

      if (hasStraight && hasFlush) {
        // Royal flush is pretty irrelevent, its the best straight flush anyways
        rank = STRAIGHT_FLUSH;
        rankValue = straightStart;
      } else if (hasQuad) {
        rank = FOUR_KIND;
      } else if (hasTriple && hasOnePair) {
        rank = FULL_HOUSE;
      } else if (hasFlush) {
        rank = FLUSH;
        for (auto it = cards.rbegin(); it != cards.rend(); it++) {
          rankValue *= 13;
          rankValue += it->value;
        }
      } else if (hasStraight) {
        rank = STRAIGHT;
        rankValue = straightStart;
      } else if (hasTriple) {
        rank = THREE_KIND;
      } else if (hasTwoPair) {
        rank = TWO_PAIRS;
        rankValue = secondPairValue * 13 + pairValue;
      } else if (hasOnePair) {
        rank = PAIR;
        rankValue = pairValue;
      } else {
        rank = HIGH_CARD;
        rankValue = 0;
      }

      // Max high card value is 12
      // Max rank value is under 13^5 (from flush ranking)
      return highCard + rankValue * 13 + rank * 13 * 13 * 13 * 13 * 13 * 13;
    }
  };

  PokerHandEval eval;

  ifstream fin("problem_input/p054.txt");
  assertFileOpened(fin);

  int32 p1wins = 0;
  while (fin) {
    vector<string> p1hand;
    vector<string> p2hand;

    string card;
    for (int32 i = 0; i < 5; i++) {
      fin >> card;
      p1hand.push_back(card);
    }

    for (int32 i = 0; i < 5; i++) {
      fin >> card;
      p2hand.push_back(card);
    }

    if (!fin.good() || fin.peek() == EOF) {
      break;
    }

    if (eval(p1hand) > eval(p2hand)) {
      p1wins++;
    }
  }

  return p1wins;
}

#include "SourceSuffix.h"
