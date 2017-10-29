#pragma once

#include "Common.h"

class BigInteger {
private:
  template <typename N>
  void init(N n) {
    if (m_nBase < 2) {
      throw string("Bad base for big integer");
      m_nBase = 0;
    }

    if (n < 0) {
      m_bIsNegative = true;
    }

    int32 i = 0;
    while (n != 0) {
      m_vnDigits[i] = n % m_nBase;
      n /= m_nBase;
      m_vnDigits.push_back(0);
      i++;
    }

    trimZeros();
  }

public:
  template <typename N>
  explicit BigInteger(N n, uint8 base = 10) : m_nBase(base), m_vnDigits(1, 0), m_bIsNegative(false) {
    init(n);
  }
  BigInteger() : BigInteger(0) {
  }

  ~BigInteger();

  int32 numberOfDigits() const;
  uint8 getNthDigitFromRight(int32 n) const; // n is zero based
  uint8 getNthDigitFromLeft(int32 n) const;  // n is zero based
  bool isZero() const;
  int32 sumOfDigits() const;
  int32 productOfDigits() const;
  bool isPalindrome() const;
  BigInteger reverse() const;
  BigInteger convertToBase(uint8 base) const;

  BigInteger operator+(const BigInteger& obj) const;
  BigInteger& operator+=(const BigInteger& obj) {
    return *this = *this + obj;
  }
  template <typename N>
  BigInteger operator+(const N& n) const {
    return *this + BigInteger(n, m_nBase);
  }
  template <typename N>
  BigInteger& operator+=(const N& n) {
    return *this += BigInteger(n, m_nBase);
  }

  BigInteger operator*(const BigInteger& obj) const;
  BigInteger& operator*=(const BigInteger& obj) {
    return *this = *this * obj;
  }
  template <typename N>
  BigInteger operator*(const N& n) const {
    return (*this) * BigInteger(n, m_nBase);
  }
  template <typename N>
  BigInteger& operator*=(const N& n) {
    return *this *= BigInteger(n, m_nBase);
  }

  template <typename N>
  BigInteger operator%(const N& n) {
    static_assert(!is_same<N, BigInteger>::value, "Cannot mod by BigInteger");
    N total = 0;
    uint64 coefficient = 1;
    for (uint64 i = 0; i < m_vnDigits.size(); i++) {
      total += coefficient * m_vnDigits[i];
      total %= n;
      coefficient *= m_nBase;
      coefficient %= n;
    }
    return BigInteger(total, m_nBase);
  }
  template <typename N>
  BigInteger& operator%=(const N& n) {
    return *this = *this % n;
  }

  bool operator==(const BigInteger& obj) const;
  template <typename N>
  bool operator==(const N& n) const {
    return *this == BigInteger(n, m_nBase);
  }
  bool operator!=(const BigInteger& obj) const {
    return !(*this == obj);
  }
  template <typename N>
  bool operator!=(const N& n) const {
    return *this != BigInteger(n, m_nBase);
  }
  bool operator<(const BigInteger& obj) const;
  template <typename N>
  bool operator<(const N& n) const {
    return *this < BigInteger(n, m_nBase);
  }
  bool operator>(const BigInteger& obj) const {
    return obj < *this;
  }
  template <typename N>
  bool operator>(const N& n) const {
    return *this > BigInteger(n, m_nBase);
  }
  bool operator<=(const BigInteger& obj) const {
    return !(*this > obj);
  }
  template <typename N>
  bool operator<=(const N& n) const {
    return !(*this > BigInteger(n, m_nBase));
  }
  bool operator>=(const BigInteger& obj) const {
    return !(*this < obj);
  }
  template <typename N>
  bool operator>=(const N& n) const {
    return !(*this < BigInteger(n, m_nBase));
  }

  BigInteger operator|(const BigInteger& obj) const;
  BigInteger& operator|=(const BigInteger& obj) {
    return *this = *this | obj;
  }
  template <typename N>
  BigInteger operator|(const N& n) const {
    return *this | BigInteger(n, m_nBase);
  }
  template <typename N>
  BigInteger& operator|=(const N& n) const {
    return *this |= BigInteger(n, m_nBase);
  }

  BigInteger operator&(const BigInteger& obj) const;
  BigInteger& operator&=(const BigInteger& obj) {
    return *this = *this & obj;
  }
  template <typename N>
  BigInteger operator&(const N& n) const {
    return *this & BigInteger(n, m_nBase);
  }
  template <typename N>
  BigInteger& operator&=(const N& n) const {
    return *this &= BigInteger(n, m_nBase);
  }

  BigInteger operator^(const BigInteger& obj) const;
  BigInteger& operator^=(const BigInteger& obj) {
    return *this = *this ^ obj;
  }
  template <typename N>
  BigInteger operator^(const N& n) const {
    return *this ^ BigInteger(n, m_nBase);
  }
  template <typename N>
  BigInteger& operator^=(const N& n) const {
    return *this ^= BigInteger(n, m_nBase);
  }

  BigInteger operator<<(int32 n) const;
  BigInteger& operator<<=(int32 n) {
    return *this = *this << n;
  }
  BigInteger operator>>(int32 n) const;
  BigInteger& operator>>=(int32 n) {
    return *this = *this >> n;
  }

  friend ostream& operator<<(ostream& out, const BigInteger& n);
  friend istream& operator>>(istream& in, BigInteger& n);

private:
  uint8 m_nBase;
  vector<uint8> m_vnDigits;
  bool m_bIsNegative;

  void assertSameBase(const BigInteger& obj) const;
  void trimZeros();

  BigInteger operator-(const BigInteger& obj) const;
  BigInteger& operator-=(const BigInteger& obj);

  BigInteger operator/(const BigInteger& obj) const;
  BigInteger& operator/=(const BigInteger& obj);

  BigInteger operator%(const BigInteger& obj) const;
  BigInteger& operator%=(const BigInteger& obj);

  BigInteger operator~() const;
};

template <typename N>
bool operator<(const N& n, const BigInteger& right) {
  return right > n;
}

template <typename N>
bool operator<=(const N& n, const BigInteger& right) {
  return right >= n;
}

template <typename N>
bool operator>(const N& n, const BigInteger& right) {
  return right < n;
}

template <typename N>
bool operator>=(const N& n, const BigInteger& right) {
  return right <= n;
}
