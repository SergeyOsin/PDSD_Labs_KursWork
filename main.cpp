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
#define ver cout << '|';
using namespace std;
int Size_SetA;
int Size_SetB;
const int MIN_ELEM = 0;
const int MAX_ELEM_A = 10 * Size_SetA;
const int MAX_ELEM_B = 10 * Size_SetB;
const int MIN_LEN = 1000;
SetStruct* SetStrA;
SetStruct* SetStrB;
SetClass* SetClA;
SetClass* SetClB;
SetList* SetListA;
SetList* SetListB;
Setset* SetsetA;
Setset* SetsetB;
Setunorderedset* SetunsetA;
Setunorderedset* SetunsetB;
Setbitset* SetbitsetA;
Setbitset* SetbitsetB;
const string horizontLine = "\n-----------------------------------------------------------------------------------------------------------------------\n";
const string title = horizontLine + "\t\t\t| Односвязный список | Класс список |    List    |     Set     |     Bitset   | Unordered_set |";
double Time[6];
clock_t start;

void CountTime_Create() {
	start = clock();
	SetStrA = createnewSet(Size_SetA, 0, 10 * Size_SetA);
	clock_t end = clock();
	SetStrB = createnewSet(Size_SetB, 0, 10 * Size_SetB);
	double time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[0] = time_createSet;
	start = clock();
	SetClA = new SetClass();
	SetClA->createnewSet(Size_SetA, 0, 10 * Size_SetA);
	end = clock();
	SetClB = new SetClass();
	SetClB->createnewSet(Size_SetB, 0, 10 * Size_SetB);
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[1] = time_createSet;
	start = clock();
	SetListA = new SetList();
	SetListA->createnewSet(Size_SetA, 0, 10 * Size_SetA);
	end = clock();
	SetListB = new SetList();
	SetListB->createnewSet(Size_SetB, 0, 10 * Size_SetB);
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[2] = time_createSet;
	SetsetA = new Setset();
	start = clock();
	SetsetA->createnewSet(Size_SetA, 0, 10 * Size_SetA);
	end = clock();
	SetsetB = new Setset();
	SetsetB->createnewSet(Size_SetB, 0, 10 * Size_SetB);
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[3] = time_createSet;
	SetunsetA = new Setunorderedset();
	start = clock();
	SetunsetA->createnewSet(Size_SetA, 0, 10 * Size_SetA);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[4] = time_createSet;
	SetunsetB = new Setunorderedset();
	SetunsetB->createnewSet(Size_SetB, 0, Size_SetB * 10);
	SetbitsetA = new Setbitset();
	start = clock();
	SetbitsetA->createnewSet(Size_SetA, 0, Size_SetA * 10);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	SetbitsetB = new Setbitset();
	SetbitsetB->createnewSet(Size_SetB, 0, Size_SetB * 10);
}

void LenSet() {
	start = clock();
	int len = LengthSet(SetStrA);
	clock_t end = clock();
	double time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[0] = time_createSet;
	start = clock();
	len = SetClA->LengthSet();
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[1] = time_createSet;
	start = clock();
	len = SetListA->LengthSet();
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[2] = time_createSet;
	start = clock();
	len = SetsetA->LengthSet();
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[3] = time_createSet;
	start = clock();
	len=SetunsetA->LengthSet();
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[4] = time_createSet;
	start = clock();
	len = SetbitsetA->LengthSet();
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[5] = time_createSet;
}

void isSubSetAA() {
	SetStruct* C = new SetStruct();
	start = clock();
	bool flag = isSubset(SetStrA, SetStrA);
	clock_t end = clock();
	double time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[0] = time_createSet;
	start = clock();
	flag = SetClA->isSubset(SetClA);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[1] = time_createSet;
	start = clock();
	SetListA = new SetList();
	flag = SetListA->isSubset(SetListA);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[2] = time_createSet;
	SetsetA = new Setset();
	start = clock();
	flag = SetsetA->isSubset(SetsetA);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[3] = time_createSet;
	start = clock();
	flag = SetunsetA->isSubset(SetunsetA);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[4] = time_createSet;
	start = clock();
	flag = SetbitsetA->isSubset(SetbitsetA);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[5] = time_createSet;
}

void isSubSetBA() {
	start = clock();
	bool flag = isSubset(SetStrB, SetStrA);
	clock_t end = clock();
	double time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[0] = time_createSet;
	start = clock();
	flag = SetClB->isSubset(SetClA);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[1] = time_createSet;
	start = clock();
	flag = SetListB->isSubset(SetListA);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[2] = time_createSet;
	start = clock();
	flag = SetsetB->isSubset(SetsetA);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[3] = time_createSet;
	start = clock();
	flag = SetunsetB->isSubset(SetunsetA);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[4] = time_createSet;
	start = clock();
	flag = SetbitsetB->isSubset(SetbitsetB);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[5] = time_createSet;
}

void isEqualAA() {
	start = clock();
	bool flag = isEqual(SetStrA, SetStrB);
	clock_t end = clock();
	double time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[0] = time_createSet;
	start = clock();
	flag = SetClA->isEqual(SetClA);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[1] = time_createSet;
	start = clock();
	flag = SetListA->isEqual(SetListA);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[2] = time_createSet;
	start = clock();
	flag = SetsetA->isEqual(SetsetA);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[3] = time_createSet;
	start = clock();
	flag = SetunsetA->isEqual(SetunsetA);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[4] = time_createSet;
	start = clock();
	flag = SetbitsetA->isEqual(SetbitsetA);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[5] = time_createSet;
}

void isEqualBA() {
	SetStruct* C = new SetStruct();
	start = clock();
	bool flag = isEqual(SetStrB, SetStrA);
	clock_t end = clock();
	double time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[0] = time_createSet;
	start = clock();
	flag = SetClB->isEqual(SetClA);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[1] = time_createSet;
	start = clock();
	flag = SetListB->isEqual(SetListA);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[2] = time_createSet;
	start = clock();
	flag = SetsetB->isEqual(SetsetA);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[3] = time_createSet;
	start = clock();
	flag = SetunsetB->isEqual(SetunsetA);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[4] = time_createSet;
	start = clock();
	flag = SetbitsetB->isEqual(SetbitsetA);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[5] = time_createSet;
}

void lineWithParam(string text) {
	while (text.size() < 23) text += " ";
	cout << horizontLine + ' ' + text + '|';
	string text1 = to_string(Time[0]);
	while (text1.size() < 20) text1 += " ";
	cout << text1 + '|';
	text1 = to_string(Time[1]);
	while (text1.size() < 14) text1 += " ";
	cout << text1 + '|';
	text1 = to_string(Time[2]);
	while (text1.size() < 12) text1 += " ";
	cout << text1 + '|';
	text1 = to_string(Time[3]);
	while (text1.size() < 13) text1 += " ";
	cout << text1 + '|';
	text1 = to_string(Time[4]);
	while (text1.size() < 14) text1 += " ";
	cout << text1 + '|';
	text1 = to_string(Time[5]);
	while (text1.size() < 15) text1 += " ";
	cout << text1 + '|';
}

void MergeAB() {
	SetStruct* C = new SetStruct();
	start = clock();
	C = merge(SetStrA, SetStrB);
	clock_t end = clock();
	double time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[0] = time_createSet;
	SetClass* C1 = new SetClass();
	start = clock();
	C1 = SetClA->merge(SetClB);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[1] = time_createSet;
	start = clock();
	SetList* C2 = new SetList();
	C2 = SetListA->merge(SetListB);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[2] = time_createSet;
	Setset* C3 = new Setset();
	start = clock();
	C3 = SetsetA->merge(SetsetB);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[3] = time_createSet;
	Setunorderedset* C4 = new Setunorderedset();
	start = clock();
	C4 = SetunsetA->merge(SetunsetB);
	end = clock();
	Time[4] = (double)(end - start) / CLOCKS_PER_SEC;
	Setbitset* C5 = new Setbitset();
	start = clock();
	C5 = SetbitsetA->merge(SetbitsetB);
	end = clock();
	Time[5] = (double)(end - start) / CLOCKS_PER_SEC;
}

void InterAB() {
	SetStruct* C = new SetStruct();
	start = clock();
	C = Intersection(SetStrA, SetStrB);
	clock_t end = clock();
	double time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[0] = time_createSet;
	SetClass* C1 = new SetClass();
	start = clock();
	C1 = SetClA->Intersection(SetClB);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[1] = time_createSet;
	start = clock();
	SetList* C2 = new SetList();
	C2 = SetListA->Intersection(SetListB);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[2] = time_createSet;
	Setset* C3 = new Setset();
	start = clock();
	C3 = SetsetA->Intersection(SetsetB);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[3] = time_createSet;
	Setunorderedset* C4 = new Setunorderedset();
	start = clock();
	C4 = SetunsetA->Intersection(SetunsetB);
	end = clock();
	Time[4] = (double)(end - start) / CLOCKS_PER_SEC;
	Setbitset* C5 = new Setbitset();
	start = clock();
	C5 = SetbitsetA->Intersection(SetbitsetB);
	end = clock();
	Time[5] = (double)(end - start) / CLOCKS_PER_SEC;
}

void DiffAB() {
	SetStruct* C = new SetStruct();
	start = clock();
	C = Difference(SetStrA, SetStrB);
	clock_t end = clock();
	double time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[0] = time_createSet;
	SetClass* C1 = new SetClass();
	start = clock();
	C1 = SetClA->Difference(SetClB);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[1] = time_createSet;
	start = clock();
	SetList* C2 = new SetList();
	C2 = SetListA->Difference(SetListB);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[2] = time_createSet;
	Setset* C3 = new Setset();
	start = clock();
	C3 = SetsetA->Difference(SetsetB);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[3] = time_createSet;
	Setunorderedset* C4 = new Setunorderedset();
	start = clock();
	C4 = SetunsetA->Difference(SetunsetB);
	end = clock();
	Time[4] = (double)(end - start) / CLOCKS_PER_SEC;
	Setbitset* C5 = new Setbitset();
	start = clock();
	C5 = SetbitsetA->Difference(SetbitsetB);
	end = clock();
	Time[5] = (double)(end - start) / CLOCKS_PER_SEC;
}

void DiffBA() {
	SetStruct* C = new SetStruct();
	start = clock();
	C = Difference(SetStrB, SetStrA);
	clock_t end = clock();
	double time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[0] = time_createSet;
	SetClass* C1 = new SetClass();
	start = clock();
	C1 = SetClB->Difference(SetClA);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[1] = time_createSet;
	start = clock();
	SetList* C2 = new SetList();
	C2 = SetListB->Difference(SetListA);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[2] = time_createSet;
	Setset* C3 = new Setset();
	start = clock();
	C3 = SetsetB->Difference(SetsetA);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[3] = time_createSet;
	Setunorderedset* C4 = new Setunorderedset();
	start = clock();
	C4 = SetunsetB->Difference(SetunsetA);
	end = clock();
	Time[4] = (double)(end - start) / CLOCKS_PER_SEC;
	Setbitset* C5 = new Setbitset();
	start = clock();
	C5 = SetbitsetB->Difference(SetbitsetA);
	end = clock();
	Time[5] = (double)(end - start) / CLOCKS_PER_SEC;
}

void SimmDifAB() {
	SetStruct* C = new SetStruct();
	start = clock();
	C = SimmetricDif(SetStrA, SetStrB);
	clock_t end = clock();
	double time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[0] = time_createSet;
	SetClass* C1 = new SetClass();
	start = clock();
	C1 = SetClA->SimmetricDif(SetClB);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[1] = time_createSet;
	start = clock();
	SetList* C2 = new SetList();
	C2 = SetListA->SimmetricDif(SetListB);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[2] = time_createSet;
	Setset* C3 = new Setset();
	start = clock();
	C3 = SetsetA->SimmetricDif(SetsetB);
	end = clock();
	time_createSet = (double)(end - start) / CLOCKS_PER_SEC;
	Time[3] = time_createSet;
	Setunorderedset* C4 = new Setunorderedset();
	start = clock();
	C4 = SetunsetA->SimmetricDif(SetunsetB);
	end = clock();
	Time[4] = (double)(end - start) / CLOCKS_PER_SEC;
	Setbitset* C5 = new Setbitset();
	start = clock();
	C5 = SetbitsetA->SimmetricDif(SetbitsetB);
	end = clock();
	Time[5] = (double)(end - start) / CLOCKS_PER_SEC;
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

void CreateStronTable() {
	CountTime_Create();
	lineWithParam("Создание множества");
	LenSet();
	lineWithParam("Мощность множества");
	isSubSetAA();
	lineWithParam("Подмножество А-А");
	isSubSetBA();
	lineWithParam("Подмножество В-А");
	isEqualAA();
	lineWithParam("Равенство А=А");
	isEqualBA();
	lineWithParam("Равенство B=А");
	MergeAB();
	lineWithParam("Объединение A и B");
	InterAB();
	lineWithParam("Пересечение A и B");
	DiffAB();
	lineWithParam("Разность A-B");
	DiffBA();
	lineWithParam("Разность B-A");
	SimmDifAB();
	lineWithParam("Симметричная разность");
}

void createTable() {
	cout << "Введите размер множества A: ";
	Size_SetA = WriteLenSet();
	cout << "Введите размер множества B: ";
	Size_SetB = WriteLenSet();
	cout << title;
	CreateStronTable();
	cout << horizontLine;
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