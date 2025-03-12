#include <iostream>
#include "SetStruct.h"
#include "SetClass.h"
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
	SetClass* SA = new SetClass();
	SA->createnewSet('A', sizeA, min_elem, max_elem);
	cout << "��������� A: ";
	cout << SA->printSet(',') << '\n';
	cout << "�������� �: " << SA->LengthSet() << '\n';
	return 0;

}
