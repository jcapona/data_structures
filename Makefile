CXX=g++ -std=c++11
INCLUDES=-Iinclude
CXXOPTS=-Wall -g -O2
CXXFLAGS=$(CXXOPTS) $(INCLUDES)
LDFLAGS=
LDLIBS=
LIB=lib/libdatastructures.a

default: all
# Object files
OBJS=src/array.o src/linked_list.o src/double_linked_list.o

all: lib $(LIB)

lib:
	mkdir lib

$(LIB): $(LIB)($(OBJS))

clean:
	rm -f lib/*.a src/*.o

%.d: %.cc
	$(CXX) -MM -MP -MF $@ -MT "$(@:.d=.o) $@" $(INCLUDES) $<

ifneq "$(MAKECMDGOALS)" "clean"
 -include $(OBJS:.o=.d)
endif
