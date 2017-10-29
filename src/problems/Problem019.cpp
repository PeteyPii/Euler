#include "SourcePrefix.h"

#include "Common.h"

int32 problem19(int32 n) {
  if (n <= 1900) {
    throw string("Cannot count backwards in time");
  }

  int32 year = 1901;
  int32 month = 0;
  int32 day = 0;

  const int32 days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  int32 totalSundays = 0;
  int32 totalDays = 1;

  while (year <= n) {
    while (month < 12) {
      if (totalDays % 7 == 6) {
        totalSundays++;
      }

      while (day < days[month]) {
        day++;
        totalDays++;
      }

      if (isLeapYear(year) && month == 1) {
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

#include "SourceSuffix.h"
