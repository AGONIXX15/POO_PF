COMPILER=g++
FLAGS=-Wall -std=c++17 -ggdb
INCLUDES=include
MAIN=main.cpp
SRC=src/*.cpp
BUILD=build

setup:
	mkdir -p build

compile:
	$(COMPILER) $(FLAGS) -I $(INCLUDES) $(MAIN) $(SRC) -o $(BUILD)/main

.PHONY: setup compile 
run:
	$(BUILD)/main


all: setup compile run
