#include <iostream>
#include "List.h"
#include "DoublyList.h"
#include "tests.h"


int main() {
    DoublyList<int>* mylist = new DoublyList<int>();

    randomTest(0,5,*mylist);
    randomTest(1,5,*mylist);
    randomTest(2,5,*mylist);
    randomTest(4,25,*mylist);
    /*randomTest(5,1,*mylist); // 5 I 3 NIE DZIALAJA
    randomTest(3,1,*mylist); // 5 I 3 NIE DZIALAJA
    */

    std::cout<< "WIELKOSC LISTY " ;
    std::cout<< mylist->getSize() << std::endl;
    delete mylist;
    return 0;
}

