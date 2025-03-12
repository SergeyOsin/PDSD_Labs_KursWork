#include <iostream>
#include "SetStruct.h"
#include "SetClass.h"
using namespace std;
const int min_size = 7, max_size = 9;
const int min_elem = 10, max_elem = 98;
int main() {
	setlocale(LC_ALL, "ru");
	cout << "Осин Сергей. 23ВП2. Вариант-21. Множество A - нечётные цифры, Множество B - числа кратные 3.\n";
	srand(time(NULL));
	cout << "Множество A: ";
	int sizeA = rand() % (max_size - min_size + 1) + min_size;
	int sizeB = rand() % (max_size - min_size + 1) + min_size;
	SetStruct* A = createnewSet('A', sizeA, min_elem, max_elem);
	cout << printSet(A, ',') << '\n';
	cout << "Мощность множества A: " << LengthSet(A) << '\n';
	SetStruct* B = createnewSet('B', sizeB, min_elem, max_elem);
	cout << "Множество B: " << printSet(B, ',') << '\n';
	cout << "Мощность множества B: " << LengthSet(B) << '\n';
	SetClass* SA = new SetClass();
	SA->createnewSet('A', sizeA, min_elem, max_elem);
	cout << "Множество A: ";
	cout << SA->printSet(',') << '\n';
	cout << "Мощность А: " << SA->LengthSet() << '\n';
	return 0;

}
