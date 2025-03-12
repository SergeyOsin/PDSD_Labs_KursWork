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
	cout << "Осин Сергей. 23ВП2. Вариант-21. Множество A - нечётные цифры, Множество B - числа кратные 3.\n";
	srand(time(NULL));
	cout << "Множество A: ";
	int sizeA = rand() % (max_size - min_size + 1) + min_size;
	int sizeB = rand() % (max_size - min_size + 1) + min_size;
	cout << "Структура SET:\n";
	SetStruct* A = createnewSet('A', sizeA, min_elem, max_elem);
	cout << printSet(A, ',') << '\n';
	cout << "Мощность множества A: " << LengthSet(A) << '\n';
	cout << "Класс SET:\n";
	SetClass* SA = new SetClass();
	SA->createnewSet('A', sizeA, min_elem, max_elem);
	cout << "Множество A: ";
	cout << SA->printSet(',') << '\n';
	cout << "Мощность А: " << SA->LengthSet() << '\n';
	cout << "Контейнер list:\n";
	SetList* setlist = new SetList();
	setlist=setlist->createnewSet('A', sizeA, min_elem, max_elem);
	cout << "Множество A: " << setlist->printSet(',');
	cout << "\nМощность A: " << setlist->LengthSet();
	cout << "\nМножество B: ";
	SetList* setlist1 = new SetList();
	setlist1 = setlist1->createnewSet('B', sizeB, min_elem, max_elem);
	cout << setlist1->printSet(',');
	cout << "\nСимметричная разность A и B: ";
	SetList* C = setlist->SimmetricDif(setlist1);
	cout << C->printSet(',') << '\n';
	cout << "Мощность C: " << C->LengthSet();
	cout << "\nКонтейнер set:\n";
	Setset* set1 = new Setset();
	set1=set1->createnewSet('A', sizeA, min_elem, max_elem);
	cout << "Множество A: " << set1->printSet(',') << '\n';
	cout << "Мощность A: " << set1->LengthSet();
	return 0;

}
