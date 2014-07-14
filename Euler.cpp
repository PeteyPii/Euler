/*******************************************************************************

	Name:			Euler.cpp
	Creator: 		Patrick Wrobel
	Date:			May 5th, 2014
	Description:	Solutions to the problems on Project Euler

*******************************************************************************/

#pragma warning( push )
#pragma warning( disable : 4244 )	// conversion, possible loss of data
#pragma warning( disable : 4018 )	// signed/unsigned mismatch

#include "Euler.h"

#include "Common.h"

using namespace std;

/*******************************************************************************

						  __  __           _
						 |  \/  |         (_)
						 | \  / |   __ _   _   _ __
						 | |\/| |  / _` | | | | '_ \
						 | |  | | | (_| | | | | | | |
						 |_|  |_|  \__,_| |_| |_| |_|


*******************************************************************************/

int32 main(int32 argc, const char **argv)
{
	ScopeTimer timer("Runtime");
	try
	{
		cout << problem30(5) << endl;
		return 0;
	}
	catch(string e)
	{
		cout << "An exception has been thrown:" << endl;
		cout << "  " << e << endl;
		return 1;
	}
	catch(...)
	{
		cout << "An unknown exception has been thrown." << endl;
		return 2;
	}
}

/*******************************************************************************

			  ______                    _    _
			 |  ____|                  | |  (_)
			 | |__  _   _  _ __    ___ | |_  _   ___   _ __   ___
			 |  __|| | | || '_ \  / __|| __|| | / _ \ | '_ \ / __|
			 | |   | |_| || | | || (__ | |_ | || (_) || | | |\__ \
			 |_|    \__,_||_| |_| \___| \__||_| \___/ |_| |_||___/


*******************************************************************************/

int32 problem1(int32 n)
{
	int32 sum = 0;
	for(int32 i = 0; i < n; i++)
	{
		if(i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
	}

	return sum;
}
int32 problem2(int32 n)
{
	int32 a = 1;
	int32 b = 2;
	int32 sum = 0;
	int32 temp;

	while(b < n)
	{
		sum += b;
		temp = 2 * b + a;
		b = 3 * b + 2* a;
		a = temp;
	}

	return sum;
}
int64 problem3(int64 n)
{
	int64 div = 3;
	int64 max = 0;

	while(n % 2 == 0)
	{
		max = 2;
		n /= 2;
	}

	while(div < n)
	{
		while(n % div != 0)
		{
			div++;
		}
		max = div;
		n /= div;
	}

	return max;
}
int32 problem4(int32 n)
{
	int32 low = pow((double)10, n - 1);
	int32 high = pow((double)10, n);
	int32 max = 0;
	int32 product;

	for(int32 x = low; x < high; x++)
	{
		for(int32 y = low; y < high; y++)
		{
			product = x * y;
			if(product > max && isPalindrome(product))
			{
				max = product;
			}
		}
	}

	return max;
}
int64 problem5(int64 n)
{
	vector<bool> table(n, false);

	int64 multiple = 1;

	for(int32 i = 1; i <= n; i++)
	{
		if(multiple % i == 0)
		{
			continue;
		}

		for(int32 j = 1; j <= i; j++)
		{
			if((j * multiple) % i == 0)
			{
				multiple *= j;
				break;
			}
		}
	}

	return multiple;
}
int64 problem6(int64 n)
{
	int64 sumOfSquares = n * (2 * n + 1) * (n + 1) / 6;
	int64 squareOfSum = n * (n + 1) / 2;
	squareOfSum *= squareOfSum;

	return squareOfSum - sumOfSquares;
}
int64 problem7(int64 n)
{
	const int64 sieveSize = 1e8;
	vector<bool> isPrime;

	sieveOfErotosthenes(sieveSize, isPrime);

	int64 c = 0;

	for(int64 i = 0; i <= sieveSize; i++)
	{
		if(isPrime[i])
		{
			c++;
			if(c == n)
			{
				return i;
			}
		}
	}

	throw string("Sieve too small");

	return -1;
}
int32 problem8(int32 n)
{
	ifstream fin("p8.txt");
	assertFileOpened(fin);

	string full = "", temp;

	while(fin >> temp)
	{
		full += temp;
	}

	int32 max = 0;
	for(int32 i = 0; i <= full.length() - n; i++)
	{
		int32 x = productOfDigits(stringToNumber<int32>(full.substr(i, n)));
		if(x > max)
		{
			max = x;
		}
	}

	return max;
}
int32 problem9()
{
	for(int32 c = 1000; c > 0; c--)
	{
		for(int32 b = 1000 - c; b > 0; b--)
		{

			int32 a = 1000 - c - b;

			if(c * c == b * b + a * a && a != 0)
			{
				return a * b * c;
			}
		}
	}

	throw string("Unable to find a*b*c");

	return -1;
}
int64 problem10(int64 n)
{
	vector<bool> isPrime;
	sieveOfErotosthenes(n, isPrime);
	int64 sum = 0;

	for(int64 i = 0; i <= n; i++)
	{
		if(isPrime[i])
		{
			sum += i;
		}
	}

	return sum;
}
int32 problem11(int32 n, int32 m)
{
	if(n > m)
	{
		throw string("Grid size is less than number of factors");
		return -1;
	}

	ifstream fin("p11.txt");
	assertFileOpened(fin);

	vector<vector<int32> > grid(m, vector<int32>(m, -1));

	for(int32 y = 0; y < m; y++)
	{
		for(int32 x = 0; x < m; x++)
		{
			fin >> grid[x][y];
			if(!fin)
			{
				throw string("Bad file formatting");
				return -1;
			}
		}
	}

	int32 max = 0;
	for(int32 y = 0; y < m; y++)
	{
		for(int32 x = 0; x < m - n + 1; x++)
		{
			int32 product = 1;
			for(int32 i = 0; i < n; i++)
			{
				product *= grid[x + i][y];
			}

			if(product > max)
			{
				max = product;
			}
		}
	}

	for(int32 x = 0; x < m; x++)
	{
		for(int32 y = 0; y < m - n + 1; y++)
		{
			int32 product = 1;
			for(int32 i = 0; i < n; i++)
			{
				product *= grid[x][y + i];
			}

			if(product > max)
			{
				max = product;
			}
		}
	}

	for(int32 x = 0; x < m - n + 1; x++)
	{
		for(int32 y = 0; y < m - n + 1; y++)
		{
			int32 forwardProduct = 1;
			int32 backwardProduct = 1;

			for(int32 i = 0; i < n; i++)
			{
				forwardProduct *= grid[x + i][y + n - 1 - i];
				backwardProduct *= grid[x + i][y + i];
			}

			if(forwardProduct > max)
			{
				max = forwardProduct;
			}

			if(backwardProduct > max)
			{
				max = backwardProduct;
			}
		}
	}

	return max;
}
int64 problem12(int32 n)
{
	if(n < 1)
	{
		return 1;
	}

	for(int32 i = 2; i < INT32_MAX; i++)
	{
		int64 x = i * (i + 1) / 2;
		int32 c = 2;
		for(int32 j = 2; j * j <= x; j++)
		{
			if(x % j == 0)
			{
				c += 2;
			}
		}

		if(c >= n)
		{
			return x;
		}
	}

	throw string("Triangle number too big");

	return -1;
}
string problem13(int32 n)
{
	ifstream fin("p13.txt");
	assertFileOpened(fin);

	BigInteger x(0);
	BigInteger temp;
	while(fin >> temp)
	{
		x += temp;
	}

	stringstream ss;
	ss << x;
	return ss.str();
}
int32 problem14(int32 n)
{
	if(n < 1)
	{
		throw string("Can't do Collatz sequence starting from a number less than 1");
		return -1;
	}

	if(n == 1)
	{
		return 1;
	}

	if(n == 2)
	{
		return 2;
	}

	int32 maxLength = 0;
	int32 maxNumber = 0;

	for(int32 i = 2; i < n; i++)
	{
		int64 term = i;
		int32 c = 1;
		while(term != 1)
		{
			if(term % 2 == 0)
			{
				term /= 2;
			}
			else
			{
				term = 3 * term + 1;
			}
			c++;
		}

		if(c > maxLength)
		{
			maxLength = c;
			maxNumber = i;
		}
	}

	return maxNumber;
}
int64 problem15(int32 n, int32 m)
{
	if(n < 1 || m < 1)
	{
		throw string("Invalid grid size for lattice paths");
		return -1;
	}

	vector<vector<int64> > paths(n + 1, vector<int64>(m + 1, 0));
	paths[0][0] = 1;

	for(int32 x = 0; x <= n; x++)
	{
		for(int32 y = 0; y <= m; y++)
		{
			if(x != 0)
			{
				paths[x][y] += paths[x - 1][y];
			}
			if(y != 0)
			{
				paths[x][y] += paths[x][y - 1];
			}
		}
	}

	return paths[n][m];
}
int32 problem16(int32 n)
{
	if(n < 0)
	{
		throw string("Negative exponent not implemented yet");
		return -1;
	}

	BigInteger x(1);
	for(int32 i = 0; i < n; i++)
	{
		x = x + x;
	}

	return x.sumOfDigits();
}
int32 problem17(int32 n)
{
	if(n < 0)
	{
		return 0;
	}

	int32 sum = 0;
	for(int32 i = 1; i <= n; i++)
	{
		string temp = getEnglishWordFromNumber(i);
		temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
		temp.erase(remove(temp.begin(), temp.end(), '-'), temp.end());
		sum += temp.size();
	}

	return sum;
}
int32 problem18(int32 n)
{
	ifstream fin("p18.txt");
	assertFileOpened(fin);

	vector<vector<int32> > triangle;
	for(int32 i = 0; i < n; i++)
	{
		triangle.push_back(vector<int32>());
		for(int32 j = 0; j <= i; j++)
		{
			int32 temp;
			fin >> temp;
			triangle[i].push_back(temp);

			if(!fin)
			{
				throw string("Bad file formatting of triangle");
				return -1;
			}
		}
	}

	if(n < 1)
	{
		throw string("Cannot have a triangle that has less than one row");
		return -1;
	}

	for(int32 i = 1; i < n; i++)
	{
		for(int32 j = 0; j <= i; j++)
		{
			if(j == 0)
			{
				triangle[i][0] += triangle[i - 1][0];
			}
			else if(j == i)
			{
				triangle[i][j] += triangle[i - 1][j - 1];
			}
			else
			{
				triangle[i][j] += maxVal(triangle[i - 1][j - 1], triangle[i - 1][j]);
			}
		}
	}

	int32 max = triangle[0][0];
	for(int32 i = 0; i < n; i++)
	{
		if(triangle[n - 1][i] > max)
		{
			max = triangle[n - 1][i];
		}
	}

	return max;
}
int32 problem19(int32 n)
{
	if(n <= 1900)
	{
		throw string("Cannot count backwards in time");
		return - 1;
	}

	int32 year = 1901;
	int32 month = 0;
	int32 day = 0;

	const int32 days[] = {
		31,
		28,
		31,
		30,
		31,
		30,
		31,
		31,
		30,
		31,
		30,
		31
	};

	int32 totalSundays = 0;
	int32 totalDays = 1;

	while(year <= n)
	{
		while(month < 12)
		{
			if(totalDays % 7 == 6)
			{
				totalSundays++;
			}

			while(day < days[month])
			{
				day++;
				totalDays++;
			}

			if(isLeapYear(year) && month == 1)
			{
				day++;
				totalDays++;
			}

			month++;
			day = 0;
		}

		year++;
		month = 0;
	}

	return totalSundays;
}
int32 problem20(int32 n)
{
	if(n == 0)
	{
		return 1;
	}

	if(n < 0)
	{
		throw string("We shouldn't take the factorial of a negative number");
		return -1;
	}

	BigInteger x(1);
	for(int32 i = 1; i <= n; i++)
	{
		x *= i;
		cout << x << endl;
	}

	return x.sumOfDigits();
}
int32 problem21(int32 n)
{
	if(n < 1)
	{
		throw string("Cannot find amicable numbers less than 1");
		return -1;
	}

	if(n == 1)
	{
		return 0;
	}

	int32 sum = 0;
	for(int32 i = 1; i < n; i++)
	{
		int32 x = sumOfDivisors(i);

		if(x != i && sumOfDivisors(x) == i)
		{
			sum += i;
		}
	}

	return sum;
}
int64 problem22()
{
	ifstream fin("p22.txt");
	assertFileOpened(fin);

	string temp;
	vector<string> names;
	while(fin >> temp)
	{
		names.push_back(temp);
	}

	sort(names.begin(), names.end());

	int64 totalScore = 0;
	for(int32 i = 0; i < names.size(); i++)
	{
		string& name = names[i];
		int32 sum = 0;
		for(int32 j = 0; j < name.size(); j++)
		{
			sum += name[j] - 'A' + 1;
		}

		totalScore += sum * (i + 1);
	}

	return totalScore;
}
int32 problem23()
{
	vector<int32> abundantNumbers;
	for(int32 i = 1; i <= 28123; i++)
	{
		if(sumOfDivisors(i) > i)
		{
			abundantNumbers.push_back(i);
		}
	}

	vector<bool> hasSum(28123 + 1, false);
	for(int32 i = 0; i < abundantNumbers.size() && abundantNumbers[i] * 2 <= 28123; i++)
	{
		for(int32 j = i; j < abundantNumbers.size(); j++)
		{
			if(abundantNumbers[i] + abundantNumbers[j] > 28123)
			{
				break;
			}

			hasSum[abundantNumbers[i] + abundantNumbers[j]] = true;
		}
	}

	int32 sum = 0;
	for(int32 i = 1; i <= 28123; i++)
	{
		if(!hasSum[i])
		{
			sum += i;
		}
	}

	return sum;
}
string problem24(int32 n)
{
	if(n < 1)
	{
		throw string("Can't find the zero-th permuatation or a negative permutation");
		return "-1";
	}

	if(n > factorial(10))
	{
		throw string("Can't find the zero-th permuatation or a negative permutation");
		return "-1";
	}

	vector<char> digits(10);
	for(int32 i = 0; i < 10; i++)
	{
		digits[i] = '0' + i;
	}

	n--;

	stringstream ss;
	for(int32 i = 10; i > 0; i--)
	{
		int32 f = factorial(i - 1);
		ss << digits[n / f];
		digits.erase(digits.begin() + (n / f));
		n %= f;
	}

	return ss.str();
}
int32 problem25(int32 n)
{
	if(n < 1)
	{
		throw string("A number cannot be less than one digit long");
		return -1;
	}

	if(n == 1)
	{
		return 1;
	}

	int32 c = 2;
	BigInteger a(1);
	BigInteger b(1);
	BigInteger temp;

	while(b.numberOfDigits() < n)
	{
		temp = b;
		b = a + b;
		a = temp;
		c++;
	}

	return c;
}
int32 problem26(int32 n)
{
	if(n < 1)
	{
		throw string("Bad number for counting reciprocal decimal digit period");
		return -1;
	}

	if(n == 1)
	{
		return 1;
	}

	int32 highestRepeater = 1;
	int32 highestPeriod = -1;

	for (int32 i = n; i > highestPeriod; i--)
	{
		int32 remainder = 1;
		vector<bool> hasSeen(i, false);
		vector<int32> whenSeen(i, -1);

		int32 c = 0;
		while(true)
		{
			int32 ix = remainder;
			if(hasSeen[ix])
			{
				break;
			}

			hasSeen[ix] = true;
			whenSeen[ix] = c;
			c++;
			remainder = (10 * remainder) % i;
		}

		int32 period = c - whenSeen[remainder];
		if(period > highestPeriod)
		{
			highestPeriod = period;
			highestRepeater = i;
		}
	}

	return highestRepeater;
}
int32 problem27(int32 n)
{
	if(n < 1)
	{
		throw string("Bad restrictions on a and b (they belong to an empty set)");
		return -1;
	}

	if(n == 1)
	{
		return 0;
	}

	if(n == 2)
	{
		// Every permutation does not generate any primes, so let's say a = b = 0
		return 0;
	}

	vector<bool> isPrime;
	sieveOfErotosthenes(n, isPrime);

	int32 bestA = 0;
	int32 bestB = 0;
	int32 bestPrimeCount = 0;

	for(int32 b = 0; b < n; b++)
	{
		if(!isPrime[b])
		{
			continue;
		}

		for(int32 a = 1 + (b == 2 ? -1 : 0); a < n; a += 2)
		{
			int32 x = 0;
			while(isNumberPrime(x * x + a * x + b))
			{
				x++;
			}

			if(x > bestPrimeCount)
			{
				bestPrimeCount = x;
				bestA = a;
				bestB = b;
			}
		}

		for(int32 a = 0; a < n; a++)
		{
			int32 x = 0;
			while(isNumberPrime(x * x - a * x + b))
			{
				x++;
			}

			if(x > bestPrimeCount)
			{
				bestPrimeCount = x;
				bestA = -a;
				bestB = b;
			}
		}
	}

	cout << bestA << endl;
	cout << bestB << endl;
	cout << bestPrimeCount << endl;

	return bestA * bestB;
}
int32 problem28(int32 n)
{
	if(n < 1)
	{
		throw string("Cannot have a spiral with a width less than one");
		return -1;
	}

	if(n % 2 == 0)
	{
		throw string("Spiral with even side length is undefined");
		return -1;
	}

	int32 x = (n - 1) / 2;
	return 4 * (4 * x * x * x + 12 * x * x + 11 * x + 3) / 3 - 6 * x * (x + 1) - 3;
}
int32 problem29(int32 n)
{
	if(n < 2)
	{
		throw string("A number cannot be at least 2 and less than 2 at the same time");
		return -1;
	}

	vector<vector<int32> > primeFactor(n + 1, vector<int32>(n + 1, 0));
	for(int32 i = 2; i <= n; i++)
	{
		int32 remainder = i;
		int32 j = 2;

		while(j <= remainder)
		{
			if(remainder % j == 0)
			{
				primeFactor[i][j]++;
				remainder /= j;
				j = 2;
			}
			else
			{
				j++;
			}
		}
	}

	unordered_set<vector<int32> > uniqueValues;
	for(int32 a = 2; a <= n; a++)
	{
		for(int32 b = 2; b <= n; b++)
		{
			vector<int32> factors = primeFactor[a];
			for(int32 i = 0; i < factors.size(); i++)
			{
				factors[i] *= b;
			}

			uniqueValues.insert(factors);
		}
	}

	return uniqueValues.size();
}
int32 problem30(int32 n)
{
	if(n < 0)
	{
		throw string("Negative powers of digits is uninteresting; result is 0");
		return 0;
	}

	if(n == 0)
	{
		return 0;
	}

	if(n == 1)
	{
		return 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9;
	}

	int32 maxDigits = 1;
	double nLogNine = n * log10(9.0);
	while(nLogNine >= maxDigits - log10(static_cast<double>(maxDigits)))
	{
		maxDigits++;
	}

	vector<int32> cachedPowers(10);
	for(int32 i = 0; i < 10; i++)
	{
		cachedPowers[i] = pow(static_cast<double>(i), n);
	}

	int32 iterationCount = 10;
	for(int32 i = 11; i < 10 + maxDigits; i++)
	{
		iterationCount *= i;
	}

	iterationCount /= factorial(maxDigits);

	vector<int32> goodNumbers;
	vector<int32> sortedNumber(maxDigits, 0);
	for(int32 i = 0; i < iterationCount; i++)
	{
		int32 sum = 0;
		for(int32 j = 0; j < sortedNumber.size(); j++)
		{
			sum += cachedPowers[sortedNumber[j]];
		}

		int32 tempSum = sum;
		if(sum > 1)
		{
			vector<int32> sortedSum(maxDigits);
			for(int32 j = 0; j < sortedSum.size(); j++)
			{
				sortedSum[j] = tempSum % 10;
				tempSum /= 10;
			}

			sort(sortedSum.begin(), sortedSum.end());

			if(sortedNumber == sortedSum)
			{
				goodNumbers.push_back(sum);
			}
		}

		int32 ix = sortedNumber.size() - 1;
		while(sortedNumber[ix] == 9)
		{
			ix--;
			if(ix < 0)
			{
				ix = 0;
				break;
			}
		}

		sortedNumber[ix]++;
		if(sortedNumber[ix] == 10)
		{
			sortedNumber[ix] = 0;
		}

		for(int32 j = ix + 1; j < sortedNumber.size(); j++)
		{
			sortedNumber[j] = sortedNumber[ix];
		}
	}

	return vectorSum(goodNumbers);
}

#pragma warning( pop )
