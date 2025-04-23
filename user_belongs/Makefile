CC ?= gcc
CPPFLAGS = -D_GNU_SOURCE
CFLAGS = -Wall -Werror -Wextra -std=c99

BIN = user_belongs
OBJS = $(BIN).o

all: $(BIN)
$(BIN): $(OBJS)
clean:
	$(RM) $(BIN) $(OBJS)
