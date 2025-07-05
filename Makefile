CC = clang
CFLAGS = -std=c11 -O3 -g -Wall
CFLAGS += -Iinclude

BIN = bin
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, $(BIN)/src/%.o, $(SRC))

.PHONY: all clean run

all: dirs build

dirs:
	mkdir -p $(BIN)/src

build: $(OBJ)
	$(CC) -o $(BIN)/effie $^ #liblink

$(BIN)/src/%.o: src/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(BIN)

run: all
	@echo "----------"
	@$(BIN)/effie
	@echo "----------"
