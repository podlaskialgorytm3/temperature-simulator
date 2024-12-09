CC = gcc
CFLAGS = -Wall -Iinclude
OBJ = build/object-files
SRC = src
EXEC = build/executable

all: $(EXEC)/program

$(EXEC)/program: $(OBJ)/main.o $(OBJ)/temperature.o
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)/*.o $(EXEC)/program
