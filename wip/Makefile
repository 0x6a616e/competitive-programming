CFLAGS = -O2 -std=c++17 -Wall -Wextra -Wshadow
CDFLAGS = --debug -std=c++17 -Wpedantic

main: curr.cpp
	@echo "Compiling..."
	g++ $(CFLAGS) curr.cpp -o main.out

debug: curr.cpp
	@echo "Compiling for debugging..."
	g++ $(CDFLAGS) curr.cpp -o main.out

publish: curr.cpp
	@echo "Generating file for upload..."
	echo "#include <bits/stdc++.h> > upload.cpp"
	tail -n 2 curr.cpp >> upload.cpp
