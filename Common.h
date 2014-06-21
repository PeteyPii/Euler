/*******************************************************************************

	Name:			Common.h
	Creator: 		Patrick Wrobel
	Date:			May 5th, 2014
	Description:	Common functions to be shared among multiple problems

*******************************************************************************/

#pragma once

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

#ifndef _MSC_VER
#include <chrono>
#endif

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

#ifndef _MSC_VER

class ScopeTimer
{
public:
	ScopeTimer(string name);
	~ScopeTimer();

private:
	chrono::high_resolution_clock::time_point m_t0;
	string m_sName;
};

#else

class ScopeTimer
{
public:
	ScopeTimer(string name);
	~ScopeTimer();
};

#endif

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
			n *= -1;
		}

		int32 i = 0;
		while(n > 0)
		{
			m_vnDigits[i] = n % m_nBase;
			n /= m_nBase;
			m_vnDigits.push_back(0);
			i++;
		}

		trimZeros();
	}

public:

#ifndef _MSC_VER

	template <typename N>
	BigInteger(N n, uint8 base = 10) :
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

#else

	template <typename N>
	BigInteger(N n, uint8 base = 10) :
	 	m_nBase(base),
		m_vnDigits(1, 0),
		m_bIsNegative(false)
	{
		init(n);
	}
	BigInteger() :
		m_nBase(10),
		m_vnDigits(1, 0),
		m_bIsNegative(false)
	{
		init(0);
	}

#endif

	~BigInteger();

	int32 numberOfDigits() const;
	uint8 getNthDigitFromRight(int32 n) const;	// n is zero based
	uint8 getNthDigitFromLeft(int32 n) const;	// n is zero based
	bool isZero() const;
	int32 sumOfDigits() const;
	int32 productOfDigits() const;


	BigInteger operator+(const BigInteger& obj) const;
	BigInteger& operator+=(const BigInteger& obj);
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
	BigInteger& operator*=(const BigInteger& obj);
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

	friend ostream& operator<<(ostream& out, const BigInteger& n);
	friend istream& operator>>(istream& in,  BigInteger& n);

private:
	uint8 m_nBase;
	vector<uint8> m_vnDigits;
	bool m_bIsNegative;

	void assertSameBase(const BigInteger& a, const BigInteger& b) const;
	void trimZeros();

	BigInteger& operator/(const BigInteger& n);
	BigInteger& operator/=(const BigInteger& n);

	BigInteger& operator-(const BigInteger& n);
	BigInteger& operator-=(const BigInteger& n);
};

void sieveOfErotosthenes(int64 n, vector<bool>& isPrime);
bool verifySieve(int64 n);
bool isPalindrome(int32 n);
void assertFileOpened(const ifstream& fin);
bool isLeapYear(int32 year);
void printProgress(uint64 current, uint64 total, int32 intervals);


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
	return a > b ? a : b;
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
	for(int32 i = 2; i * i <= n; i++)
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
N factorial(int32 n)
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