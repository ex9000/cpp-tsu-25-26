analyze.exe: main.cpp libbubble_sort-read_data.a libmedian-selection_sort.so libconvert_product-product.so
	g++ -std=c++17 main.cpp \
	    -L. -lmedian-selection_sort -lconvert_product-product \
	    libbubble_sort-read_data.a \
	    -o analyze.exe

libbubble_sort-read_data.a: bubble_sort.cpp read_data.cpp
	g++ -std=c++17 -c bubble_sort.cpp read_data.cpp
	ar rcs libbubble_sort-read_data.a bubble_sort.o read_data.o

libmedian-selection_sort.so: median.cpp selection_sort.cpp
	g++ -std=c++17 -shared -fPIC median.cpp selection_sort.cpp -o libmedian-selection_sort.so

libconvert_product-product.so: convert_product.cpp product.cpp
	g++ -std=c++17 -shared -fPIC convert_product.cpp product.cpp -o libconvert_product-product.so
	