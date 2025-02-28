CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lglfw -ldl -lGL -lm
SRC_DIR = src
BUILD_DIR = build
TARGET = $(BUILD_DIR)/app

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

all: $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJ) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

run: all
	./$(TARGET)
