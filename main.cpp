#include <iostream>
#include <iomanip>
#include "SetStruct.h"
#include "SetClass.h"
#include "SetList.h"
#include "Setset.h"
#include "Setunorderedset.h"
#include "Setbitset.h"
#include <Windows.h>
#define nl '\n';
using namespace std;
int Size_SetA;
int Size_SetB;
const int MIN_ELEM = 0;
const int MAX_ELEM_A = 10 * Size_SetA;
const int MAX_ELEM_B = 10 * Size_SetB;
const int MIN_LEN = 1000;
SetStruct* SetStrA;
SetStruct* SetStrB;
SetClass* SetClA, SetClB;
SetList* SetListA, SetListB;
Setset* SetsetA, SetsetB;
const string horizontLine = "\n---------------------------------------------------------------------------------------------------------------------\n";
const string title = horizontLine + "\t\t\t| Односвязный список | Класс список |    List    |     Set     |";
double Time[4];

void CreateSetTime() {
	clock_t start = clock();
	SetStrA = createnewSet(Size_SetA, 0, 10 * Size_SetA);
	clock_t end = clock();
	double time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[0] = time_createSet;
	start = clock();
	SetClA->createnewSet(Size_SetA, 0, 10 * Size_SetA);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[1] = time_createSet;
	start = clock();
	SetListA->createnewSet(Size_SetA, 0, 10 * Size_SetA);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[2] = time_createSet;
	start = clock();
	SetListA->createnewSet(Size_SetA, 0, 10 * Size_SetA);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[3] = time_createSet;
}

void lineWithParam(string text) {
	while (text.size() < 23) text += " ";
	string emptyCell1(18, ' ');
	string emptyCell2(9, ' ');
	string emptyCell3(12, ' ');
	string emptyCell4(13, ' ');
	cout << horizontLine + ' ' + text + '|' << emptyCell1 << Time[0] << '|' << emptyCell2 << Time[1] << '|' << emptyCell3 << Time[2] << '|' <<
		emptyCell4 << Time[3] << '|';
}

void addAllLineWithParam() {
	/*addTitle();*/
	lineWithParam("Создание множества");
	lineWithParam("Мощность");
	lineWithParam("Подмножество А-А");
	lineWithParam("Подмножество В-А");
	lineWithParam("Равенство А-А");
	lineWithParam("Равенство В-А");
	lineWithParam("Объединение");
	lineWithParam("Пересечение");
	lineWithParam("Разность А-В");
	lineWithParam("Разность В-А");
	lineWithParam("Симметричная разность");
	cout << horizontLine;
}

int WriteLenSet() {
	int size1;
	do {
		if (!(cin >> size1)) {
			cout << "Введите целое число!\n";
			cin.clear();
			cin.ignore();
			continue;
		}
		if (size1 < MIN_LEN)
			cout << "Введите размер больше 1000:  ";
	} while (size1 < MIN_LEN);
	return size1;
}

void createTable() {
	cout << "Введите размер множества A: ";
	Size_SetA = WriteLenSet();
	cout << "Введите размер множества B: ";
	Size_SetB = WriteLenSet();
	cout << title;
	CreateSetTime();
	lineWithParam("Создание множества");
	
	
	/*addAllLineWithParam();*/
}
int main() {
	setlocale(LC_ALL, "ru");
	SetConsoleTitle(L"Осин Сергей 23ВП2");
	createTable();
	system("pause");
	return 0;
}

//void addTitle() {
//	//	
//	//	cout << title;
//	//}
//	}