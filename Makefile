NAME := tree

CFLAGS += -g
SRC := $(shell ls ./*.c)
OBJS := $(SRC:.c=.o)

TAR_EXEC := a
TAR_LIB := lib$(NAME).so
TAR_ALIB := lib$(NAME).a

default:$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TAR_EXEC)
	$(CC) $(CFLAGS) $(OBJS) -shared -o $(TAR_LIB)
	ar -r $(TAR_ALIB) $(OBJS)
exec:$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TAR_EXEC)
lib:$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -shared -o $(TAR_LIB)
ar:$(OBJS)
	ar -r $(TAR_ALIB) $(OBJS)
clean:
	rm -f $(OBJS) $(TAR_EXEC) $(TAR_LIB) $(TAR_ALIB)
dist clean:
	rm -f $(OBJS) $(TAR_EXEC) $(TAR_LIB) $(TAR_ALIB)
