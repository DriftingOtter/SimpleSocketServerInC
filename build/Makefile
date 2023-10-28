# Makefile for GTK C Project

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -fstack-protector-strong -D_FORTIFY_SOURCE=2 -Wformat-security -pie -fPIE -O3 -flto -funroll-loops -finline-functions -fomit-frame-pointer `pkg-config --cflags gtk+-4.0`

# Linker flags
LDFLAGS = `pkg-config --libs gtk+-3.0`

# Target executable name
TARGET = myapp

# Source files
SRC = main.c window.c

# Object files (automatically generated)
OBJ = $(SRC:.c=.o)

# Default target (executable)
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up intermediate object files and executable
clean:
	rm -f $(OBJ) $(TARGET)

