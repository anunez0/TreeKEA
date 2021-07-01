OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Almacen.o Sala.o Sistema.o
	g++ -o program.exe *.o

Almacen.o: Almacen.cc Almacen.hh Sala.hh Sistema.hh BinTree.hh
	g++ -c Almacen.cc $(OPCIONS)

Sala.o: Sala.cc Sala.hh
	g++ -c Sala.cc $(OPCIONS)

Sistema.o: Sistema.cc Sistema.hh
	g++ -c Sistema.cc $(OPCIONS)

program.o: program.cc Almacen.hh Sala.hh Sistema.hh
	g++ -c program.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
