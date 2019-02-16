#pragma once

#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef uint8_t uint8;
typedef int8_t int8;
typedef uint16_t uint16;
typedef int16_t int16;
typedef uint32_t uint32;
typedef int32_t int32;
typedef uint64_t uint64;
typedef int64_t int64;

const double PI = 3.14159265358979;
const double SQRT_2 = 1.41421356237310;

void sieveOfErotosthenes(int64 n, vector<bool>& isPrime);
bool verifySieve(int64 n);
bool isPalindrome(int32 n, int32 base = 10);
void assertFileOpened(const ifstream& fin);
bool isLeapYear(int32 year);
void printProgress(uint64 current, uint64 total, int32 intervals);
double logarithmicIntegralApprox(double x, int32 iterations = 50);

// Sorted sequences of positive integers that sum to x.
vector<vector<int32>> partitions(int32 x);

// Sorted sequences of positive integers of length n that sum to x.
vector<vector<int32>> partitionsOfSizeN(int32 x, int32 n);

// Sorted sets (i.e. no repeats) of positive integers of cardinality n that sum to x.
vector<vector<int32>> partitionSetsOfSizeN(int32 x, int32 n, int32 min = 1);

template <typename N>
N stringToNumber(string s) {
  stringstream ss;
  ss << s;
  N n;
  ss >> n;
  return n;
}

template <typename N>
N stringToNumber(char c) {
  if (c >= '0' && c <= '9') {
    return N(c - '0');
  } else if (c >= 'a' && c <= 'z') {
    return N(c - 'a');
  } else if (c >= 'A' && c <= 'Z') {
    return N(c - 'A');
  } else {
    return N(c);
  }
}

template <typename N>
string numberToString(N n) {
  stringstream ss;
  ss << n;
  return ss.str();
}

template <typename N>
N sumOfDigits(N n) {
  N sum = 0;
  while (n != 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

template <typename N>
N productOfDigits(N n) {
  N product = 1;
  while (n != 0) {
    product *= n % 10;
    n /= 10;
    if (product == 0) {
      break;
    }
  }
  return product;
}

template <typename T>
inline T minVal(const T& a, const T& b) {
  return a < b ? a : b;
}

template <typename T>
inline T maxVal(const T& a, const T& b) {
  return b < a ? a : b;
}

template <typename N>
N gcd(N a, N b) {
  while (b != N(0)) {
    N temp = b;
    b = a % b;
    a = temp;
  }

  return a;
}

template <typename N>
bool isNumberPrime(N n) {
  if (n < 2) {
    return false;
  }

  if (n % 2 == 0 && n != 2) {
    return false;
  }

  N div = 3;
  while (div * div <= n) {
    if (n % div == 0) {
      return false;
    }

    div += 2;
  }

  return true;
}

template <typename N>
string getEnglishWordFromNumber(N n) {
  const string singles[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  const string teens[] = {
      "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  const string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
  const string triplets[] = {"", "thousand", "million", "billion", "trillion", "quadrillion", "quintillion"};

  if (n == 0) {
    return "zero";
  }

  string prefix = "";
  string suffix = "";

  if (n < 0) {
    prefix += "negative ";
    n *= -1;
  }

  int32 c = 0;
  while (n > 0) {
    string temp = "";
    int32 x = n % 1000;
    int32 triDigit = x / 100;
    int32 duoDigit = (x % 100) / 10;
    int32 monoDigit = x % 10;

    if (triDigit) {
      temp += singles[triDigit] + " hundred";
    }

    if (triDigit && (duoDigit || monoDigit)) {
      temp += " and ";
    }

    if (duoDigit || monoDigit) {
      temp += tens[duoDigit];

      if (duoDigit > 1 && monoDigit) {
        temp += "-" + singles[monoDigit];
      } else if (duoDigit == 1) {
        temp += teens[monoDigit];
      } else { // duoDigit == 0
        temp += singles[monoDigit];
      }
    }

    if (c > 0) {
      temp += " " + triplets[c];
    }

    suffix = temp + suffix;
    n /= 1000;
    c++;
  }

  return prefix + suffix;
}

template <typename N>
N sumOfDivisors(N n) {
  if (n < 1) {
    throw string("Cannot find divisors of numbers less than 1");
    return -1;
  }

  if (n == 1) {
    return 0;
  }

  N sum = 1;
  for (N i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      sum += i;

      if (i * i != n) {
        sum += n / i;
      }
    }
  }

  return sum;
}

template <typename N>
N factorial(N n) {
  if (n < 0) {
    throw string("Cannot do factorial of negative number");
    return N(-1);
  }

  N product(1);
  for (int32 i = 2; i <= n; i++) {
    product *= i;
  }

  return product;
}

template <typename T>
size_t make_hash(const T& v) {
  return hash<T>()(v);
}

// adapted from boost::hash_combine
inline void hash_combine(size_t& h, const size_t& v) {
  h ^= v + 0x9e3779b9 + (h << 6) + (h >> 2);
}

template <typename T>
struct hash_container {
  size_t operator()(const T& v) const {
    size_t h = 0;
    for (typename T::const_iterator i = v.cbegin(); i != v.cend(); i++) {
      hash_combine(h, make_hash(*i));
    }

    return h;
  }
};

namespace std {
template <typename T, typename U>
struct hash<pair<T, U>> {
  size_t operator()(const pair<T, U>& v) const {
    size_t h = make_hash(v.first);
    hash_combine(h, make_hash(v.second));
    return h;
  }
};

template <typename T>
struct hash<vector<T>> : hash_container<vector<T>> {};

template <typename T>
struct hash<set<T>> : hash_container<set<T>> {};

template <typename T, typename U>
struct hash<map<T, U>> : hash_container<map<T, U>> {};
} // namespace std

template <typename T>
T vectorSum(const vector<T>& v) {
  return accumulate(v.cbegin(), v.cend(), T(0));
}

template <typename T>
T vectorProduct(const vector<T>& v) {
  return accumulate(v.cbegin(), v.cend(), T(1), [](T product, T item) -> T { return product * item; });
}

template <typename T>
T setSum(const set<T>& s) {
  return accumulate(s.cbegin(), s.cend(), T(0));
}

bool isStringPandigital(const string& s);

template <typename N>
bool isPandigital(const N& n) {
  string s = numberToString(n);
  return isStringPandigital(s);
}

template <>
inline bool isPandigital<string>(const string& s) {
  return isStringPandigital(s);
}

template <typename T, typename U>
T power(T x, U y) {
  // Computes x^y
  T product(1);
  while (y > 0) {
    if ((y & 1) == 1) {
      product *= x;
    }

    y >>= 1;
    x *= x;
  }

  return product;
}

template <typename T, typename U, typename V>
T modPower(T x, U y, V m) {
  // Computes x^y mod m
  T product(1);
  x %= m;
  while (y > 0) {
    if ((y & 1) == 1) {
      product *= x;
      product %= m;
    }

    y >>= 1;
    x *= x;
    x %= m;
  }

  return product;
}

template <typename N, typename T>
bool assertEquality(N a, T b) {
  if (a == b) {
    return true;
  } else {
    cout << "BAD! " << a << " != " << b << endl;
    return false;
  }
}

template <typename R, typename... Args>
function<R(Args...)> memoized(R (*fn)(Args...)) {
  map<tuple<Args...>, R> memory;
  return [fn, memory](Args... args) mutable -> R {
    auto argt = make_tuple(args...);
    auto it = memory.find(argt);
    if (it == memory.end()) {
      it = memory.insert(make_pair(argt, fn(args...))).first;
    }

    return it->second;
  };
}

template <typename N>
void totientValues(N n, vector<N>& values) {
  vector<vector<N>> sieve(n + 1);
  for (N i = 2; i <= n; i++) {
    if (sieve[i].size() > 0) {
      continue;
    }

    for (N j = i; j <= n; j += i) {
      sieve[j].push_back(i);
    }
  }

  values = vector<N>(n + 1);

  values[0] = 0;
  values[1] = 1;

  for (N i = 2; i <= n; i++) {
    N totientVal = i;
    for (N primeDivisor : sieve[i]) {
      totientVal /= primeDivisor;
      totientVal *= primeDivisor - 1;
    }

    values[i] = totientVal;
  }
}

template <typename N, typename Iterator>
vector<vector<N>> combinations(const Iterator& begin, const Iterator& end, N k) {
  if (k == 1) {
    vector<vector<N>> results;
    for (auto it = begin; it != end; ++it) {
      results.push_back(vector<N>(1, *it));
    }
    return results;
  }

  vector<vector<N>> results;
  for (auto it = begin; it != end - k + 1; ++it) {
    const N& n = *it;
    vector<vector<N>> combos = combinations(it + 1, end, k - 1);
    vector<vector<N>> newCombos(combos.size(), vector<N>(1, n));
    for (uint32 i = 0; i < combos.size(); i++) {
      newCombos[i].insert(newCombos[i].end(), combos[i].begin(), combos[i].end());
    }
    results.insert(results.end(), newCombos.begin(), newCombos.end());
  }
  return results;
}

template <typename N>
bool fpEqual(N f1, N f2) {
  return (fabs(f1 - f2) <= numeric_limits<N>::epsilon() * fmax(fabs(f1), fabs(f2)));
}

template <typename N>
bool isIntegral(N n) {
  N m;
  n = modf(n, &m);
  return abs(n) < std::numeric_limits<N>::epsilon();
}
