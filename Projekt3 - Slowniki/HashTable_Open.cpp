
#include "HashTable_Open.h"
#include <iostream>
#include <stdexcept>

HashTable_Open::HashTable_Open(): size(10), count(0){   //Konstruktor
     table = new Entry[size]();
     for(int i = 0; i < size; ++i){
         table[i].key = INT_MIN; // pusty wpis
     }
}

HashTable_Open::~HashTable_Open() { //Destruktor
    delete[] table;
}

int HashTable_Open::hashCode(int key) { //Funckja hashujaca
    return key % size;
}

void HashTable_Open::resize() { //Powiekszenie tablicy
    int oldSize = size;
    size = size * 2;
    Entry* oldTable = table;
    table = new Entry[size]();
    for(int i = 0; i < size; ++i){
        table[i].key = INT_MIN; // pusty wpis
    }

    count = 0;
    for(int j = 0; j < oldSize; ++j){
        if(oldTable[j].key != INT_MIN){
            insert(oldTable[j].key, oldTable[j].value);
        }
    }
    delete[] oldTable;
}

int HashTable_Open::getSize() {
    return count;
}

void HashTable_Open::insert(int key, int value) { //Wstawienie elementu
    if(count >= size / 2){
        resize(); // powiekszenie tablicy, jesli jest taka potrzeba
    }

    int index = hashCode(key);
    while(table[index].key != INT_MIN && table[index].key != key){
        index = (index + 1) % size;
    }

    if(table[index].key == INT_MIN){
        count++;
    }
    table[index].key = key;
    table[index].value = value;
}

int HashTable_Open::find(int key) { //Znalezienie elementu wg klucza
    int index = hashCode(key);
    int initialIndex = index;

    while(table[index].key != INT_MIN){
        if(table[index].key == key){
            return table[index].value;
        }
        index = (index + 1) % size;
        if(index == initialIndex){
            break;  // zapobiega zapetleniu
        }
    }
    throw std::runtime_error("Klucz nie znaleziony");
}

void HashTable_Open::remove(int key) {  //Usuniecie elementu z tablicy
    int index = hashCode(key);
    int initialIndex = index;

    while(table[index].key != INT_MIN){
        if(table[index].key == key){
            table[index].key = INT_MIN;
            count--;
            return;
        }
        index = (index + 1) % size;
        if(index == initialIndex){
            break;
        }
    }
}

void HashTable_Open::print() { //Wypisanie tablicy
    for(int i = 0; i < size; ++i){
        if(table[i].key != INT_MIN){
            std::cout << "HashTable[" << i << "]   " << "Key: " << table[i].key << " " << "Value: " << table[i].value << std::endl;
        }
    }
}