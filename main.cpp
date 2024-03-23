#include <iostream>
#include "List.h"
#include "tests.h"


int main() {
    List<int>* mylist = new List<int>();

    randomTest(0,50000,*mylist);
    randomTest(1,50000,*mylist);
    randomTest(2,5000,*mylist);
    randomTest(4,5000,*mylist);
    randomTest(5,5000,*mylist);
    randomTest(3,300000,*mylist);

    std::cout<< "WIELKOSC LISTY " ;
    std::cout<< mylist->getSize() << std::endl;
    delete mylist;
    return 0;
}

