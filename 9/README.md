### Preprocessor examples

Simple text processing:
```
cpp -DNAME=test 1_cpp.txt
cpp 2_cpp.txt
```

Processing C++ source:
```
g++ -E rational.cc
```

### Generate assembly code
```
g++ -S rational.cc
```

## Compile and link
### Compile C++ source files
```
g++ -W -Wall -O2 -c rational.cc
g++ -W -Wall -O2 -c 3_rational_test.cc
```

### Link generated object files
```
g++ -o rational.o 3_rational_test.o -o 3_rational_test
```
