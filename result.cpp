#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;
#include "combination.h"
// Флеш роял -  12 флеш+1
// Стрит флеш - 11 флеш+стрит
// Каре -       8
// Фулл хаус -  7 сет+две пары
// Флеш -       6
// Стрит -      5
// Сет(тройка)- 4
// Две пары -   3
// Пара -       2
//определение комбинации
int hodCasino(int* array) {
	//проверяем флеш роял - карты одной масти с 10
	if (flash(array) == 12) {
		cout << "Флеш роял" << endl;
		return 12;
	}
	//проверяем флеш - карты одной масти
	if (flash(array) == 6) {
		cout << "Флеш" << endl;
		return 6;
	}
	//проверяем стрит флеш - карты одной масти
	if (flash(array) == 11) {
		cout << "Стрит флеш" << endl;
		return 11;
	}
	//проверяем стрит - карты последовательно
	if (strit(array) == 5) {
		cout << "Стрит" << endl;
		return 5;
	}
	//проверяем каре - четыре карты одного достоинства
	if (kare(array) == 8) {
		cout << "Каре" << endl;
		return 8;
	}
	//проверяем сет - три карты одного достоинства возврвщает 1//фулл хаус возвращает 2
	if (set(array) == 4) {
		cout << "Сет" << endl;
		return 4;
	}
	//проверяем фулл хаус - три карты одного достоинства и пара
	if (set(array) == 7) {
		cout << "Фулл хаус" << endl;
		return 7;
	}
	//проверяем две пары возврашает 
	if (para(array) == 3) {
		cout << "Две пары" << endl;
		return 3;
	}
	//проверяем пару
	if (para(array) == 2) {
		cout << "Пара" << endl;
		return 2;
	}
	//получаем старшую
	return 0;
}