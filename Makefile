FLAGS:= -g -Wall
GXX:= g++

all: main

main: base_list.o main.o
	$(GXX) $(FLAGS) -o main base_list.o main.o
base_list.o: base_list.cpp base_list.h
	$(GXX) $(FLAGS) -c base_list.cpp
main.o:	main.cpp 
	$(GXX) $(FLAGS) -c main.cpp
clean: 
	rm -f main *.o
