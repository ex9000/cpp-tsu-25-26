analyze.exe: main.cpp libminimum-read_data-selection_sort.a libbubble_sort-convert_product.so
	g++ -std=c++17 main.cpp \
		libminimum-read_data-selection_sort.a \
		-L. -lbubble_sort-convert_product -o analyze.exe

libminimum-read_data-selection_sort.a: minimum.cpp read_data.cpp selection_sort.cpp
	g++ -std=c++17 -c minimum.cpp read_data.cpp selection_sort.cpp
	ar rcs libminimum-read_data-selection_sort.a minimum.o read_data.o selection_sort.o

libbubble_sort-convert_product.so: bubble_sort.cpp convert_product.cpp libminimum-read_data-selection_sort.a
	g++ -std=c++17 -shared -fPIC bubble_sort.cpp convert_product.cpp \
		libminimum-read_data-selection_sort.a -o libbubble_sort-convert_product.so