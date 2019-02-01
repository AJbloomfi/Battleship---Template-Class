a.out:main.cpp gameClass.o list.o
	g++ -std=c++11 main.cpp gameClass.o list.o
gameClass.o: gameClass.cpp gameClass.h
	g++ -std=c++11 -c gameClass.cpp
list.o: list.cpp list.h
	g++ -std=c++11 -c list.cpp
clean:
	rm *.o a.out
