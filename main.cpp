#include <iostream>
#include "SetStruct/SetStruct.h"
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
	string isSubSetAtoB = (isSubset(A, B)) ? "Да" : "Нет";
	string isSubSetBtoA = (isSubset(A, A)) ? "Да" : "Нет";
	cout << "Множество А является подмножеством B? " << isSubSetAtoB << '\n';
	cout << "Множество A является подмножеством A? " << isSubSetBtoA << '\n';
	string isEqualSetAtoB = (isEqual(A, B)) ? "Да" : "Нет";
	string isEqualSetAtoA = (isEqual(A, A)) ? "Да" : "Нет";
	cout << "Множество А равно Множеству B? " << isEqualSetAtoB << '\n';
	cout << "Множество А равно Множеству А? " << isEqualSetAtoA << '\n';
	SetStruct* C = merge(A, B);
	cout << "Объединение множеств A и B: " << printSet(C, ',') << '\n';
	cout << "Мощность множества C: " << LengthSet(C) << '\n';
	SetStruct* C1 = Intersection(A, B);
	cout << "Пересечение множеств A и B: " << printSet(C1, ',') << '\n';
	cout << "Мощность множества C: " << LengthSet(C1) << '\n';
	SetStruct* C2 = Difference(A, B);
	cout << "Разность множеств А и B: " << printSet(C2, ',') << '\n';
	cout << "Мощность множества C: " << LengthSet(C2) << '\n';
	SetStruct* C3 = Difference(B, A);
	cout << "Разность множеств B и A: " << printSet(C3, ',') << '\n';
	cout << "Мощность множества C: " << LengthSet(C3) << '\n';
	SetStruct* C4 = SimmetricDif(A, B);
	cout << "Симметричная разность A и B: " << printSet(C4, ',') << '\n';
	cout << "Мощность множества C: " << LengthSet(C4);
	return 0;

}
