CXXFLAGS=-Wall -Wextra -g -O2
CC=$(CXX)

2_lnko: 2_lnko.o lnko.o lkkt.o
lkkt.o: lkkt.cc lkkt.h lnko.h
lnko.o: lnko.cc lnko.h
2_lnko.o: 2_lnko.cc lnko.h lkkt.h
