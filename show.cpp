#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;

//просмотр массива
void showArray(int* array) {

	int size = _msize(array) / sizeof(array[0]);
	for (int i = 0; i < size; i++) {
		if (array[i] / 100 == 3) cout << char(3) << array[i] - 300 << " ";
		if (array[i] / 100 == 4) cout << char(4) << array[i] - 400 << " ";
		if (array[i] / 100 == 5) cout << char(5) << array[i] - 500 << " ";
		if (array[i] / 100 == 6) cout << char(6) << array[i] - 600 << " ";
	}
	cout << endl;
}