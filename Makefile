.DEFAULT_GOAL := help

SRC := main.cpp
BIN_RUN := bin/run.out
BIN_TEST := bin/test.out
OPTION := -std=c++2b -O2 -D DEBUG -I ./ac-library

$(BIN_RUN): $(SRC)
	@g++-11 $(OPTION) $< -o $@

$(BIN_TEST): $(SRC)
	@g++-11 $(OPTION) $< -D TEST -o $@

.PHONY: r
r: $(BIN_RUN) ## run
	@./$^ < i

.PHONY: t
t: $(BIN_TEST) ## test
	@./$^ < i | tee i

.PHONY: clean
clean: ## clean
	@rm -f $(BIN_RUN) $(BIN_TEST)

.PHONY: help
help: ## show this help
	@echo 'Usage: make [Targets]'
	@echo ''
	@echo 'Targets:'
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(firstword $(MAKEFILE_LIST)) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'
