//#include "Setbitset.h"
//using namespace std;
//
////F1.
//Setbitset::Setbitset() {
//}
//
////F2.
//bool Setbitset::isEmptySet() {
//	return bitset0.any() == 0;
//}
//
////F3.
//bool Setbitset::isElementinSet(int element) {
//	
//}
//
////F4.
//void Setbitset::addnewElement(int new_element) {
//	if (!isElementinSet(new_element))
//		bitset0
//}
//
////F5.
//Setbitset* Setbitset::createnewSet(char A, int size, int min_element, int max_element) {
//	Setbitset* newset = new Setbitset();
//	if (size <= 0 || min_element >= max_element)
//		return newset;
//	int count_elem = 0;
//	while (count_elem < size) {
//		int rand_elem = rand() % (max_element - min_element + 1) + min_element;
//		if (A == 'A') {
//			if (rand_elem % 2 == 0)
//				rand_elem++;
//		}
//		else if (rand_elem % 3 != 0)
//			rand_elem += 3 - rand_elem % 3;
//		newset->addnewElement(rand_elem);
//		count_elem++;
//	}
//	return newset;
//}
//
////F6.
//int Setbitset::LengthSet() {
//	return bitset0.size();
//}
//
////F7.
//std::string Setbitset::printSet(char delimiter) {
//	if (isEmptySet())
//		return " ";
//	std::string printing_set = "";
//	for (auto iter = bitset0.begin(); iter != bitset0.end(); iter++)
//		printing_set += std::to_string(*iter) + delimiter;
//	printing_set.pop_back();
//	return printing_set;
//}
//
////F8. 
//void Setbitset::clearSet() {
//	bitset0.clear();
//}
//
////F9.
//bool Setbitset::isSubset(Setbitset* SecondB) {
//	for (auto iter = bitset0.begin(); iter != bitset0.end(); iter++) {
//		if (!SecondB->isElementinSet(*iter))
//			return false;
//	}
//	return true;
//}
//
////F10
//bool Setbitset::isEqual(Setbitset* SecondB) {
//	return this->isSubset(SecondB) && SecondB->isSubset(this);
//}
//
////F11
//Setbitset* Setbitset::merge(Setbitset* SecondB) {
//	Setbitset* C = new Setbitset();
//	for (auto iteri = bitset0.begin(); iteri != bitset0.end(); iteri++)
//		C->addnewElement(*iteri);
//	for (auto iterj = SecondB->bitset0.begin(); iterj != SecondB->bitset0.end(); iterj++)
//		C->addnewElement(*iterj);
//	return C;
//}
//
////F12
//Setbitset* Setbitset::Intersection(Setbitset* SecondB) {
//	Setbitset* C = new Setbitset();
//	for (auto iteri = bitset0.begin(); iteri != bitset0.end(); iteri++)
//		if (SecondB->isElementinSet(*iteri))
//			C->addnewElement(*iteri);
//	return C;
//}
//
////F13
//Setbitset* Setbitset::Difference(Setbitset* SecondB) {
//	Setbitset* C = new Setbitset();
//	for (auto iteri = bitset0.begin(); iteri != bitset0.end(); iteri++)
//		if (!SecondB->isElementinSet(*iteri))
//			C->addnewElement(*iteri);
//	return C;
//}
//
////F14
//Setbitset* Setbitset::SimmetricDif(Setbitset* SecondB) {
//	return this->merge(SecondB)->Difference(this->Intersection(SecondB));
//}