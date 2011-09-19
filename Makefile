OBJS := main.o tree_node_base.o tree_base.o tree_operation.o

TARGET := a

default:$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
clean:
	rm -rf $(OBJS) $(EXEC)
