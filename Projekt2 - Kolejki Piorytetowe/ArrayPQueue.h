
#ifndef STRUKTURYDANYCHP2_ARRAYPQUEUE_H
#define STRUKTURYDANYCHP2_ARRAYPQUEUE_H


template <class T>
class PriorityQueue{

public:

    PriorityQueue(); // Konstruktor
    ~PriorityQueue(); // Destruktor

    int getSize(); // Zwraca ilosc elementow w kolejce
    void printQueue(); // Wypisuje wszystkie elementy z tablicy
    void insert(int priority,int value); // Umieszcza element o danej wartosci i priorytecie w odpowiednim miejscu
    int extractMax(); // Zwraca i usuwa element o najwiekszym priorytecie
    void modifyKey(int priority,int value); // Zmienia priorytet elementu o danej wartosci
    int peek(); // Zwraca element o najwiekszym priorytecie

    // DODATKOWA DLA TESTOW CZY DOBRZE SORTUJE
    int extractMaxPrio(); // Usuwa element i zwraca jego piorytet
private:

    struct Element {
        int value;
        int priority;
    };

    Element *data = nullptr; // Wskaznik
    int arraySize; // Dlugosc tablicy
    int size; // Ilosc elementow w tablicy
    void resize(); // Powieksza tablice jesli to konieczne
    bool needtoresize(); // Sprawdza czy trzeba powiekszyc tablice


};
#endif //STRUKTURYDANYCHP2_ARRAYPQUEUE_H
