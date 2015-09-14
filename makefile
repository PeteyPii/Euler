CXX = g++
CXXFLAGS = -Wall -std=c++11

UNAME = $(shell uname)

ifneq (,$(findstring MINGW,$(UNAME)))
EXEC = Euler.exe
else
EXEC = Euler
endif

all: $(EXEC)

$(EXEC): Euler.cpp Euler.h Common.cpp Common.h
	$(CXX) $(CXXFLAGS) Euler.cpp Common.cpp -o $(EXEC)

test: $(EXEC)
	$(EXEC)

clean:
	rm -f $(EXEC)
