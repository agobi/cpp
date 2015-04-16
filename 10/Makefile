all: 3_rational_test
CC=$(CXX)
CXXFLAGS=-W -Wall -O2 -g
clean:
	rm -rf 3_rational_test.o 3_rational_test rational.o
3_rational_test: 3_rational_test.o rational.o
3_rational_test.o: 3_rational_test.cc rational.h
rational.o: rational.cc rational.h
