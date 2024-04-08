#ifndef ISA_STRUKTURY_DANYCH_TESTS_H
#define ISA_STRUKTURY_DANYCH_TESTS_H
#include "DoublyList.h"
#include "TailList.h"
#include "ArrayList.h"
#include "List.h"
#include <fstream>

// PODAJAC SCIEZKI DO PLIKU PODAWAJ ZAWSZE SCIEZKE BEZWZGLEDNA
// W PLIKU CPP KOD DLA KAZDEJ FUNCKJI JEST IDENTYCZNY TYLKO Z ZMIENONYM ARGUMENTEM

// TESTUJE OPERACJE N RAZY NA DOWOLNEJ STRUKTURZE
void randomTest(int operation, int times,ArrayList<int>& list);
void randomTest(int operation, int times,List<int>& list);
void randomTest(int operation, int times,TailList<int>& list);
void randomTest(int operation,int times,DoublyList<int>& list);

// WCZYTUJE DANE Z PLIKU DO STRUKTURY WYBRANA OPERACJA
void addFromFile (int operation,const std::string& filename,ArrayList<int>& list);
void addFromFile (int operation,const std::string& filename,List<int>& list);
void addFromFile (int operation,const std::string& filename,TailList<int>& list);
void addFromFile (int operation,const std::string& filename,DoublyList<int>& list);

#endif //ISA_STRUKTURY_DANYCH_TESTS_H
