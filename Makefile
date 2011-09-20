SRC := $(shell ls ./*.c)
OBJS = $(SRC:.c=.o)

TAR_EXEC := a
TAR_LIB := tree.so
TAR_ALIB := tree.a

CFLAGS += -g

default:$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TAR_EXEC)
	$(CC) $(CFLAGS) $(OBJS) -shared -o $(TAR_LIB)
	ar -r $(TAR_ALIB) $(OBJS)
clean:
	rm $(OBJS) $(TAR_EXEC) $(TAR_LIB) $(TAR_ALIB)
