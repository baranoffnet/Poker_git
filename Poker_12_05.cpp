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
	initcolodaArray(colodaArray);     //мешаем колоду
	//раздача
	int gamer;
	cout << "Ввидите кол - во игроков:" << endl;
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
	int* casino = new int[5]{};
	razdacha(colodaArray, casino);
	cout << "Карты КАЗИНО:" << endl;
	cout << endl;
	cout << " |  |  |  |  |  |" << endl;
	cout << endl;
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
			cout << endl;
			showArray(igrok1);
			cout << endl;
			break;
		}
		case 2: {
			razdacha(colodaArray, igrok1);
			cout << "Карты ИГРОКА1:" << endl;
			cout << endl;
			showArray(igrok1);
			cout << endl;
			razdacha(colodaArray, igrok2);
			cout << "Карты ИГРОКА2:" << endl;
			cout << endl;
			showArray(igrok2);
			cout << endl;
			break;
		}
		case 3: {
			razdacha(colodaArray, igrok1);
			cout << "Карты ИГРОКА1:" << endl;
			cout << endl;
			showArray(igrok1);
			cout << endl;
			razdacha(colodaArray, igrok2);
			cout << "Карты ИГРОКА2:" << endl;
			cout << endl;
			showArray(igrok2);
			cout << endl;
			razdacha(colodaArray, igrok3);
			cout << "Карты ИГРОКА3:" << endl;
			cout << endl;
			showArray(igrok3);
			cout << endl;
			break;
		}
		case 4: {
			razdacha(colodaArray, igrok1);
			cout << "Карты ИГРОКА1:" << endl;
			cout << endl;
			showArray(igrok1);
			cout << endl;
			razdacha(colodaArray, igrok2);
			cout << "Карты ИГРОКА2:" << endl;
			cout << endl;
			showArray(igrok2);
			cout << endl;
			razdacha(colodaArray, igrok3);
			cout << "Карты ИГРОКА3:" << endl;
			cout << endl;
			showArray(igrok3);
			cout << endl;
			razdacha(colodaArray, igrok4);
			cout << "Карты ИГРОКА4:" << endl;
			cout << endl;
			showArray(igrok4);
			cout << endl;
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
		cout << "Для обмена нажмите 1:" << endl;
		cout << "Завершить ход нажмите 2:" << endl;
		cin >> a;
		switch (a)
		{
		case 1: //делаем обмен
			cout << "Сколько карт меняем?" << endl;
			cin >> b;
			//обмен карт	
			for (int i = 0; i < b; i++) {
				cout << "Укажите номер карты для обмена:" << endl;
				cin >> k;
				obmen(colodaArray, igrok1, k);
				cout << "Поменяли карту: " << k << endl << endl;
				showArray(igrok1);
				cout << endl;
			}
			break;
		}
		m += 1;
	}
	//ходит второй игрок
	if (m < gamer && m == 1) {
		cout << "Ходит игрок: " << m + 1 << endl;
		cout << "Для обмена нажмите 1:" << endl;
		cout << "Завершить ход нажмите 2:" << endl;
		cin >> a;
		switch (a)
		{
		case 1: //делаем обмен
			cout << "Сколько карт меняем?" << endl;
			cin >> b;
			//обмен карт	
			for (int i = 0; i < b; i++) {
				cout << "Укажите номер карты для обмена:" << endl;
				cin >> k;
				obmen(colodaArray, igrok2, k);
				cout << "Поменяли карту: " << k << endl << endl;
				showArray(igrok2);
				cout << endl;
			}
			break;
		}
		m += 1;
	}
	//ходит третий
	if (m < gamer && m == 2) {
		cout << "Ходит игрок: " << m + 1 << endl;
		cout << "Для обмена нажмите 1:" << endl;
		cout << "Завершить ход нажмите 2:" << endl;
		cin >> a;
		switch (a)
		{
		case 1: //делаем обмен
			cout << "Сколько карт меняем?" << endl;
			cin >> b;
			//обмен карт	
			for (int i = 0; i < b; i++) {
				cout << "Укажите номер карты для обмена:" << endl;
				cin >> k;
				obmen(colodaArray, igrok3, k);
				cout << "Поменяли карту: " << k << endl << endl;
				showArray(igrok3);
				cout << endl;
			}
			break;
		}
		m += 1;
	}
	//ходит четвертый
	if (m < gamer && m == 3) {
		cout << "Ходит игрок: " << m + 1 << endl;
		cout << "Для обмена нажмите 1:" << endl;
		cout << "Завершить ход нажмите 2:" << endl;
		cin >> a;
		switch (a)
		{
		case 1: //делаем обмен
			cout << "Сколько карт меняем?" << endl;
			cin >> b;
			//обмен карт	
			for (int i = 0; i < b; i++) {
				cout << "Укажите номер карты для обмена:" << endl;
				cin >> k;
				obmen(colodaArray, igrok4, k);
				cout << "Поменяли карту: " << k << endl<<endl;
				showArray(igrok4);
				cout << endl;
			}
			break;
		}
		m += 1;
	}
	//VIN
	cout << "Карты казино" << endl;
	showArray(casino);
	int vincasino = hodCasino(casino);
	switch (gamer) {
		case 1: {
			cout << "Результат Игрок 1" << endl;
			    int vinigrok1 = hodCasino(igrok1);
			    if (vinigrok1 > vincasino) {
					cout << "VIN Игрок 1 - ";
					cout << showArrayVin(vinigrok1) << endl;
				}
				else {
					cout << "VIN Казино - ";
					cout << showArrayVin(vincasino) << endl;
				}
			break;
		}
		case 2: {
			cout << "Результат Игрок 1" << endl;
				int vinigrok1 = hodCasino(igrok1);
				if (vinigrok1 > vincasino) {
					cout << "VIN Игрок 1 - ";
					cout << showArrayVin(vinigrok1) << endl;
				}
				else {
					cout << "VIN Казино - ";
					cout << showArrayVin(vincasino) << endl;
				}
			cout << "Результат Игрок 2" << endl;
			    int vinigrok2 = hodCasino(igrok2);
				if (vinigrok2 > vincasino) {
					cout << "VIN Игрок 2 - ";
					cout << showArrayVin(vinigrok2) << endl;
				}
				else {
					cout << "VIN Казино - ";
					cout << showArrayVin(vincasino) << endl;
				}
			break;
		}
		case 3: {
			cout << "Результат Игрок 1" << endl;
				int vinigrok1 = hodCasino(igrok1);
				if (vinigrok1 > vincasino) {
					cout << "VIN Игрок 1 - ";
					cout << showArrayVin(vinigrok1) << endl;
				}
				else {
					cout << "VIN Казино - ";
					cout << showArrayVin(vincasino) << endl;
				}
			cout << "Результат Игрок 2" << endl;
				int vinigrok2 = hodCasino(igrok2);
				if (vinigrok2 > vincasino) {
					cout << "VIN Игрок 2 - ";
					cout << showArrayVin(vinigrok2) << endl;
				}
				else {
					cout << "VIN Казино - ";
					cout << showArrayVin(vincasino) << endl;
				}
			cout << "Результат Игрок 3" << endl;
				int vinigrok3 = hodCasino(igrok3);
				if (vinigrok3 > vincasino) {
					cout << "VIN Игрок 3 - ";
					cout << showArrayVin(vinigrok3) << endl;
				}
				else {
					cout << "VIN Казино - ";
					cout << showArrayVin(vincasino) << endl;
				}
			break;
		}
		case 4: {
			cout << "Результат Игрок 1" << endl;
				int vinigrok1 = hodCasino(igrok1);
				if (vinigrok1 > vincasino) {
					cout << "VIN Игрок 1 - ";
					cout << showArrayVin(vinigrok1) << endl;
				}
				else {
					cout << "VIN Казино - ";
					cout << showArrayVin(vincasino) << endl;
				}
			cout << "Результат Игрок 2" << endl;
				int vinigrok2 = hodCasino(igrok2);
				if (vinigrok2 > vincasino) {
					cout << "VIN Игрок 2 - ";
					cout << showArrayVin(vinigrok2) << endl;
				}
				else {
					cout << "VIN Казино - ";
					cout << showArrayVin(vincasino) << endl;
				}
			cout << "Результат Игрок 3" << endl;
				int vinigrok3 = hodCasino(igrok3);
				if (vinigrok3 > vincasino) {
					cout << "VIN Игрок 3 - ";
					cout << showArrayVin(vinigrok3) << endl;
				}
				else {
					cout << "VIN Казино - ";
					cout << showArrayVin(vincasino) << endl;
				}
			cout << "Результат Игрок 4" << endl;
				int vinigrok4 = hodCasino(igrok4);
				if (vinigrok4 > vincasino) {
					cout << "VIN Игрок 4 - ";
					cout << showArrayVin(vinigrok4) << endl;
				}
				else {
					cout << "VIN Казино - ";
					cout << showArrayVin(vincasino) << endl;
				}
			break;
		}
	}
	
}