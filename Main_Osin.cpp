#include <iostream>
#include <iomanip>
#include <chrono>
#include "SetStruct.h"
#include "SetClass.h"
#include "SetList.h"
#include "Setset.h"
#include "Setunorderedset.h"
#include "Setbitset.h"
#include <Windows.h>
#include <typeinfo>
#define nl '\n';
#define ver cout << '|';
using namespace std;
using namespace std::chrono;

int Size_SetA;
int Size_SetB;
const int MIN_ELEM = 0;
const int MAX_ELEM_A = 10 * Size_SetA;
const int MAX_ELEM_B = 10 * Size_SetB;
const int MIN_LEN = 1000;
SetStruct* SetStrA;
SetStruct* SetStrB;
SetClass* SetClA;
SetClass* SetClB;
SetList* SetListA;
SetList* SetListB;
Setset* SetsetA;
Setset* SetsetB;
Setunorderedset* SetunsetA;
Setunorderedset* SetunsetB;
Setbitset* SetbitsetA;
Setbitset* SetbitsetB;
const string horizontLine = "\n-----------------------------------------------------------------------------------------------------------------------\n";
const string title = horizontLine + "\t\t\t| Односвязный список | Класс список |    List    |     Set     |  Unordered_set  |   Bitset   |";
double Time[6];
high_resolution_clock::time_point start;
high_resolution_clock::time_point end;

void CountTime_Create() {
    start = high_resolution_clock::now();
    SetStrA = createnewSet(Size_SetA, 0, 10 * Size_SetA);
    high_resolution_clock::time_point end = high_resolution_clock::now();
    SetStrB = createnewSet(Size_SetB, 0, 10 * Size_SetB);
    double time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[0] = time_createSet;

    start = high_resolution_clock::now();
    SetClA = new SetClass();
    SetClA->createnewSet(Size_SetA, 0, 10 * Size_SetA);
    end = high_resolution_clock::now();
    SetClB = new SetClass();
    SetClB->createnewSet(Size_SetB, 0, 10 * Size_SetB);
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[1] = time_createSet;

    start = high_resolution_clock::now();
    SetListA = new SetList();
    SetListA->createnewSet(Size_SetA, 0, 10 * Size_SetA);
    end = high_resolution_clock::now();
    SetListB = new SetList();
    SetListB->createnewSet(Size_SetB, 0, 10 * Size_SetB);
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[2] = time_createSet;

    SetsetA = new Setset();
    start = high_resolution_clock::now();
    SetsetA->createnewSet(Size_SetA, 0, 10 * Size_SetA);
    end = high_resolution_clock::now();
    SetsetB = new Setset();
    SetsetB->createnewSet(Size_SetB, 0, 10 * Size_SetB);
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[3] = time_createSet;

    SetunsetA = new Setunorderedset();
    start = high_resolution_clock::now();
    SetunsetA->createnewSet(Size_SetA, 0, 10 * Size_SetA);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[4] = time_createSet;

    SetunsetB = new Setunorderedset();
    SetunsetB->createnewSet(Size_SetB, 0, Size_SetB * 10);

    SetbitsetA = new Setbitset();
    start = high_resolution_clock::now();
    SetbitsetA->createnewSet(Size_SetA, 0, Size_SetA * 10);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    SetbitsetB = new Setbitset();
    SetbitsetB->createnewSet(Size_SetB, 0, Size_SetB * 10);
    Time[5] = time_createSet;
}

void LenSet() {
    start = high_resolution_clock::now();
    int len = LengthSet(SetStrA);
    auto end = high_resolution_clock::now();
    double time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[0] = time_createSet;

    start = high_resolution_clock::now();
    len = SetClA->LengthSet();
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[1] = time_createSet;

    start = high_resolution_clock::now();
    len = SetListA->LengthSet();
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[2] = time_createSet;

    start = high_resolution_clock::now();
    len = SetsetA->LengthSet();
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[3] = time_createSet;

    start = high_resolution_clock::now();
    len = SetunsetA->LengthSet();
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[4] = time_createSet;

    start = high_resolution_clock::now();
    len = SetbitsetA->LengthSet();
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[5] = time_createSet;
}

void isSubSetAA() {
    SetStruct* C = new SetStruct();
    start = high_resolution_clock::now();
    bool flag = isSubset(SetStrA, SetStrA);
    auto end = high_resolution_clock::now();
    double time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[0] = time_createSet;

    start = high_resolution_clock::now();
    flag = SetClA->isSubset(SetClA);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[1] = time_createSet;

    start = high_resolution_clock::now();
    SetListA = new SetList();
    flag = SetListA->isSubset(SetListA);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[2] = time_createSet;

    SetsetA = new Setset();
    start = high_resolution_clock::now();
    flag = SetsetA->isSubset(SetsetA);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[3] = time_createSet;

    start = high_resolution_clock::now();
    flag = SetunsetA->isSubset(SetunsetA);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[4] = time_createSet;

    start = high_resolution_clock::now();
    flag = SetbitsetA->isSubset(SetbitsetA);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[5] = time_createSet;
}

void isSubSetBA() {
    start = high_resolution_clock::now();
    bool flag = isSubset(SetStrB, SetStrA);
    auto end = high_resolution_clock::now();
    double time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[0] = time_createSet;

    start = high_resolution_clock::now();
    flag = SetClB->isSubset(SetClA);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[1] = time_createSet;

    start = high_resolution_clock::now();
    flag = SetListB->isSubset(SetListA);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[2] = time_createSet;

    start = high_resolution_clock::now();
    flag = SetsetB->isSubset(SetsetA);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[3] = time_createSet;

    start = high_resolution_clock::now();
    flag = SetunsetB->isSubset(SetunsetA);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[4] = time_createSet;

    start = high_resolution_clock::now();
    flag = SetbitsetB->isSubset(SetbitsetA);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[5] = time_createSet;
}

void isEqualAA() {
    start = high_resolution_clock::now();
    bool flag = isEqual(SetStrA, SetStrA);
    auto end = high_resolution_clock::now();
    double time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[0] = time_createSet;

    start = high_resolution_clock::now();
    flag = SetClA->isEqual(SetClA);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[1] = time_createSet;

    start = high_resolution_clock::now();
    flag = SetListA->isEqual(SetListA);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[2] = time_createSet;

    start = high_resolution_clock::now();
    flag = SetsetA->isEqual(SetsetA);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[3] = time_createSet;

    start = high_resolution_clock::now();
    flag = SetunsetA->isEqual(SetunsetA);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[4] = time_createSet;

    start = high_resolution_clock::now();
    flag = SetbitsetA->isEqual(SetbitsetA);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[5] = time_createSet;
}

void isEqualBA() {
    SetStruct* C = new SetStruct();
    start = high_resolution_clock::now();
    bool flag = isEqual(SetStrB, SetStrA);
    auto end = high_resolution_clock::now();
    double time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[0] = time_createSet;

    start = high_resolution_clock::now();
    flag = SetClB->isEqual(SetClA);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[1] = time_createSet;

    start = high_resolution_clock::now();
    flag = SetListB->isEqual(SetListA);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[2] = time_createSet;

    start = high_resolution_clock::now();
    flag = SetsetB->isEqual(SetsetA);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[3] = time_createSet;

    start = high_resolution_clock::now();
    flag = SetunsetB->isEqual(SetunsetA);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[4] = time_createSet;

    start = high_resolution_clock::now();
    flag = SetbitsetB->isEqual(SetbitsetA);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[5] = time_createSet;
}

void MergeAB() {
    SetStruct* C = new SetStruct();
    start = high_resolution_clock::now();
    C = merge(SetStrA, SetStrB);
    auto end = high_resolution_clock::now();
    double time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[0] = time_createSet;

    SetClass* C1 = new SetClass();
    start = high_resolution_clock::now();
    C1 = SetClA->merge(SetClB);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[1] = time_createSet;

    start = high_resolution_clock::now();
    SetList* C2 = new SetList();
    C2 = SetListA->merge(SetListB);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[2] = time_createSet;

    Setset* C3 = new Setset();
    start = high_resolution_clock::now();
    C3 = SetsetA->merge(SetsetB);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[3] = time_createSet;

    Setunorderedset* C4 = new Setunorderedset();
    start = high_resolution_clock::now();
    C4 = SetunsetA->merge(SetunsetB);
    end = high_resolution_clock::now();
    Time[4] = duration_cast<duration<double>>(end - start).count();

    Setbitset* C5 = new Setbitset();
    start = high_resolution_clock::now();
    C5 = SetbitsetA->merge(SetbitsetB);
    end = high_resolution_clock::now();
    Time[5] = duration_cast<duration<double>>(end - start).count();
}

void InterAB() {
    SetStruct* C = new SetStruct();
    start = high_resolution_clock::now();
    C = Intersection(SetStrA, SetStrB);
    auto end = high_resolution_clock::now();
    double time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[0] = time_createSet;

    SetClass* C1 = new SetClass();
    start = high_resolution_clock::now();
    C1 = SetClA->Intersection(SetClB);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[1] = time_createSet;

    start = high_resolution_clock::now();
    SetList* C2 = new SetList();
    C2 = SetListA->Intersection(SetListB);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[2] = time_createSet;

    Setset* C3 = new Setset();
    start = high_resolution_clock::now();
    C3 = SetsetA->Intersection(SetsetB);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[3] = time_createSet;

    Setunorderedset* C4 = new Setunorderedset();
    start = high_resolution_clock::now();
    C4 = SetunsetA->Intersection(SetunsetB);
    end = high_resolution_clock::now();
    Time[4] = duration_cast<duration<double>>(end - start).count();

    Setbitset* C5 = new Setbitset();
    start = high_resolution_clock::now();
    C5 = SetbitsetA->Intersection(SetbitsetB);
    end = high_resolution_clock::now();
    Time[5] = duration_cast<duration<double>>(end - start).count();
}

void DiffAB() {
    SetStruct* C = new SetStruct();
    start = high_resolution_clock::now();
    C = Difference(SetStrA, SetStrB);
    auto end = high_resolution_clock::now();
    double time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[0] = time_createSet;

    SetClass* C1 = new SetClass();
    start = high_resolution_clock::now();
    C1 = SetClA->Difference(SetClB);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[1] = time_createSet;

    start = high_resolution_clock::now();
    SetList* C2 = new SetList();
    C2 = SetListA->Difference(SetListB);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[2] = time_createSet;

    Setset* C3 = new Setset();
    start = high_resolution_clock::now();
    C3 = SetsetA->Difference(SetsetB);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[3] = time_createSet;

    Setunorderedset* C4 = new Setunorderedset();
    start = high_resolution_clock::now();
    C4 = SetunsetA->Difference(SetunsetB);
    end = high_resolution_clock::now();
    Time[4] = duration_cast<duration<double>>(end - start).count();

    Setbitset* C5 = new Setbitset();
    start = high_resolution_clock::now();
    C5 = SetbitsetA->Difference(SetbitsetB);
    end = high_resolution_clock::now();
    Time[5] = duration_cast<duration<double>>(end - start).count();
}

void DiffBA() {
    SetStruct* C = new SetStruct();
    start = high_resolution_clock::now();
    C = Difference(SetStrB, SetStrA);
    auto end = high_resolution_clock::now();
    double time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[0] = time_createSet;

    SetClass* C1 = new SetClass();
    start = high_resolution_clock::now();
    C1 = SetClB->Difference(SetClA);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[1] = time_createSet;

    start = high_resolution_clock::now();
    SetList* C2 = new SetList();
    C2 = SetListB->Difference(SetListA);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[2] = time_createSet;

    Setset* C3 = new Setset();
    start = high_resolution_clock::now();
    C3 = SetsetB->Difference(SetsetA);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[3] = time_createSet;

    Setunorderedset* C4 = new Setunorderedset();
    start = high_resolution_clock::now();
    C4 = SetunsetB->Difference(SetunsetA);
    end = high_resolution_clock::now();
    Time[4] = duration_cast<duration<double>>(end - start).count();

    Setbitset* C5 = new Setbitset();
    start = high_resolution_clock::now();
    C5 = SetbitsetB->Difference(SetbitsetA);
    end = high_resolution_clock::now();
    Time[5] = duration_cast<duration<double>>(end - start).count();
}

void SimmDifAB() {
    SetStruct* C = new SetStruct();
    start = high_resolution_clock::now();
    C = SimmetricDif(SetStrA, SetStrB);
    auto end = high_resolution_clock::now();
    double time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[0] = time_createSet;

    SetClass* C1 = new SetClass();
    start = high_resolution_clock::now();
    C1 = SetClA->SimmetricDif(SetClB);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[1] = time_createSet;

    start = high_resolution_clock::now();
    SetList* C2 = new SetList();
    C2 = SetListA->SimmetricDif(SetListB);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[2] = time_createSet;

    Setset* C3 = new Setset();
    start = high_resolution_clock::now();
    C3 = SetsetA->SimmetricDif(SetsetB);
    end = high_resolution_clock::now();
    time_createSet = duration_cast<duration<double>>(end - start).count();
    Time[3] = time_createSet;

    Setunorderedset* C4 = new Setunorderedset();
    start = high_resolution_clock::now();
    C4 = SetunsetA->SimmetricDif(SetunsetB);
    end = high_resolution_clock::now();
    Time[4] = duration_cast<duration<double>>(end - start).count();

    Setbitset* C5 = new Setbitset();
    start = high_resolution_clock::now();
    C5 = SetbitsetA->SimmetricDif(SetbitsetB);
    end = high_resolution_clock::now();
    Time[5] = duration_cast<duration<double>>(end - start).count();
}

void lineWithParam(string text) {
    while (text.size() < 23) text += " ";
    cout << horizontLine + ' ' + text + '|';
    string text1 = to_string(Time[0]);
    while (text1.size() < 20) text1 += " ";
    cout << text1 + '|';
    text1 = to_string(Time[1]);
    while (text1.size() < 14) text1 += " ";
    cout << text1 + '|';
    text1 = to_string(Time[2]);
    while (text1.size() < 12) text1 += " ";
    cout << text1 + '|';
    text1 = to_string(Time[3]);
    while (text1.size() < 13) text1 += " ";
    cout << text1 + '|';
    text1 = to_string(Time[4]);
    while (text1.size() < 17) text1 += " ";
    cout << text1 + '|';
    text1 = to_string(Time[5]);
    while (text1.size() < 12) text1 += " ";
    cout << text1 + '|';
}

int WriteLenSet() {
    int size1;
    cin >> size1;
    while (size1<0 || cin.fail()) {
        if (cin.fail())
            cout << "Введите целое число! ";
        else if (size1<0)
            cout << "Введите положительное число! ";
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Повторите ввод: ";
        cin >> size1;
    }
    return size1;
}

void CreateStronTable() {
    CountTime_Create();
    lineWithParam("Создание множества");
    LenSet();
    lineWithParam("Мощность множества");
    isSubSetAA();
    lineWithParam("Подмножество А-А");
    isSubSetBA();
    lineWithParam("Подмножество В-А");
    isEqualAA();
    lineWithParam("Равенство А=А");
    isEqualBA();
    lineWithParam("Равенство B=А");
    MergeAB();
    lineWithParam("Объединение A и B");
    InterAB();
    lineWithParam("Пересечение A и B");
    DiffAB();
    lineWithParam("Разность A-B");
    DiffBA();
    lineWithParam("Разность B-A");
    SimmDifAB();
    lineWithParam("Симметричная разность");
}

void createTable() {
    cout << "Введите размер множества A: ";
    Size_SetA = WriteLenSet();
    cout << "Введите размер множества B: ";
    Size_SetB = WriteLenSet();
    cout << title;
    CreateStronTable();
    cout << horizontLine;
}

int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleTitle(L"Осин Сергей 23ВП2");
    createTable();
    system("pause");
    return 0;
}