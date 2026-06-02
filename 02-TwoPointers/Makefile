CXX      ?= g++
CXXFLAGS ?= -std=c++17 -O2 -Wall -Wextra
BUILD    := build

SRCS  := $(wildcard *.cpp)
NAMES := $(SRCS:.cpp=)
BINS  := $(addprefix $(BUILD)/,$(NAMES))

.PHONY: all clean list help $(NAMES) $(addprefix run-,$(NAMES))

all: $(BINS)

# Compile: build/<name> from <name>.cpp
$(BUILD)/%: %.cpp | $(BUILD)
	@echo "  CXX  $<"
	@$(CXX) $(CXXFLAGS) $< -o $@

$(BUILD):
	@mkdir -p $(BUILD)

# Shortcut: `make containsDuplicate`  →  builds build/containsDuplicate
$(NAMES): %: $(BUILD)/%

# Shortcut: `make run-containsDuplicate`  →  build + run
$(addprefix run-,$(NAMES)): run-%: $(BUILD)/%
	@echo "→ $<"
	@./$<

list:
	@printf '  %s\n' $(NAMES)

clean:
	@rm -rf $(BUILD)
	@echo "cleaned $(BUILD)/"

help:
	@echo "make                 build every .cpp in this folder"
	@echo "make <name>          build build/<name>"
	@echo "make run-<name>      build and run"
	@echo "make list            list problems in this folder"
	@echo "make clean           remove build/"
