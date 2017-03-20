clean:
	rm PrintManager.o
	rm StudentDatabaseDriver.o
	rm Driver

compile:
	g++ PrintManager.cpp -c
	g++ StudentDatabaseDriver.cpp -c
	g++ PrintManager.o StudentDatabaseDriver.o -o Driver

cleanrun:
	make clean
	make compile
	./Driver

run:
	make compile
	./Driver
