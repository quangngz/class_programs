# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Source and object files
SRC = main.c listops.c treeops.c
OBJ = main.o listops.o treeops.o

# Output program name
TARGET = program

# Default rule to build everything
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Individual compilation rules
main.o: main.c listops.h treeops.h
	$(CC) $(CFLAGS) -c main.c

listops.o: listops.c listops.h
	$(CC) $(CFLAGS) -c listops.c

treeops.o: treeops.c treeops.h
	$(CC) $(CFLAGS) -c treeops.c

# Clean rule to remove object files and the executable
clean:
	rm *.o
	rm *.exe

