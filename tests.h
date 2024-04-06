#ifndef ISA_STRUKTURY_DANYCH_TESTS_H
#define ISA_STRUKTURY_DANYCH_TESTS_H

#include "List.h"
#include "fstream"

// PODAJAC SCIEZKI DO PLIKU PODAWAJ ZAWSZE SCIEZKE BEZWZGLEDNA

void randomTest(int operation,int times,DoublyList<int>& list); // TESTUJE OPRACJE NA LISCIE DWU-KIERUNKOWEJ Z LOSOWO GENEROWANYMI WARTOSCIAMI
void randomTest(int operation,int times,List<int>& list); // TESTUJE OPERACJE NA LISCIE Z LOSOWYMI LICZBAMI

void readFile (int operation,const std::string& filename,DoublyList<int>& list); // TESTUJE OPERACJE DODAWANIA DO LISTY DWU-KIERUNKOWEJ NA DANYCH Z PLIKU (NOWA LINIA NOWY INT)
void readFile (int operation,const std::string& filename,List<int>& list); // TESTUJE OPERACJE DODAWANIA DO LISTY NA DANYCH Z PLIKU (NOWA LINIA NOWY INT)

#endif //ISA_STRUKTURY_DANYCH_TESTS_H
