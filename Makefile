analyze.exe: main.cpp read_data.cpp convert_product.cpp geometric.cpp bubble_sort.cpp insertion_sort.cpp product.cpp
	g++ -std=c++17 main.cpp read_data.cpp convert_product.cpp geometric.cpp bubble_sort.cpp insertion_sort.cpp product.cpp -o analyze.exe

clean:
	rm -f *.o *.a *.so analyze.exe
