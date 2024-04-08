
#include <iostream>
#include "ArrayList.h"
#include <cstdlib>
#include <ctime>


template class ArrayList<int>;   // Explicit instantiation

template <class T>       // Konstruktor
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
void ArrayList<T>::addRandom(const T &t) { // Dodaje element w losowym miejscu w tablicy
    if(size == 0){
        this->addFront(t);
    }
    try {
        if (needtoresize()) // Sprawdzenie czy trzeba powiekszyc tablice, jesli tak to powieksza 2x
            resize();
    } catch (const std::exception& e) {  // Wylapywanie wyjatkow
        std::cerr << "Wyjątek podczas zmiany rozmiaru tablicy: " << e.what() << std::endl;
    }

    srand(time(nullptr)); // Inicjalizacja generatora liczb pseudo-losowych
    int random = rand() % size; // Generuje indeks danej liczby z przedzialu 0 do size-1

    for (int i = size; i > random; i--){    // Przesuniecie elementow na prawo od wygenerowanego losowo indeksu w celu zrobienia miejsca dla nowej liczby
        data[i] = data[i - 1];
    }
    data[random] = t;   // Wlozenie nowej liczby w miejsce, ktore zostalo zwolnione
    size++; // Zwiekszenie ilosci elementow w tablicy o jeden

}

template <class T>
void ArrayList<T>::addEnd(const T &t) {    //Dodaje element na koncu tablicy
    try {
        if (needtoresize())
            resize();
    } catch (const std::exception& e) {
        std::cerr << "Wyjątek podczas zmiany rozmiaru tablicy: " << e.what() << std::endl;
    }
    data[size] = t;     // Dodananie liczby na koncu tablicy
    size++;
}

template <class T>
void ArrayList<T>::addFront(const T &t) {   // Dodaje liczbe na poczatku tablicy
    try {
        if (needtoresize())
            resize();
    } catch (const std::exception& e) {
        std::cerr << "Wyjątek podczas zmiany rozmiaru tablicy: " << e.what() << std::endl;
    }
    for(int i = size; i > 0; i--){
        data[i] = data[i - 1];     // Przesuniecie elementow w prawo zeby zrobic miejsce dla nowego elementu
    }
    data[0] = t;    // Wstawienie nowego elementu na poczatek tablicy
    size++;
}

template <class T>
void ArrayList<T>::removeFront() {      // Usuniecie elementu z poczatku tablicy
    if (size == 0) {    // Sprawdzenie czy ilosc elementow w tablicy wynosi 0, jesli tak to wypisuje komunikat
        std::cout << "Tablica jest pusta." << std::endl;
        return;
    }
    for (int i = 0; i < size - 1; ++i) {       // Przesuniecie elementow o jedno miejsce w lewo i usuniecie przy tym pierwszego
        data[i] = data[i + 1];
    }
    data[size] = 0;                      // Usuniecie dodadkowego ostatniego elementu
    size--;

}

template <class T>
void ArrayList<T>::removeEnd() {    // Usuniecie elementu ostatniego z tablicy
    if (size == 0) {
        std::cout << "Tablica jest pusta." << std::endl;
        return;
    }
    data[size] = 0;
    size--;
}

template <class T>
void ArrayList<T>::removeRandom() {     // Usuniecie losowego elementu z tablicy
    if (size == 0) {
        std::cout << "Tablica jest pusta." << std::endl;
        return;
    }
    srand(time(nullptr));   // Inicjalizacja generatora
    int random = rand() % size;         // Generuje indeks danej liczby z przedzialu 0 do size - 1
    for( int i = random; i < size - 1; i++){  // Przesuniecie elementow z tablicy po losowej liczbie o jedna pozycje w lewo
        data[i] = data[i + 1];
    }
    size--;
}

template <class T>
bool ArrayList<T>::needtoresize() {  // Sprawdza czy trzeba powiekszyc tablice
    return size >= arraySize;
}

template <class T>
void ArrayList<T>::resize() { // Powiekszenie tablicy dwukrotnie
    arraySize = arraySize*2;
    T *newData = new T[arraySize];
    for(int i = 0; i < size; i++){
        newData[i] = data[i];
    }
    delete []data;
    data = newData;
}

/*
template <class T>
bool ArrayList<T>::isEmpty() {  // Sprawdza czy tablica jest pusta
    if (size == 0)
        return true;
}
*/
template <class T>
void ArrayList<T>::printList() {  // Drukuje cala zawartosc tablicy
    if (size == 0){
        std::cout << "Tablica jest pusta, nie ma co wypisac. (printList)" << std::endl;
        return;
    }
    for(int i = 0; i < size; i++){
        std::cout << data[i] << " ";
    }

}

template <class T>
void ArrayList<T>::printRandom() {      // Drukuje losowy element z tablicy
    if (size == 0){
        std::cout << "Tablica jest pusta, nie ma co wypisac. (printRandom)" << std::endl;
        return;
    }
    srand(time(nullptr));   // Inicjalizacja generatora
    int random = rand() % size;         // Generuje indeks danej liczby z przedzialu 0 do size-1
    int temp = data[random];
    std::cout << "Losowa liczba wynosi:" << temp << std::endl;

}