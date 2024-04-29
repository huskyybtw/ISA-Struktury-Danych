#include <iostream>
#include <windows.h>
#include "ArrayList.h"
#include "List.h"
#include "DoublyList.h"
#include "TailList.h"
#include "tests.h"

int getConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}
void printDashes(int amount) {
    for (int i = 0; i < amount; ++i) {
        std::cout << '-';
    }
}
void printData(ArrayList<int>& alist,
                     List<int>& list,
                     TailList<int>& tlist,
                     DoublyList<int>& dlist){
    int dashes = getConsoleWidth();
    printDashes(dashes);
    std::cout << "ArrayList size:" << alist.getSize() << std::endl;
    std::cout << "List size:" << list.getSize() << std::endl;
    std::cout << "TailList size:" << tlist.getSize() << std::endl;
    std::cout << "DoublyList size:" << dlist.getSize() << std::endl;
    printDashes(dashes);
}
void printOperations(){
    std::cout << "0 - addFront" << std::endl;
    std::cout << "1 - addEnd" << std::endl;
    std::cout << "2 - addRandom" << std::endl;
    std::cout << "3 - removeRandom" << std::endl;
    std::cout << "4 - removeFront" << std::endl;
    std::cout << "5 - removeEnd" << std::endl;
}
void printStructures(){
    std::cout << "1 - ArrayList" << std::endl;
    std::cout << "2 - List" << std::endl;
    std::cout << "3 - TailList" << std::endl;
    std::cout << "4 - DoublyList" << std::endl;
    std::cout << "5 - exit" << std::endl;
}

void App(ArrayList<int>& alist,
         List<int>& list,
         TailList<int>& tlist,
         DoublyList<int>& dlist){

    bool exit = false;

    while(!exit) {

        int dataStructure = 0; // Initialize to 0 or any value outside the valid range
        while (dataStructure < 1 || dataStructure > 5) {
            printData(alist, list, tlist, dlist);
            printStructures();

            std::cout << "Enter data structure choice: ";
            std::cin >> dataStructure;
            std::cout << std::endl;
            system("cls");
        }

        if (dataStructure == 5){
                delete &alist;
                delete &list;
                delete &tlist;
                delete &dlist;
                return;
        }

        int operation = -1;
        while (operation < 0 || operation > 5) {
            printData(alist ,list ,tlist ,dlist);
            printOperations();

            std::cout << "Enter operation choice: ";
            std::cin >> operation;
            std::cout << std::endl;
            system("cls");
        }

        int times = -1;
        while (times < 0 || times > 500000) {
            printData(alist ,list ,tlist ,dlist);
            std::cout << "Number of times to perform operation (MAX 500_00)" << std::endl;
            std::cin >> times;
            std::cout << std::endl;
            system("cls");
        }

        switch (dataStructure) {
            case 1: // ArrayList
                randomTest(operation, times, alist);
                break;
            case 2: // List
                randomTest(operation, times, list);
                break;
            case 3: // TailList
                randomTest(operation, times, tlist);
                break;
            case 4: // ArrayList
                randomTest(operation, times, dlist);
                break;
            case 5:
                exit = true;
                break;
            default:
                std::cerr << "Invalid choice" << std::endl;
                break;
        }

        if (exit == true){
            delete &alist;
            delete &list;
            delete &tlist;
            delete &dlist;
            return;
        }
    }
}