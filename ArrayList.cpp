
#include <iostream>
#include "ArrayList.h"
#include <cstdlib>
#include <ctime>


template class ArrayList<int>;   //undefined reference bez tego

template <class T>       // konstruktor
ArrayList<T>::ArrayList() {
    arraySize = 5;
    size = 0;
    data = new T[arraySize];
}

template <class T>       // Destruktor
ArrayList<T>::~ArrayList(){
    delete[] data;
}

template <class T>
void ArrayList<T>::addRandom(const T &t) {

    try {
        if (needtoresize())
            resize();
    } catch (const std::exception& e) {
        std::cerr << "Wyjątek podczas zmiany rozmiaru tablicy: " << e.what() << std::endl;
    }

    srand(time(nullptr));
    int random = rand() % size;

    for (int i = size; i > random; i--){
        data[i] = data[i - 1];
    }
    data[random] = t;
    size++;

}

template <class T>
void ArrayList<T>::addEnd(const T &t) {    //dodaje element na koncu tablicy
    try {
        if (needtoresize())
            resize();
    } catch (const std::exception& e) {
        std::cerr << "Wyjątek podczas zmiany rozmiaru tablicy: " << e.what() << std::endl;
    }
    data[size] = t;
    size++;
}

template <class T>
void ArrayList<T>::addFront(const T &t) {
    try {
        if (needtoresize())
            resize();
    } catch (const std::exception& e) {
        std::cerr << "Wyjątek podczas zmiany rozmiaru tablicy: " << e.what() << std::endl;
    }
    for(int i = size; i > 0; i--){
        data[i] = data[i - 1];     //przesuniecie elementow w prawo zeby zrobic miejsce dla nowego elementu
    }
    data[0] = t;    //wstawienie nowego elementu na poczatek tablicy
    size++;
}

template <class T>
void ArrayList<T>::removeFront() {
    for (int i = 0; i < size - 1; ++i) {       //przesuniecie elementow o 1 w lewo i usuniecie przy tym pierwszego
        data[i] = data[i + 1];
    }
    data[size] = 0;                      // usuniecie dodadkowego ostatniego elementu
    size--;

}

template <class T>
void ArrayList<T>::removeEnd() {
    data[size] = 0;
    size--;
}

template <class T>
void ArrayList<T>::removeRandom() {
    srand(time(nullptr));   //inicjalizacja generatora
    int random = rand() % size;         //generuje liczbe z przedzialu 0 do size - 1
    for( int i = random; i < size - 1; i++){  // przesuniecie elementow z tablicy po losowej liczbie o jedna pozycje w lewo
        data[i] = data[i + 1];
    }
    size--;
}

template <class T>
bool ArrayList<T>::needtoresize() {  //sprawdza czy trzeba powiekszyc tablice
    return size >= arraySize;
}

template <class T>
void ArrayList<T>::resize() { // powiekszenie tablicy dwukrotnie
    arraySize = arraySize*2;
    T *newData = new T[arraySize];
    for(int i = 0; i < size; i++){
        newData[i] = data[i];
    }
    delete []data;
    data = newData;
}


template <class T>
bool ArrayList<T>::isEmpty() {  //sprawdza czy tablica jest pusta
    return size == 0;
}

template <class T>
void ArrayList<T>::printList() {  //drukuje cala zawartosc tablicy

    for(int i = 0; i < size; i++){
        std::cout << data[i] << " ";
    }

}