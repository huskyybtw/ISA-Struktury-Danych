#include <iostream>
#include "List.h"
#include "DoublyList.h"
#include "tests.h"


int main() {
    DoublyList<int>* mylist = new DoublyList<int>();


    std::cout<< "WIELKOSC LISTY " ;
    std::cout<< mylist->getSize() << std::endl;
    delete mylist;
    return 0;
}

