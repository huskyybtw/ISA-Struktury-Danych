
#ifndef ISA_STRUKTURY_DANYCH_ARRAYLIST_H
#define ISA_STRUKTURY_DANYCH_ARRAYLIST_H


template <class T>
class ArrayList{

public:

    ArrayList(); // Konstruktor
    ~ArrayList(); // Destruktor

    void addFront (const T &t); // Dodaje element na poczatku tablicy
    void removeFront (); // Usuwa element na poczatku tablicy

    void addEnd(const T &t); // Dodaje element na koncu tablicy
    void removeEnd(); // Usuwa element na koncu tablicy

    void addRandom(const T &t); // Dodaje element w losowym miejscu tablicy
    void removeRandom(); // Usuwa element w losowym miejscu tablicy

    void printList(); // Wypisuje wszystkie elementy z tablicy
    void printRandom(); // Wypisuje losowy element z tablicy

    int getSize();

 //   bool isEmpty(); // Sprawdza czy tablica jest pusta


private:

    T *data = nullptr; // Wskaznik na tablice
    int arraySize; // Dlugosc tablicy
    int size; // Ilosc elementow w tablicy
    void resize(); // Powieksza tablice jesli to konieczne
    bool needtoresize(); // Sprawdza czy trzeba powiekszyc tablice


};

#endif //ISA_STRUKTURY_DANYCH_ARRAYLIST_H
