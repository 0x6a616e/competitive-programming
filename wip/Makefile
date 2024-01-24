CFLAGS = -O2 -std=c++11 -Wall -Wextra -Wshadow
CDFLAGS = --debug -std=c++11 -Wpedantic

main: *.cpp
	@echo "Compiling..."
	g++ $(CFLAGS) *.cpp -o main.out

debug: *.cpp
	@echo "Compiling for debugging..."
	g++ $(CDFLAGS) *.cpp -o main.out

clean:
	@echo "Deleting files..."
	rm main.out
