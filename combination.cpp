#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;
#include "show.h"
//флеш роял - карты одной масти от 10 до туза
int flashRoyl(int* array) {
	if (array[0] % 100 == 10) {
		for (int i = 0; i < 4; i++) {
			if ((array[i] % 100 + 1) != array[i + 1] % 100) {
				cout << "не флеш роял" << endl;
				return 1;
				break;
			}
		}
		return 2;
	}
	return 1;
}
//флеш - карты одной масти
int flash(int* array) {
	int temp;
	for (int i = 0; i < 5 - 1; i++) {
		for (int j = 0; j < 5 - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	cout << "Сортировка flash" << endl;
	showArray(array);
	for (int i = 0; i < 4; i++) {
		if (array[i] / 100 != array[i + 1] / 100) {
			cout << "не флеш" << endl;
			return 0;
			break;
		}
	}

	return flashRoyl(array);

}
//стрит - последовательно расположенные карты
int strit(int* array) {
	int temp;
	for (int i = 0; i < 5 - 1; i++) {
		for (int j = 0; j < 5 - i - 1; j++) {
			if (array[j] % 100 > array[j + 1] % 100) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	cout << "Сортировка strit" << endl;
	showArray(array);
	for (int i = 0; i < 4; i++) {
		if ((array[i] % 100) + 1 != array[i + 1] % 100) {
			cout << "не стрит" << endl;
			return 0;
			break;
		}
	}
	return 1;
}
//каре - 4 карты одного достоинства
int kare(int* array) {
	int temp;
	int counter = 0;
	for (int i = 0; i < 5 - 1; i++) {
		for (int j = 0; j < 5 - i - 1; j++) {
			if (array[j] % 100 > array[j + 1] % 100) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	cout << "Сортировка kare" << endl;
	showArray(array);
	for (int i = 0; i < 4; i++) {
		if ((array[i] % 100) == array[i + 1] % 100 && counter < 3) counter++;
		if ((array[i] % 100) != array[i + 1] % 100 && counter < 3 && counter > 0) {
			cout << "не каре" << endl;
			return 0;
			break;
		}
	}
	return 1;
}
//сет - три карты одного достоинства
int set(int* array) {
	int temp;
	int counter = 0;
	for (int i = 0; i < 5 - 1; i++) {
		for (int j = 0; j < 5 - i - 1; j++) {
			if (array[j] % 100 > array[j + 1] % 100) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	cout << "Сортировка set" << endl;
	showArray(array);
	for (int i = 0; i < 4; i++) {
		if ((array[i] % 100) == array[i + 1] % 100 && counter < 2) counter++;
		if ((array[i] % 100) != array[i + 1] % 100 && counter < 2 && counter > 0) {
			cout << "не каре" << endl;
			return 0;
			break;
		}
	}
	return 1;
}
//две пары/пара
int Para(int* array) {
	int temp;
	int counter = 0;
	for (int i = 0; i < 5 - 1; i++) {
		for (int j = 0; j < 5 - i - 1; j++) {
			if (array[j] % 100 > array[j + 1] % 100) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	cout << "Сортировка две пары" << endl;
	showArray(array);
	for (int i = 0; i < 4; i++) {
		if ((array[i] % 100) == array[i + 1] % 100) {
			i++;
			counter++;
		}
	}
	return counter;
}