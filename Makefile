CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c99 -pedantic -fsanitize=address

BIN = myfind
SOURCE = $(shell find src/ -name *.c)

all: $(BIN)

$(BIN): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(BIN)

check: $(BIN) pytest

pytest:
	pytest

clean:
	$(RM) $(BIN)
