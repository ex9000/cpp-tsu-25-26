CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall

# Цель по умолчанию — сборка исполняемого файла analyze.exe
all: analyze.exe

# Динамическая библиотека с функциями convert_product, minimum, read_data
libconvert_product-minimum-read_data.so: convert_product.o minimum.o read_data.o
	$(CXX) -shared -fPIC -o $@ $^

# Статическая библиотека с harmonic и selection_sort
libharmonic-selection_sort.a: harmonic.o selection_sort.o
	ar rcs $@ $^

# Основная программа с линковкой библиотек
analyze.exe: main.o libconvert_product-minimum-read_data.so libharmonic-selection_sort.a
	$(CXX) $(CXXFLAGS) -o $@ main.o -L. -lharmonic-selection_sort -lconvert_product-minimum-read_data

# Правило компиляции .cpp в .o (с PIC для создания .so)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -fPIC -c $<

# Очистка файлов сборки
clean:
	rm -f *.o *.a *.so analyze.exe
