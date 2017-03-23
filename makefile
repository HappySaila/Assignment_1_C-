clean:
	rm *.o
	rm Driver

compile:
	g++ *.cpp -c
	g++ *.o -o Driver

run:
	make compile
	./Driver
