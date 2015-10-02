CXXFLAGS ?= -std=c++11 -O2 -W -Wall -g

.PHONY: all clean
all: $(PROGRAMS)

clean:
	rm -rf $(PROGRAMS)  $(PROGRAMS:=.dSYM)
