.DEFAULT_GOAL := help

SRC ?= main.cpp

BUILD_DIR := Bin/
SRC_FLAT = $(subst /,_,$(SRC))
BIN_RUN = $(BUILD_DIR)/$(SRC_FLAT:.cpp=.out)
BIN_TEST := $(BUILD_DIR)/test.out
OPTION := -std=c++2a -O2 -D DEBUG -I /ac-library
DEPENDS = $(BIN_RUN:.out=.d) $(BIN_TEST:.out=.d)

$(BIN_RUN): $(SRC)
	@g++-12 $(OPTION) $< -MMD -MP -o $@

$(BIN_TEST): $(SRC)
	@g++-12 $(OPTION) $< -D TEST -MMD -MP -o $@

.PHONY: i
i: ## reset
	@cp Library/Main/$(SRC) ./$(SRC)

.PHONY: y
y: ## yank
	@python Command/inline_includes.py $(SRC) | tee main_copy.cpp | xsel -bi

.PHONY: r
r: $(BIN_RUN) ## run
	@./$^ < i

.PHONY: t
t: $(BIN_TEST) ## test
	@./$^ < i | tee i

.PHONY: clean
clean: ## clean
	@rm -f $(BUILD_DIR)/*

-include $(DEPENDS)

.PHONY: help
help: ## show this help
	@echo 'Usage: make [Targets]'
	@echo ''
	@echo 'Targets:'
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(firstword $(MAKEFILE_LIST)) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'
