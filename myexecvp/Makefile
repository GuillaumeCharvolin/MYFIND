CC ?= gcc
CPPFLAGS = -D_GNU_SOURCE
CFLAGS = -Wall -Werror -Wextra -std=c99 -pedantic

BIN = myexecvp
OBJS = $(BIN).o

all: $(BIN)
$(BIN): $(OBJS)
clean:
	$(RM) $(BIN) $(OBJS)
