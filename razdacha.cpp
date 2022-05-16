#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;
//создаем колоду
int* creatArray() {
	int* colodaArray = new int[] {302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 502, 503, 504, 505, 506, 507, 508, 509, 510, 511, 512, 513, 514, 602, 603, 604, 605, 606, 607, 608, 609, 610, 611, 612, 613, 614};
	return colodaArray;
}
//мешаем колоду
void initcolodaArray(int* colodaArray) {
	int size = _msize(colodaArray) / sizeof(colodaArray[0]);
	srand(time(NULL));
	for (int i = 0, j = 0; i < size; i++) {
		j = 1 + rand() % 9;
		swap(colodaArray[i], colodaArray[j]);
	}
}
//раздаем
int* razdacha(int*& colodaArray, int*& casino) {
	int size1 = _msize(colodaArray) / sizeof(colodaArray[0]);
	for (int i = 0; i < 5; i++) {
		casino[i] = colodaArray[i];
	}
	int* buf = new int[size1 - 5];
	for (int i = 0; i < size1 - 5; i++) {
		buf[i] = colodaArray[i + 5];
	}
	delete[]colodaArray;
	colodaArray = buf;
	return casino;
}
//обмен карт
int* obmen(int*& colodaArray, int*& igrok, int k) {
	int size1 = _msize(colodaArray) / sizeof(colodaArray[0]);
	igrok[k - 1] = colodaArray[0];
	int* buf = new int[size1 - 1];
	for (int i = 0; i < size1 - 1; i++) {
		buf[i] = colodaArray[i + 1];
	}
	delete[]colodaArray;
	colodaArray = buf;
	return igrok;
}