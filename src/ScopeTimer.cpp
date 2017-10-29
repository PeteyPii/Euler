#include "SourcePrefix.h"

#include "ScopeTimer.h"

#include "Common.h"

ScopeTimer::ScopeTimer(string name, bool isVerbose)
    : m_t0(chrono::high_resolution_clock::now()), m_sName(name), m_bIsVerbose(isVerbose) {
  if (m_bIsVerbose) {
    cout << m_sName << " timer began now." << endl;
  }
}

ScopeTimer::~ScopeTimer() {
  if (m_bIsVerbose) {
    cout << m_sName << " timer finished after " << getElapsedMilliseconds()
         << " ms." << endl;
  }
}

int64 ScopeTimer::getElapsedMilliseconds() const {
  chrono::milliseconds timeElapsed =
      chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - m_t0);

  return timeElapsed.count();
}

#include "SourceSuffix.h"
