clean:
	rm PrintManager.o
	rm StudentDatabaseDriver.o
	rm Student.o
	rm Driver

compile:
	g++ PrintManager.cpp -c
	g++ StudentDatabaseDriver.cpp -c
	g++ Student.cpp -c
	g++ PrintManager.o StudentDatabaseDriver.o Student.o -o Driver

run:
	make compile
	./Driver
