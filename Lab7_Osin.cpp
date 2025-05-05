#include <iostream>
#include <iomanip>
#include <chrono>
#include "SetStruct.h"
#include "SetClass.h"
#include "SetList.h"
#include "Setset.h"
#include "Setunorderedset.h"
#include "Setbitset.h"
#include "Tree_Lab7_Osin.h"
#include <Windows.h>
#include <vector>
#define nl '\n';
#define ver cout << '|';
using std::cout;
using std::vector;
using namespace std::chrono;

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "ru");
    SetConsoleTitle(L"���� ������ 23��2");
    cout << "�������� ������� ������\n";
    BinarySearchTree* bst = new BinarySearchTree();
    cout << "������ ������? ";
    string str = (bst->IsEmptyTree()) ? "��" : "���";
    cout << str << '\n';
    cout << "������� ������: \n";
    bst->createTree(10,100,10);
    cout << "����� ������ ����: " << bst->AvoidfromToptoButtom() << '\n';
    cout << "������� �������� 58 � ������: \n";
    bst->InsertNewData(58);
    cout << "����� ������ ����: " << bst->AvoidfromToptoButtom() << '\n';
    cout << "����� ����� �������: " << bst->AvoidLeftToRight() << '\n';
    cout << "����� ����� �����: " << bst->AvoidButtomtoTop() << '\n';
    cout << "�������� ������: ";
    bst->DeleteTree();
    system("pause");
    return 0;
}