#include <iostream>
#include "List.h"
#include "DoublyList.h"
#include "tests.h"


int main() {

    TailList<int>* lista = new TailList<int>();
    randomTest(0,10,*lista);
    randomTest(1,8,*lista);
   // randomTest(5,1,*lista);
    //randomTest(2,10000,*lista);
    //randomTest(3,9997,*lista);
    lista->printList();
    delete lista;

    return 0;
}

