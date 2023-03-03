.PHONY: create_bin structs clear

all: create_bin structs

create_bin:
	mkdir -p bin

structs: create_bin
	clang++ Lecture\ 2/structs.cpp -o bin/structs.out -std=c++17 -Wall

clear:
	rm -rf bin/*
