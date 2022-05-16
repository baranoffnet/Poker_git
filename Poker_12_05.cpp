#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;
#include "razdacha.h"
#include "show.h"
#include "combination.h"

//3 - черви 4 - буба 5 - крести 6 - пика

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
	int* casino = new int[5]{307,407,305,508,609};
	//ТЕСТ
	//razdacha(colodaArray, casino);
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
		break;
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