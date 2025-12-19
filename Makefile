.DEFAULT_GOAL := help

CXX := g++
PYTHON := uv run python
OPTION := -std=c++2b -O2 -D DEBUG -I /ac-library -Wall -Wextra -Wshadow -Wconversion -Wno-sign-conversion

SRC ?= main.cpp
SRC_CORRECT ?= main_correct.cpp
SRC_TESTCASES ?= main_testcases.cpp
BUILD_DIR := Bin/

SRC_FLAT = $(subst /,_,$(SRC))
SRC_COPY_FLAT = $(BUILD_DIR)/$(SRC_FLAT:.cpp=_copy.cpp)
BIN_RUN = $(BUILD_DIR)/$(SRC_FLAT:.cpp=.out)
BIN_TEST := $(BUILD_DIR)/test.out

DEPENDS = $(BIN_RUN:.out=.d) $(BIN_TEST:.out=.d)
HEADERS = $(shell find ./ -name "*.hpp")

$(SRC_COPY_FLAT): $(SRC) $(HEADERS)
	@$(PYTHON) Command/inline_includes.py $< | tee $@ | xsel -bi

$(BIN_RUN): $(SRC) $(HEADERS)
	@$(CXX) $(OPTION) $< -MMD -MP -o $@

$(BIN_TEST): $(SRC) $(HEADERS)
	@$(CXX) $(OPTION) $< -D TEST -MMD -MP -o $@

.PHONY: i
i: ## reset
	@cp Library/Main/$(SRC) ./$(SRC)
	@cp Library/Main/$(SRC) ./$(SRC_CORRECT)
	@cp Library/Main/$(SRC) ./$(SRC_TESTCASES)
	@rm -f *.o

.PHONY: y
y: $(SRC_COPY_FLAT) ## yank
	@$(CXX) $(OPTION) $(SRC_COPY_FLAT) -o tmp && rm -r tmp

.PHONY: r
r: $(BIN_RUN) ## run
	@./$^ < i

.PHONY: ri
ri: $(BIN_RUN) ## run without input
	@./$^

.PHONY: t
t: ## test
	@$(PYTHON) Command/debug_compare.py $(SRC) $(SRC_CORRECT) $(SRC_TESTCASES) | tee i

.PHONY: ti
ti: ## interactive test
	@$(PYTHON) Command/debug_interactive.py $(SRC) $(SRC_TESTCASES) | tee i

.PHONY: c
c: $(BIN_RUN) ## compile

.PHONY: clean
clean: ## clean
	@rm -f $(BUILD_DIR)/*
	@rm -f *.o

-include $(DEPENDS)

.PHONY: help
help: ## show this help
	@echo 'Usage: make [Targets]'
	@echo ''
	@echo 'Targets:'
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(firstword $(MAKEFILE_LIST)) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'
