all: build

bin:
	mkdir -p bin

bin/main.method1.out: src/main.cpp
	g++ -O3 -g -DMethod1 src/main.cpp -o bin/main.method1.out

bin/main.method2.out: src/main.cpp
	g++ -O3 -g src/main.cpp -o bin/main.method2.out

build: bin/main.method1.out bin/main.method2.out

run: bin/main.method1.out bin/main.method2.out
	./bin/main.method1.out 1
	./bin/main.method2.out 2

cache_test: build
	valgrind --tool=cachegrind ./bin/main.method1.out 1
	valgrind --tool=cachegrind ./bin/main.method2.out 2



