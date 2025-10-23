analyze.exe: main.cpp libbubble_sort.a libaverage-convert_product-selection_sort.so libread_data.a
	g++ -std=c++17 -O2 -Wall main.cpp \
	    libbubble_sort.a libread_data.a -L. -laverage-convert_product-selection_sort \
	    -o analyze.exe

libbubble_sort.a: bubble_sort.cpp
	g++ -std=c++17 -O2 -Wall -c bubble_sort.cpp
	ar rcs libbubble_sort.a bubble_sort.o

libaverage-convert_product-selection_sort.so: average.cpp convert_product.cpp selection_sort.cpp
	g++ -std=c++17 -O2 -Wall -shared -fPIC average.cpp convert_product.cpp selection_sort.cpp -o libaverage-convert_product-selection_sort.so

libread_data.a: read_data.cpp
	g++ -std=c++17 -O2 -Wall -c read_data.cpp
	ar rcs libread_data.a read_data.o