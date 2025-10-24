analyze.exe: main.cpp libmaximum-product.a libconvert_product-read_data.a libselection_sort.so
	g++ main.cpp \
	    -L. libselection_sort.so \
	    libconvert_product-read_data.a \
	    libmaximum-product.a \
	    -o analyze.exe

libmaximum-product.a: maximum.cpp product.cpp
	g++ -c maximum.cpp product.cpp
	ar rcs libmaximum-product.a maximum.o product.o

libconvert_product-read_data.a: convert_product.cpp read_data.cpp
	g++ -c convert_product.cpp read_data.cpp
	ar rcs libconvert_product-read_data.a convert_product.o read_data.o

libselection_sort.so: selection_sort.cpp
	g++ -shared -fPIC selection_sort.cpp -o libselection_sort.so
