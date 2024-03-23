#ifndef ISA_STRUKTURY_DANYCH_DOUBLYLIST_H
#define ISA_STRUKTURY_DANYCH_DOUBLYLIST_H

#include "DNode.h"


    // BLAD Z TEMPLATAMI DZIALA TYLKO NA INTACH
    template <typename T>
    class DoublyList {
    public:

        DoublyList(); // KONSTRUKTOR USTAWIALISTE
        ~DoublyList(); // DESTRUKTOR USUWA WSZYSTKIE ELEMENTY Z LISTY

        bool empty() const; // ZWRACA CZY LISTA ZAWIERA ELEMENTY
        const T& first() const; // ZWRACA PIERWSZY ELEMENT
        const T& last() const; // ZWRACA OSTATNI ELEMENT
        const T& random() const; // ZWRACA LOSOWY ELEMENT

        void addFront (const T& t); // DODAJE ELEMENT Z PRZODU LISTY
        void removeFront (); // USUWA ELEMENT Z PRZODU LISTY

        void addEnd(const T& t); // DODAJE ELEMENT Z KONCA LISTY
        void removeEnd(); // USUWA ELEMENT Z KONCA LISTY

        void addRandom(const T& t); // DODAJE ELEMENT PO LOSOWYM ELEMENCIE
        void removeRandom(); // USUWA ELEMENT PO LOSOWYM ELEMENCIE

        void printList(); // WYPISUJE WYSZTKIE ELEMENTY LISTY
        void printRandom(); // WYPISUJE LOSOWY ELEMENT LISTY

        int getSize(); // ZWRACA WIELKOSC LISTY

    private:
        DNode<T>* head; // WSKAZNIK NA PIERWSZY ELEMENT LISTY
        DNode<T>* tail; // WSKAZNIK NA OSTATNI ELEMENT LISTY
        int size; // PRZECHOWUJE WIELKOSC LISTY
    };


#endif //ISA_STRUKTURY_DANYCH_DOUBLYLIST_H
