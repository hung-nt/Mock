NC='\033[0m'       # No color

# Bold
BBlack='\033[1;30m'       # Black
BRed='\033[1;31m'         # Red
BGreen='\033[1;32m'       # Green
BYellow='\033[1;33m'      # Yellow
BBlue='\033[1;34m'        # Blue
BPurple='\033[1;35m'      # Purple
BCyan='\033[1;36m'        # Cyan
BWhite='\033[1;37m'       # White

CXX ?= g++
CXXFLAGS := -std=c++11 -Wall -Wextra -Werror -pedantic -g
CXXFLAGS += -Wno-error

# Path
SRC_DIR = .
BUILD_DIR = build
BIN_DIR = bin

# Executable
BIN_NAME = runner

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
SRCS += $(wildcard $(SRC_DIR)/Controller/*.cpp)
SRCS += $(wildcard $(SRC_DIR)/Model/*.cpp)
SRCS += $(wildcard $(SRC_DIR)/View/*.cpp)

# Object files
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Main file
MAIN_SRC = main.cpp
MAIN_OBJ = $(BUILD_DIR)/main.o

# Flags
INCS = -I $(SRC_DIR) -I $(SRC_DIR)/Controller/inc -I $(SRC_DIR)/Model/inc -I $(SRC_DIR)/View/inc
LIBS = -lstdc++ -lm

.PHONY: all
all: build

.PHONY: build
build: dirs $(BIN_DIR)/$(BIN_NAME)
  
.PHONY: dirs
dirs:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BIN_DIR)
	@mkdir -p $(addprefix $(BUILD_DIR)/, $(dir $(SRCS)))

  
$(BIN_DIR)/$(BIN_NAME): $(OBJS) $(MAIN_OBJ)
	@echo $(BBlue)"Linking: $@"$(NC)
	$(CXX) $(OBJS) $(MAIN_OBJ) -o $@ $(LIBS)
 	
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/%.h
	@echo $(BYellow)"Compiling: $< -> $@ "$(NC)
	$(CXX) $(CXXFLAGS) $(INCS) -c $< -o $@

$(MAIN_OBJ): $(MAIN_SRC)
	@echo $(BYellow)"Compiling Main: $< -> $@ "$(NC)
	$(CXX) $(CXXFLAGS) $(INCS) -c $< -o $@

.PHONY: clean
clean:
	@echo $(BRed)"Cleaning up..."$(NC)
	@rm -rf $(BUILD_DIR) $(BIN_DIR)
	@echo $(BGreen)"Cleanup complete!"$(NC)