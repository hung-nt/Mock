CXX ?= g++
CXXFLAGS := -std=c++11 -Wall -Wextra -pedantic -g
SRC = .
BUILD = build
BIN = bin
BIN_NAME = runner

# Source files
SRCS = $(wildcard $(SRC)/*.cpp $(SRC)/*/*/*.cpp)
# Header files
INCS = $(wildcard $(SRC)/*.h $(SRC)/*/*/*.h)

# Object files
OBJS = $(patsubst $(SRC)/%.cpp,$(BUILD)/%.o,$(SRCS))

# Include directories
INCS_DIRS = -I$(SRC) -I$(SRC)/Controller/inc -I$(SRC)/Model/inc -I$(SRC)/View/inc
LIBS = -lstdc++ -lm -lstdc++fs

.PHONY: default
default: build


.PHONY: build
build: dirs
	@$(MAKE) --no-print-directory all


.PHONY: dirs
dirs:
	@mkdir -p $(BUILD)
	@mkdir -p $(BIN)
	@mkdir -p $(BUILD)/Controller/src
	@mkdir -p $(BUILD)/Model/src
	@mkdir -p $(BUILD)/View/src

.PHONY: clean
clean:
	@rm -rf $(BUILD)
	@rm -rf $(BIN)

.PHONY: run
run: $(BIN)/$(BIN_NAME)
	@./$(BIN)/$(BIN_NAME)

.PHONY: all
all: $(BIN)/$(BIN_NAME)

# Check memory leak
.PHONY: valgrind
valgrind: dirs $(BIN)/$(BIN_NAME)
	@valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --track-origins=yes --num-callers=20 $(BIN)/$(BIN_NAME)

$(BIN)/$(BIN_NAME): $(OBJS)
	@$(CXX) $(OBJS) -o $@ ${LIBS}

$(BUILD)/%.o: $(SRC)/%.cpp
	@$(CXX) $(CXXFLAGS) $(INCS_DIRS) -c $< -o $@