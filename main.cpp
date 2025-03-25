#include <iostream>
#include <iomanip>
#include "SetStruct.h"
#include "SetClass.h"
#include "SetList.h"
#include "Setset.h"
#include "Setunorderedset.h"
#include "Setbitset.h"
#include <Windows.h>
using namespace std;
const int min_size = 7, max_size = 9;
const int min_elem = 10, max_elem = 98;
int SIZE_SET;
void lineWithParam(string text) {
	string horizontLine = "\n---------------------------------------------------------------------------------------------------------------------\n";
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
	cout << "������� ������ ���������: \n";
	addAllLineWithParam();
}
int main() {
	setlocale(LC_ALL, "ru");
	SetConsoleTitle(L"���� ������ 23��2");
	createTable();
	/*cout << "���� ������. 23��2. �������-21. ��������� A - �������� �����, ��������� B - ����� ������� 3.\n";
	srand(time(NULL));
	cout << "��������� A: ";
	int sizeA = rand() % (max_size - min_size + 1) + min_size;
	int sizeB = rand() % (max_size - min_size + 1) + min_size;
	cout << "��������� set3:\n";
	SetStruct* A = createnewSet('A', sizeA, min_elem, max_elem);
	cout << printSet(A, ',') << '\n';
	cout << "�������� ��������� A: " << LengthSet(A) << '\n';
	cout << "����� set3:\n";
	SetClass* SA = new SetClass();
	SA->createnewSet('A', sizeA, min_elem, max_elem);
	cout << "��������� A: ";
	cout << SA->printSet(',') << '\n';
	cout << "�������� �: " << SA->LengthSet() << '\n';
	cout << "��������� list:\n";
	SetList* setlist = new SetList();
	setlist=setlist->createnewSet('A', sizeA, min_elem, max_elem);
	cout << "��������� A: " << setlist->printSet(',');
	cout << "\n�������� A: " << setlist->LengthSet();
	cout << "\n��������� B: ";
	SetList* setlist1 = new SetList();
	setlist1 = setlist1->createnewSet('B', sizeB, min_elem, max_elem);
	cout << setlist1->printSet(',');
	cout << "\n������������ �������� A � B: ";
	SetList* C = setlist->SimmetricDif(setlist1);
	cout << C->printSet(',') << '\n';
	cout << "�������� C: " << C->LengthSet();
	cout << "\n��������� set3:\n";
	Setset* set1 = new Setset();
	set1=set1->createnewSet('A', sizeA, min_elem, max_elem);
	cout << "��������� A: " << set1->printSet(',') << '\n';
	cout << "�������� A: " << set1->LengthSet();
	cout << "\n��������� unorderedset:\n";
	Setunorderedset* setB = new Setunorderedset();
	setB = setB->createnewSet('A', sizeA, min_elem, max_elem);
	cout << "��������� B: " << setB->printSet(',') << '\n';
	cout << "�������� B: " << setB->LengthSet() << '\n';
	cout << "��������� bitset:\n";
	Setbitset* set3 = new Setbitset();
	set3 = set3->createnewSet('A', 10, 10, 99);
	cout << "A: " << set3->printSet(',') + '\n';
	cout << "length A: "<< set3->LengthSet() + '\n';
	Setbitset* setb = new Setbitset();
	setb = setb->createnewSet('B', 10, 11, 99);
	cout << "B: " + setb->printSet(',') + '\n';
	Setbitset* C1 = new Setbitset();
	C1= set3->Intersection(setb);
	cout << "C1: " + C1->printSet(',') + '\n';
	cout << "Length C1: " << C1->LengthSet() + '\n';*/
	system("pause");
	return 0;

}
