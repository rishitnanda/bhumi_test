# Makefile for Twixt-C

CC := gcc
CFLAGS := -Wall -Wextra -std=c11 -O2 -g
SRC_DIR := source
BUILD_DIR := build
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)
TARGET := twixt

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
    $(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(BUILD_DIR):
    mkdir -p $(BUILD_DIR)

run: $(TARGET)
    ./$(TARGET)

clean:
    rm -rf $(BUILD_DIR) $(TARGET)

-include $(DEPS)