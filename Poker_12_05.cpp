#include "pch.h"
#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;
#include "razdacha.h"
#include "show.h"
#include "combination.h"
#include "result.h"

//3 - черви 4 - буба 5 - крести 6 - пика

int main()
{
	setlocale(LC_ALL, "rus");
	int* colodaArray = creatArray();  //создаем колоду
	cout << "создаем колоду" << endl;
	initcolodaArray(colodaArray);     //мешаем колоду
	cout << "мешаем колоду" << endl;

	//раздача
	int gamer;
	cout << "Ввидите кол - во игроков" << endl;
	cin >> gamer;
	for (int i = 0; i < 1;)
		if (gamer >= 5) {
			cout << "В видите количество игроков от 1 до 4 :" << endl;
			i = 0;
			cin >> gamer;
		}
		else break;
	//казино всегда участвует в раздаче
	//ТЕСТ
	int* casino = new int[5]{5};
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
			cout << "--------------" << endl;
			cout << "Карты ИГРОКА1:" << endl;
			showArray(igrok1);
			break;
		}
		case 2: {
			razdacha(colodaArray, igrok1);
			cout << "--------------" << endl;
			cout << "Карты ИГРОКА1:" << endl;
			showArray(igrok1);
			razdacha(colodaArray, igrok2);
			cout << "--------------" << endl;
			cout << "Карты ИГРОКА2:" << endl;
			showArray(igrok2);
			break;
		}
		case 3: {
			razdacha(colodaArray, igrok1);
			cout << "--------------" << endl;
			cout << "Карты ИГРОКА1:" << endl;
			showArray(igrok1);
			razdacha(colodaArray, igrok2);
			cout << "--------------" << endl;
			cout << "Карты ИГРОКА2:" << endl;
			showArray(igrok2);
			razdacha(colodaArray, igrok3);
			cout << "--------------" << endl;
			cout << "Карты ИГРОКА3:" << endl;
			showArray(igrok3);
			break;
		}
		case 4: {
			razdacha(colodaArray, igrok1);
			cout << "--------------" << endl;
			cout << "Карты ИГРОКА1:" << endl;
			showArray(igrok1);
			razdacha(colodaArray, igrok2);
			cout << "--------------" << endl;
			cout << "Карты ИГРОКА2:" << endl;
			showArray(igrok2);
			razdacha(colodaArray, igrok3);
			cout << "--------------" << endl;
			cout << "Карты ИГРОКА3:" << endl;
			showArray(igrok3);
			razdacha(colodaArray, igrok4);
			cout << "--------------" << endl;
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
	cout << "--------------" << endl;
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
		cout << "--------------" << endl;
	}
	//ходит третий
	if (m < gamer && m == 2) {
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
				obmen(colodaArray, igrok3, k);
				cout << "Поменяли карту: " << k << endl;
				showArray(igrok3);
			}
			break;
		}
		m += 1;
		cout << "--------------" << endl;
	}
	//ходит четвертый
	if (m < gamer && m == 3) {
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
				obmen(colodaArray, igrok4, k);
				cout << "Поменяли карту: " << k << endl;
				showArray(igrok4);
			}
			break;
		}
		m += 1;
		cout << "--------------"<<endl;
	}
	cout <<hodCasino(casino);
}