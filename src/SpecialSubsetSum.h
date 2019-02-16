#pragma once

#include "Common.h"

vector<pair<vector<int32>, vector<int32>>> disjointInequalityChecks(int32 n);
bool isValidSpecialSubset(
    const vector<int32>& partition, const vector<pair<vector<int32>, vector<int32>>>& disjointChecks);
