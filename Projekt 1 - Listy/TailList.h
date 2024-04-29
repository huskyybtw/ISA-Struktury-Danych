#ifndef ISA_STRUKTURY_DANYCH_TAILLIST_H
#define ISA_STRUKTURY_DANYCH_TAILLIST_H

#include "SNode.h"

// BLAD Z TEMPLATAMI DZIALA TYLKO NA INTACH
template <typename T>
class TailList {
public:

    TailList(); // KONSTRUKTOR USTAWIALISTE
    ~TailList(); // DESTRUKTOR USUWA WSZYSTKIE ELEMENTY Z LISTY

    bool empty() const; // ZWRACA CZY LISTA ZAWIERA ELEMENTY
    const T& first() const; // ZWRACA PIERWSZY ELEMENT
    const T& last() const; // ZWRACA OSTATNI ELEMENT
    const T& random() const; // ZWRACA LOSOWY ELEMENT

    void addFront (const T& t); // DODAJE ELEMENT Z PRZODU LISTY
    void removeFront (); // USUWA ELEMENT Z PRZODU LISTY

    void addEnd(const T& t); // DODAJE ELEMENT Z KONCA LISTY
    void removeEnd(); // USUWA ELEMENT Z KONCA LISTY

    void addRandom(const T& t,int random); // DODAJE ELEMENT PO LOSOWYM ELEMENCIE
    void removeRandom(int random); // USUWA ELEMENT PO LOSOWYM ELEMENCIE

    void printList(); // WYPISUJE WYSZTKIE ELEMENTY LISTY
    void printRandom(); // WYPISUJE LOSOWY ELEMENT LISTY

    int getSize(); // ZWRACA WIELKOSC LISTY

private:
    SNode<T>* tail;
    SNode<T>* head; // WSKAZNIK NA PIERWSZY ELEMENT LISTY
    int size; // PRZECHOWUJE WIELKOSC LISTY
};

#endif //ISA_STRUKTURY_DANYCH_TAILLIST_H
