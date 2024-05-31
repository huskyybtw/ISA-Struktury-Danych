#include "HashTable_Bucket.h"
#include <iostream>
#include <list>

HashTable_Bucket::HashTable_Bucket() : size(10) ,count(0) {
    array = new std::list<Entry>[size];
}

HashTable_Bucket::~HashTable_Bucket() {
    delete[] array;
}


void HashTable_Bucket::resize() {
    int oldSize = size;
    size = size*2;
    std::list<Entry>* newArray = new std::list<Entry>[size];

    // PRZEPISZ KLUCZE Z STAREJ TABLICY
    for (int i = 0; i < oldSize; ++i) {
        for (const auto& entry : array[i]) {
            int hashedKey = hashCode(entry.key);
            newArray[hashedKey].push_front(entry);
        }
    }

    delete[] array;
    array = newArray;
}

int HashTable_Bucket::hashCode(int key) {
    if (key < 0) {
        key = static_cast<unsigned int>(-key);
    }
    return key % size;
}

void HashTable_Bucket::insert(int key, int value) {
    if(count == size/2){
        resize();
    }
    int hashedKey = hashCode(key);
    for(auto& it: array[hashedKey]){
        if(it.key == key){
            it.key = key;
            it.value = value;
            return;
        }
    }

    array[hashedKey].push_front({key,value});
    count++;
}

void HashTable_Bucket::remove(int key) {
    int hashedKey = hashCode(key);
    auto& entries = array[hashedKey];
    for (auto it = entries.begin(); it != entries.end(); it++){
        if (it->key == key) {
            entries.erase(it);
            count--;
            return;
        }
    }
}

int HashTable_Bucket::find(int key) {
    int hashedKey = hashCode(key);
    for (auto& entry : array[hashedKey]) {
        if (entry.key == key) {
            return entry.value;
        }
    }
    throw std::invalid_argument("key not found");
}

void HashTable_Bucket::print() {
    for(int i=0 ; i<size ; i++){
        for (auto it : array[i]){
            std::cout << it.key << " : " << it.value << std::endl;
        }
    }
}

int HashTable_Bucket::getSize() {
    return count;
}
