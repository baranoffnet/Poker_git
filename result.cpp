#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;
#include "combination.h"
// ???? ???? -  12 ????+1
// ????? ???? - 11 ????+?????
// ???? -       8
// ???? ???? -  7 ???+??? ????
// ???? -       6
// ????? -      5
// ???(??????)- 4
// ??? ???? -   3
// ???? -       2
//??????????? ??????????
int hodCasino(int* array) {
	//?????????? ????
	int m = flash(array);
	//????????? ???? ???? - ????? ????? ????? ? 10
		if (m == 12) return 12;
		//????????? ???? - ????? ????? ?????
		if (m == 6) return 6;
		//????????? ????? ???? - ????? ????? ?????
		if (m == 11) return 11;
	//????????? ????? - ????? ???????????????
	if (strit(array) == 5) return 5;
	//????????? ???? - ?????? ????? ?????? ???????????
	if (kare(array) == 8) return 8;
	//????????? ??? - ??? ????? ?????? ??????????? ?????????? 1//???? ???? ?????????? 2
	if (set(array) == 4) return 4;
	//????????? ???? ???? - ??? ????? ?????? ??????????? ? ????
	if (set(array) == 7) return 7;
	//????????? ??? ???? ?????????? 
	if (para(array) == 3) return 3;
	//????????? ????
	if (para(array) == 2) return 2;
	//???????? ???????
	return big(array);
}