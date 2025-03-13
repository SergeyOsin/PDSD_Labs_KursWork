#include <iostream>
#include <iomanip>
#include "SetStruct.h"
#include "SetClass.h"
#include "SetList.h"
#include "Setset.h"
#include "Setunorderedset.h"
#include "Setbitset.h"
using namespace std;
const int min_size = 7, max_size = 9;
const int min_elem = 10, max_elem = 98;
const char underline = '_';
const char verticline = '|';
void build_table() {
	cout << setw(100) << setfill(underline) << '\n';
	cout << setw(10) << setfill(verticline) << "����������� ������" << setfill(verticline);
}
int main() {
	setlocale(LC_ALL, "ru");
	cout << "���� ������. 23��2. �������-21. ��������� A - �������� �����, ��������� B - ����� ������� 3.\n";
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
	cout << "Length C1: " << C1->LengthSet() + '\n';
	return 0;

}
