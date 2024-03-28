#include <iostream>
#include "List.h"
#include "DoublyList.h"
#include "tests.h"


int main() {
    DoublyList<int>* mylist = new DoublyList<int>();

    randomTest(0,3,*mylist);
    randomTest(1,2,*mylist);
    randomTest(2,20,*mylist);
    //randomTest(4,25,*mylist); // dziala wpelni
    //randomTest(5,19,*mylist); // 5  dziala jesli nie dodajemy 2
    //randomTest(3,4999,*mylist); // 5 I 2 wydaja sie nie dzialac i psuc inne funckje


    std::cout<< "WIELKOSC LISTY " ;
    std::cout<< mylist->getSize() << std::endl;
    mylist->printList();
    delete mylist;
    return 0;
}

