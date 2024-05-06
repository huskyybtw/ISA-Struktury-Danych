#include <iostream>
#include <string>
#include "ArrayPQueue.h"

template class PriorityQueue<int>;   // Explicit instantiation

template <class T>       // Konstruktor
PriorityQueue<T>::PriorityQueue() {
    arraySize = 5;
    size = 0;
    data = new Element[arraySize];
}

template <class T>       // Destruktor
PriorityQueue<T>::~PriorityQueue(){
    delete[] data;
}


template <class T>
void PriorityQueue<T>::resize() {   // Powiekszenie tablicy dwukrotnie
    arraySize = arraySize*2;
    Element *newData = new Element[arraySize];
    for(int i = 0; i < size; i++){
        newData[i] = data[i];
    }
    delete []data;
    data = newData;
}

template <class T>
int PriorityQueue<T>::getSize() {   // Zwrocenie ilosci elementow w kolejce
    return size;
}

template <class T>
bool PriorityQueue<T>::needtoresize() {  // Sprawdza czy trzeba powiekszyc tablice
    return size >= arraySize;
}

template <class T>
void PriorityQueue<T>::insert(int priority,int value) {    // Umieszcza element o danej wartosci i priorytecie w odpowiednim miejscu

    if(needtoresize()) {
        resize();
    }

    int i = size;
    while (i > 0 && priority < data[i - 1].priority) {  // Umieszczenie elementu w posortowany sposob
        data[i] = data[i - 1];
        i--;
    }

    data[i].value = value;
    data[i].priority = priority;
    size++;
}

template <class T>
int PriorityQueue<T>::extractMax() {    // Zwraca i usuwa element o najwiekszym priorytecie

    if (size == 0){
        std::cout << "Tablica jest pusta, nie ma co usunac. " << std::endl;
        return 0;
    }

    if(needtoresize()) {
        resize();
    }
    int removedElement = data[size - 1].value;
    size--;
    return removedElement;
}
// DODATKOWA DLA TESTOW CZY DOBRZE SORTUJE
template <class T>
int PriorityQueue<T>::extractMaxPrio() {    // Zwraca najwyzszy piorytet

    if (size == 0){
        std::cout << "Tablica jest pusta, nie ma co usunac. " << std::endl;
        return 0;
    }

    if(needtoresize()) {
        resize();
    }
    int removedElement = data[size - 1].priority;
    size--;
    return removedElement;
}

template <class T>
void PriorityQueue<T>::printQueue() {  // Drukuje cala kolejke

    if (size == 0){
        std::cout << "Tablica jest pusta, nie ma co wypisac. " << std::endl;
        return;
    }
    for(int i = 0; i < size; i++){
        //std::cout << data[i].value << " ";
        std::cout << data[i].value << "->" << data[i].priority << std::endl;
    }

}

template <class T>
int PriorityQueue<T>::peek() {     // Zwraca element o najwiekszym priorytecie

    if (size == 0){
        throw std::logic_error ("Tablica jest pusta, nie ma co wypisac. ");
    }
    //std::cout << std::endl;
    //std::cout << "Element o najwiekszym priorytecie rownym " << data[size - 1].priority << " to: " << data[size - 1].value;
    return data[size - 1].value;
}

template <class T>
void PriorityQueue<T>::modifyKey(int priority,int value) {     // Zmienia priorytet elementu o danej wartosci

    for (int i = 0; i < size; i++) {
        if (data[i].value == value) {   // Znalezienie indeksu elementu do podmiany
            data[i].priority = priority;    // Podmiana priorytetu

            // Jeśli nowy priorytet jest niższy niż poprzedni, przesuwamy element w górę tablicy
            while (i > 0 && priority < data[i - 1].priority) {
                std::swap(data[i], data[i - 1]);
                i--;
            }

            // Jeśli nowy priorytet jest wyższy niż poprzedni, przesuwamy element w dół tablicy
            while (i < size - 1 && priority > data[i + 1].priority) {
                std::swap(data[i], data[i + 1]);
                i++;
            }
            return;
        }
    }
}