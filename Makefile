OBJS := main.o tree.o

TARGET := a

CFLAGS += -g

default:$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
clean:
	rm -rf $(OBJS) $(EXEC)
