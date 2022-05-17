#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;

// Флеш роял -  12 флеш+1
// Стрит флеш - 11 флеш+стрит
// Каре -       8
// Фулл хаус -  7 сет+две пары
// Флеш -       6
// Стрит -      5
// Сет(тройка)- 4
// Две пары -   3
// Пара -       2

//просмотр массива
void showArray(int* array) {

	int size = _msize(array) / sizeof(array[0]);
		//cout << " --------------------------" << endl;
		cout << " |";
	for (int i = 0; i < size; i++) {
		if (array[i] / 100 == 3 && array[i] % 100 <= 10) cout << char(3) << array[i] - 300  << "|";
		if (array[i] / 100 == 4 && array[i] % 100 <= 10) cout << char(4) << array[i] - 400  << "|";
		if (array[i] / 100 == 5 && array[i] % 100 <= 10) cout << char(5) << array[i] - 500  << "|";
		if (array[i] / 100 == 6 && array[i] % 100 <= 10) cout << char(6) << array[i] - 600  << "|";
		//валет
		if (array[i] / 100 == 3 && array[i] % 100 == 11) cout << char(3) << "В"  << "|";
		if (array[i] / 100 == 4 && array[i] % 100 == 11) cout << char(4) << "В"  << "|";
		if (array[i] / 100 == 5 && array[i] % 100 == 11) cout << char(5) << "В"  << "|";
		if (array[i] / 100 == 6 && array[i] % 100 == 11) cout << char(6) << "В"  << "|";
		//дама
		if (array[i] / 100 == 3 && array[i] % 100 == 12) cout << char(3) << "Д"  << "|";
		if (array[i] / 100 == 4 && array[i] % 100 == 12) cout << char(4) << "Д"  << "|";
		if (array[i] / 100 == 5 && array[i] % 100 == 12) cout << char(5) << "Д"  << "|";
		if (array[i] / 100 == 6 && array[i] % 100 == 12) cout << char(6) << "Д"  << "|";
		//король
		if (array[i] / 100 == 3 && array[i] % 100 == 13) cout << char(3) << "К"  << "|";
		if (array[i] / 100 == 4 && array[i] % 100 == 13) cout << char(4) << "К"  << "|";
		if (array[i] / 100 == 5 && array[i] % 100 == 13) cout << char(5) << "К"  << "|";
		if (array[i] / 100 == 6 && array[i] % 100 == 13) cout << char(6) << "К"  << "|";
		//туз
		if (array[i] / 100 == 3 && array[i] % 100 == 14) cout << char(3) << "Т"  << "|";
		if (array[i] / 100 == 4 && array[i] % 100 == 14) cout << char(4) << "Т"  << "|";
		if (array[i] / 100 == 5 && array[i] % 100 == 14) cout << char(5) << "Т"  << "|";
		if (array[i] / 100 == 6 && array[i] % 100 == 14) cout << char(6) << "Т"  << "|";
	}
	cout << endl;
	//cout << " -------------------------" << endl;
}
string showArrayVin(int vin) {
	if (vin == 2) return "Пара";
	if (vin == 3) return "Две пары";
	if (vin == 4) return "Сет";
	if (vin == 5) return "Стрит";
	if (vin == 6) return "Флеш";
	if (vin == 7) return "Фулл хаус";
	if (vin == 8) return "Каре";
	if (vin == 11) return "Стрит флеш";
	if (vin == 12) return "Флеш роял";
	return "Наибольшая";
}