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
int32		problem18(int32 n);				// Max sum of a path through a n row tall triangle.
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

#endif
