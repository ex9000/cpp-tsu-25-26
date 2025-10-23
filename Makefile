analyze.exe: main.cpp libaverage-bubble_sort-insertion_sort-read_data-sum.so libconvert_product.a
  g++ -std=c++17 main.cpp \
	    libconvert_product.a \
	    -L. -laverage-bubble_sort-insertion_sort-read_data-sum -o analyze.exe

libaverage-bubble_sort-insertion_sort-read_data-sum.so: average.cpp bubble_sort.cpp insertion_sort.cpp read_data.cpp sum.cpp
	g++ -std=c++17 -shared -fPIC average.cpp bubble_sort.cpp insertion_sort.cpp read_data.cpp sum.cpp -o libaverage-bubble_sort-insertion_sort-read_data-sum.so

libconvert_product.a: convert_product.cpp 
	g++ -std=c++17 -c convert_product.cpp 
	ar rcs libconvert_product.a convert_product.o 

clean:
	rm -f *.o *.a *.so analyze.exe
