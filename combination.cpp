#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;
#include "show.h"
int flashRoyl(int* array);
int flash(int* array);
int strit(int* array);
int kare(int* array);
int set(int* array);
int para(int* array);
int big(int* array);

// ���� ���� -  12 ����+6
// ����� ���� - 11 ����+�����
// ���� -       8
// ���� ���� -  7 ���+��� ����
// ���� -       6
// ����� -      5
// ���(������)- 4
// ��� ���� -   3
// ���� -       2

void sortingM(int* array) {   //���������� �����
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
}
void sortingZ(int* array) {    //���������� �� ��������
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
}
//���� ���� - ����� ����� ����� �� 10 �� ����
int flashRoyl(int* array) {
	if (array[0] % 100 == 10) {
		for (int i = 0; i < 4; i++) {
			if ((array[i] % 100 + 1) != array[i + 1] % 100) {
				return 0;
			}
		}
		return 6;
	}
}
//���� - ����� ����� �����
int flash(int* array) {
	sortingM(array);
	for (int i = 0; i < 4; i++) {
		if (array[i] / 100 != array[i + 1] / 100) {
			return 0;
		}
	}
	if (flashRoyl(array) == 6) return 12;
	if (strit(array) == 5) return 11;
	return 6;

}
//����� - ��������������� ������������� �����
int strit(int* array) {
	sortingZ(array);
	for (int i = 0; i < 4; i++) {
		if ((array[i] % 100) + 1 != array[i + 1] % 100) {
			return 0;
		}
	}
	return 5;
}
//���� - 4 ����� ������ �����������
int kare(int* array) {
	int counter = 0;
	sortingZ(array);
	for (int i = 0; i < 4; i++) {
		if (array[i] % 100 == array[i + 1] % 100 && counter < 3) counter++;
		if (array[i] % 100 != array[i + 1] % 100 && counter < 3 && i>0) return 0;
	}
	return 8;
}
//��� - ��� ����� ������ �����������
int set(int* array) {
	int counter = 0;
	sortingZ(array);
	for (int i = 0; i < 4; i++) {
		if (array[i] % 100 == array[i + 1] % 100 && counter < 2) counter++;
		if (array[i] % 100 != array[i + 1] % 100 && i>1) {
			return 0;
		}
	}
	if (para(array) == 3) return 7;
	return 4;
}
//��� ����/����
int para(int* array) {
	int counter = 1;
	sortingZ(array);
	for (int i = 0; i < 4; i++) {
		if ((array[i] % 100) == array[i + 1] % 100) {
			i++;
			counter++;
		}
	}
	return counter;
}
//�������
int big(int* array) {
	sortingZ(array);
	return (array[4]%100)/10;
}