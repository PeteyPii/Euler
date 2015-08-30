/*******************************************************************************

	Name:			Euler.cpp
	Creator: 		Patrick Wrobel
	Date:			May 5th, 2014
	Description:	Solutions to the problems on Project Euler

*******************************************************************************/

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4244 )	// conversion, possible loss of data
#pragma warning( disable : 4018 )	// signed/unsigned mismatch
#endif

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

template <typename N, typename T>
bool checkEquality(N a, T b)
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

void verifyResults(int32 begin, int32 end)
{
	typedef bool (*fpCheck)();
	const fpCheck checks[] =
	{
		[] () -> bool { return true; },

		[] () -> bool { return checkEquality(problem1(1000), 233168); },
		[] () -> bool { return checkEquality(problem2(4000000), 4613732); },
		[] () -> bool { return checkEquality(problem3(600851475143), 6857); },
		[] () -> bool { return checkEquality(problem4(3), 906609); },
		[] () -> bool { return checkEquality(problem5(20), 232792560); },

		[] () -> bool { return checkEquality(problem6(100), 25164150); },
		[] () -> bool { return checkEquality(problem7(10001), 104743); },
		[] () -> bool { return checkEquality(problem8(13), 23514624000); },
		[] () -> bool { return checkEquality(problem9(), 31875000); },
		[] () -> bool { return checkEquality(problem10(2000000), 142913828922); },

		[] () -> bool { return checkEquality(problem11(4, 20), 70600674); },
		[] () -> bool { return checkEquality(problem12(500), 76576500); },
		[] () -> bool { return checkEquality(problem13(10), "5537376230"); },
		[] () -> bool { return checkEquality(problem14(1000000), 837799); },
		[] () -> bool { return checkEquality(problem15(20, 20), 137846528820); },

		[] () -> bool { return checkEquality(problem16(1000), 1366); },
		[] () -> bool { return checkEquality(problem17(1000), 21124); },
		[] () -> bool { return checkEquality(problem18(15), 1074); },
		[] () -> bool { return checkEquality(problem19(2000), 171); },
		[] () -> bool { return checkEquality(problem20(100), 648); },

		[] () -> bool { return checkEquality(problem21(10000), 31626); },
		[] () -> bool { return checkEquality(problem22(), 871198282); },
		[] () -> bool { return checkEquality(problem23(), 4179871); },
		[] () -> bool { return checkEquality(problem24(1000000), "2783915460"); },
		[] () -> bool { return checkEquality(problem25(1000), 4782); },

		[] () -> bool { return checkEquality(problem26(1000), 983); },
		[] () -> bool { return checkEquality(problem27(1000), -59231); },
		[] () -> bool { return checkEquality(problem28(1001), 669171001); },
		[] () -> bool { return checkEquality(problem29(100), 9183); },
		[] () -> bool { return checkEquality(problem30(5), 443839); },

		[] () -> bool { return checkEquality(problem31(200), 73682); },
		[] () -> bool { return checkEquality(problem32(), 45228); },
		[] () -> bool { return checkEquality(problem33(), 100); },
		[] () -> bool { return checkEquality(problem34(), 40730); },
		[] () -> bool { return checkEquality(problem35(1000000), 55); },

		[] () -> bool { return checkEquality(problem36(1000000), 872187); },
		[] () -> bool { return checkEquality(problem37(), 748317); },
		[] () -> bool { return checkEquality(problem38(), 932718654); },
		[] () -> bool { return checkEquality(problem39(1000), 840); },
		[] () -> bool { return checkEquality(problem40(6), 210); },

		[] () -> bool { return checkEquality(problem41(), 7652413); },
		[] () -> bool { return checkEquality(problem42(), 162); },
		[] () -> bool { return checkEquality(problem43(), 16695334890); },
		[] () -> bool { return checkEquality(problem44(), 5482660); },
		[] () -> bool { return checkEquality(problem45(1), 1533776805); },

		[] () -> bool { return checkEquality(problem46(1), 5777); },

		[] () -> bool { return false; }
	};

	if (end - begin + 1 > 0)
	{
		int64 total = 0;
		int64 maxTime = -1;
		int32 maxProblem = -1;

		for (int32 i = begin; i <= end; i++)
		{
			ScopeTimer timer("", false);
			try
			{
				if (checks[i]())
				{
					cout << "Problem " << i << " SUCCEEDED! ";
				}
				else
				{
					cout << "Problem " << i << " FAILED! ";
				}
			}
			catch(const string& e)
			{
				cout << "BAD! An excpetion was thrown: " << e << endl;
				cout << "Problem " << i << " FAILED! ";
			}
			catch(...)
			{
				cout << "BAD! An unknown excpetion was thrown" << endl;
				cout << "Problem " << i << " FAILED! ";
			}

			int64 elapsed = timer.getElapsedMilliseconds();
			cout << "(" << elapsed << " ms)" << endl;
			total += elapsed;

			if (elapsed > maxTime)
			{
				maxTime = elapsed;
				maxProblem = i;
			}
		}

		cout << "Total time: " << total << " ms" << endl;
		cout << "Average time: " << total / (end - begin + 1) << " ms" << endl;
		cout << "Worst time: " << maxTime << " ms (problem " << maxProblem << ")" << endl;
	}
}

int32 main(int32 argc, const char **argv)
{
	try
	{
		verifyResults(46, 46);

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
int64 problem8(int32 n)
{
	ifstream fin("p8.txt");
	assertFileOpened(fin);

	string full = "", temp;

	while(fin >> temp)
	{
		full += temp;
	}

	int64 max = 0;
	for(uint32 i = 0; i <= full.length() - n; i++)
	{
		int64 x = productOfDigits(stringToNumber<int64>(full.substr(i, n)));
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
	return ss.str().substr(0, n);
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
	// start at 2 since 1 isn't an amicable number
	for(int32 i = 2; i < n; i++)
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
	for(uint32 i = 0; i < names.size(); i++)
	{
		string& name = names[i];
		uint32 sum = 0;
		for(uint32 j = 0; j < name.size(); j++)
		{
			sum += name[j] - 'A' + 1;
		}

		totalScore += static_cast<int64>(sum * (i + 1));
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
	for(uint32 i = 0; i < abundantNumbers.size() && abundantNumbers[i] * 2 <= 28123; i++)
	{
		for(uint32 j = i; j < abundantNumbers.size(); j++)
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
		throw string("Can't find the zero-th permutation or a negative permutation");
		return "-1";
	}

	if(n > factorial(10))
	{
		throw string("Can't find the zero-th permutation or a negative permutation");
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
			for(uint32 i = 0; i < factors.size(); i++)
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
		for(uint32 j = 0; j < sortedNumber.size(); j++)
		{
			sum += cachedPowers[sortedNumber[j]];
		}

		int32 tempSum = sum;
		if(sum > 1)
		{
			vector<int32> sortedSum(maxDigits);
			for(uint32 j = 0; j < sortedSum.size(); j++)
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

		for(uint32 j = ix + 1; j < sortedNumber.size(); j++)
		{
			sortedNumber[j] = sortedNumber[ix];
		}
	}

	return vectorSum(goodNumbers);
}
int32 problem31(int32 n)
{
	if(n < 0)
	{
		throw string("Cannot make a negative amount of money with change");
	}

	vector<int32> generatingFunction;
	map<int32, int32> fps;
	fps[0] = 1;
	vector<int32> coinValues = {1, 2, 5, 10, 20, 50, 100, 200};

	// Let generatingFunction represent a formal power series A(x)
	// Let fps be another formal power series B(x)
	// The problem is a composition problem where parts can be 0. Each part corresponds
	// to the number a certain coin to use and we create a generating function for this
	// tuple of coin counts using the respective coin values as the weight. The generating
	// function is simply 1 / ((1 - x)(1 - x^2)(1 - x^5)...) = 1 / B(x) = A(x) where the x powers
	// are distinct coin values. [x^n] A(x) is then the number of different ways to get n
	// value using a number of each coin. The code goes through the evaluation of B(x) and
	// then its inverse, A(x), to get the coefficient values.

	for(uint32 i = 0; i < coinValues.size(); i++)
	{
		map<int32, int32> tempFps;
		for(auto it = fps.begin(); it != fps.end(); it++)
		{
			tempFps[it->first] += it->second;
			tempFps[it->first + coinValues[i]] -= it->second;
		}
		fps = tempFps;
	}

	generatingFunction.push_back(1);
	auto last = fps.end();
	last--;
	for(int32 i = 1; i < last->first; i++)
	{
		int32 sum = 0;
		for(int32 j = 0; j < i; j++)
		{
			sum += generatingFunction[j] * fps[i - j];
		}
		generatingFunction.push_back(-sum / fps[0]);
	}

	// Note: if n >= sum of all distinct coin values, the function needs to be extended
	// to evalutate the n-th term of a recurrence relation defined by fps
	return generatingFunction[n];
}
int32 problem32()
{
	string permutation = "123456789";
	sort(permutation.begin(), permutation.end());
	set<int32> pandigitalIdentities;

	// Break up every permutation of "123456789" and check if a product is achieved. The first part will be the
	// product and the second part will be split into two factors. The first factor can always be the smallest since
	// we will eventually check the equivalent permutation where that factor is the second one
	do
	{
		int32 product;
		int32 multiplicand;
		int32 multiplier;

		for(int32 j : {1, 2})
		{
			// Product can only be 4 digits since 5 digits is above what can be multiplied to by a total of 4 digits
			// and 3 digits is below what can be multiplied to with a total of 6 digits
			product = stringToNumber<int32>(permutation.substr(0, 4));
			multiplicand = stringToNumber<int32>(permutation.substr(4, j));
			multiplier = stringToNumber<int32>(permutation.substr(4 + j));

			if(product == multiplicand * multiplier)
			{
				pandigitalIdentities.insert(product);
			}
		}
	}
	while(next_permutation(permutation.begin(), permutation.end()));

	return accumulate(pandigitalIdentities.begin(), pandigitalIdentities.end(), 0);
}
int32 problem33()
{
	vector<int32> numerators;
	vector<int32> denominators;

	// After removing two digits the fraction will be i/j where i is in [1, 8]
	// and j is in [1, 9]. The digit we remove is from 1 to 9 and it cannot be
	// from both the ones or both the tens or else it is trvial. So we brute force
	// all these combinations and check them
	for(int32 i = 1; i <= 8; i++)
	{
		for(int32 j = i + 1; j <= 9; j++)
		{
			for(int32 k = 1; k <= 9; k++)
			{
				// f1 = ki / jk, f2 = ik / kj
				int32 num1 = 10 * k + i;
				int32 den1 = 10 * j + k;
				int32 num2 = 10 * i + k;
				int32 den2 = 10 * k + j;

				if (num1 * j == den1 * i)
				{
					numerators.push_back(i);
					denominators.push_back(j);
				}

				if (num2 * j == den2 * i)
				{
					numerators.push_back(i);
					denominators.push_back(j);
				}
			}
		}
	}

	int32 productNumerator = vectorProduct(numerators);
	int32 productDenominator = vectorProduct(denominators);

	return productDenominator / gcd(productNumerator, productDenominator);
}
int32 problem34()
{
	// 8 * 9! = 2903040 so less than 7 digits
	// 7 * 9! = 2540160 <-- highest number that could possibly work

	vector<int32> digitFactorials;
	for(int32 i = 0; i < 10; i++)
	{
		digitFactorials.push_back(factorial(i));
	}

	int32 total = 0;

	// Don't do one digit numbers as per the spec
	for(int32 i = 10; i <= 2540160; i++)
	{
		int32 n = i;
		int32 sum = 0;
		while(n > 0)
		{
			sum += digitFactorials[n % 10];
			n /= 10;
		}

		if(sum == i)
		{
			total += sum;
		}
	}

	return total;
}
int32 problem35(int32 n)
{
	if(n < 2)
	{
		return 0;
	}

	vector<bool> isPrime;
	sieveOfErotosthenes(n, isPrime);

	int32 digits = 1;
	int32 nextBoundary = 10;
	int32 i = 2;
	int32 count = 0;
	while(i < n)
	{
		if(isPrime[i])
		{
			bool isCircular = true;
			int32 rotated = i;

			for(int32 j = 0; j < digits - 1; j++)
			{
				int32 onesDigit = rotated % 10;
				rotated /= 10;
				rotated += onesDigit * (nextBoundary / 10);

				if(!isPrime[rotated])
				{
					isCircular = false;
					break;
				}
			}

			if(isCircular)
			{
				count++;
			}
		}

		i++;
		if(i == nextBoundary)
		{
			digits++;
			nextBoundary *= 10;
		}
	}

	return count;
}
int32 problem36(int32 n)
{
	int32 sum = 0;
	for(int32 i = 1; i < n; i++)
	{
		if(isPalindrome(i, 10) && isPalindrome(i, 2))
		{
			sum += i;
		}
	}

	return sum;
}
int32 problem37()
{
	// Truncatable primes must begin and end with a prime. If an at least
	// 3-digit prime contains an even number or 5 then one truncation
	// will end with such a digit making that truncation composite.
	// We could generate the possible truncatable primes using these
	// ideas but it is simple to just brute force it.
	int32 sum = 0;
	int32 i = 10;		// Single digit primes do not count
	int32 count = 0;
	while(count < 11)	// There are eleven truncatable primes
	{
		if(isNumberPrime(i))
		{
			bool isTruncatable = true;
			int32 sliderFactor = 10;
			while(i / sliderFactor > 0)
			{
				if(!isNumberPrime(i / sliderFactor) || !isNumberPrime(i % sliderFactor))
				{
					isTruncatable = false;
					break;
				}

				sliderFactor *= 10;
			}

			if(isTruncatable)
			{
				sum += i;
				count++;
			}
		}

		i++;
	}

	return sum;
}
int32 problem38()
{
	// We are given that 9 x (1,2,3,4,5) = 918273645, a 1-9 pandigital number.
	// So our number must begin with a 9 if it is larger. One digit numbers other
	// than 9 won't create a concatenated product starting with a 9. A two digit
	// number starting with 9 will have a concatenated product whose size is
	// 2 -> 5 -> 8 -> 11 -> ... so it cannot work. Similarly for 3-digit numbers
	// and 5-digit and larger numbers. So our concatenated product is formed by
	// a 4-digit integer starting with 9 and (1,2) if it is larger than 918273645.
	// Otherwise, 918273645 is the largest. So we check all 4-digit numbers
	// beginning with 9.
	int32 largest = 918273645;
	for(int32 i = 9000; i < 10000; i++)
	{
		int32 concatenatedProduct = i * 100000 + 2 * i;
		if(concatenatedProduct > largest && isPandigital(concatenatedProduct))
		{
			largest = concatenatedProduct;
		}
	}

	return largest;
}
int32 problem39(int32 n)
{
	// Use Euclid's formula for generating all unique Pythagorean triplets. It is the folllowing:
	// a = k * (t^2 - s^2)
	// b = k * 2 * s * t
	// c = k * (s^2 + t^2)
	// where s, t, and k are positive integers, gcd(s, t) = 1, t > s, and t - s is odd

	// b < c and b + c < n so 2 * b < n
	map<int32, int32> solutionCount;
	for(int32 s = 1; 4 * s < n; s++)
	{
		int32 t = s + 1;
		while(4 * s * t < n)
		{
			if(gcd(s, t) == 1)
			{
				int32 perimeter = 2 * t * (s + t);
				int32 k = 1;
				while(k * perimeter < n)
				{
					solutionCount[k * perimeter]++;
					k++;
				}
			}

			t += 2;
		}
	}

	int32 maxCount = -1;
	int32 maxPerimeter = -1;
	for(auto item : solutionCount)
	{
		if(item.second > maxCount)
		{
			maxPerimeter = item.first;
			maxCount = item.second;
		}
	}

	return maxPerimeter;
}
int32 problem40(int32 n)
{
	if(n < 0)
	{
		throw string("10^n must be a postive integer");
	}

	int32 i = 0;
	int32 digit = 1;

	int32 bracketStart = 1;
	int32 bracketEnd = 10;
	int32 bracketWidth = 1;
	int32 powerOfTen = 1;

	int32 product = 1;
	while(i <= n)
	{
		while(digit >= bracketEnd)
		{
			bracketWidth++;
			powerOfTen *= 10;
			bracketStart = bracketEnd;
			bracketEnd += powerOfTen * bracketWidth * 9;
		}

		int32 x = (digit - bracketStart) / bracketWidth;
		int32 y = bracketWidth - 1 - ((digit - bracketStart) % bracketWidth);

		int32 number = powerOfTen + x;
		while(y > 0)
		{
			number /= 10;
			y--;
		}

		product *= number % 10;

		i++;
		digit *= 10;
	}

	return product;
}
int32 problem41()
{
	// The sum of the digits of a 9-digit pandigital number is 45 so it
	// cannot be prime since it will always be divisible by three. Similarly
	// for 8-digit pandigital numbers. So the largest pandigital number that
	// is prime can be at most 7 digits long.
	string permutation = "7654321";
	do
	{
		int32 number = stringToNumber<int32>(permutation);
		if(isNumberPrime(number))
		{
			return number;
		}
	}
	while(prev_permutation(permutation.begin(), permutation.end()));

	throw string("No 7-digit pandigital number that is prime exists");
}
int32 problem42()
{
	int32 nextAdd = 1;
	int32 maxAdd = 0;
	set<int32> triangleNumbers;

	ifstream fin("p42.txt");
	assertFileOpened(fin);

	int32 count = 0;

	string word;
	while(fin >> word)
	{
		int32 score = 0;
		for(char c : word)
		{
			score += c - 'A' + 1;
		}

		while(score > maxAdd)
		{
			maxAdd += nextAdd;
			triangleNumbers.insert(maxAdd);
			nextAdd++;
		}

		if(triangleNumbers.count(score) == 1)
		{
			count++;
		}
	}

	return count;
}
int64 problem43()
{
	class Substringifier
	{
	public:
		int32 operator() (char* start)
		{
			// Just hard-code it as a 3-digit substring. This is
			// pretty niche and better performance is nice.
			return start[0] * 100 + start[1] * 10 + start[2];
		}
	} substringifier;

	// Use integers instead of ASCII codes to make taking numerical substrings easier
	char permutation[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	int64 sum = 0;

	do
	{
		if((substringifier(permutation + 1) % 2 == 0) &&
			(substringifier(permutation + 2) % 3 == 0) &&
			(substringifier(permutation + 3) % 5 == 0) &&
			(substringifier(permutation + 4) % 7 == 0) &&
			(substringifier(permutation + 5) % 11 == 0) &&
			(substringifier(permutation + 6) % 13 == 0) &&
			(substringifier(permutation + 7) % 17 == 0))
		{
			// Need to have LL constants, otherwise the multiplication
			// might overflow before being added. I'm doing it this way instead of
			// a loop since a loop would be a little slower.
			sum += permutation[0] * 1000000000LL;
			sum += permutation[1] * 100000000LL;
			sum += permutation[2] * 10000000LL;
			sum += permutation[3] * 1000000LL;
			sum += permutation[4] * 100000LL;
			sum += permutation[5] * 10000LL;
			sum += permutation[6] * 1000LL;
			sum += permutation[7] * 100LL;
			sum += permutation[8] * 10LL;
			sum += permutation[9];
		}
	}
	while(next_permutation(permutation, permutation + 10));

	return sum;
}
int32 problem44()
{
	set<int32> pentagonalNumbers;

	int32 pk = 1;	// Pentagonal number to see if any pentagonal numbers sum to it
	int32 n = 2;	// Next pentagonal number index to use

	bool isFound = false;
	int32 pi;
	int32 pj;
	while(!isFound)
	{
		for(int32 px : pentagonalNumbers)
		{
			if(pentagonalNumbers.count(pk - px) == 1)
			{
				if(px > pk - px)
				{
					if(pentagonalNumbers.count(2 * px - pk) == 1)
					{
						pi = px;
						pj = pk - px;
						isFound = true;
						break;
					}
				}
				else
				{
					if(pentagonalNumbers.count(pk - 2 * px) == 1)
					{
						pi = pk - px;
						pj = px;
						isFound = true;
						break;
					}
				}
			}
		}

		pentagonalNumbers.insert(pk);
		pk = n * (3 * n - 1) / 2;
		n++;
	}

	// At this point we have an upper bound for what the minimal difference could be in (pi - pj).
	// It turns out this is the minimal difference so we will wave our hands magically and say we
	// have the answer. The proper thing to do would be to generate all the pentagonal numbers up
	// to a point where two adjacent numbers differ by more than pi and pj and brute force the rest
	// of the possible pairs.

	return pi - pj;
}
int64 problem45(int32 n)
{
	int64 t = 285;
	int64 p = 165;
	int64 h = 143;

	int64 vt;
	int64 vp;
	int64 vh;
	vt = vp = vh = 40755;

	// Simple brute force solution of manually keeping track of three different numbers for each
	// respective type (triangle, pentagonal, and hexagonal). If all three are equal then
	// we've found one number satisfying the property. If not, take the smallest number(s)
	// and find their next terms. The terms monotonically increase so this method will always
	// find any numbers that satisfy this property.
	while(true)
	{
		if(vt < vp)
		{
			t++;
			vt = t * (t + 1) / 2;
		}
		else if(vt > vp)
		{
			p++;
			vp = p * (3 * p - 1) / 2;
		}
		else
		{
			if(vt < vh)
			{
				t++;
				p++;
				vt = t * (t + 1) / 2;
				vp = p * (3 * p - 1) / 2;
			}
			else if(vt > vh)
			{
				h++;
				vh = h * (2 * h - 1);
			}
			else
			{
				n--;
				if(n < 0)
				{
					break;
				}

				t++;
				p++;
				h++;
				vt = t * (t + 1) / 2;
				vp = p * (3 * p - 1) / 2;
				vh = h * (2 * h - 1);
			}
		}
	}

	return vt;
}
int64 problem46(int32 n)
{
	set<int64> primes;
	set<int64> squareDoubles;

	squareDoubles.insert(2);
	squareDoubles.insert(8);

	int64 highestSquareDouble = 8;
	int64 highestSquareIx = 2;

	int64 lastNumberFound = -1;

	int64 i = 3;

	while(n > 0)
	{
		if(i > highestSquareDouble)
		{
			highestSquareIx++;
			highestSquareDouble = 2 * highestSquareIx * highestSquareIx;
			squareDoubles.insert(highestSquareDouble);
		}

		if(isNumberPrime(i))
		{
			primes.insert(i);
		}
		else
		{
			bool foundSum = false;
			for(int64 squareDouble : squareDoubles)
			{
				if(primes.count(i - squareDouble) == 1)
				{
					foundSum = true;
					break;
				}
			}

			if(!foundSum)
			{
				n--;
				lastNumberFound = i;
			}
		}

		i += 2;
	}

	return lastNumberFound;
}

#ifdef _MSC_VER
#pragma warning( pop )
#endif
