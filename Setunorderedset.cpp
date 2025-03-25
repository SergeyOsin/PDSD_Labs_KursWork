#include "Setunorderedset.h"
//F1. �������� ������� ���������
Setunorderedset::Setunorderedset() {

}

//F2. �������� ��������� �� �������
bool Setunorderedset::isEmptySet() {
	return set1.empty();
}

//F3. �������� �������������� �������� ���������
bool Setunorderedset::isElementinSet(int element) {
	if (isEmptySet())
		return false;
	return set1.count(element) > 0;
}

//F4. ���������� ������ �������� � ���������
bool Setunorderedset::addnewElement(int new_element) {
	if (!isElementinSet(new_element)) {
		set1.insert(new_element);
		return true;
	}
	return false;
}

//F5. �������� ���������
Setunorderedset* Setunorderedset::createnewSet(char A, int size, int min_element, int max_element) {
	Setunorderedset* newset = new Setunorderedset();
	if (size <= 0 || min_element >= max_element)
		return newset;
	int count_elem = 0;
	while (count_elem < size) {
		int rand_elem = rand() % (max_element - min_element + 1) + min_element;
		if (A == 'A') {
			if (rand_elem % 2 == 0)
				rand_elem++;
		}
		else if (rand_elem % 3 != 0)
			rand_elem += 3 - rand_elem % 3;
		if (newset->addnewElement(rand_elem))
			count_elem++;
	}
	return newset;
}

//F6. �������� ���������
int Setunorderedset::LengthSet() {
	return set1.size();
}

//F7. ����� ��������� ���������
std::string Setunorderedset::printSet(char delimiter) {
	if (isEmptySet())
		return " ";
	std::string printing_set = "";
	for (auto iter = set1.begin(); iter != set1.end(); iter++)
		printing_set += std::to_string(*iter) + delimiter;
	printing_set.pop_back();
	return printing_set;
}

//F8. �������� ��������� (������� ������, ���������� �������).
void Setunorderedset::clearSet() {
	set1.clear();
}

//F9. ��������� A �������� ������������� B?
bool Setunorderedset::isSubset(Setunorderedset* SecondB) {
	for (auto iter = set1.begin(); iter != set1.end(); iter++) {
		if (!SecondB->isElementinSet(*iter))
			return false;
	}
	return true;
}

//F10. ��������� � ����� ��������� B?
bool Setunorderedset::isEqual(Setunorderedset* SecondB) {
	return this->isSubset(SecondB) && SecondB->isSubset(this);
}

//F11. ����������� ��������� � � ��������� B.
Setunorderedset* Setunorderedset::merge(Setunorderedset* SecondB) {
	Setunorderedset* C = new Setunorderedset();
	for (auto iteri = set1.begin(); iteri != set1.end(); iteri++)
		C->addnewElement(*iteri);
	for (auto iterj = SecondB->set1.begin(); iterj != SecondB->set1.end(); iterj++)
		C->addnewElement(*iterj);
	return C;
}

//F12. ����������� �������� � � B.
Setunorderedset* Setunorderedset::Intersection(Setunorderedset* SecondB) {
	Setunorderedset* C = new Setunorderedset();
	for (auto iteri = set1.begin(); iteri != set1.end(); iteri++)
		if (SecondB->isElementinSet(*iteri))
			C->addnewElement(*iteri);
	return C;
}

//F13. �������� ��������� � � B.
Setunorderedset* Setunorderedset::Difference(Setunorderedset* SecondB) {
	Setunorderedset* C = new Setunorderedset();
	for (auto iteri = set1.begin(); iteri != set1.end(); iteri++)
		if (!SecondB->isElementinSet(*iteri))
			C->addnewElement(*iteri);
	return C;
}

//F14. ������������ �������� � � �.
Setunorderedset* Setunorderedset::SimmetricDif(Setunorderedset* SecondB) {
	return this->merge(SecondB)->Difference(this->Intersection(SecondB));
}