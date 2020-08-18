CC      := g++
CCSTD   := c++17
CCFLAGS := -lncurses

# Only for Unix
OS_NAME := $(shell uname -s | tr A-Z a-z)

ifeq ($(OS_NAME),Darwin)
	CCFLAGS += -largp
endif

snake: main.cpp snake.cpp
	$(CC) $^ -o $@ -std=$(CCSTD) $(CCFLAGS)
