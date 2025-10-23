analyze.exe: main.cpp libaverage-convert_product.a libread_data-selection_sort-sum.so
	g++ main.cpp -L. -laverage-convert_product -lread_data-selection_sort-sum -o analyze.exe

libaverage-convert_product.a: average.cpp convert_product.cpp
	g++ -std=c++17 -c average.cpp convert_product.cpp
	ar rcs libaverage-convert_product.a average.o convert_product.o

libread_data-selection_sort-sum.so: read_data.cpp selection_sort.cpp sum.cpp
	g++ -std=c++17 -shared -fPIC read_data.cpp selection_sort.cpp sum.cpp -o libread_data-selection_sort-sum.so

clean:
	rm -f *.o *.a *.so *.exe

.PHONY: clean
