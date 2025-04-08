#include <iostream>
#include <iomanip>
#include "SetStruct.h"
#include "SetClass.h"
#include "SetLab5_Osin.h"
#include "Setunorderedset.h"
#include "Setbitset.h"
#include <Windows.h>
#include <time.h>
#define nl '\n'
using namespace std;
const int min_size = 7, max_size = 9;
const int min_elem = 10, max_elem = 98;
const string horizontLine = "\n---------------------------------------------------------------------------------------------------------------------\n";
int setSize;
void lineWithParam(string text) {
	horizontLine;
	while (text.size() < 23) text += " ";
	string emptyCell1(20, ' ');
	string emptyCell2(14, ' ');
	string emptyCell3(12, ' ');
	string emptyCell4(13, ' ');
	string emptyCell5(10, ' ');
	string emptyCell6(15, ' ');

	cout << horizontLine + ' ' + text + '|' + emptyCell1 + '|' + emptyCell2 +
		'|' + emptyCell3 + '|' + emptyCell4 + '|' + emptyCell5 +
		'|' + emptyCell6 + '|';
}
void emptycell(int num,string text) {
	string empty(num, ' ');
	cout << empty << text;
}
void buildSetStruct() {
	cout << horizontLine;
	emptycell(6, "�������� ���������|");
	SetStruct* set0 = new SetStruct();
	clock_t clock0 = clock();
	set0 = createnewSet('A', setSize, 0, setSize * 10);
	clock_t finish = clock();
	double rez =(double) (finish - clock0) / CLOCKS_PER_SEC;
	cout << rez;
}
void addTitle() {
	const string horizontLine = "\n---------------------------------------------------------------------------------------------------------------------\n";
	const string title = horizontLine + "\t\t\t| ����������� ������ | ����� ������ |    List    |     Set     |  Bitset  | Unordered_set |";
	cout << title;
}

void addAllLineWithParam() {
	addTitle();
	lineWithParam("�������� ���������");
	lineWithParam("��������");
	lineWithParam("������������ �-�");
	lineWithParam("������������ �-�");
	lineWithParam("��������� �-�");
	lineWithParam("��������� �-�");
	lineWithParam("�����������");
	lineWithParam("�����������");
	lineWithParam("�������� �-�");
	lineWithParam("�������� �-�");
	lineWithParam("������������ ��������");
	const string horizontLine = "\n---------------------------------------------------------------------------------------------------------------------\n";
	cout << horizontLine;
}

void createTable() {
	cout << "������� ������ ���������: ";
	cin>>setSize;
	cout << '\n';
	addTitle();
	buildSetStruct();
}

void Lab5() {
	cout << "������������ ������ 5.\n���� ������. 23��2. �������-21. ��������� A - �������� �����, ��������� B - ����� ������� 3.\n";
	srand(time(NULL));
	int sizeA = rand() % (max_size - min_size + 1) + min_size;
	int sizeB = rand() % (max_size - min_size + 1) + min_size;
	cout << "��������� A: ";
	Setset* setsetA = new Setset();
	setsetA = setsetA->createnewSet('A', sizeA, min_elem, max_elem);
	cout << setsetA->printSet(',') + '\n';
	cout << "�������� A: " << setsetA->LengthSet() << nl;
	cout << "��������� B: ";
	Setset* setsetB = new Setset();
	setsetB = setsetB->createnewSet('B', sizeB, min_elem, max_elem);
	cout << setsetB->printSet(',') + nl;
	cout << "�������� B: " << setsetB->LengthSet() << nl;
	string state = setsetA->isSubset(setsetB) ? "��" : "���";
	cout << "��������� A ������������ B? " + state + nl;
	state = setsetA->isSubset(setsetA) ? "��" : "���";
	cout << "��������� � ������������ �? " + state + nl;
	state = setsetA->isEqual(setsetB) ? "��" : "���";
	cout << "��������� � ����� B? " + state + nl;
	state = setsetA->isEqual(setsetA) ? "��" : "���";
	cout << "��������� � ����� A? " + state + nl;
	Setset* setsetC = new Setset();
	setsetC = setsetA->merge(setsetB);
	cout << "����������� � � �: " << setsetC->printSet(',') + nl;
	cout << "�������� C: " << setsetC->LengthSet() << nl;
	setsetC = setsetA->Intersection(setsetB);
	cout << "����������� � � �: " << setsetC->printSet(',') + nl;
	cout << "�������� �: " << setsetC->LengthSet() << nl;
	setsetC = setsetA->Difference(setsetB);
	cout << "�������� � � �: " << setsetC->printSet(',') + nl;
	cout << "�������� �: " << setsetC->LengthSet() << nl;
	setsetC = setsetB->Difference(setsetA);
	cout << "�������� � � �: " << setsetC->printSet(',') + nl;
	cout << "�������� C: " << setsetC->LengthSet() << nl;
	setsetC = setsetA->SimmetricDif(setsetB);
	cout << "������������ �������� A � B: " << setsetC->printSet(',') + nl;
	cout << "�������� �: " << setsetC->LengthSet() << nl;
	cout << "������� �������� A � B: " << nl;
	setsetA->clearSet();
	setsetB->clearSet();
	cout << "��������� �: " << setsetA->printSet(',') + nl;
	cout << "�������� �: " << setsetA->LengthSet() << nl;
	cout << "��������� B: " << setsetB->printSet(',') + nl;
	cout << "�������� B: " << setsetB->LengthSet() << nl;
}
int main() {
	setlocale(LC_ALL, "ru");
	SetConsoleTitle(L"���� ������ 23��2");
	Lab5();
	/*createTable();*/
	system("pause");
	return 0;
}

