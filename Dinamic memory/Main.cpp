# include <iostream>
#include<cstdlib>
#include<ctime>

template<typename T>
void fill_Arr(T arr[], int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}

template<typename T>
void print_Arr(T arr[], int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}

template<typename T>
void arr_Add(T*& arr, int& length, int num) {
	if (num <= 0)
		return;
	T* tmp = new T[length + num]{};
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
	length += num;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	// Динамическая память
	int* pointer = new int;
	*pointer = 7;
	std::cout << "pointer = " << pointer << "\n\n";
	std::cout << "*pointer = " << *pointer << "\n\n";

	delete pointer; // Освобождение области памяти, на которую направлен указатель
	pointer = nullptr;

	pointer = new int;
	std::cout << "pointer = " << pointer << "\n\n";
	std::cout << "*pointer = " << *pointer << "\n\n";

	// Динамические одномерные массивы
	std::cout << "Enter size of array -> ";
	int dsize;
	std::cin >> dsize;
	int* darr = new int[dsize];
	std::cout << std::endl;
	srand(time(NULL));
	for (short i = 0; i < dsize; i++) {
		darr[i] = rand() % 11 + 10;
		std::cout << darr[i] << ' ';
	}
	std::cout << std::endl;

	delete[] darr;

	// Динамические двумерные массивы
	int rows = 5, cols = 4;
	// Выделение памяти 
	int** dmx = new int*[rows];
	for (short i = 0; i < rows; i++)
		dmx[i] = new int[cols];
	// Чистка памяти
	for (short i = 0; i < rows; i++)
		delete[] dmx[i];
	delete[] dmx;

	// Задача 1. Увеличение размера массива
	std::cout << "Task 1\n\nEnter a size of array -> ";
	int size1;
	std::cin >> size1;
	int* arr1 = new int[size1];
	fill_Arr(arr1, size1, 1, 11);
	std::cout << std::endl << "Source array is: ";
	print_Arr(arr1, size1);
	std::cout << "Enter a number of new elements -> ";
	std::cin >> n;
	arr_Add(arr1, size1, n);
	print_Arr(arr1, size1);
	std::cout << std::endl;

	delete[] arr1;
	arr1 = nullptr;

	return 0;
}