#include <iostream>
#include "SetStruct.h"
#include "SetClass.h"
#include "SetList.h"
#include "Setset.h"
using namespace std;
const int min_size = 7, max_size = 9;
const int min_elem = 10, max_elem = 98;
int main() {
	setlocale(LC_ALL, "ru");
	cout << "���� ������. 23��2. �������-21. ��������� A - �������� �����, ��������� B - ����� ������� 3.\n";
	srand(time(NULL));
	cout << "��������� A: ";
	int sizeA = rand() % (max_size - min_size + 1) + min_size;
	int sizeB = rand() % (max_size - min_size + 1) + min_size;
	cout << "��������� SET:\n";
	SetStruct* A = createnewSet('A', sizeA, min_elem, max_elem);
	cout << printSet(A, ',') << '\n';
	cout << "�������� ��������� A: " << LengthSet(A) << '\n';
	cout << "����� SET:\n";
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
	cout << "\n��������� set:\n";
	Setset* set1 = new Setset();
	set1=set1->createnewSet('A', sizeA, min_elem, max_elem);
	cout << "��������� A: " << set1->printSet(',') << '\n';
	cout << "�������� A: " << set1->LengthSet();
	return 0;

}
