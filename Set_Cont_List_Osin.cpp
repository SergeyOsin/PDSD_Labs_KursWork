#include <iostream>
#include "SetStruct.h"
#include "SetClass.h"
#include "SetLab4_Osin.h"
using namespace std;
const int min_size = 7, max_size = 9;
const int min_elem = 10, max_elem = 98;
int main() {
	setlocale(LC_ALL, "ru");
	cout << "������������ ������ 4\n";
	cout << "���� ������. 23��2. �������-21. ��������� A - �������� �����, ��������� B - ����� ������� 3.\n";
	srand(time(NULL));
	int sizeA = rand() % (max_size - min_size + 1) + min_size;
	int sizeB = rand() % (max_size - min_size + 1) + min_size;
	SetList* setlist = new SetList();
	setlist=setlist->createnewSet('A', sizeA, min_elem, max_elem);
	cout << "��������� A: " << setlist->printSet(',');
	cout << "\n�������� A: " << setlist->LengthSet();
	cout << "\n��������� B: ";
	SetList* setlist1 = new SetList();
	setlist1 = setlist1->createnewSet('B', sizeB, min_elem, max_elem);
	cout << setlist1->printSet(',') + '\n';
	cout << "�������� B: " << setlist1->LengthSet()<<'\n';
	SetList* C = new SetList();
	setlist->isSubset(setlist1);
	string answ = (setlist->isSubset(setlist1)) ? "��" : "���";
	cout << "��������� � ������������ �? " <<answ<< '\n';
	answ = (setlist->isSubset(setlist)) ? "��" : "���";
	cout << "��������� � ������������ A? " << answ << '\n';
	answ = (setlist->isEqual(setlist1)) ? "��" : "���";
	cout << "��������� � ����� �? " + answ << '\n';
	answ = (setlist->isEqual(setlist)) ? "��" : "���";
	cout << "��������� � ����� A? " + answ + '\n';
	C = setlist->merge(setlist1);
	cout << "����������� �������� � � �: " << C->printSet(',') + '\n';
	cout << "�������� C: " << C->LengthSet() <<'\n';
	C = setlist->Intersection(setlist1);
	cout << "����������� �������� � � �: " << C->printSet(',') + '\n';
	cout << "�������� C: " << C->LengthSet() << '\n';
	C = setlist->Difference(setlist1);
	cout << "�������� � � B: " << C->printSet(',') << '\n';
	cout << "�������� C: " << C->LengthSet() << '\n';
	C = setlist1->Difference(setlist);
	cout << "�������� B � A: " << C->printSet(',') << '\n';
	cout << "�������� C: " << C->LengthSet() << '\n';
	C = setlist->SimmetricDif(setlist1);
	cout << "������������ �������� � � B: " << C->printSet(',') << '\n';
	cout << "�������� C: " << C->LengthSet() << '\n';
	cout << "������� �������� A � B:\n";
	setlist->clearSet();
	setlist1->clearSet();
	cout << "��������� A: " << setlist->printSet(',') << '\n';
	cout << "�������� A: " << setlist->LengthSet() << '\n';
	cout << "��������� B: " << setlist1->printSet(',') << '\n';
	cout << "�������� B: " << setlist1->LengthSet() << '\n';
	return 0;
}
