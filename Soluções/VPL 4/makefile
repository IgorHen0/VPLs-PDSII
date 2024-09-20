CC=g++
CFLAGS=-std=c++11 -Wall
SRC_DIR=src
INCLUDE_DIR=include
OBJ_DIR=obj

all: main

$(OBJ_DIR)/Banco.o: $(INCLUDE_DIR)/Banco.hpp $(SRC_DIR)/Banco.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Banco.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Banco.o

$(OBJ_DIR)/ContaBancaria.o: $(INCLUDE_DIR)/ContaBancaria.hpp $(SRC_DIR)/ContaBancaria.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/ContaBancaria.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/ContaBancaria.o

$(OBJ_DIR)/main.o: $(INCLUDE_DIR)/Banco.hpp $(INCLUDE_DIR)/ContaBancaria.hpp $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/main.o

main: $(OBJ_DIR)/Banco.o $(OBJ_DIR)/ContaBancaria.o $(OBJ_DIR)/main.o
	$(CC) $(CFLAGS) $(OBJ_DIR)/Banco.o $(OBJ_DIR)/ContaBancaria.o $(OBJ_DIR)/main.o -o vpl_execution

clean:
	rm -f $(OBJ_DIR)/*.o main