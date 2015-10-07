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

void verifyResults(int32 begin, int32 end);

int32 main(int32 argc, const char **argv)
{
	try
	{
		verifyResults(72, 72);

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

void verifyResults(int32 begin, int32 end)
{
	typedef bool (*fpCheck)();
	const fpCheck checks[] =
	{
		[] () -> bool { return true; },

		[] () -> bool { return assertEquality(problem1(1000), 233168); },
		[] () -> bool { return assertEquality(problem2(4000000), 4613732); },
		[] () -> bool { return assertEquality(problem3(600851475143), 6857); },
		[] () -> bool { return assertEquality(problem4(3), 906609); },
		[] () -> bool { return assertEquality(problem5(20), 232792560); },

		[] () -> bool { return assertEquality(problem6(100), 25164150); },
		[] () -> bool { return assertEquality(problem7(10001), 104743); },
		[] () -> bool { return assertEquality(problem8(13), 23514624000); },
		[] () -> bool { return assertEquality(problem9(), 31875000); },
		[] () -> bool { return assertEquality(problem10(2000000), 142913828922); },

		[] () -> bool { return assertEquality(problem11(4, 20), 70600674); },
		[] () -> bool { return assertEquality(problem12(500), 76576500); },
		[] () -> bool { return assertEquality(problem13(10), "5537376230"); },
		[] () -> bool { return assertEquality(problem14(1000000), 837799); },
		[] () -> bool { return assertEquality(problem15(20, 20), 137846528820); },

		[] () -> bool { return assertEquality(problem16(1000), 1366); },
		[] () -> bool { return assertEquality(problem17(1000), 21124); },
		[] () -> bool { return assertEquality(problem18(), 1074); },
		[] () -> bool { return assertEquality(problem19(2000), 171); },
		[] () -> bool { return assertEquality(problem20(100), 648); },

		[] () -> bool { return assertEquality(problem21(10000), 31626); },
		[] () -> bool { return assertEquality(problem22(), 871198282); },
		[] () -> bool { return assertEquality(problem23(), 4179871); },
		[] () -> bool { return assertEquality(problem24(1000000), "2783915460"); },
		[] () -> bool { return assertEquality(problem25(1000), 4782); },

		[] () -> bool { return assertEquality(problem26(1000), 983); },
		[] () -> bool { return assertEquality(problem27(1000), -59231); },
		[] () -> bool { return assertEquality(problem28(1001), 669171001); },
		[] () -> bool { return assertEquality(problem29(100), 9183); },
		[] () -> bool { return assertEquality(problem30(5), 443839); },

		[] () -> bool { return assertEquality(problem31(200), 73682); },
		[] () -> bool { return assertEquality(problem32(), 45228); },
		[] () -> bool { return assertEquality(problem33(), 100); },
		[] () -> bool { return assertEquality(problem34(), 40730); },
		[] () -> bool { return assertEquality(problem35(1000000), 55); },

		[] () -> bool { return assertEquality(problem36(1000000), 872187); },
		[] () -> bool { return assertEquality(problem37(), 748317); },
		[] () -> bool { return assertEquality(problem38(), 932718654); },
		[] () -> bool { return assertEquality(problem39(1000), 840); },
		[] () -> bool { return assertEquality(problem40(6), 210); },

		[] () -> bool { return assertEquality(problem41(), 7652413); },
		[] () -> bool { return assertEquality(problem42(), 162); },
		[] () -> bool { return assertEquality(problem43(), 16695334890); },
		[] () -> bool { return assertEquality(problem44(), 5482660); },
		[] () -> bool { return assertEquality(problem45(1), 1533776805); },

		[] () -> bool { return assertEquality(problem46(1), 5777); },
		[] () -> bool { return assertEquality(problem47(4), 134043); },
		[] () -> bool { return assertEquality(problem48(1000), 9110846700); },
		[] () -> bool { return assertEquality(problem49(), "296962999629"); },
		[] () -> bool { return assertEquality(problem50(1000000), 997651); },

		[] () -> bool { return assertEquality(problem51(), 121313); },
		[] () -> bool { return assertEquality(problem52(), 142857); },
		[] () -> bool { return assertEquality(problem53(100, 1000000), 4075); },
		[] () -> bool { return assertEquality(problem54(), 376); },
		[] () -> bool { return assertEquality(problem55(), 249); },

		[] () -> bool { return assertEquality(problem56(100), 972); },
		[] () -> bool { return assertEquality(problem57(1000), 153); },
		[] () -> bool { return assertEquality(problem58(1, 10), 26241); },
		[] () -> bool { return assertEquality(problem59(), 107359); },
		[] () -> bool { return assertEquality(problem60(5), 26033); },

		[] () -> bool { return assertEquality(problem61(), 28684); },
		[] () -> bool { return assertEquality(problem62(5), "127035954683"); },
		[] () -> bool { return assertEquality(problem63(), 49); },
		[] () -> bool { return assertEquality(problem64(10000), 1322); },
		[] () -> bool { return assertEquality(problem65(100), 272); },

		[] () -> bool { return assertEquality(problem66(1000), 661); },
		[] () -> bool { return assertEquality(problem67(), 7273); },
		[] () -> bool { return assertEquality(problem68(), "6531031914842725"); },
		[] () -> bool { return assertEquality(problem69(1000000), 510510); },
		[] () -> bool { return assertEquality(problem70(10000000), 8319823); },

		[] () -> bool { return assertEquality(problem71(1000000), 428570); },
		[] () -> bool { return assertEquality(problem72(1000000), 303963552391); },

		[] () -> bool { return false; }
	};

	if(end - begin + 1 > 0)
	{
		int64 total = 0;
		int64 maxTime = -1;
		int32 maxProblem = -1;

		for(int32 i = begin; i <= end; i++)
		{
			ScopeTimer timer("", false);
			try
			{
				if(checks[i]())
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

			if(elapsed > maxTime)
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
	// Li(x) is approximately equal to pi(x) so use trial and
	// error to find a vale where Li(x) >= n.
	double pixUpperBound = 10;
	while(logarithmicIntegralApprox(pixUpperBound) < n)
	{
		pixUpperBound *= 1.25;
	}

	// Add a bit on to be safe
	int64 sieveSize = static_cast<int64>(pixUpperBound * 1.5);
	vector<bool> isPrime;

	int64 c = 0;
	while(true)
	{
		sieveOfErotosthenes(sieveSize, isPrime);
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
		sieveSize *= 3;
		sieveSize /= 2;
	}

	throw string("Sieve too small");
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

	vector<vector<int32>> grid(m, vector<int32>(m, -1));

	for(int32 y = 0; y < m; y++)
	{
		for(int32 x = 0; x < m; x++)
		{
			fin >> grid[x][y];
			if(!fin)
			{
				throw string("Bad file formatting");
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
	}

	vector<vector<int64>> paths(n + 1, vector<int64>(m + 1, 0));
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
int32 problem18()
{
	ifstream fin("p18.txt");
	assertFileOpened(fin);

	vector<vector<int32>> triangle;
	string temp;
	while(getline(fin, temp))
	{
		triangle.push_back(vector<int32>());

		stringstream ss;
		ss << temp;
		int32 number;
		while(ss >> number)
		{
			triangle.back().push_back(number);
		}
	}

	for(uint32 i = 1; i < triangle.size(); i++)
	{
		for(uint32 j = 0; j <= i; j++)
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

	int32 max = triangle.back()[0];
	for(uint32 i = 1; i < triangle.back().size(); i++)
	{
		if(triangle.back()[i] > max)
		{
			max = triangle.back()[i];
		}
	}

	return max;
}
int32 problem19(int32 n)
{
	if(n <= 1900)
	{
		throw string("Cannot count backwards in time");
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
	}

	if(n > factorial(10))
	{
		throw string("Can't find the zero-th permutation or a negative permutation");
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
	}

	if(n % 2 == 0)
	{
		throw string("Spiral with even side length is undefined");
	}

	int32 x = (n - 1) / 2;
	return 4 * (4 * x * x * x + 12 * x * x + 11 * x + 3) / 3 - 6 * x * (x + 1) - 3;
}
int32 problem29(int32 n)
{
	if(n < 2)
	{
		throw string("A number cannot be at least 2 and less than 2 at the same time");
	}

	vector<vector<int32>> primeFactor(n + 1, vector<int32>(n + 1, 0));
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

	unordered_set<vector<int32>> uniqueValues;
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
	if(n <= 1)
	{
		return 0;
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
	if(n <= 12)
	{
		throw string("There are no right triangles with integer side lengths with a perimeter below 12");
	}

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
	};

	Substringifier substringifier;

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
	if(n < 0)
	{
		throw string("There are no matching triangle, pentagonal, hexagonal numbers before 40755");
	}

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
	if(n < 1)
	{
		throw string("N must be at least one since it denotes the nth occurrence");
	}

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
int32 problem47(int32 n)
{
	if(n < 1)
	{
		throw string("Cannot have a sequence of length less than one");
	}

	if(n == 1)
	{
		return 1;
	}

	vector<set<int32>> primeFactors;

	primeFactors.push_back(set<int32>());
	primeFactors.push_back(set<int32>({1}));
	primeFactors.push_back(set<int32>({2}));
	primeFactors.push_back(set<int32>({3}));

	int32 i = 4;
	int32 sequenceLength = 0;

	while(sequenceLength < n)
	{
		if(i % 2 == 0)
		{
			set<int32> temp = primeFactors[i / 2];
			temp.insert(2);
			primeFactors.push_back(temp);
		}
		else
		{
			bool prime = true;
			int32 factor = 3;
			while(factor * factor <= i)
			{
				if(i % factor == 0)
				{
					set<int32> temp = primeFactors[i / factor];
					temp.insert(factor);
					primeFactors.push_back(temp);
					prime = false;
					break;
				}

				factor += 2;
			}

			if(prime)
			{
				primeFactors.push_back({i});
			}
		}

		if(primeFactors.back().size() == static_cast<uint32>(n))
		{
			sequenceLength++;
		}
		else
		{
			sequenceLength = 0;
		}

		i++;
	}

	return i - n;
}
int64 problem48(int32 n)
{
	if(n < 1)
	{
		return 0;
	}

	const int64 modulus = 1e10;
	int64 sum = 0;

	// Do a boring O(n^2) solution since doing a logarithmic time
	// modulus exponent requires an integral type with more than
	// 64 bits (we need to be able to multiply two 10 digit numbers
	// together with the ideal way and 64 bits is not enough).
	for(int64 i = 1; i <= static_cast<int64>(n); i++)
	{
		int64 product = i;
		for(int64 j = 1; j < i; j++)
		{
			product *= i;
			product %= modulus;
		}

		sum += product;
		sum %= modulus;
	}

	return sum;
}
string problem49()
{
	const uint32 upperPrime = 9999;
	vector<uint32> primes;
	vector<bool> isPrime;
	sieveOfErotosthenes(upperPrime, isPrime);
	for(uint32 i = 1000; i <= upperPrime; i++)
	{
		if(isPrime[i])
		{
			primes.push_back(i);
		}
	}

	for(uint32 i = 0; i < primes.size(); i++)
	{
		for(uint32 j = i + 1; j < primes.size(); j++)
		{
			uint32 prime1 = primes[i];
			uint32 prime2 = primes[j];
			uint32 candidate = 2 * prime2 - prime1;

			if(candidate <= upperPrime && isPrime[candidate])
			{
				if(prime1 == 1487 && prime2 == 4817)
				{
					continue;
				}

				string sPrime1 = numberToString(prime1);
				string sPrime2 = numberToString(prime2);
				string sPrime3 = numberToString(candidate);

				string sequence = sPrime1 + sPrime2 + sPrime3;

				sort(sPrime1.begin(), sPrime1.end());
				sort(sPrime2.begin(), sPrime2.end());
				sort(sPrime3.begin(), sPrime3.end());

				if(sPrime1 == sPrime2 && sPrime2 == sPrime3)
				{
					return sequence;
				}
			}
		}
	}

	throw string("Couldn't find prime sequence satisfying the requirements");
}
int32 problem50(int32 n)
{
	if(n <= 2)
	{
		throw string("There are no primes below 2");
	}

	vector<bool> isPrime;
	sieveOfErotosthenes(n, isPrime);

	vector<int64> primes;
	for(uint32 i = 0; i < isPrime.size(); i++)
	{
		if(isPrime[i])
		{
			primes.push_back(i);
		}
	}

	uint32 left = 0;
	uint32 right = primes.size() - 1;
	int64 sum = vectorSum(primes);

	// Slide right index to the maximum number of consecutive primes based on sum
	while(sum >= n)
	{
		sum -= primes[right];
		right--;
	}

	while(true)	// Break on first find
	{
		int32 nextSum = sum - primes[right];
		while(sum < n)
		{
			if(isPrime[static_cast<uint32>(sum)])
			{
				return sum;
			}

			sum -= primes[left];
			left++;
			right++;
			sum += primes[right];
		}

		right = right - left - 1;
		left = 0;
		sum = nextSum;
	}

	throw string("Could not find prime successfully");
}
int32 problem51()
{
	// Of the ten digits we can choose to replace with, in modulus 3, three of them
	// are equivalent to 0, three of them to 1, and three of them to 2. For an eight
	// prime family, we can only choose 2 digits not to use, so we always end up using
	// a digit from each modulus value. If the number of digits we replace is not
	// equivalent to zero mod 3, then the sum of our digits of any of our final number
	// will be x * y + z, where x is the digit we replace with, y is the number of digits
	// we replace and z is the sum of the digits we don't replace. No matter the value of
	// z, and since y =/= 0 mod 3, we will end up having a situation such that
	// x * y + z = 0 (mod 3) thus this number cannot be part of eight prime family since
	// this number will be divisible by 3, thus, composite. Therefore, we must replace
	// 3, 6, 9, ... digits for our eight prime family.

	// We also cannot replace the last digit because will end up having to replace it with
	// an even number which will make the number composite.

	// From above, we must replace at least 3 digits, and we cannot replace the last digit
	// so we must have at least a 4 digit number.

	// At most we can start off by using 2s as the digits we replace numbers with so we only
	// need to look for numbers with a bunch of 0s, 1s, or 2s digits.

	int32 i = 1000;
	while(true)
	{
		int32 digitCount[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		std::vector<int32> digits;
		int32 n = i / 10;	// Skip last digit
		while(n > 0)
		{
			digitCount[n % 10]++;
			digits.push_back(n % 10);
			n /= 10;
		}

		// This is implicitly checked by the for loop above but it probably
		// eliminates the need to check if numbers are prime a good portion
		// of the time
		if(digitCount[0] >= 3 || digitCount[1] >= 3 || digitCount[2] >= 3)
		{
			if(isNumberPrime(i))
			{
				// Replace 0s, then 1s, then 2s
				for(int32 d = 0; d <= 2; d++)
				{
					// Replace k digits
					for(int32 k = 3; k <= digitCount[d]; k += 3)
					{
						// If there's c >= 3 digits and we only replace k of them, we need to try
						// every possible way of replacing k of them
						vector<int32> digitReplacePerm;
						for(int32 x = 0; x < k; x++)
						{
							digitReplacePerm.push_back(1);
						}
						for(int32 x = k; x < digitCount[d]; x++)
						{
							digitReplacePerm.push_back(0);
						}

						// Sort the digit replacement permutation
						next_permutation(digitReplacePerm.begin(), digitReplacePerm.end());
						do
						{
							// Prime family forms an arithmetic sequence so figuring out
							// the next prime to check is as easy as adding a constant
							// number every single time
							int32 difference = 0;
							int32 digitPower = 10;
							uint32 x = 0;
							for(int32 digit : digits)
							{
								if(digit == d)
								{
									difference += digitReplacePerm[x] * digitPower;
									x++;
								}

								digitPower *= 10;
							}

							// At most 2 numbers we check can be composite and if we start
							// with digits 1 or 2, the prior numbers can be considered
							// invalid/composite
							int32 misses = d;
							bool found = true;
							for(int32 y = 1; y <= 9 - d; y++)
							{
								if(!isNumberPrime(i + y * difference))
								{
									misses++;
									if(misses >= 3)
									{
										found = false;
										break;
									}
								}
							}

							if(found)
							{
								return i;
							}
						}
						while(next_permutation(digitReplacePerm.begin(), digitReplacePerm.end()));
					}
				}
			}
		}

		i++;
	}

	throw string("Could not find eight prime family successfully");
}
int32 problem52()
{
	// Number cannot start with any digit but 1 since six times a number starting
	// with 2 will lead to a number that is one digit longer, which will be invalid.
	// We can extend this to the 2nd, 3rd, and 4th digits and so on.
	int32 nextPower = 100;
	int32 i = 10;
	while(true)
	{
		while(6 * i < nextPower)
		{
			string candidate = numberToString(i);
			sort(candidate.begin(), candidate.end());
			bool successful = true;
			for(int32 multiplier = 2; multiplier <= 6; multiplier++)
			{
				string sorted = numberToString(i * multiplier);
				sort(sorted.begin(), sorted.end());

				if(sorted != candidate)
				{
					successful = false;
					break;
				}
			}

			if(successful)
			{
				return i;
			}

			i++;
		}

		i = nextPower;
		nextPower *= 10;
	}

	throw string("A number satisfying the conditions could not be found");
}
int64 problem53(int32 n, int64 m)
{
	if(n < 1)
	{
		return 0;
	}

	class FactorialMemoizer
	{
	public:
		BigInteger& operator()(int32 x)
		{
			if(m_cMemory.count(x) == 0)
			{
				m_cMemory.insert(make_pair(x, factorial(BigInteger(x))));
			}

			return m_cMemory[x];
		}
	private:
		map<int32, BigInteger> m_cMemory;
	};

	FactorialMemoizer factorialMemoizer;

	int64 count = 0;
	BigInteger limit(m);

	while(n > 0)
	{
		BigInteger numerator = factorialMemoizer(n);

		int32 left = n / 2;
		int32 right = n - (n / 2);
		while(factorialMemoizer(left) * factorialMemoizer(right) * limit < numerator)
		{
			left--;
			right++;
		}

		if(left != right)
		{
			count += right - left - 1;
		}
		else
		{
			break;
		}

		n--;
	}

	return count;
}
int32 problem54()
{
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
	static const int32 HIGH_CARD		= 0;
	static const int32 PAIR				= 1;
	static const int32 TWO_PAIRS		= 2;
	static const int32 THREE_KIND		= 3;
	static const int32 STRAIGHT			= 4;
	static const int32 FLUSH			= 5;
	static const int32 FULL_HOUSE		= 6;
	static const int32 FOUR_KIND		= 7;
	static const int32 STRAIGHT_FLUSH	= 8;

	class Card
	{
	public:
		int32 value;
		char suit;

		Card(string card)
		{
			value = cardVals[static_cast<int32>(card[0])];
			suit = card[1];
		}

		bool operator<(const Card& other)
		{
			return value < other.value;
		}
	};

	class PokerHandEval
	{
	public:
		int32 operator()(const vector<string>& hand)
		{
			// This is pretty ugly. Basically we try to figure out the hand's best rank
			// (e.g. thrre of a kind) and the value of that rank (e.g. 3 queens). We also try
			// to find the best high card not part of that rank. Then we map those three values
			// we found to a single number in such a way that the higher that number is, the better
			// the hand.

			vector<Card> cards;
			transform(hand.begin(), hand.end(), back_inserter(cards), [] (const string& c) -> Card { return Card(c); });
			sort(cards.begin(), cards.end());

			int32 straightStart = cards[0].value;
			char flushSuit = cards[0].value;

			vector<int32> cardCounts(13, 0);
			cardCounts[cards[0].value]++;

			bool hasFlush = true;
			bool hasStraight = true;

			for(uint32 i = 1; i < 5; i++)
			{
				if(cards[i].suit != flushSuit)
				{
					hasFlush = false;
				}

				if(cards[i].value != static_cast<int32>(straightStart + i))
				{
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

			for(uint32 i = 0; i < 13; i++)
			{
				switch(cardCounts[i])
				{
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

			if(hasStraight && hasFlush)
			{
				rank = STRAIGHT_FLUSH;	// Royal flush is pretty irrelevent, its the best straight flush anyways
				rankValue = straightStart;
			}
			else if(hasQuad)
			{
				rank = FOUR_KIND;
			}
			else if(hasTriple && hasOnePair)
			{
				rank = FULL_HOUSE;
			}
			else if(hasFlush)
			{
				rank = FLUSH;
				for(auto it = cards.rbegin(); it != cards.rend(); it++)
				{
					rankValue *= 13;
					rankValue += it->value;
				}
			}
			else if(hasStraight)
			{
				rank = STRAIGHT;
				rankValue = straightStart;
			}
			else if(hasTriple)
			{
				rank = THREE_KIND;
			}
			else if(hasTwoPair)
			{
				rank = TWO_PAIRS;
				rankValue = secondPairValue * 13 + pairValue;
			}
			else if(hasOnePair)
			{
				rank = PAIR;
				rankValue = pairValue;
			}
			else
			{
				rank = HIGH_CARD;
				rankValue = 0;
			}

			// Max high card value is 12
			// Max rank value is under 13^5 (from flush ranking)
			return highCard + rankValue * 13 + rank * 13 * 13 * 13 * 13 * 13 * 13;
		}
	};

	PokerHandEval eval;

	ifstream fin("p54.txt");
	assertFileOpened(fin);

	int32 p1wins = 0;
	while(fin)
	{
		vector<string> p1hand;
		vector<string> p2hand;

		string card;
		for(int32 i = 0; i < 5; i++)
		{
			fin >> card;
			p1hand.push_back(card);
		}

		for(int32 i = 0; i < 5; i++)
		{
			fin >> card;
			p2hand.push_back(card);
		}

		if(!fin.good())
		{
			break;
		}

		if(eval(p1hand) > eval(p2hand))
		{
			p1wins++;
		}
	}

	return p1wins;
}
int32 problem55()
{
	const int32 CHECK_MAX = 10000;
	const int32 ITERATION_LIMIT = 50;

	int32 count = 0;
	for(int32 n = 1; n < CHECK_MAX; n++)
	{
		int32 i = 0;
		bool isLychrel = true;
		BigInteger candidate(n);
		while(i < ITERATION_LIMIT)
		{
			candidate = candidate + candidate.reverse();
			if(candidate.isPalindrome())
			{
				isLychrel = false;
				break;
			}
			i++;
		}

		if(isLychrel)
		{
			count++;
		}
	}

	return count;
}
int32 problem56(int32 n)
{
	if(n < 1)
	{
		throw string("Invalid set of integers to create powers");
	}

	int32 maximalSum = 0;
	for(int32 a = 1; a < n; a++)
	{
		BigInteger bigPower(a);
		for(int32 b = 1; b < n; b++)
		{
			int32 sum = bigPower.sumOfDigits();
			if(sum > maximalSum)
			{
				maximalSum = sum;
			}

			bigPower *= a;
		}
	}

	return maximalSum;
}
int32 problem57(int32 n)
{
	if(n < 1)
	{
		return 0;
	}

	// Know that convergent terms for 2^(1/2) are [1; 2, ...]
	vector<BigInteger> pi;	// convergent numerators
	vector<BigInteger> qi;	// convergent denominators

	pi.push_back(BigInteger(1));
	qi.push_back(BigInteger(1));

	pi.push_back(pi[0] * 2 + 1);
	qi.push_back(qi[0] * 2);

	int32 count = 0;
	if(pi[0].numberOfDigits() > qi[0].numberOfDigits())
	{
		count++;
	}
	if(pi[1].numberOfDigits() > qi[1].numberOfDigits())
	{
		count++;
	}
	for(uint32 i = 2; i <= static_cast<uint32>(n); i++)
	{
		pi.push_back(pi[i - 1] * 2 + pi[i - 2]);
		qi.push_back(qi[i - 1] * 2 + qi[i - 2]);
		if(pi[i].numberOfDigits() > qi[i].numberOfDigits())
		{
			count++;
		}
	}

	return count;
}
int32 problem58(int32 n, int32 m)
{
	if(n < 0 || m < 1)
	{
		throw string("Impossible ratio of primes to non-primes");
	}

	int32 numberCount = 5;
	int32 primeCount = 3;
	int32 lastNumber = 9;
	int32 incrementer = 4;	// One less than the next spiral side-length

	while(m * primeCount >= n * numberCount)
	{
		lastNumber += incrementer;
		if(isNumberPrime(lastNumber))
		{
			primeCount++;
		}

		lastNumber += incrementer;
		if(isNumberPrime(lastNumber))
		{
			primeCount++;
		}

		lastNumber += incrementer;
		if(isNumberPrime(lastNumber))
		{
			primeCount++;
		}

		lastNumber += incrementer;
		// Don't have to check the last number number because it's going to be an odd square

		numberCount += 4;
		incrementer += 2;
	}

	return incrementer - 1;
}
int32 problem59()
{
	ifstream fin("p59.txt");
	assertFileOpened(fin);

	vector<int32> characters;
	int32 temp;
	while(fin >> temp)
	{
		characters.push_back(temp);
	}

	int32 charCounts[3][256] = {0};
	for(uint32 i = 0; i < characters.size(); i++)
	{
		charCounts[i % 3][characters[i]]++;
	}

	int32 highestFreq[3] = {0};
	int32 highestFreqChar[3] = {0};
	for(uint32 i = 0; i < 3; i++)
	{
		for(uint32 j = 0; j < 256; j++)
		{
			if(charCounts[i][j] > highestFreq[i])
			{
				highestFreq[i] = charCounts[i][j];
				highestFreqChar[i] = j;
			}
		}
	}

	int32 encryptionKeys[3];
	for(uint32 i = 0; i < 3; i++)
	{
		// Space should be the most frequent character
		encryptionKeys[i] = highestFreqChar[i] ^ ' ';
	}

	int32 asciiSum = 0;
	for(uint32 i = 0; i < characters.size(); i++)
	{
		characters[i] ^= encryptionKeys[i % 3];
		asciiSum += characters[i];
	}

	return asciiSum;
}
int32 problem60(int32 n)
{
	if(n < 2)
	{
		throw string("Need at least two numbers to concatenate");
	}

	// Need to have an upper bound on what prime can be in the set (it's just a guess)
	const int32 maxPrimeBound = 10000;

	vector<bool> isPrime;
	sieveOfErotosthenes(maxPrimeBound, isPrime);

	struct Node
	{
		int32 val;
		int32 power;
		set<int32> adjacencies;
	};

	int32 power = 10;
	vector<Node> nodes;
	for(int32 i = 0; i < static_cast<int32>(isPrime.size()); i++)
	{
		if(i >= power)
		{
			power *= 10;
		}

		if(isPrime[i])
		{
			Node node;
			node.power = power;
			node.val = i;
			nodes.push_back(node);
		}
	}

	for(uint32 i = 0; i < nodes.size() - 1; i++)
	{
		for(uint32 j = i + 1; j < nodes.size(); j++)
		{
			if(isNumberPrime(nodes[j].val * nodes[i].power + nodes[i].val) && isNumberPrime(nodes[i].val * nodes[j].power + nodes[j].val))
			{
				nodes[i].adjacencies.insert(j);
				nodes[j].adjacencies.insert(i);
			}
		}
	}

	// Things tend to have a lot of adjacencies (barring 2 and 5) so this is pretty pointless.
	#if 0
	auto it = remove_if(nodes.begin(), nodes.end(), [n](Node& node) -> bool {
		return node.adjacencies.size() < static_cast<uint32>(n - 1);
	});
	nodes.erase(it, nodes.end());

	// Recompute indices of adjacencies
	#endif

	class KNFinder
	{
	public:
		KNFinder(const vector<Node>& graph) :
			m_vcGraph(graph)
		{
		}

		vector<set<int32>> operator()(int32 n)
		{
			m_nN = n;
			m_vsResults = vector<set<int32>>();

			set<int32> placeholder;
			recurse(placeholder, 0);

			return m_vsResults;
		}

	private:
		const vector<Node>& m_vcGraph;
		int32 m_nN;
		vector<set<int32>> m_vsResults;

		void recurse(set<int32>& candidate, int32 minIx)
		{
			if(candidate.size() == static_cast<uint32>(m_nN))
			{
				m_vsResults.push_back(candidate);
				return;
			}

			for(uint32 i = minIx; i < m_vcGraph.size(); i++)
			{
				bool isValid = true;
				for(int32 ix : candidate)
				{
					if(m_vcGraph[i].adjacencies.count(ix) == 0)
					{
						isValid = false;
						break;
					}
				}

				if(isValid)
				{
					candidate.insert(i);
					recurse(candidate, i + 1);
					candidate.erase(i);
				}
			}
		}
	};

	KNFinder knFinder(nodes);
	vector<set<int32>> validSets = knFinder(n);

	if(validSets.size() == 0)
	{
		throw string("Prime upper bound not set high enough to find a valid prime family");
	}

	sort
	(
		validSets.begin(),
		validSets.end(),
		[&nodes] (const set<int32>& x, const set<int32>& y) -> bool
		{
			int32 xSum = 0;
			for(int32 ix : x)
			{
				xSum += nodes[ix].val;
			}

			int32 ySum = 0;
			for(int32 ix : y)
			{
				ySum += nodes[ix].val;
			}

			return xSum < ySum;
		}
	);

	int32 sum = 0;
	for(int32 ix : validSets[0])
	{
		sum += nodes[ix].val;
	}
	return sum;
}
int32 problem61()
{
	int32 i;

	vector<int32> triangleNumbers;
	i = 0;
	while(i * (i + 1) / 2 < 1000)
	{
		i++;
	}
	while(i * (i + 1) / 2 < 10000)
	{
		triangleNumbers.push_back(i * (i + 1) / 2);
		i++;
	}

	vector<int32> squareNumbers;
	i = 0;
	while(i * i < 1000)
	{
		i++;
	}
	while(i * i < 10000)
	{
		squareNumbers.push_back(i * i);
		i++;
	}

	vector<int32> pentagonalNumbers;
	i = 0;
	while(i * (3 * i - 1) / 2 < 1000)
	{
		i++;
	}
	while(i * (3 * i - 1) / 2 < 10000)
	{
		pentagonalNumbers.push_back(i * (3 * i - 1) / 2);
		i++;
	}

	vector<int32> hexagonalNumbers;
	i = 0;
	while(i * (2 * i - 1) < 1000)
	{
		i++;
	}
	while(i * (2 * i - 1) < 10000)
	{
		hexagonalNumbers.push_back(i * (2 * i - 1));
		i++;
	}

	vector<int32> heptagonalNumbers;
	i = 0;
	while(i * (5 * i - 3) / 2 < 1000)
	{
		i++;
	}
	while(i * (5 * i - 3) / 2 < 10000)
	{
		heptagonalNumbers.push_back(i * (5 * i - 3) / 2);
		i++;
	}

	vector<int32> octagonalNumbers;
	i = 0;
	while(i * (3 * i - 2) < 1000)
	{
		i++;
	}
	while(i * (3 * i - 2) < 10000)
	{
		octagonalNumbers.push_back(i * (3 * i - 2));
		i++;
	}

	static const int32 TYPE_TRIANGLE		= 0;
	static const int32 TYPE_SQUARE			= 1;
	static const int32 TYPE_PENTAGONAL		= 2;
	static const int32 TYPE_HEXAGONAL		= 3;
	static const int32 TYPE_HEPTAGONAL		= 4;
	static const int32 TYPE_OCTAGONAL		= 5;

	vector<vector<pair<int32, int32>>> graph(100);
	for(int32 n : triangleNumbers)
	{
		graph[n / 100].push_back(make_pair(TYPE_TRIANGLE, n % 100));
	}
	for(int32 n : squareNumbers)
	{
		graph[n / 100].push_back(make_pair(TYPE_SQUARE, n % 100));
	}
	for(int32 n : pentagonalNumbers)
	{
		graph[n / 100].push_back(make_pair(TYPE_PENTAGONAL, n % 100));
	}
	for(int32 n : hexagonalNumbers)
	{
		graph[n / 100].push_back(make_pair(TYPE_HEXAGONAL, n % 100));
	}
	for(int32 n : heptagonalNumbers)
	{
		graph[n / 100].push_back(make_pair(TYPE_HEPTAGONAL, n % 100));
	}
	for(int32 n : octagonalNumbers)
	{
		graph[n / 100].push_back(make_pair(TYPE_OCTAGONAL, n % 100));
	}

	class SpecialCycleFinder
	{
	public:
		SpecialCycleFinder(const vector<vector<pair<int32, int32>>>& graph) :
			m_vcGraph(graph)
		{
		}

		vector<int32> operator()()
		{
			set<int32> usedTypes;
			usedTypes.insert(TYPE_TRIANGLE);

			vector<int32> result;

			for(int32 i = 0; i < 100; i++)
			{
				for(auto adjacency : m_vcGraph[i])
				{
					if(adjacency.first == TYPE_TRIANGLE)
					{
						result.push_back(i * 100 + adjacency.second);
						if(recurse(result, usedTypes))
						{
							return result;
						}
						result.pop_back();
					}
				}
			}

			throw string("Could could find the special cycle");
		}

	private:
		const vector<vector<pair<int32, int32>>>& m_vcGraph;

		bool recurse(vector<int32>& result, set<int32>& usedTypes)
		{
			if(result.size() == 6 && result.front() / 100 == result.back() % 100)
			{
				return true;
			}

			for(auto adjacency : m_vcGraph[result.back() % 100])
			{
				if(usedTypes.count(adjacency.first) == 0)
				{
					usedTypes.insert(adjacency.first);
					result.push_back(result.back() % 100 * 100 + adjacency.second);
					if(recurse(result, usedTypes))
					{
						return true;
					}
					result.pop_back();
					usedTypes.erase(adjacency.first);
				}
			}

			return false;
		}
	};

	SpecialCycleFinder cycleFinder(graph);
	return vectorSum(cycleFinder());
}
string problem62(int32 n)
{
	if(n < 1)
	{
		throw string("Must be at least one permutation");
	}
	else if(n == 1)
	{
		return "0";
	}

	map<string, pair<int32, string>> cubes;
	int32 i = 0;
	while(true)
	{
		BigInteger x(i);
		string cube = numberToString(x * x * x);
		string sorted = cube;
		sort(sorted.begin(), sorted.end());
		auto it = cubes.find(cube);
		if(it == cubes.end())
		{
			it = cubes.insert(make_pair(sorted, make_pair(0, cube))).first;
		}

		it->second.first++;
		if(it->second.first == n)
		{
			return it->second.second;
		}

		i++;
	}

	throw string("Unable to find enough permutations of a cube that are cube as well");
}
int32 problem63()
{
	// Numbers greater than 9 cannot work since 10^1 is two digits, 10^2 is three digits,
	// and so on. We can figure out the numbers that work by calculating powers of 1 digit numbers.
	// Starting from one, once a number's power does not have the correct amount of digits, it will
	// always be that way since the required number will get 10 times greater while the power will
	// only get k <= 9 times greater.

	set<BigInteger> successes;
	for(int32 i = 1; i <= 9; i++)
	{
		BigInteger n(i);
		BigInteger bound(1);
		while(n >= bound)
		{
			successes.insert(n);
			n *= i;
			bound *= 10;
		}
	}

	return successes.size();
}
int32 problem64(int32 n)
{
	if(n <= 1)
	{
		return 0;
	}

	set<int32> perfectSquares;
	int32 i = 2;
	while(i * i <= n)
	{
		perfectSquares.insert(i * i);
		i++;
	}

	int32 count = 0;
	int32 root = 1;
	for(int32 x = 2; x <= n; x++)
	{
		if(x == (root + 1) * (root + 1))
		{
			root++;
			continue;
		}

		int32 a = root;
		int32 b = 1;
		set<pair<int32, int32>> seen;
		while(true)
		{
			pair<int32, int32> temp = make_pair(a, b);
			if(seen.count(temp) == 1)
			{
				count += seen.size() % 2 == 1 ? 1 : 0;
				break;
			}

			seen.insert(temp);

			b = (x - a * a) / b;
			a = (((a + root) / b) * b) - a;
		}
	}

	return count;
}
int32 problem65(int32 n)
{
	if(n < 1)
	{
		throw string("Cannot have a non-positive indexed convergent of e");
	}

	vector<int32> ai(n);
	ai[0] = 2;
	for(int32 i = 1; i < n; i++)
	{
		if(i % 3 == 2)
		{
			ai[i] = (i + 1) / 3 * 2;
		}
		else
		{
			ai[i] = 1;
		}
	}

	vector<BigInteger> pi;	// convergent numerators
	pi.push_back(BigInteger(1) * ai[0]);
	if(n > 1)
	{
		pi.push_back(pi[0] * ai[1] + 1);
	}

	for(int32 i = 2; i < n; i++)
	{
		pi.push_back(pi[i - 1] * ai[i] + pi[i - 2]);
	}

	return pi.back().sumOfDigits();
}
int32 problem66(int32 n)
{
	if(n < 2)
	{
		throw string("Cannot find minimum of an empty set");
	}

	BigInteger largestX(0);
	int32 maxD = 0;

	// Minimal solution in x is found by getting a specific convergent
	// for the continued fraction of the square root of D.
	int32 root = 1;
	for(int32 i = 2; i <= n; i++)
	{
		if(i == (root + 1) * (root + 1))
		{
			root++;
			continue;
		}

		vector<int32> ai;
		ai.push_back(root);

		int32 s = root;
		int32 t = 1;

		while(ai.back() != ai.front() * 2)
		{
			t = (i - s * s) / t;
			ai.push_back((s + root) / t);
			s = ai.back() * t - s;
		}

		vector<BigInteger> pi;
		pi.push_back(BigInteger(ai[0]));
		pi.push_back(BigInteger(ai[0] * ai[1] + 1));

		int32 r = ai.size() - 2;
		if(r % 2 == 1)
		{
			for(int32 j = 2; j <= r; j++)
			{
				pi.push_back(pi[j - 1] * ai[j] + pi[j - 2]);
			}

			if(pi[r] > largestX)
			{
				largestX = pi[r];
				maxD = i;
			}
		}
		else
		{
			for(int32 j = 2; j <= r + 1; j++)
			{
				pi.push_back(pi[j - 1] * ai[j] + pi[j - 2]);
			}

			for(int32 j = 1; j < r + 1; j++)
			{
				pi.push_back(pi[j + r] * ai[j] + pi[j + r - 1]);
			}

			if(pi[2 * r + 1] > largestX)
			{
				largestX = pi[2 * r + 1];
				maxD = i;
			}
		}
	}

	return maxD;
}
int32 problem67()
{
	ifstream fin("p67.txt");
	assertFileOpened(fin);

	vector<vector<int32>> triangle;
	string temp;
	while(getline(fin, temp))
	{
		triangle.push_back(vector<int32>());

		stringstream ss;
		ss << temp;
		int32 number;
		while(ss >> number)
		{
			triangle.back().push_back(number);
		}
	}

	for(uint32 i = 1; i < triangle.size(); i++)
	{
		for(uint32 j = 0; j <= i; j++)
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

	int32 max = triangle.back()[0];
	for(uint32 i = 1; i < triangle.back().size(); i++)
	{
		if(triangle.back()[i] > max)
		{
			max = triangle.back()[i];
		}
	}

	return max;
}
string problem68()
{
	// It's easy to permute every possible magic 5-gon filling and then
	// check if it works. Each permutation has 4 other equivalent permutations
	// so we can represent the 5-gon as a 10 element array and assume the string
	// begins with what our representation begins with (so we must check that the
	// first element is the smallest on the outside. We can begin permuting from
	// 6 5 10 4 9 3 8 2 7 1, since 6 is the highest element that can be the minimum
	// on the outer ring and the rest of higher numbers must be on the outer ring.
	// The representation goes clockwise alternating with outside and then inside.
	// The first 2 numbers in the representation are the 2 first digits in the resulting
	// string so once we find a permutation that is successful, we only need to check
	// the remaining permutations in the last 8 digits since lower the first two digits
	// will always result in a string lower than the one that is found.

	int32 ring[10] = {6, 5, 10, 4, 9, 3, 8, 2, 7, 1};

	string max = "0";
	do
	{
		if(ring[1] == 10)
		{
			continue;
		}

		do
		{
			if(ring[3] == 10 || ring[5] == 10 || ring[7] == 10 || ring[9] == 10)
			{
				continue;
			}

			if(ring[2] < ring[0] || ring[4] < ring[0] || ring[6] < ring[0] || ring[8] < ring[0])
			{
				continue;
			}

			int32 sum = ring[0] + ring[1] + ring[3];
			bool sumsGood = true;
			for(int32 i = 2; i < 10; i += 2)
			{
				if(ring[i] + ring[i + 1] + ring[(i + 3) % 10] != sum)
				{
					sumsGood = false;
					break;
				}
			}

			if(!sumsGood)
			{
				continue;
			}

			stringstream ss;
			for(int32 i = 0; i < 10; i += 2)
			{
				ss << ring[i] << ring[i + 1] << ring[(i + 3) % 10];
			}

			if(ss.str() > max)
			{
				max = ss.str();
			}
		}
		while(prev_permutation(ring + 2, ring + 10));
	}
	while(max == "0" && prev_permutation(ring, ring + 10));

	return max;
}
int32 problem69(int32 n)
{
	// Consider a prime factorization of x and it's ratio x/phi(x) = r.
	// The resulting ratio of x multiplied by one of its prime factors is
	// no different. Thus, consider x with only unique prime factors. Changing
	// one of x's factors to be a lower, but still unique, prime factor increases
	// its ratio x/phi(x). Thus, consider x which is a product of the first z
	// primes. Multiplying x by the (z+1)th prime increases its ratio. Thus, the
	// value of x that maximizes its ratio is the product of the most sequential
	// primes beginning at 2 that does not exceed n.

	if(n < 1)
	{
		throw string("The phi function must be well defined for values of within the interval and the interval must be non-empty");
	}

	if(n == 1)
	{
		return 1;
	}

	int32 product = 2;
	int32 i = 3;
	while(product * i <= n)
	{
		if(isNumberPrime(i))
		{
			product *= i;
		}

		i += 2;
	}

	return product;
}
int32 problem70(int32 n)
{
	if(n < 2)
	{
		throw string("Cannot compute minimum of an empty set");
	}

	vector<vector<int32>> sieve(n);
	for(int32 i = 2; i < n; i++)
	{
		if(sieve[i].size() > 0)
		{
			continue;
		}

		for(int32 j = i; j < n; j += i)
		{
			sieve[j].push_back(i);
		}
	}

	vector<int32> phi;
	totientValues(n - 1, phi);

	int32 min = 10;		// Ratio should never exceed 10 since the numerator
	int32 minPhi = 1;	// and denominator will have the same number of digits
	for(int32 i = 2; i < n; i++)
	{
		string num = numberToString(i);
		string denom = numberToString(phi[i]);

		sort(num.begin(), num.end());
		sort(denom.begin(), denom.end());

		if(num == denom)
		{
			if(static_cast<int64>(i) * minPhi < static_cast<int64>(min) * phi[i])
			{
				min = i;
				minPhi = phi[i];
			}
		}
	}

	return min;
}
int32 problem71(int32 n)
{
	if(n < 1)
	{
		throw string("Denominator should be able to be positive");
	}

	int64 bestNum = 0;
	int64 bestDenom = 1;

	for(int32 i = 2; i <= n; i++)
	{
		int32 candidateNum = 3 * i / 7;
		if(i % 7 == 0)
		{
			candidateNum -= 1;
		}

		if(candidateNum * bestDenom > bestNum * i)
		{
			bestNum = candidateNum;
			bestDenom = i;
		}
	}

	return bestNum / gcd(bestNum, bestDenom);
}
int64 problem72(int64 n)
{
	if(n < 1)
	{
		throw string("Denominator should be able to be positive");
	}

	vector<int64> phi;
	totientValues(n, phi);

	return vectorSum(phi) - 1; // Minus 1 from phi(1) which should not be included
}

#ifdef _MSC_VER
#pragma warning( pop )
#endif
