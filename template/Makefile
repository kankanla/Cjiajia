CXX = g++
CXXOPTS = -Wall -frepo -DGCC

main: main.o square.o
	$(CXX) $(CXXOPTS) -o main main.o square.o

main.o: main.cpp
	$(CXX) $(CXXOPTS) -c main.cpp

square.o: square.cpp
	$(CXX) $(CXXOPTS) -c square.cpp

clean:
	rm *.o main
