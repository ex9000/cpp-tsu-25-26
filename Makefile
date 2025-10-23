CXX = g++
CXXFLAGS = -std=c++17 -fPIC
AR = ar
ARFLAGS = rcs

MAIN = main.cpp
LIBSRC = convert_product.cpp read_data.cpp insertion_sort.cpp harmonic.cpp
PRODSRC = product.cpp

OBJ = $(LIBSRC:.cpp=.o)
PRODOBJ = $(PRODSRC:.cpp=.o)

LIBNAME = libconvert_product-harmonic-insertion_sort-read_data.a
PRODLIB = libproduct.so

EXEC = analyze.exe

.PHONY: all clean

all: $(PRODLIB) $(LIBNAME) $(EXEC)

$(EXEC): $(MAIN) $(LIBNAME) $(PRODLIB)
	$(CXX) $(MAIN) $(LIBNAME) -L. -lproduct -o $(EXEC) -Wl,-rpath,.

$(LIBNAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

$(PRODLIB): $(PRODSRC)
	$(CXX) $(CXXFLAGS) -shared $(PRODSRC) -o $(PRODLIB)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o *.a *.so $(EXEC)
