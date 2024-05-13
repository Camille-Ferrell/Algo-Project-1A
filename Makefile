Main: Main.o Code.o 
	g++ main.o Code.o -o Main

Main.o: Main.cpp Code.h
	g++ -c Main.cpp

Code.o: Code.cpp Code.h
	g++ -c Code.cpp

clean:
	rm -rf *.o main
