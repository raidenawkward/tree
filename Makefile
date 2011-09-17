OBJS := main.o tree.o

TARGET := a

default:$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
clean:
	rm -rf $(OBJS) $(EXEC)
