#include "SourcePrefix.h"

#include "Common.h"
#include "Problems.h"
#include "ScopeTimer.h"

using namespace std;

void verifyResults();

int32 main(int32 argc, const char** argv) {
  try {
    verifyResults();

    return 0;
  } catch (string e) {
    cout << "An exception has been thrown:" << endl;
    cout << "  " << e << endl;
    return 1;
  } catch (...) {
    cout << "An unknown exception has been thrown." << endl;
    return 2;
  }
}

void verifyResults() {
  typedef bool (*fpCheck)();
  const fpCheck checks[] = {
      []() -> bool { return assertEquality(problem1(1000), 233168); },
      []() -> bool { return assertEquality(problem2(4000000), 4613732); },
      []() -> bool { return assertEquality(problem3(600851475143), 6857); },
      []() -> bool { return assertEquality(problem4(3), 906609); },
      []() -> bool { return assertEquality(problem5(20), 232792560); },

      []() -> bool { return assertEquality(problem6(100), 25164150); },
      []() -> bool { return assertEquality(problem7(10001), 104743); },
      []() -> bool { return assertEquality(problem8(13), 23514624000); },
      []() -> bool { return assertEquality(problem9(), 31875000); },
      []() -> bool { return assertEquality(problem10(2000000), 142913828922); },

      []() -> bool { return assertEquality(problem11(4, 20), 70600674); },
      []() -> bool { return assertEquality(problem12(500), 76576500); },
      []() -> bool { return assertEquality(problem13(10), "5537376230"); },
      []() -> bool { return assertEquality(problem14(1000000), 837799); },
      []() -> bool { return assertEquality(problem15(20, 20), 137846528820); },

      []() -> bool { return assertEquality(problem16(1000), 1366); },
      []() -> bool { return assertEquality(problem17(1000), 21124); },
      []() -> bool { return assertEquality(problem18(), 1074); },
      []() -> bool { return assertEquality(problem19(2000), 171); },
      []() -> bool { return assertEquality(problem20(100), 648); },

      []() -> bool { return assertEquality(problem21(10000), 31626); },
      []() -> bool { return assertEquality(problem22(), 871198282); },
      []() -> bool { return assertEquality(problem23(), 4179871); },
      []() -> bool { return assertEquality(problem24(1000000), "2783915460"); },
      []() -> bool { return assertEquality(problem25(1000), 4782); },

      []() -> bool { return assertEquality(problem26(1000), 983); },
      []() -> bool { return assertEquality(problem27(1000), -59231); },
      []() -> bool { return assertEquality(problem28(1001), 669171001); },
      []() -> bool { return assertEquality(problem29(100), 9183); },
      []() -> bool { return assertEquality(problem30(5), 443839); },

      []() -> bool { return assertEquality(problem31(200), 73682); },
      []() -> bool { return assertEquality(problem32(), 45228); },
      []() -> bool { return assertEquality(problem33(), 100); },
      []() -> bool { return assertEquality(problem34(), 40730); },
      []() -> bool { return assertEquality(problem35(1000000), 55); },

      []() -> bool { return assertEquality(problem36(1000000), 872187); },
      []() -> bool { return assertEquality(problem37(), 748317); },
      []() -> bool { return assertEquality(problem38(), 932718654); },
      []() -> bool { return assertEquality(problem39(1000), 840); },
      []() -> bool { return assertEquality(problem40(6), 210); },

      []() -> bool { return assertEquality(problem41(), 7652413); },
      []() -> bool { return assertEquality(problem42(), 162); },
      []() -> bool { return assertEquality(problem43(), 16695334890); },
      []() -> bool { return assertEquality(problem44(), 5482660); },
      []() -> bool { return assertEquality(problem45(1), 1533776805); },

      []() -> bool { return assertEquality(problem46(1), 5777); },
      []() -> bool { return assertEquality(problem47(4), 134043); },
      []() -> bool { return assertEquality(problem48(1000), 9110846700); },
      []() -> bool { return assertEquality(problem49(), "296962999629"); },
      []() -> bool { return assertEquality(problem50(1000000), 997651); },

      []() -> bool { return assertEquality(problem51(), 121313); },
      []() -> bool { return assertEquality(problem52(), 142857); },
      []() -> bool { return assertEquality(problem53(100, 1000000), 4075); },
      []() -> bool { return assertEquality(problem54(), 376); },
      []() -> bool { return assertEquality(problem55(), 249); },

      []() -> bool { return assertEquality(problem56(100), 972); },
      []() -> bool { return assertEquality(problem57(1000), 153); },
      []() -> bool { return assertEquality(problem58(1, 10), 26241); },
      []() -> bool { return assertEquality(problem59(), 107359); },
      []() -> bool { return assertEquality(problem60(5), 26033); },

      []() -> bool { return assertEquality(problem61(), 28684); },
      []() -> bool { return assertEquality(problem62(5), "127035954683"); },
      []() -> bool { return assertEquality(problem63(), 49); },
      []() -> bool { return assertEquality(problem64(10000), 1322); },
      []() -> bool { return assertEquality(problem65(100), 272); },

      []() -> bool { return assertEquality(problem66(1000), 661); },
      []() -> bool { return assertEquality(problem67(), 7273); },
      []() -> bool { return assertEquality(problem68(), "6531031914842725"); },
      []() -> bool { return assertEquality(problem69(1000000), 510510); },
      []() -> bool { return assertEquality(problem70(10000000), 8319823); },

      []() -> bool { return assertEquality(problem71(1000000), 428570); },
      []() -> bool { return assertEquality(problem72(1000000), 303963552391); },
      []() -> bool { return assertEquality(problem73(12000), 7295372); },
      []() -> bool { return assertEquality(problem74(1000000, 60), 402); },
      []() -> bool { return assertEquality(problem75(1500000), 161667); },

      []() -> bool { return assertEquality(problem76(100), 190569291); },
      []() -> bool { return assertEquality(problem77(5000), 71); },
      []() -> bool { return assertEquality(problem78(1000000), 55374); },
      []() -> bool { return assertEquality(problem79(), "73162890"); },
      []() -> bool { return assertEquality(problem80(100, 100), 40886); },

      []() -> bool { return assertEquality(problem81(80, 80), 427337); },
      []() -> bool { return assertEquality(problem82(80, 80), 260324); },
      []() -> bool { return assertEquality(problem83(80, 80), 425185); },
      []() -> bool { return assertEquality(problem84(4), "101524"); },
      []() -> bool { return assertEquality(problem85(2000000), 2772); },

      []() -> bool { return assertEquality(problem86(1000000), 1818); },
      []() -> bool { return assertEquality(problem87(50000000), 1097343); },
      []() -> bool { return assertEquality(problem88(12000), 7587457); },
      []() -> bool { return assertEquality(problem89(), 743); },
      []() -> bool { return assertEquality(problem90(), 1217); },

      []() -> bool { return assertEquality(problem91(50), 14234); },
      []() -> bool { return assertEquality(problem92(10000000), 8581146); },
      []() -> bool { return assertEquality(problem93(), 1258); },
      []() -> bool { return assertEquality(problem94(1000000000), 518408346); },
      []() -> bool { return assertEquality(problem95(1000000), 14316); },

      []() -> bool { return assertEquality(problem96(), 24702); },
      []() -> bool { return assertEquality(problem97(28433, 7830457), 8739992577); },
  };

  ifstream fin("run.txt");
  assertFileOpened(fin);

  string line;
  set<int32> problems;
  while (getline(fin, line)) {
    if (line.length() > 0 && line[0] != '#') {
      problems.insert(stringToNumber<int32>(line));
    }
  }

  if (problems.size() > 0) {
    int64 total = 0;
    int64 maxTime = -1;
    int32 maxProblem = -1;

    for (auto problem : problems) {
      if (problem < 1 || static_cast<uint32>(problem) > sizeof(checks) / sizeof(fpCheck)) {
        stringstream ss;
        ss << "Problem " << problem << " does not exist or has not been solved";
        throw string(ss.str());
      }

      ScopeTimer timer("", false);
      try {
        if (checks[problem - 1]()) {
          cout << "Problem " << problem << " SUCCEEDED! ";
        } else {
          cout << "Problem " << problem << " FAILED! ";
        }
      } catch (const string& e) {
        cout << "BAD! An excpetion was thrown: " << e << endl;
        cout << "Problem " << problem << " FAILED! ";
      } catch (...) {
        cout << "BAD! An unknown excpetion was thrown" << endl;
        cout << "Problem " << problem << " FAILED! ";
      }

      int64 elapsed = timer.getElapsedMilliseconds();
      cout << "(" << elapsed << " ms)" << endl;
      total += elapsed;

      if (elapsed > maxTime) {
        maxTime = elapsed;
        maxProblem = problem;
      }
    }

    cout << "Total time: " << total << " ms" << endl;
    cout << "Average time: " << total / problems.size() << " ms" << endl;
    cout << "Worst time: " << maxTime << " ms (problem " << maxProblem << ")" << endl;
  }
}

#include "SourceSuffix.h"
