#include <cstdlib>
#include <ctime>
#include <iostream>

#include "List.h"
#include "Node.h"


void randomTest(int operation,int times,List<int>& list){

    switch(operation) {
        case 0: // addFront

            std::cout << "ADDFRONT TEST :" << std::endl;
            std::srand(std::time(nullptr));

            for (int i = 0; i < times; i++) {
                int random = std::rand() % 100;
                random = random + i; // BUG GENEROWALO CALY CZAS TE SAME LICZBY NIE WIEM CZEMU
                list.addFront(random);
            }
            list.printList();
            break;

        case 1: // addEnd
            std::cout << "ADDEND TEST :" << std::endl;
            std::srand(std::time(nullptr));

            for (int i = 0; i < times; i++) {
                int random = std::rand() % 100;
                random = random + i; // BUG GENEROWALO CALY CZAS TE SAME LICZBY NIE WIEM CZEMU
                list.addEnd(random);
            }
            list.printList();
            break;

        case 2: // addRandom
            std::cout << "ADDRANDOM TEST :" << std::endl;
            std::srand(std::time(nullptr));

            for (int i = 0; i < times; i++) {
                int random = std::rand() % 100;
                random = random + i; // BUG GENEROWALO CALY CZAS TE SAME LICZBY NIE WIEM CZEMU
                list.addRandom(random);
            }
            list.printList();
            break;

        case 3:
            for (int i = 0; i < times; i++) {
                list.removeRandom();
            }
            list.printList();
            break;

        case 4:
            for (int i = 0; i < times; i++) {
                list.removeFront();
            }
            list.printList();
            break;

        case 5:
            for (int i = 0; i < times; i++) {
                list.removeEnd();
            }
            list.printList();
            break;
    }
}