APP=asrepl
CC=gcc
CFLAGS=-g3 -O0 -Wall -DASSEMBLER=\"$(AS)\"
SRCS=main.c asrepl_commands.c asrepl.c
OBJS=$(SRCS:.c=.o)
LDFLAGS=-lreadline 

all: $(APP)

$(APP): $(OBJS)
	$(CC) $^ -o $@ $(LDFLAGS)

clean:
	$(RM) $(OBJS) $(APP)
