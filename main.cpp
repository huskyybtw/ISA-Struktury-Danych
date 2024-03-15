#include <iostream>
#include "List.h"
#include "Node.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    List<int>* mylist = new List<int>();

    for (int i=0 ; i < 10 ; i++) {
        mylist->addEnd(i);
    }
    std::cout<< mylist->last() << std::endl;

    delete mylist;

    return 0;
}
