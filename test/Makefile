CXX=g++ -std=c++11
# Includes, cflags
INCLUDES=-I../include -L../lib
CXXOPTS=-Wall -O2 -g
CXXFLAGS=$(CXXOPTS) $(INCLUDES)
# Libs flags
LDLIBS=-ldatastructures
# Binaries
TARGETS=test_array

all:$(TARGETS)

clean:
	rm -f $(TARGETS)

default:
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDLIBS)
