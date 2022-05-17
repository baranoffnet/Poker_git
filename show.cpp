#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;

// ���� ���� -  12 ����+1
// ����� ���� - 11 ����+�����
// ���� -       8
// ���� ���� -  7 ���+��� ����
// ���� -       6
// ����� -      5
// ���(������)- 4
// ��� ���� -   3
// ���� -       2

//�������� �������
void showArray(int* array) {

	int size = _msize(array) / sizeof(array[0]);
		//cout << " --------------------------" << endl;
		cout << " |";
	for (int i = 0; i < size; i++) {
		if (array[i] / 100 == 3 && array[i] % 100 <= 10) cout << char(3) << array[i] - 300  << "|";
		if (array[i] / 100 == 4 && array[i] % 100 <= 10) cout << char(4) << array[i] - 400  << "|";
		if (array[i] / 100 == 5 && array[i] % 100 <= 10) cout << char(5) << array[i] - 500  << "|";
		if (array[i] / 100 == 6 && array[i] % 100 <= 10) cout << char(6) << array[i] - 600  << "|";
		//�����
		if (array[i] / 100 == 3 && array[i] % 100 == 11) cout << char(3) << "�"  << "|";
		if (array[i] / 100 == 4 && array[i] % 100 == 11) cout << char(4) << "�"  << "|";
		if (array[i] / 100 == 5 && array[i] % 100 == 11) cout << char(5) << "�"  << "|";
		if (array[i] / 100 == 6 && array[i] % 100 == 11) cout << char(6) << "�"  << "|";
		//����
		if (array[i] / 100 == 3 && array[i] % 100 == 12) cout << char(3) << "�"  << "|";
		if (array[i] / 100 == 4 && array[i] % 100 == 12) cout << char(4) << "�"  << "|";
		if (array[i] / 100 == 5 && array[i] % 100 == 12) cout << char(5) << "�"  << "|";
		if (array[i] / 100 == 6 && array[i] % 100 == 12) cout << char(6) << "�"  << "|";
		//������
		if (array[i] / 100 == 3 && array[i] % 100 == 13) cout << char(3) << "�"  << "|";
		if (array[i] / 100 == 4 && array[i] % 100 == 13) cout << char(4) << "�"  << "|";
		if (array[i] / 100 == 5 && array[i] % 100 == 13) cout << char(5) << "�"  << "|";
		if (array[i] / 100 == 6 && array[i] % 100 == 13) cout << char(6) << "�"  << "|";
		//���
		if (array[i] / 100 == 3 && array[i] % 100 == 14) cout << char(3) << "�"  << "|";
		if (array[i] / 100 == 4 && array[i] % 100 == 14) cout << char(4) << "�"  << "|";
		if (array[i] / 100 == 5 && array[i] % 100 == 14) cout << char(5) << "�"  << "|";
		if (array[i] / 100 == 6 && array[i] % 100 == 14) cout << char(6) << "�"  << "|";
	}
	cout << endl;
	//cout << " -------------------------" << endl;
}
string showArrayVin(int vin) {
	if (vin == 2) return "����";
	if (vin == 3) return "��� ����";
	if (vin == 4) return "���";
	if (vin == 5) return "�����";
	if (vin == 6) return "����";
	if (vin == 7) return "���� ����";
	if (vin == 8) return "����";
	if (vin == 11) return "����� ����";
	if (vin == 12) return "���� ����";
	return "����������";
}