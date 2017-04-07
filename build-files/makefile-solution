SRC = answer.cc
OBJ = answer.o
CC = g++
FLAGS = -I../../include/ -O2 -fomit-frame-pointer

all: clean build

clean:
	@rm -f *.o

build: $(SRC)
	@$(CC) $(FLAGS) -o $(OBJ) $(SRC)
