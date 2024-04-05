
#ifndef ISA_STRUKTURY_DANYCH_ARRAYLIST_H
#define ISA_STRUKTURY_DANYCH_ARRAYLIST_H


template <class T>
class ArrayList{

public:

    ArrayList(); //Konstruktor
    ~ArrayList(); //Destruktor

    void addFront (const T &t); // DODAJE ELEMENT Z PRZODU LISTY
    void removeFront (); // USUWA ELEMENT Z PRZODU LISTY

    void addEnd(const T &t); // DODAJE ELEMENT Z KONCA LISTY
    void removeEnd(); // USUWA ELEMENT Z KONCA LISTY

    void addRandom(const T &t); // DODAJE ELEMENT PO LOSOWYM ELEMENCIE
    void removeRandom(); // USUWA ELEMENT PO LOSOWYM ELEMENCIE

    void printList(); // WYPISUJE WYSZTKIE ELEMENTY LISTY
    void printRandom(); // WYPISUJE LOSOWY ELEMENT LISTY

    int getSize(); // ZWRACA WIELKOSC LISTY

    bool isEmpty();

private:

    T *data = nullptr; //wskaznik na tablice
    int arraySize; // dlugosc tablicy
    int size; // ilosc elementow w tablicy
    void resize(); // powiekszyc tablice jesli konieczne
    bool needtoresize(); // sprawdza czy trzeba powiekszyc tablice


};

#endif //ISA_STRUKTURY_DANYCH_ARRAYLIST_H
