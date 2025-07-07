CC = clang
CFLAGS = -std=c11 -O3 -g -Wall
CFLAGS += -Iinclude -Ilib/bec/include
LDFLAGS = -Llib/bec/bin
LDFLAGS += -lbec

BIN = bin
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, $(BIN)/src/%.o, $(SRC))

.PHONY: all libs clean run

all: dirs libs build

dirs:
	mkdir -p $(BIN)/src

libs:
	cd lib/bec && make all # bec

build: $(OBJ)
	$(CC) -o $(BIN)/effie $^ $(LDFLAGS)

$(BIN)/src/%.o: src/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(BIN)

run: all
	@echo "----------"
	@$(BIN)/effie $(ARGS)
	@echo "----------"

ARGS := $(wordlist 2, $(words $(MAKECMDGOALS)), $(MAKECMDGOALS))
