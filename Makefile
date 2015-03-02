CC = g++
CPPFLAGS = -Wall -g -I$(INCLUDE)
SRC = ./src
INCLUDE = ./include
OBJ = ./obj
BIN = ./bin
DOC = ./doc
SOURCES := $(wildcard $(SRC)/*.cpp)
OBJECTS := $(SOURCES:$(SRC)/%.cpp=$(OBJ)/%.o)

all:necesario $(BIN)/main $(BIN)/pruebaTSP

necesario:
	mkdir $(OBJ) $(BIN)


$(BIN)/main:$(OBJ)/main.o $(OBJ)/TSPSolucion.o
	$(CC) $(CPPFLAGS) -o $@ $^ 2> salida

$(BIN)/pruebaTSP:$(OBJ)/pruebaTSP.o $(OBJ)/TSPSolucion.o
	$(CC) $(CPPFLAGS) -o $@ $^ 2> salida

$(OBJECTS): $(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $< 2> salida

# ************ Limpieza ************
clean:
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper: clean
	-rm $(BIN)/* doc/html/*