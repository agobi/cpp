## Preprocessor
cpp -DNAME=test 1_cpp.txt
cpp 2_cpp.txt

## Preprocessor
g++ -E rational.cc

## Assebly
g++ -S rational.cc

## Compile and link
g++ -W -Wall -O2 -c rational.cc
g++ -W -Wall -O2 -c 3_rational_test.cc
g++ -o rational.o 3_rational_test.o -o 3_rational_test
