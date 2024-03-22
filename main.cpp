#include <iostream>
#include "List.h"
#include "tests.h"


int main() {
    List<int>* mylist = new List<int>();
    delete mylist;
    return 0;
}

