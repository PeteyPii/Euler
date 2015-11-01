/*******************************************************************************

	Name:			Common.h
	Creator: 		Patrick Wrobel
	Date:			May 5th, 2014
	Description:	Common functions to be shared among multiple problems

*******************************************************************************/

#ifndef COMMON_H
#define COMMON_H

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <chrono>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/*******************************************************************************

	  _____               _                     _    _
	 |  __ \             | |                   | |  (_)
	 | |  | |  ___   ___ | |  __ _  _ __  __ _ | |_  _   ___   _ __   ___
	 | |  | | / _ \ / __|| | / _` || '__|/ _` || __|| | / _ \ | '_ \ / __|
	 | |__| ||  __/| (__ | || (_| || |  | (_| || |_ | || (_) || | | |\__ \
	 |_____/  \___| \___||_| \__,_||_|   \__,_| \__||_| \___/ |_| |_||___/


*******************************************************************************/

typedef		uint8_t		uint8;
typedef		int8_t		int8;
typedef		uint16_t	uint16;
typedef		int16_t		int16;
typedef		uint32_t	uint32;
typedef		int32_t		int32;
typedef		uint64_t	uint64;
typedef		int64_t		int64;

using namespace std;

const double PI			= 3.14159265358979;
const double SQRT_2		= 1.41421356237310;

class ScopeTimer
{
public:
	ScopeTimer(string name, bool isVerbose = true);
	~ScopeTimer();

	int64 getElapsedMilliseconds() const;

private:
	chrono::high_resolution_clock::time_point m_t0;
	string m_sName;
	bool m_bIsVerbose;
};

class BigInteger
{
private:
	template <typename N>
	void init(N n)
	{
		if(m_nBase < 2)
		{
			throw string("Bad base for big integer");
			m_nBase = 0;
		}

		if(n < 0)
		{
			m_bIsNegative = true;
		}

		int32 i = 0;
		while(n != 0)
		{
			m_vnDigits[i] = n % m_nBase;
			n /= m_nBase;
			m_vnDigits.push_back(0);
			i++;
		}

		trimZeros();
	}

public:
	template <typename N>
	explicit BigInteger(N n, uint8 base = 10) :
	 	m_nBase(base),
		m_vnDigits(1, 0),
		m_bIsNegative(false)
	{
		init(n);
	}
	BigInteger() :
		BigInteger(0)
	{
	}

	~BigInteger();

	int32 numberOfDigits() const;
	uint8 getNthDigitFromRight(int32 n) const;	// n is zero based
	uint8 getNthDigitFromLeft(int32 n) const;	// n is zero based
	bool isZero() const;
	int32 sumOfDigits() const;
	int32 productOfDigits() const;
	bool isPalindrome() const;
	BigInteger reverse() const;
	BigInteger convertToBase(uint8 base) const;


	BigInteger operator+(const BigInteger& obj) const;
	BigInteger& operator+=(const BigInteger& obj)
	{
		return *this = *this + obj;
	}
	template <typename N>
	BigInteger operator+(const N& n) const
	{
		return *this + BigInteger(n, m_nBase);
	}
	template <typename N>
	BigInteger& operator+=(const N& n)
	{
		return *this += BigInteger(n, m_nBase);
	}

	BigInteger operator*(const BigInteger& obj) const;
	BigInteger& operator*=(const BigInteger& obj)
	{
		return *this = *this * obj;
	}
	template <typename N>
	BigInteger operator*(const N& n) const
	{
		return (*this) * BigInteger(n, m_nBase);
	}
	template <typename N>
	BigInteger& operator*=(const N& n)
	{
		return *this *= BigInteger(n, m_nBase);
	}

	bool operator==(const BigInteger& obj) const;
	template <typename N>
	bool operator==(const N& n) const
	{
		return *this == BigInteger(n, m_nBase);
	}
	bool operator!=(const BigInteger& obj) const
	{
		return !(*this == obj);
	}
	template <typename N>
	bool operator!=(const N& n) const
	{
		return *this != BigInteger(n, m_nBase);
	}
	bool operator<(const BigInteger& obj) const;
	template <typename N>
	bool operator<(const N& n) const
	{
		return *this < BigInteger(n, m_nBase);
	}
	bool operator>(const BigInteger& obj) const
	{
		return obj < *this;
	}
	template <typename N>
	bool operator>(const N& n) const
	{
		return *this < BigInteger(n, m_nBase);
	}
	bool operator<=(const BigInteger& obj) const
	{
		return !(*this > obj);
	}
	template <typename N>
	bool operator<=(const N& n) const
	{
		return !(*this > BigInteger(n, m_nBase));
	}
	bool operator>=(const BigInteger& obj) const
	{
		return !(*this < obj);
	}
	template <typename N>
	bool operator>=(const N& n) const
	{
		return !(*this < BigInteger(n, m_nBase));
	}

	BigInteger operator|(const BigInteger& obj) const;
	BigInteger& operator|=(const BigInteger& obj)
	{
		return *this = *this | obj;
	}
	template <typename N>
	BigInteger operator|(const N& n) const
	{
		return *this | BigInteger(n, m_nBase);
	}
	template <typename N>
	BigInteger& operator|=(const N& n) const
	{
		return *this |= BigInteger(n, m_nBase);
	}

	BigInteger operator&(const BigInteger& obj) const;
	BigInteger& operator&=(const BigInteger& obj)
	{
		return *this = *this & obj;
	}
	template <typename N>
	BigInteger operator&(const N& n) const
	{
		return *this & BigInteger(n, m_nBase);
	}
	template <typename N>
	BigInteger& operator&=(const N& n) const
	{
		return *this &= BigInteger(n, m_nBase);
	}

	BigInteger operator^(const BigInteger& obj) const;
	BigInteger& operator^=(const BigInteger& obj)
	{
		return *this = *this ^ obj;
	}
	template <typename N>
	BigInteger operator^(const N& n) const
	{
		return *this ^ BigInteger(n, m_nBase);
	}
	template <typename N>
	BigInteger& operator^=(const N& n) const
	{
		return *this ^= BigInteger(n, m_nBase);
	}

	BigInteger operator<<(int32 n) const;
	BigInteger operator>>(int32 n) const;

	friend ostream& operator<<(ostream& out, const BigInteger& n);
	friend istream& operator>>(istream& in,  BigInteger& n);

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
bool operator<(const N& n, const BigInteger& right)
{
	return right > n;
}

template <typename N>
bool operator<=(const N& n, const BigInteger& right)
{
	return right >= n;
}

template <typename N>
bool operator>(const N& n, const BigInteger& right)
{
	return right < n;
}

template <typename N>
bool operator>=(const N& n, const BigInteger& right)
{
	return right <= n;
}

void sieveOfErotosthenes(int64 n, vector<bool>& isPrime);
bool verifySieve(int64 n);
bool isPalindrome(int32 n, int32 base = 10);
void assertFileOpened(const ifstream& fin);
bool isLeapYear(int32 year);
void printProgress(uint64 current, uint64 total, int32 intervals);
double logarithmicIntegralApprox(double x, int32 iterations = 50);

template <typename N>
N stringToNumber(string s)
{
	stringstream ss;
	ss << s;
	N n;
	ss >> n;
	return n;
}

template <typename N>
N stringToNumber(char c)
{
	if(c >= '0' && c <= '9')
	{
		return N(c - '0');
	}
	else if(c >= 'a' && c <= 'z')
	{
		return N(c - 'a');
	}
	else if(c >= 'A' && c <= 'Z')
	{
		return N(c - 'A');
	}
	else
	{
		return N(c);
	}
}

template <typename N>
string numberToString(N n)
{
	stringstream ss;
	ss << n;
	return ss.str();
}

template <typename N>
N sumOfDigits(N n)
{
	N sum = 0;
	while(n != 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

template <typename N>
N productOfDigits(N n)
{
	N product = 1;
	while(n != 0)
	{
		product *= n % 10;
		n /= 10;
		if(product == 0)
		{
			break;
		}
	}
	return product;
}

template <typename T>
inline T minVal(const T& a, const T& b)
{
	return a < b ? a : b;
}

template <typename T>
inline T maxVal(const T& a, const T& b)
{
	return b < a ? a : b;
}

template <typename N>
N gcd(N a, N b)
{
	while (b != N(0))
	{
		N temp = b;
		b = a % b;
		a = temp;
	}

	return a;
}

template <typename N>
bool isNumberPrime(N n)
{
	if(n < 2)
	{
		return false;
	}

	if(n % 2 == 0 && n != 2)
	{
		return false;
	}

	N div = 3;
	while(div * div <= n)
	{
		if(n % div == 0)
		{
			return false;
		}

		div += 2;
	}

	return true;
}

template <typename N>
string getEnglishWordFromNumber(N n)
{
	const string singles[] = {
		"",
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine"
	};

	const string teens[] = {
		"ten",
		"eleven",
		"twelve",
		"thirteen",
		"fourteen",
		"fifteen",
		"sixteen",
		"seventeen",
		"eighteen",
		"nineteen"
	};

	const string tens[] = {
		"",
		"",
		"twenty",
		"thirty",
		"forty",
		"fifty",
		"sixty",
		"seventy",
		"eighty",
		"ninety"
	};

	const string triplets[] = {
		"",
		"thousand",
		"million",
		"billion",
		"trillion",
		"quadrillion",
		"quintillion"
	};

	if(n == 0)
	{
		return "zero";
	}

	string prefix = "";
	string suffix = "";

	if(n < 0)
	{
		prefix += "negative ";
		n *= -1;
	}

	int32 c = 0;
	while(n > 0)
	{
		string temp = "";
		int32 x = n % 1000;
		int32 triDigit = x / 100;
		int32 duoDigit = (x % 100) / 10;
		int32 monoDigit = x % 10;

		if(triDigit)
		{
			temp += singles[triDigit] + " hundred";
		}

		if(triDigit && (duoDigit || monoDigit))
		{
			temp += " and ";
		}

		if(duoDigit || monoDigit)
		{
			temp += tens[duoDigit];

			if(duoDigit > 1 && monoDigit)
			{
				temp += "-" + singles[monoDigit];
			}
			else if(duoDigit == 1)
			{
				temp += teens[monoDigit];
			}
			else // duoDigit == 0
			{
				temp += singles[monoDigit];
			}
		}

		if(c > 0)
		{
			temp += " " + triplets[c];
		}

		suffix = temp + suffix;
		n /= 1000;
		c++;
	}

	return prefix + suffix;
}

template <typename N>
N sumOfDivisors(N n)
{
	if(n < 1)
	{
		throw string("Cannot find divisors of numbers less than 1");
		return -1;
	}

	if(n == 1)
	{
		return 0;
	}

	N sum = 1;
	for(N i = 2; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			sum += i;

			if(i * i != n)
			{
				sum += n / i;
			}
		}
	}

	return sum;
}

template <typename N>
N factorial(N n)
{
	if(n < 0)
	{
		throw string("Cannot do factorial of negative number");
		return N(-1);
	}

	N product(1);
	for(int32 i = 2; i <= n; i++)
	{
		product *= i;
	}

	return product;
}

template<typename T>
size_t make_hash(const T& v)
{
    return hash<T>()(v);
}

// adapted from boost::hash_combine
inline void hash_combine(size_t& h, const size_t& v)
{
    h ^= v + 0x9e3779b9 + (h << 6) + (h >> 2);
}

template<typename T>
struct hash_container
{
    size_t operator()(const T& v) const
    {
        size_t h = 0;
        for(typename T::const_iterator i = v.cbegin(); i != v.cend(); i++)
        {
            hash_combine(h, make_hash(*i));
        }

        return h;
    }
};

namespace std
{
    template<typename T, typename U>
    struct hash<pair<T, U>>
    {
        size_t operator()(const pair<T,U>& v) const
        {
            size_t h=make_hash(v.first);
            hash_combine(h, make_hash(v.second));
            return h;
        }
    };

	template<typename T>
	struct hash<vector<T>> : hash_container<vector<T>> {};

	template<typename T, typename U>
	struct hash<map<T, U>> : hash_container<map<T, U>> {};
}

template<typename T>
T vectorSum(const vector<T>& v)
{
	return accumulate(v.cbegin(), v.cend(), T(0));
}

template<typename T>
T vectorProduct(const vector<T>& v)
{
	return accumulate(v.cbegin(), v.cend(), T(1), [] (T product, T item) -> T { return product * item; });
}

template<typename T>
T setSum(const set<T>& s)
{
	return accumulate(s.cbegin(), s.cend(), T(0));
}

template <typename N>
bool isPandigital(N n)
{
	string s = numberToString(n);

	sort(s.begin(), s.end());

	char c = s[0];
	for(uint32 i = 1; i < s.length(); i++)
	{
		if(c + 1 != s[i])
		{
			return false;
		}

		c++;
	}

	return true;
}

template <typename T, typename U>
T power(T x, U y)
{
	// Computes x^y
	T product(1);
	while(y > 0)
	{
		if((y & 1) == 1)
		{
			product *= x;
		}

		y >>= 1;
		x *= x;
	}

	return product;
}

template <typename T, typename U, typename V>
T modPower(T x, U y, V m)
{
	// Computes x^y mod m
	T product(1);
	x %= m;
	while(y > 0)
	{
		if((y & 1) == 1)
		{
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
bool assertEquality(N a, T b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		cout << "BAD! " << a << " != " << b << endl;
		return false;
	}
}

template <typename R, typename... Args>
function<R (Args...)> memoized(R (*fn)(Args...))
{
	map<tuple<Args...>, R> memory;
	return [fn, memory] (Args... args) mutable -> R
	{
		auto argt = make_tuple(args...);
		auto it = memory.find(argt);
		if(it == memory.end())
		{
			it = memory.insert(make_pair(argt, fn(args...))).first;
		}

		return it->second;
	};
}

template <typename N>
void totientValues(N n, vector<N>& values)
{
	vector<vector<N>> sieve(n + 1);
	for(N i = 2; i <= n; i++)
	{
		if(sieve[i].size() > 0)
		{
			continue;
		}

		for(N j = i; j <= n; j += i)
		{
			sieve[j].push_back(i);
		}
	}

	values = vector<N>(n + 1);

	values[0] = 0;
	values[1] = 1;

	for(N i = 2; i <= n; i++)
	{
		N totientVal = i;
		for(N primeDivisor : sieve[i])
		{
			totientVal /= primeDivisor;
			totientVal *= primeDivisor - 1;
		}

		values[i] = totientVal;
	}
}


#endif
