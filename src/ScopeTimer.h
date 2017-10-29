#pragma once

#include "Common.h"

class ScopeTimer {
public:
  ScopeTimer(string name, bool isVerbose = true);
  ~ScopeTimer();

  int64 getElapsedMilliseconds() const;

private:
  chrono::high_resolution_clock::time_point m_t0;
  string m_sName;
  bool m_bIsVerbose;
};
