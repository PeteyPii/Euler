#include "SourcePrefix.h"

#include "Common.h"
#include "SpecialSubsetSum.h"

int32 problem106(int32 n) {
  return disjointInequalityChecks(n).size();
}

#include "SourceSuffix.h"
