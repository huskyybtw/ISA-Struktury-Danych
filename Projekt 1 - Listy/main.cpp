#include <iostream>
#include "ArrayList.h"
#include "List.h"
#include "DoublyList.h"
#include "TailList.h"
#include "tests.h"
#include "ui.h"

// UWAGA NIE DAC SEEDA WIEKSZEGO NIZ ILOSC ELEMENTOW BO JAKO LOSOWY ELEMENT ZAWSZE DAJE SEED[I]
int seeds[10] = {100,2222,3333,4444,5123,6123,7432,8222,9111,1034};
int seedsSize = sizeof(seeds) / sizeof (seeds[0]);

int main() {
    ArrayList<int>* alist = new ArrayList<int>();
    List<int>* list = new List<int>();
    TailList<int>* tlist = new TailList<int>();
    DoublyList<int>* dlist = new DoublyList<int>();

    std::cout << generatorTest(2,seeds,seedsSize,1000000,*list) << std::endl;
    //App(*alist,*list,*tlist,*dlist);

    delete &alist;
    delete &list;
    delete &tlist;
    delete &dlist;
    return 0;
}

