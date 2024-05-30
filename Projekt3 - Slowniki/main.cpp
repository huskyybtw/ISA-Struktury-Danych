#include <iostream>
#include "HashTable_Bucket.h"
#include "HashTable.h"
#include <random>

int main (){
    int amount = 1000;
    std::vector<int> numbers;
    std::mt19937 rng(123);

    for (int i = 0; i < amount-4; ++i) {
        int randPrio = rng();
        numbers.push_back(randPrio);
    }

    HashTable_Bucket* temp = new HashTable_Bucket();
    HashTable* virt;
    virt = temp;
    for(int i=0 ; i< amount ; i++){
        virt->insert(numbers[i],i);
    }

    std::cout << temp->getSize() << std:: endl;
    virt -> print();

    std::cout << virt ->find(0) << std::endl;
}