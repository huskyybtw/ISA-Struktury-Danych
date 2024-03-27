#include <cstdlib>
#include <ctime>
#include <iostream>

#include "List.h"
#include "DoublyList.h"



// TESTUJE PODSTAWOWE OPERACJE NA LISCIE Z LOSOWO GENEROWANYMI WARTOSCIAMI
void randomTest(int operation,int times,DoublyList<int>& list){

    switch(operation) {
        case 0: // addFront

            std::cout << "ADDFRONT TEST :" << std::endl;
            std::srand(std::time(nullptr));

            for (int i = 0; i < times; i++) {
                int random = std::rand() % 100;
                random = random + i; // BUG GENEROWALO CALY CZAS TE SAME LICZBY NIE WIEM CZEMU
                list.addFront(random);
            }
            break;

        case 1: // addEnd
            std::cout << "ADDEND TEST :" << std::endl;
            std::srand(std::time(nullptr));

            for (int i = 0; i < times; i++) {
                int random = std::rand() % 100;
                random = random + i; // BUG GENEROWALO CALY CZAS TE SAME LICZBY NIE WIEM CZEMU
                list.addEnd(random);
            }
            break;

        case 2: // addRandom
            std::cout << "ADDRANDOM TEST :" << std::endl;
            std::srand(std::time(nullptr));

            for (int i = 0; i < times; i++) {
                int random = std::rand() % 100;
                random = random + i; // BUG GENEROWALO CALY CZAS TE SAME LICZBY NIE WIEM CZEMU
                list.addRandom(random);
            }
            break;

        case 3: // removeRandom
            std::cout << "removeRANDOM TEST :" << std::endl;
        for (int i = 0; i < times; i++) {
                list.removeRandom();
            }
            break;

        case 4: // removeFront
            std::cout << "removeFront TEST :" << std::endl;
            for (int i = 0; i < times; i++) {
                list.removeFront();
            }
            break;

        case 5: //removeEnd
            std::cout << "removeEnd TEST :" << std::endl;
            for (int i = 0; i < times; i++) {
                list.removeEnd();
            }
            break;
    }
}