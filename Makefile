COMPILER=g++
FLAGS=-Wall -std=c++17
INCLUDES=-I include
MAIN=main.cpp
SRC=src/**/*.cpp
BUILD=build

setup:
	# Crear el directorio build
	mkdir -p build

compile:
	# Compilar el proyecto
	$(COMPILER) $(FLAGS) $(INCLUDES) $(MAIN) $(SRC) -o $(BUILD)/main

.PHONY: setup compile run

run:
	# Ejecutar el programa
	$(BUILD)/main

all: setup compile run

