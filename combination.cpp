#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;
#include "show.h"
//���� ���� - ����� ����� ����� �� 10 �� ����
int flashRoyl(int* array) {
	if (array[0] % 100 == 10) {
		for (int i = 0; i < 4; i++) {
			if ((array[i] % 100 + 1) != array[i + 1] % 100) {
				cout << "�� ���� ����" << endl;
				return 1;
				break;
			}
		}
		return 2;
	}
	return 1;
}
//���� - ����� ����� �����
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
	cout << "���������� flash" << endl;
	showArray(array);
	for (int i = 0; i < 4; i++) {
		if (array[i] / 100 != array[i + 1] / 100) {
			cout << "�� ����" << endl;
			return 0;
			break;
		}
	}

	return flashRoyl(array);

}
//����� - ��������������� ������������� �����
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
	cout << "���������� strit" << endl;
	showArray(array);
	for (int i = 0; i < 4; i++) {
		if ((array[i] % 100) + 1 != array[i + 1] % 100) {
			cout << "�� �����" << endl;
			return 0;
			break;
		}
	}
	return 1;
}
//���� - 4 ����� ������ �����������
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
	cout << "���������� kare" << endl;
	showArray(array);
	for (int i = 0; i < 4; i++) {
		if ((array[i] % 100) == array[i + 1] % 100 && counter < 3) counter++;
		if ((array[i] % 100) != array[i + 1] % 100 && counter < 3 && counter > 0) {
			cout << "�� ����" << endl;
			return 0;
			break;
		}
	}
	return 1;
}
//��� - ��� ����� ������ �����������
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
	cout << "���������� set" << endl;
	showArray(array);
	for (int i = 0; i < 4; i++) {
		if ((array[i] % 100) == array[i + 1] % 100 && counter < 2) counter++;
		if ((array[i] % 100) != array[i + 1] % 100 && counter < 2 && counter > 0) {
			cout << "�� ����" << endl;
			return 0;
			break;
		}
	}
	return 1;
}
//��� ����/����
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
	cout << "���������� ��� ����" << endl;
	showArray(array);
	for (int i = 0; i < 4; i++) {
		if ((array[i] % 100) == array[i + 1] % 100) {
			i++;
			counter++;
		}
	}
	return counter;
}