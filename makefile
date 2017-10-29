# Taken from https://spin.atomicobject.com/2016/08/26/makefile-c-projects/.

BUILD_DIR ?= ./build
SRC_DIRS ?= ./src
TARGETS_DIR ?= ./src/targets

HEADERS := $(shell find $(SRC_DIRS) -name '*.h')
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -not -path '$(TARGETS_DIR)/**')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)
TARGET_SRCS := $(shell find $(TARGETS_DIR) -name *.cpp)
TARGET_OBJS := $(TARGET_SRCS:%=$(BUILD_DIR)/%.o)
TARGET_EXECS := $(TARGET_SRCS:$(TARGETS_DIR)/%.cpp=$(BUILD_DIR)/%)

INC_DIRS := $(SRC_DIRS)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CXX := g++
CPPFLAGS ?= $(INC_FLAGS) -MMD -MP -std=c++1z -Wall -O3

all: $(TARGET_EXECS)

$(TARGET_EXECS): $(BUILD_DIR)/%: $(BUILD_DIR)/$(TARGETS_DIR)/%.cpp.o $(OBJS)
	@echo $(CXX) ... -o $@ $(LDFLAGS)
	@$(CXX) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean test format

clean:
	$(RM) -r $(BUILD_DIR)

test: $(BUILD_DIR)/euler
	$(BUILD_DIR)/euler

format:
	clang-format -i -style=file $(SRCS) $(TARGET_SRCS) $(HEADERS)

-include $(DEPS)

MKDIR_P ?= mkdir -p
