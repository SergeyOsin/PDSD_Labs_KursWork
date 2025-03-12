#include "Setset.h"
using namespace std;

//F1. ��������  ������� ���������
Setset::Setset() {
}

//F2. ������ ���������?
bool Setset::isEmptySet() {
	return set0.empty();
}

//F3. �������� �������������� �������� ���������
bool Setset::isElementinSet(int element) {
	if (isEmptySet())
		return false;
	return set0.count(element) > 0;
}

//F4. ���������� ������ �������� � ���������
Setset* Setset::addnewElement(int new_element) {
	if (isElementinSet(new_element))
		return this;
	set0.insert(new_element);
	return this;
}

//F5. �������� ���������
Setset* Setset::createnewSet(char A, int size, int min_element, int max_element) {
	if (size <= 0 || min_element >= max_element)
		return nullptr;
	Setset* SetSet = new Setset();
	int count_elem = 0;
	while (count_elem < size) {
		int random_element = rand() % (max_element + 1 - min_element) + min_element;
		if (A == 'A') {
			if (random_element % 2 == 0)
				random_element++;
		}
		else if (random_element % 3 != 0)
			random_element += 3 - random_element % 3;
		SetSet = SetSet->addnewElement(random_element);
		count_elem++;
	}
	return SetSet;
}

////F6. �������� ���������
int Setset::LengthSet() {
	return set0.size();
}

//F7. ����� ��������� ���������
string Setset::printSet(char delimiter) {
	if (isEmptySet())
		return "";
	string result = "";
	for (auto iter : set0)
		result += std::to_string(iter) + delimiter;
	result.pop_back();
	return result;
}

//F8. �������� ��������� (������� ������, ���������� �������).
Setset* Setset::clearSet() {
	set0.clear();
	return this;
}

//F9. ��������� � �������� ������������� ��������� B?
bool Setset::isSubset(Setset* SecondB) {
	if (isEmptySet())
		return true;
	for (auto elem : set0) {
		if (!SecondB->isElementinSet(elem))
			return false;
	}
	return true;
}

//F10. ��������� � ����� ��������� B?
bool Setset::isEqual(Setset* SecondB) {
	return isSubset(SecondB) && SecondB->isSubset(this);
}

////F11. ����������� �������� A � B.
Setset* Setset::merge(Setset* SecondB) {
	if (isEmptySet())
		return SecondB;
	if (SecondB->isEmptySet())
		return this;
	Setset* C = new Setset();
	for (auto iter = set0.begin(); iter != set0.end(); iter++) {
		C->addnewElement(*iter);
	}
	for (auto iter = SecondB->set0.begin(); iter != SecondB->set0.end(); iter++) {
		C->addnewElement(*iter);
	}
	return C;
}

////F12. ����������� �������� � � B.
Setset* Setset::Intersection(Setset* SecondB) {
	Setset* C = new Setset();
	if (isEmptySet() || SecondB->isEmptySet())
		return C;
	for (auto iteration = set0.begin(); iteration != set0.end(); iteration++) {
		if (SecondB->isElementinSet(*iteration))
			C->addnewElement(*iteration);
	}
	return C;
}

////F13. �������� ����� ����������� A � B.
Setset* Setset::Difference(Setset* SecondB) {
	Setset* C = new Setset();
	if (isEmptySet())
		return C;
	for (auto iteration = set0.begin(); iteration != set0.end(); iteration++) {
		if (!SecondB->isElementinSet(*iteration))
			C->addnewElement(*iteration);
	}
	return C;
}
//
////F14. ������������ �������� �������� A � B.
Setset* Setset::SimmetricDif(Setset* SecondB) {
	return this->merge(SecondB)->Difference(Intersection(SecondB));
}
