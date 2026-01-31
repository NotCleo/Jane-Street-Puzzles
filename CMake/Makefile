# Define the compiler
CC = gcc

# Define compile flags 
CFLAGS = -Wall -g

# The final executable 
TARGET = my_program

# Rule to link everything together
# It depends on main.o and helper.o
$(TARGET): main.o helper.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o helper.o

# Rule to compile main.c into main.o
main.o: main.c helper.h
	$(CC) $(CFLAGS) -c main.c

# Rule to compile helper.c into helper.o
helper.o: helper.c helper.h
	$(CC) $(CFLAGS) -c helper.c

clean:
	rm -f *.o $(TARGET)
