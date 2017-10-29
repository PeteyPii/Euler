#include "SourcePrefix.h"

#include "BigInteger.h"

BigInteger::~BigInteger() {}

int32 BigInteger::numberOfDigits() const {
  int32 c = m_vnDigits.size();
  for (int32 i = m_vnDigits.size() - 1; i >= 0; i--) {
    if (m_vnDigits[i] == 0) {
      c--;
    } else {
      break;
    }
  }

  return maxVal(c, 1);
}

uint8 BigInteger::getNthDigitFromRight(int32 n) const { // n is zero based
  if (n >= static_cast<int32>(m_vnDigits.size())) {
    return 0;
  }

  if (n < 0) {
    throw string("Tried to get a negative digit");
  }

  return m_vnDigits[n];
}

uint8 BigInteger::getNthDigitFromLeft(int32 n) const { // n is zero based
  if (n < 0) {
    return 0;
  }

  if (n >= static_cast<int32>(m_vnDigits.size())) {
    throw string("Tried to get a digit below the ones digit");
  }

  return m_vnDigits[m_vnDigits.size() - 1 - n];
}

bool BigInteger::isZero() const {
  return m_vnDigits[0] == 0 && m_vnDigits.size() == 1;
}

int32 BigInteger::sumOfDigits() const {
  int32 sum = 0;
  for (uint32 i = 0; i < m_vnDigits.size(); i++) {
    sum += m_vnDigits[i];
  }
  return sum;
}

int32 BigInteger::productOfDigits() const {
  int32 product = 1;
  for (uint32 i = 0; i < m_vnDigits.size(); i++) {
    product *= m_vnDigits[i];
    if (product == 0) {
      break;
    }
  }
  return product;
}

bool BigInteger::isPalindrome() const {
  uint32 left = m_vnDigits.size() - 1;
  uint32 right = 0;
  while (right < left) {
    if (m_vnDigits[right] != m_vnDigits[left]) {
      return false;
    }

    right++;
    left--;
  }

  return true;
}

BigInteger BigInteger::reverse() const {
  BigInteger copy(*this);
  std::reverse(copy.m_vnDigits.begin(), copy.m_vnDigits.end());
  copy.trimZeros();
  return copy;
}

BigInteger BigInteger::convertToBase(uint8 base) const {
  BigInteger sum(0, base);
  BigInteger digitValue(1, base);
  for (uint32 i = 0; i < m_vnDigits.size(); i++) {
    sum += digitValue * m_vnDigits[i];
    digitValue *= m_nBase;
  }

  return sum;
}

BigInteger BigInteger::operator+(const BigInteger& obj) const {
  assertSameBase(obj);

  BigInteger retVal(0, m_nBase);
  vector<uint8>& digits = retVal.m_vnDigits;
  digits.resize(1 + (maxVal(m_vnDigits.size(), obj.m_vnDigits.size())));

  int32 carry = 0;
  for (uint32 i = 0; i < digits.size(); i++) {
    uint16 sum = getNthDigitFromRight(i) + obj.getNthDigitFromRight(i) + carry;
    digits[i] = sum % retVal.m_nBase;
    carry = (sum >= retVal.m_nBase ? 1 : 0);
  }

  retVal.trimZeros();

  return retVal;
}

BigInteger BigInteger::operator*(const BigInteger& obj) const {
  assertSameBase(obj);

  if (m_vnDigits.size() < obj.m_vnDigits.size()) {
    return obj * (*this);
  }

  if (obj.isZero() || isZero()) {
    return BigInteger(0, m_nBase);
  }

  BigInteger retVal(0, m_nBase);
  vector<uint8>& digits = retVal.m_vnDigits;
  digits.resize(m_vnDigits.size() + obj.m_vnDigits.size(), 0);

  retVal.m_bIsNegative = (m_bIsNegative != obj.m_bIsNegative);

  if (obj.m_vnDigits.size() == 1) {
    uint8 carry = 0;
    uint8 factor = obj.m_vnDigits[0];

    for (uint32 i = 0; i < m_vnDigits.size(); i++) {
      uint16 val = factor * m_vnDigits[i] + carry;
      digits[i] = val % m_nBase;
      carry = val / m_nBase;
    }
    digits[digits.size() - 1] = carry;

    retVal.trimZeros();

    return retVal;
  }

  for (uint32 i = 0; i < obj.m_vnDigits.size(); i++) {
    uint8 factor = obj.m_vnDigits[i];

    if (factor == 0) {
      continue;
    }

    BigInteger temp(0, m_nBase);
    temp.m_vnDigits.resize(m_vnDigits.size() + i + 1);

    for (uint32 j = 0; j < i; j++) {
      temp.m_vnDigits[j] = 0;
    }

    uint8 carry = 0;
    for (uint32 j = 0; j <= m_vnDigits.size(); j++) {
      uint16 val = factor * getNthDigitFromRight(j) + carry;
      temp.m_vnDigits[j + i] = val % m_nBase;
      carry = val / m_nBase;
    }

    retVal += temp;
  }

  retVal.trimZeros();

  return retVal;
}

bool BigInteger::operator==(const BigInteger& obj) const {
  assertSameBase(obj);
  return m_vnDigits == obj.m_vnDigits;
}

bool BigInteger::operator<(const BigInteger& obj) const {
  uint32 leftDigits = numberOfDigits();
  uint32 rightDigits = obj.numberOfDigits();
  if (leftDigits < rightDigits) {
    return true;
  } else if (leftDigits > rightDigits) {
    return false;
  } else {
    for (uint32 i = 1; i <= leftDigits; i++) {
      if (m_vnDigits[leftDigits - i] < obj.m_vnDigits[leftDigits - i]) {
        return true;
      } else if (m_vnDigits[leftDigits - i] > obj.m_vnDigits[leftDigits - i]) {
        return false;
      }
    }
  }

  return false;
}

BigInteger BigInteger::operator|(const BigInteger& obj) const {
  assertSameBase(obj);

  if ((m_nBase & (m_nBase - 1)) != 0) {
    throw string("Bitwise operators must be in a power of 2 base");
  }

  BigInteger retVal(0);
  if (m_vnDigits.size() > obj.m_vnDigits.size()) {
    retVal.m_vnDigits.resize(m_vnDigits.size());
    for (uint32 i = 0; i < obj.m_vnDigits.size(); i++) {
      retVal.m_vnDigits[i] = m_vnDigits[i] | obj.m_vnDigits[i];
    }
    for (uint32 i = obj.m_vnDigits.size(); i < m_vnDigits.size(); i++) {
      retVal.m_vnDigits[i] = m_vnDigits[i];
    }
  } else {
    retVal.m_vnDigits.resize(obj.m_vnDigits.size());
    for (uint32 i = 0; i < m_vnDigits.size(); i++) {
      retVal.m_vnDigits[i] = m_vnDigits[i] | obj.m_vnDigits[i];
    }
    for (uint32 i = m_vnDigits.size(); i < obj.m_vnDigits.size(); i++) {
      retVal.m_vnDigits[i] = obj.m_vnDigits[i];
    }
  }

  return retVal;
}

BigInteger BigInteger::operator&(const BigInteger& obj) const {
  assertSameBase(obj);

  if ((m_nBase & (m_nBase - 1)) != 0) {
    throw string("Bitwise operators must be in a power of 2 base");
  }

  BigInteger retVal(0);
  if (m_vnDigits.size() < obj.m_vnDigits.size()) {
    retVal.m_vnDigits.resize(m_vnDigits.size());
  } else {
    retVal.m_vnDigits.resize(obj.m_vnDigits.size());
  }

  for (uint32 i = 0; i < retVal.m_vnDigits.size(); i++) {
    retVal.m_vnDigits[i] = m_vnDigits[i] & obj.m_vnDigits[i];
  }

  retVal.trimZeros();

  return retVal;
}

BigInteger BigInteger::operator^(const BigInteger& obj) const {
  assertSameBase(obj);

  if ((m_nBase & (m_nBase - 1)) != 0) {
    throw string("Bitwise operators must be in a power of 2 base");
  }

  BigInteger retVal(0);
  if (m_vnDigits.size() > obj.m_vnDigits.size()) {
    retVal.m_vnDigits.resize(m_vnDigits.size());
    for (uint32 i = 0; i < obj.m_vnDigits.size(); i++) {
      retVal.m_vnDigits[i] = m_vnDigits[i] ^ obj.m_vnDigits[i];
    }
    for (uint32 i = obj.m_vnDigits.size(); i < m_vnDigits.size(); i++) {
      retVal.m_vnDigits[i] = m_vnDigits[i];
    }
  } else {
    retVal.m_vnDigits.resize(obj.m_vnDigits.size());
    for (uint32 i = 0; i < m_vnDigits.size(); i++) {
      retVal.m_vnDigits[i] = m_vnDigits[i] ^ obj.m_vnDigits[i];
    }
    for (uint32 i = m_vnDigits.size(); i < obj.m_vnDigits.size(); i++) {
      retVal.m_vnDigits[i] = obj.m_vnDigits[i];
    }
  }

  retVal.trimZeros();

  return retVal;
}

BigInteger BigInteger::operator<<(int32 n) const {
  if (n < 0) {
    throw string("Negative bitshifts not allowed");
  } else if (n == 0) {
    return *this;
  }

  bool changedBase = false;
  uint8 oldBase;
  if ((m_nBase & (m_nBase - 1)) != 0) {
    changedBase = true;
    oldBase = m_nBase;
  }

  uint8 fullMask = changedBase ? 128 - 1 : m_nBase - 1;
  uint8 bits = 0;
  uint8 x = fullMask;
  while (x > 0) {
    x >>= 1;
    bits++;
  }

  BigInteger number = changedBase ? convertToBase(128) : *this;
  vector<uint8> buffer(number.numberOfDigits() + n / bits + 1, 0);

  int32 digitShift = n / bits;
  for (uint32 i = 0; i < number.m_vnDigits.size(); i++) {
    buffer[i + digitShift] = number.m_vnDigits[i];
  }

  int32 bitShift = n % bits;
  if (bitShift != 0) {
    uint8 carryFromMask = 0;
    uint8 carryShiftCount = bits;

    while (x < bitShift) {
      carryFromMask <<= 1;
      carryFromMask |= 1;
      carryShiftCount -= 1;
      x++;
    }

    carryFromMask <<= carryShiftCount;

    for (uint32 i = 0; i < buffer.size(); i++) {
      buffer[i] <<= bitShift;
      buffer[i] &= fullMask;
    }

    for (uint32 i = 0; i < number.m_vnDigits.size(); i++) {
      buffer[i + digitShift + 1] |= (number.m_vnDigits[i] & carryFromMask) >> carryShiftCount;
    }
  }

  number.m_vnDigits = buffer;
  if (changedBase) {
    number = number.convertToBase(oldBase);
  } else {
    number.trimZeros();
  }
  return number;
}

BigInteger BigInteger::operator>>(int32 n) const {
  if (n < 0) {
    throw string("Negative bitshifts not allowed");
  } else if (n == 0) {
    return *this;
  }

  bool changedBase = false;
  uint8 oldBase;
  if ((m_nBase & (m_nBase - 1)) != 0) {
    changedBase = true;
    oldBase = m_nBase;
  }

  uint8 fullMask = changedBase ? 128 - 1 : m_nBase - 1;
  uint8 bits = 0;
  uint8 x = fullMask;
  while (x > 0) {
    x >>= 1;
    bits++;
  }

  BigInteger number = changedBase ? convertToBase(128) : *this;
  vector<uint8> buffer(max(number.numberOfDigits() - n / bits, 1), 0);

  int32 digitShift = n / bits;
  for (int32 i = 0;
       i < static_cast<int32>(number.m_vnDigits.size()) - digitShift;
       i++) {
    buffer[i] = number.m_vnDigits[i + digitShift];
  }

  int32 bitShift = n % bits;
  if (bitShift != 0) {
    uint8 carryFromMask = 0;
    uint8 carryShiftCount = bits;

    while (x < bitShift) {
      carryFromMask <<= 1;
      carryFromMask |= 1;
      carryShiftCount -= 1;
      x++;
    }

    for (uint32 i = 0; i < buffer.size(); i++) {
      buffer[i] >>= bitShift;
    }

    for (uint32 i = 0;
         i < buffer.size() && i + digitShift + 1 < number.m_vnDigits.size();
         i++) {
      buffer[i] |= (number.m_vnDigits[i + digitShift + 1] & carryFromMask)
                   << carryShiftCount;
    }
  }

  number.m_vnDigits = buffer;
  if (changedBase) {
    number = number.convertToBase(oldBase);
  } else {
    number.trimZeros();
  }
  return number;
}

ostream& operator<<(ostream& out, const BigInteger& n) {
  if (n.isZero()) {
    out << "0";
    return out;
  }

  bool foundNonZero = false;
  string spacer = (n.m_nBase > 10 ? "." : "");
  for (int32 i = n.m_vnDigits.size() - 1; i >= 0; i--) {
    if (!foundNonZero) {
      if (n.m_vnDigits[i] != 0) {
        foundNonZero = true;
        out << (n.m_bIsNegative ? "-" : "");
        out << (int32)n.m_vnDigits[i];
      }
    } else {
      out << spacer << (int32)n.m_vnDigits[i];
    }
  }

  return out;
}

istream& operator>>(istream& in, BigInteger& n) {
  uint8 base = n.m_nBase;

  if (base > 10) {
    throw string("Big integer stream read not implemented for high bases");
    n = BigInteger(0, base);
    return in;
  }

  while (in && (in.peek() == ' ' || in.peek() == '\n' || in.peek() == '\t')) {
    in.get();
  }

  if (in && in.peek() == '-') {
    n.m_bIsNegative = true;
    in.get();
  } else {
    n.m_bIsNegative = false;
  }

  vector<uint8> numbers;
  while (in && in.peek() >= '0' && in.peek() <= '9') {
    char c = in.get();
    numbers.push_back(stringToNumber<uint8>(c));
  }

  vector<uint8>& digits = n.m_vnDigits;
  digits.resize(numbers.size());
  int32 j = 0;
  for (int32 i = numbers.size() - 1; i >= 0; i--) {
    if (numbers[i] >= n.m_nBase) {
      throw string("Stream input has digits larger than the base can handle");
      n = BigInteger(0, base);
      return in;
    }

    digits[j] = numbers[i];
    j++;
  }

  return in;
}

void BigInteger::assertSameBase(const BigInteger& obj) const {
  if (m_nBase != obj.m_nBase) {
    throw string("The base of two big integers do not match");
  }
}

void BigInteger::trimZeros() {
  if (m_vnDigits.size() > 1) {
    uint32 i = m_vnDigits.size();
    while (i > 1 && m_vnDigits[i - 1] == 0) {
      i--;
    }

    m_vnDigits.erase(m_vnDigits.begin() + i, m_vnDigits.end());
  }
}

#include "SourceSuffix.h"
