#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa matop
# Autor		: Rafael Granja (rafaelgranja2003@ufmg.br)
# Histórico	: 2022-10-15 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo   
#			: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
CFLAGS = -pg -Wall 
SRC = src
BIN = bin
OBJ = obj
INC = include
clean:
	rm -f $(BIN)/*
	rm -f $(OBJ)/*

all:
	$(CC) $(CFLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o
	$(CC) $(CFLAGS) -o $(BIN)/main.exe $(OBJ)/main.o
	$(BIN)/main.exe
