analyze.exe: main.cpp libconvert_product-geometric-read_data.so libbubble_sort-insertion_sort-product.a
 g++ -std=c++17 main.cpp libbubble_sort-insertion_sort-product.a -L. -lconvert_product-geometric-read_data -o analyze.exe

libconvert_product-geometric-read_data.so: convert_product.cpp geometric.cpp read_data.cpp
 g++ -std=c++17 -shared -fPIC convert_product.cpp geometric.cpp read_data.cpp -o libconvert_product-geometric-read_data.so

libbubble_sort-insertion_sort-product.a: bubble_sort.cpp insertion_sort.cpp product.cpp
 g++ -std=c++17 -c bubble_sort.cpp insertion_sort.cpp product.cpp
 ar rcs libbubble_sort-insertion_sort-product.a bubble_sort.o insertion_sort.o product.o

clean:
 rm -f *.o *.a *.so analyze.exe
