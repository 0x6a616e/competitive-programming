CFLAGS = -O2 -std=c++11 -Wall
CDFLAGS = --debug -std=c++11 -Wpedantic

main: main.cpp
	@echo "Compiling..."
	g++ $(CFLAGS) main.cpp -o main.out

debug: main.cpp
	@echo "Compiling for debugging..."
	g++ $(CFLAGS) main.cpp -o main.out

clean:
	@echo "Deleting files..."
	rm main.out
