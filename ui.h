#ifndef ISA_STRUKTURY_DANYCH_UI_H
#define ISA_STRUKTURY_DANYCH_UI_H


#include "ArrayList.h"
#include "List.h"
#include "DoublyList.h"
#include "TailList.h"

void printData(ArrayList<int>& alist, List<int>& list, TailList<int>& tlist, DoublyList<int>& dlist);
void printStructures();
void printOperations();
void App(ArrayList<int>& alist, List<int>& list, TailList<int>& tlist, DoublyList<int>& dlist);

#endif //ISA_STRUKTURY_DANYCH_UI_H
