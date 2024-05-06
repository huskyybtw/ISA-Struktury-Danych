#ifndef ISA_STRUKTURY_DANYCH_TEST_H
#define ISA_STRUKTURY_DANYCH_TEST_H
#include "PQheap.h"
#include <vector>
// TESTY DO POMIARU CZASU
// 100 POWTORZEŃ DLA KAZDEGO SEEDA
double generatorTestHeap(int operation,int* seeds,int seedsSize,int amount);
double generatorTestArray(int operation,int* seeds,int seedsSize,int amount);

//  TESTY GENERUJACY KOPIE TABLICY DLA DANEGO SEEDA I SPRAWDZAJACY POPRAWNOSC SORTOWANIA
bool checkValidHeap(int seed,int amount);
bool checkValidArray(int seed,int amount);

std::vector<int> Generator(int seed,int amount);
#endif //ISA_STRUKTURY_DANYCH_TEST_H
