#include "pch.h"
#include <iostream>
#include <ctime>
//3 - черви 4 - буба 5 - крести 6 - пика
using namespace std;
int flashRoyl(int* array);
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
	//int* casino = new int[5];
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
//флеш роял - карты одной масти от 10 до туза
int flashRoyl(int* array) {
	if (array[0] % 100 == 10) {
		for (int i = 0; i < 4; i++) {
			if (array[i] / 100 != array[i + 1] / 100) {
				cout << "не флеш роял" << endl;
				return 1;
				break;
			}
		}
	}
	return 2;
}
//каре - 4 карты одного достоинства
int kare(int* array) {
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
	cout << "Сортировка kare" << endl;
	showArray(array);
	for (int i = 0; i < 4; i++) {
		if ((array[i] % 100) == array[i + 1] % 100);
		else {
			i++;
			if ((array[i] % 100) != array[i + 1] % 100) {
				cout << "не каре" << endl;
				return 0;
				break;
			}
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
		if ((array[i] % 100) == array[i + 1] % 100) {
			counter++;
			if (counter == 3 && array[3] == array[4]) {
				return 2;
				break;
			}
			if (counter == 6 && array[0] == array[1]) {
				return 2;
				break;
			}
		}
		else {
			i++;
			if ((array[i] % 100) != array[i + 1] % 100) {
				i++;
				counter = 3;
				if ((array[i] % 100) != array[i + 1] % 100) {
					cout << "не set" << endl;
					return 0;
					break;
				}
			}
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
//определение комбинации
int hodCasino(int* array) {
	//проверяем флеш - карты одной масти
	cout << flash(array) << endl;
	//
	//проверяем стрит - карты последовательно
	cout << strit(array) << endl;
	//
	//проверяем стрит флеш - карты одной масти и последовательно
	//flash(array) и strit(array) должны вернуть по 1
	// 
	//проверяем флеш роял - карты одной масти и последовательно, первая карта 10
	//flash(array)- должен вернуть 2
	//
	//проверяем каре - четыре карты одного достоинства
	cout << kare(array) << endl;
	//
	//проверяем сет - три карты одного достоинства возврвщает 1//фулл хаус возвращает 2
	cout << set(array) << endl;
	//
	//проверяем две пары возврашает 2 //проверяем пару возвращает 1
	cout << Para(array) << endl;
	//

	return 1;
}
int main()
{
	setlocale(LC_ALL, "rus");
	//создаем колоду
	int* colodaArray = creatArray();
	cout << "создаем колоду" << endl;
	//мешаем колоду
	initcolodaArray(colodaArray);
	cout << "мешаем колоду" << endl;
	//раздача
	int gamer;
	cout << "Ввидите кол - во игроков" << endl;
	cin >> gamer;
	//казино всегда участвует в раздаче
	int* casino = new int[5]{};
	razdacha(colodaArray, casino);
	cout << "Карты КАЗИНО:" << endl;
	showArray(casino);
	//максимальное колличество игроков 4 + казино. калода 52 карты. в раздаче 5.
	//первоначально раздается 25 карт. игроки могут поменять все 5 карт или меньше один раз
	int* igrok1 = new int[5]{};
	int* igrok2 = new int[5]{};
	int* igrok3 = new int[5]{};
	int* igrok4 = new int[5]{};
	//кол-во игроков
	switch (gamer) {
	case 1: {
		razdacha(colodaArray, igrok1);
		cout << "Карты ИГРОКА1:" << endl;
		showArray(igrok1);
	}
	case 2: {
		razdacha(colodaArray, igrok1);
		cout << "Карты ИГРОКА1:" << endl;
		showArray(igrok1);
		razdacha(colodaArray, igrok2);
		cout << "Карты ИГРОКА2:" << endl;
		showArray(igrok2);
		break;
	}
	case 3: {
		razdacha(colodaArray, igrok1);
		cout << "Карты ИГРОКА1:" << endl;
		showArray(igrok1);
		razdacha(colodaArray, igrok2);
		cout << "Карты ИГРОКА2:" << endl;
		showArray(igrok2);
		razdacha(colodaArray, igrok3);
		cout << "Карты ИГРОКА3:" << endl;
		showArray(igrok3);
		break;
	}
	case 4: {
		razdacha(colodaArray, igrok1);
		cout << "Карты ИГРОКА1:" << endl;
		showArray(igrok1);
		razdacha(colodaArray, igrok2);
		cout << "Карты ИГРОКА2:" << endl;
		showArray(igrok2);
		razdacha(colodaArray, igrok3);
		cout << "Карты ИГРОКА3:" << endl;
		showArray(igrok3);
		razdacha(colodaArray, igrok4);
		cout << "Карты ИГРОКА4:" << endl;
		showArray(igrok4);
		break;
	}
	}
	//ход игрока
	int a; //выбор действия
	int b; //кол-во карт для обмена
	int k; //номер карты для обмена
	int m = 0; //счетчик ходов
	//ходит первый игрок
	if (m < gamer && m == 0) {
		cout << "Ходит игрок: " << m + 1 << endl;
		cout << "Для обмена нажмите 1:";
		cout << "Завершить ход нажмите 2:";
		cin >> a;
		switch (a)
		{
		case 1: //делаем обмен
			cout << "Сколько карт меняем?";
			cin >> b;
			//обмен карт	
			for (int i = 0; i < b; i++) {
				cout << "Укажите номер карты для обмена:";
				cin >> k;
				obmen(colodaArray, igrok1, k);
				cout << "Поменяли карту: " << k << endl;
				showArray(igrok1);
			}
			break;
		}
		m += 1;
	}
	//ходит второй игрок
	if (m < gamer && m == 1) {
		cout << "Ходит игрок: " << m + 1 << endl;
		cout << "Для обмена нажмите 1:";
		cout << "Завершить ход нажмите 2:";
		cin >> a;
		switch (a)
		{
		case 1: //делаем обмен
			cout << "Сколько карт меняем?";
			cin >> b;
			//обмен карт	
			for (int i = 0; i < b; i++) {
				cout << "Укажите номер карты для обмена:";
				cin >> k;
				obmen(colodaArray, igrok2, k);
				cout << "Поменяли карту: " << k << endl;
				showArray(igrok2);
			}
			break;
		}
		m += 1;
	}
	hodCasino(casino);
}