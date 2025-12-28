CC = clang
CFLAGS = -std=c11 -O3 -g -Wall
CFLAGS +=  -Ilib -Iinclude -Ilib/bec/include $(shell pkg-config --cflags sdl3)
LDFLAGS = -Llib/bec/bin -lbec $(shell pkg-config --libs sdl3)

BIN = bin
SRC = $(shell find src -name '*.c')
OBJ = $(patsubst src/%.c,$(BIN)/%.o,$(SRC))

.PHONY: all dirs libs build clean run

all: dirs libs build

dirs:
	@ mkdir -p $(BIN)

libs:
	@ $(MAKE) -C lib/bec all > /dev/null 2>&1 && echo "[compile::success] bec"

build: $(OBJ)
	@ $(CC) -o $(BIN)/effie $^ $(LDFLAGS) -g

$(BIN)/%.o: src/%.c
	@ mkdir -p $(dir $@)
	@ $(CC) -o $@ -c $< $(CFLAGS)

clean:
	@ rm -rf $(BIN)

run: all
	@$(BIN)/effie assets/torrent-files/shaun-the-sheep-movie.torrent # hardcoding the torrent file paths for now
