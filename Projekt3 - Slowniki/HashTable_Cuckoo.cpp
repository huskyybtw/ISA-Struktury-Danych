#include <iostream>
#include <climits>
#include "HashTable_Cuckoo.h"

HashTable_Cuckoo::HashTable_Cuckoo() : size(10), count(0) {
    arrFirst = new Entry[size];
    arrSecond = new Entry[size];

    for (int i = 0; i < size; i++) {
        arrFirst[i] = {INT_MIN, 0};
        arrSecond[i] = {INT_MIN, 0};
    }
}

HashTable_Cuckoo::~HashTable_Cuckoo() {
    delete[] arrFirst;
    delete[] arrSecond;
}

void HashTable_Cuckoo::assign(int key, int value) {
    Entry temp = {key, value};
    int it = 0;

    while (it < size) {
        int pos1 = hashFirst(temp.key);
        if (arrFirst[pos1].key == INT_MIN) {
            arrFirst[pos1] = temp;
            count++;
            return;
        }

        std::swap(arrFirst[pos1], temp);

        int pos2 = hashSecond(temp.key);
        if (arrSecond[pos2].key == INT_MIN) {
            arrSecond[pos2] = temp;
            count++;
            return;
        }

        std::swap(arrSecond[pos2], temp);

        it++;
    }

    resize();
    assign(temp.key, temp.value); // Retry inserting the element after resizing
}

int HashTable_Cuckoo::hashFirst(int key) {
    if (key < 0) {
        key = static_cast<unsigned int>(-key);
    }
    return key % size;
}

int HashTable_Cuckoo::hashSecond(int key) {
    if (key < 0) {
        key = static_cast<unsigned int>(-key);
    }
    const int prime = 7;
    return (key / prime) % size;
}

void HashTable_Cuckoo::resize() {
    int oldSize = size;
    size = size * 2;

    Entry* _arrFirst = new Entry[size];
    Entry* _arrSecond = new Entry[size];

    for (int i = 0; i < size; i++) {
        _arrFirst[i] = {INT_MIN, 0};
        _arrSecond[i] = {INT_MIN, 0};
    }

    Entry* oldArrFirst = arrFirst;
    Entry* oldArrSecond = arrSecond;

    arrFirst = _arrFirst;
    arrSecond = _arrSecond;

    count = 0; // Reset count before re-inserting elements

    for (int i = 0; i < oldSize; i++) {
        if (oldArrFirst[i].key != INT_MIN) {
            assign(oldArrFirst[i].key, oldArrFirst[i].value);
        }
        if (oldArrSecond[i].key != INT_MIN) {
            assign(oldArrSecond[i].key, oldArrSecond[i].value);
        }
    }

    delete[] oldArrFirst;
    delete[] oldArrSecond;
}

void HashTable_Cuckoo::insert(int key, int value) {
    if (find(key) != INT_MIN) {
        replace(key,value);
        return; // Key already exists
    }
    if (count >= size / 2) { // Trigger resize when load factor exceeds 0.5
        resize();
    }
    assign(key, value);
}

void HashTable_Cuckoo::replace(int key,int value) {
    if(find(key) == INT_MIN){
        return;
    }

    int pos1 = hashFirst(key);
    if (arrFirst[pos1].key == key) {
        arrFirst[pos1].key = key;
        arrFirst[pos1].value = value;
        return;
    }

    int pos2 = hashSecond(key);
    if (arrSecond[pos2].key == key) {
        if (arrSecond[pos2].key == key) {
            arrSecond[pos2].key = key;
            arrSecond[pos2].value = value;
            return;
        }
    }
}

int HashTable_Cuckoo::find(int key) {
    int pos1 = hashFirst(key);
    if (arrFirst[pos1].key == key) {
        return arrFirst[pos1].value;
    }

    int pos2 = hashSecond(key);
    if (arrSecond[pos2].key == key) {
        return arrSecond[pos2].value;
    }

    return INT_MIN; // Key not found
}

void HashTable_Cuckoo::remove(int key) {
    int pos1 = hashFirst(key);
    if (arrFirst[pos1].key == key) {
        arrFirst[pos1] = {INT_MIN, 0};
        count--;
        return;
    }

    int pos2 = hashSecond(key);
    if (arrSecond[pos2].key == key) {
        arrSecond[pos2] = {INT_MIN, 0};
        count--;
        return;
    }
}

int HashTable_Cuckoo::getSize() {
    return count;
}

void HashTable_Cuckoo::print() {
    std::cout << "First Array: ";
    for (int i = 0; i < size; i++) {
        if (arrFirst[i].key != INT_MIN) {
            std::cout << "[" << arrFirst[i].key << ":" << arrFirst[i].value << "] ";
        }
    }
    std::cout << "\nSecond Array: ";
    for (int i = 0; i < size; i++) {
        if (arrSecond[i].key != INT_MIN) {
            std::cout << "[" << arrSecond[i].key << ":" << arrSecond[i].value << "] ";
        }
    }
    std::cout << std::endl;

}