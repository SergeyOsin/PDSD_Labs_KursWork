#include <iostream>
#include "SetStruct/SetStruct.h"
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
	SetStruct* A = createnewSet('A', sizeA, min_elem, max_elem);
	cout << printSet(A, ',') << '\n';
	cout << "�������� ��������� A: " << LengthSet(A) << '\n';
	SetStruct* B = createnewSet('B', sizeB, min_elem, max_elem);
	cout << "��������� B: " << printSet(B, ',') << '\n';
	cout << "�������� ��������� B: " << LengthSet(B) << '\n';
	string isSubSetAtoB = (isSubset(A, B)) ? "��" : "���";
	string isSubSetBtoA = (isSubset(A, A)) ? "��" : "���";
	cout << "��������� � �������� ������������� B? " << isSubSetAtoB << '\n';
	cout << "��������� A �������� ������������� A? " << isSubSetBtoA << '\n';
	string isEqualSetAtoB = (isEqual(A, B)) ? "��" : "���";
	string isEqualSetAtoA = (isEqual(A, A)) ? "��" : "���";
	cout << "��������� � ����� ��������� B? " << isEqualSetAtoB << '\n';
	cout << "��������� � ����� ��������� �? " << isEqualSetAtoA << '\n';
	SetStruct* C = merge(A, B);
	cout << "����������� �������� A � B: " << printSet(C, ',') << '\n';
	cout << "�������� ��������� C: " << LengthSet(C) << '\n';
	SetStruct* C1 = Intersection(A, B);
	cout << "����������� �������� A � B: " << printSet(C1, ',') << '\n';
	cout << "�������� ��������� C: " << LengthSet(C1) << '\n';
	SetStruct* C2 = Difference(A, B);
	cout << "�������� �������� � � B: " << printSet(C2, ',') << '\n';
	cout << "�������� ��������� C: " << LengthSet(C2) << '\n';
	SetStruct* C3 = Difference(B, A);
	cout << "�������� �������� B � A: " << printSet(C3, ',') << '\n';
	cout << "�������� ��������� C: " << LengthSet(C3) << '\n';
	SetStruct* C4 = SimmetricDif(A, B);
	cout << "������������ �������� A � B: " << printSet(C4, ',') << '\n';
	cout << "�������� ��������� C: " << LengthSet(C4);
	return 0;

}
