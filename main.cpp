#include <iostream>
#include "List.h"
#include "DoublyList.h"
#include "tests.h"


int main() {
    DoublyList<int>* mylist = new DoublyList<int>();

    randomTest(0,1000,*mylist);
    randomTest(1,1000,*mylist);
    randomTest(2,100000,*mylist);
    randomTest(4,1000,*mylist); // dziala wpelni
    randomTest(5,1500,*mylist); // 5  dziala jesli nie dodajemy 2
    randomTest(3,499900,*mylist); // 5 I 2 wydaja sie nie dzialac i psuc inne funckje


    std::cout<< "WIELKOSC LISTY " ;
    std::cout<< mylist->getSize() << std::endl;
    delete mylist;
    return 0;
}

