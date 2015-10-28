/*******************************************************************************

	Name:			Euler.h
	Creator: 		Patrick Wrobel
	Date:			May 5th, 2014
	Description:	Solutions to the problems on Project Euler

*******************************************************************************/

#ifndef EULER_H
#define EULER_H

#include "Common.h"

int32		problem1(int32 n);				// Sum of all multiples of 3 and 5 less than n.
int32		problem2(int32 n);				// Sum of even Fibonacci numbers less than n.
int64		problem3(int64 n);				// Largest prime factor of n.
int32		problem4(int32 n);				// Largest palindrome from product of two n-digit numbers.
int64		problem5(int64 n);				// Smallest multiple of numbers up to n.

int64		problem6(int64 n);				// Difference between square of sum and sum of squares up to n.
int64		problem7(int64 n);				// Find the nth prime.
int64		problem8(int32 n);				// Max product of n-digit number within extremely long number.
int32		problem9();						// a+b+c=1000 and a^2+b^2=c^2, find a*b*c.
int64		problem10(int64 n);				// Sum of every prime up to n.

int32		problem11(int32 n, int32 m);	// Max product of n adjacent numbers in m*m grid.
int64		problem12(int32 n);				// Smallest triangle number with at least n divisors.
string		problem13(int32 n);				// First n digits of the sum of many very long numbers.
int32		problem14(int32 n);				// Longest Collatz sequence for a number less than n.
int64		problem15(int32 n, int32 m);	// Number of lattice paths in an n*m grid.

int32		problem16(int32 n);				// Sum of digits of 2^n.
int32		problem17(int32 n);				// Total number of letters for each word from 1 to n.
int32		problem18();					// Max sum of a path through a tall triangle.
int32		problem19(int32 n);				// Number of Sunday 1sts from start of 1901 until end of year n.
int32		problem20(int32 n);				// Sum of the digits of n!.

int32		problem21(int32 n);				// Sum of all amicable numbers under n.
int64		problem22();					// Sum of word scores of many names.
int32		problem23();					// Sum of all positive numbers that cannot a be sum of two abundant numbers.
string		problem24(int32 n);				// Nth lexicographical permutation of 0123456789.
int32		problem25(int32 n);				// Term number of the first n-digit Fibonacci number.

int32		problem26(int32 n);				// Number betweeen 1 and n (inclusive) that has the longest reciprocal cycle (in decimal).
int32		problem27(int32 n);				// Product of a and b where x^2+ax+b yields the most prime numbers for consecutive x values and |a|, |b| < n.
int32		problem28(int32 n);				// Sum of the diagonals in a n*n spiral of consecutive numbers.
int32		problem29(int32 n);				// Number of distinct powers of a^b where a and b are between 2 and n (inclusive).
int32		problem30(int32 n);				// Sum of all the numbers that can be written as the sum of nth powers of their digits.

int32		problem31(int32 n);				// Number of ways to make n pence with British currency.
int32		problem32();					// Sum of all 1-9 pandigital multiplicand/multiplier/product identities.
int32		problem33();					// Denominator of product of faulty division rule fractions.
int32		problem34();					// Sum of all numbers which are equal to the sum of the factorial of their digits.
int32		problem35(int32 n);				// Number of circular primes there are below n.

int32		problem36(int32 n);				// Sum of all numbers, less than n, that are palindromic in base 2 and 10.
int32		problem37();					// Sum of all eleven truncatable primes.
int32		problem38();					// Largest 1-9 pandigital number that can be formed as a concatenated product of an integer and (1,2,...,k).
int32		problem39(int32 n);				// Value of p that is at most n, such that the number of right triangles with integer side lengths and perimeter p is maximised.
int32		problem40(int32 n);				// Value of d(1) * d(10) * ... * d(10^n) where d(n) is the nth digit of Champernowne's constant.

int32		problem41();					// Largest number that is prime and pandigital.
int32		problem42();					// Number of words with triangular number scores.
int64		problem43();					// Sum of all 0-9 pandigital numbers whose specific substrings satisfy certain divisibilities.
int32		problem44();					// Value of D such that D is a pentagonal number, it is the difference between two pentagonal numbers, the sum of those two pentagonal numbers is pentagonal, and it is minimized.
int64		problem45(int32 n);				// Triangle number that is also a pentagonal number and a hexagonal number such that there are n numbers with this property below it starting at the 285th triangle number.

int64		problem46(int32 n);				// Nth odd composite that cannot be written as the sum of a prime and twice a square.
int32		problem47(int32 n);				// First number of the first sequence of n numbers with n unique factors.
int64		problem48(int32 n);				// Last ten digits of 1^1 + 2^2 + 3^3 + ... + n^n.
string		problem49();					// 12 digits of 3 4-digit primes in order with the primes spaced out equally and permutations of each other and is not 1487 4817 8147.
int32		problem50(int32 n);				// Lowest prime below n that is the sum of the most consecutive primes (more consecutive takes precedence over lower primes).

int32		problem51();					// Lowest prime where, by replacing part of the of it by the same digit, it is part of an eight prime value family.
int32		problem52();					// Smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
int64		problem53(int32 n, int64 m);	// Number of, not necessarily distinct, values of x choose r that exceed m where 1 <= x <= n.
int32		problem54();					// Number of poker hands player 1 wins.
int32		problem55();					// Number of Lycherel numbers below ten-thousand.

int32		problem56(int32 n);				// Maximal digit sum of a^b where a, b < n.
int32		problem57(int32 n);				// Number of convergents of square root 2, where the convergent has a numerator with more digits than the denominator and the term is at most the n-th term.
int32		problem58(int32 n, int32 m);	// Side length of spiral where, on the diagonals, the fraction of primes is under n / m.
int32		problem59();					// Decrypt a message that uses a form of XOR encryption and find the sum of the ASCII values.
int32		problem60(int32 n);				// Minimum sum of a prime family of size n where concatenating any two of the primes forms a prime.

int32		problem61();					// Sum of the only ordered set of six cyclic 4-digit figurate numbers of different types.
string		problem62(int32 n);				// Smallest cube whose digits are a permutation of exactly n cubes.
int32		problem63();					// Number of k-digit positive integers that are also a kth power.
int32		problem64(int32 n);				// Number of continued fractions for irrational square roots of x <= n that have an odd period.
int32		problem65(int32 n);				// Sum of digits in the numerator of the nth convergent of the continued fraction for e.

int32		problem66(int32 n);				// Value of D that maximises x which is part of an minimized integer solution to x^2 - Dy^2 = 1 for D <= n.
int32		problem67();					// Max sum of a path through a taller triangle.
string		problem68();					// Max 16-digit string from a solved magic 5-gon ring.
int32		problem69(int32 n);				// Value of x that maximises x/phi(x) for x <= n.
int32		problem70(int32 n);				// Value of x that minimises x/phi(x) for x < n and for x such that x is a permutation of phi(x).

int32		problem71(int32 n);				// Numerator of the reduced fraction that is just below 3/7 where the denominator is at most n.
int64		problem72(int64 n);				// Number of reduced proper fractions with a denominator at most n.
int32		problem73(int32 n);				// Number of reduced proper fractions greater than 1/3 and below 1/2 with a denominator at most n.
int32		problem74(int32 n, int32 m);	// Number of digit factorial chains with exactly m elements starting a number below n.
int32		problem75(int32 n);				// Number of integer sided right triangles with a unique perimeter at most n.

int32		problem76(int32 n);				// Number of different ways to write n as a sum of at least two positive integers.
int32		problem77(int32 n);				// First number that can be written as the sum of primes in over n different ways.
int32		problem78(int32 n);				// Smallest number that can be partitioned in a number of ways divisible by n.
string		problem79();					// Find the shortest possible passcode from the ordered digits.

#endif
