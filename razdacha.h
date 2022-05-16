#pragma once

//создаем колоду
int* creatArray();
//мешаем колоду
void initcolodaArray(int* colodaArray);
//раздаем
int* razdacha(int*& colodaArray, int*& casino);
//обмен карт
int* obmen(int*& colodaArray, int*& igrok, int k);