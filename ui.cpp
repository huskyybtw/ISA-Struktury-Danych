#include <iostream>
#include "ArrayList.h"
#include "List.h"
#include "DoublyList.h"
#include "TailList.h"


void testGui(ArrayList<int>& list){
    int operation = 0;
    std::cout << "Chosee a data strcuture" << std::endl;
    std::cin >> operation;
    std::cout << std::endl;

    int times = 0;
    std::cout << "Number of times to perform operation" << std::endl;

    std::cin >> times;
    std::cout << std::endl;
    randomTest(operation,times,*list);
}

bool App(){
    int operation = 0;
    std::cout << "Chosee a data strcuture" << std::endl;

    switch (operation){
        case 0: // ArrayList
            ArrayList<int>* list = new ArrayList<int>();
            testGui(*list);
            break;
        case 1: // ArrayList
            List<int>* list = new List<int>();
            testGui(*list);
            break;
        case 2: // ArrayList
            TailyList<int>* list = new TailyList<int>();
            testGui(*list);
            break;
        case 3: // ArrayList
            DoublyList<int>* list = new DoublyList<int>();
            testGui(*list);
            break;
    }
}