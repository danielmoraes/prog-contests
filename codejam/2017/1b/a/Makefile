SRC = a.cc
OBJ = a
CC = g++
FLAGS = -O2 -fomit-frame-pointer

all: clean build

clean:
	@rm -f a *.out

build: $(SRC)
	@$(CC) $(FLAGS) -o $(OBJ) $(SRC)
