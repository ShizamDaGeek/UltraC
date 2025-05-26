# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -I./src/include

# Directories
SRC_DIR = src
BUILD_DIR = build

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

# Output binary
TARGET = $(BUILD_DIR)/UltraC

# Default target
all: $(TARGET)

# Link all object files into final binary
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

# Compile each .c to .o into build/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(BUILD_DIR)/*.o $(TARGET)

.PHONY: all clean
