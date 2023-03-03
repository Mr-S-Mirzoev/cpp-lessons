.PHONY: create_bin basics functions clear

all: create_bin basics functions

create_bin:
	mkdir -p bin

basics: create_bin
	clang++ Lecture\ 1/basics.cpp -o bin/basics.out -std=c++17 -Wall

functions: create_bin
	clang++ Lecture\ 1/functions.cpp -o bin/functions.out -std=c++17 -Wall

clear:
	rm -rf bin/*
