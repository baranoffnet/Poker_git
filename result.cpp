#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;
#include "combination.h"
// ���� ���� -  12 ����+1
// ����� ���� - 11 ����+�����
// ���� -       8
// ���� ���� -  7 ���+��� ����
// ���� -       6
// ����� -      5
// ���(������)- 4
// ��� ���� -   3
// ���� -       2
//����������� ����������
int hodCasino(int* array) {
	//��������� ���� ���� - ����� ����� ����� � 10
	if (flash(array) == 12) {
		cout << "���� ����" << endl;
		return 12;
	}
	//��������� ���� - ����� ����� �����
	if (flash(array) == 6) {
		cout << "����" << endl;
		return 6;
	}
	//��������� ����� ���� - ����� ����� �����
	if (flash(array) == 11) {
		cout << "����� ����" << endl;
		return 11;
	}
	//��������� ����� - ����� ���������������
	if (strit(array) == 5) {
		cout << "�����" << endl;
		return 5;
	}
	//��������� ���� - ������ ����� ������ �����������
	if (kare(array) == 8) {
		cout << "����" << endl;
		return 8;
	}
	//��������� ��� - ��� ����� ������ ����������� ���������� 1//���� ���� ���������� 2
	if (set(array) == 4) {
		cout << "���" << endl;
		return 4;
	}
	//��������� ���� ���� - ��� ����� ������ ����������� � ����
	if (set(array) == 7) {
		cout << "���� ����" << endl;
		return 7;
	}
	//��������� ��� ���� ���������� 
	if (para(array) == 3) {
		cout << "��� ����" << endl;
		return 3;
	}
	//��������� ����
	if (para(array) == 2) {
		cout << "����" << endl;
		return 2;
	}
	//�������� �������
	return 0;
}