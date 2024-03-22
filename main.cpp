#include <iostream>
#include "List.h"
#include "tests.h"


int main() {
    List<int>* mylist = new List<int>();


    randomTest(0,1000,*mylist);
    randomTest(1,1000,*mylist);
    randomTest(2,1000,*mylist);
    randomTest(3,100,*mylist);
    randomTest(4,100,*mylist);
    randomTest(5,1000,*mylist);


    std::cout<< "After operations :" << std::endl;
    mylist->printList();

    std::cout<< "dziala :" << std::endl;
    std::cout << mylist->getSize()<< std::endl;
    delete mylist;
    return 0;
}

