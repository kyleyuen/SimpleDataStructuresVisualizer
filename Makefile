CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -Iinclude
SRC_DIR := src
BIN_DIR := bin
TARGET := $(BIN_DIR)/demo

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:.cpp=.o)

.PHONY: test all clean

# default target
test: $(TARGET)
	@echo "Running demo..."
	./$(TARGET)

all: $(TARGET)

$(TARGET): $(SRCS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -rf $(BIN_DIR) *.o
