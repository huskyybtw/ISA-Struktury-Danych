//
// Created by marek on 23.04.2024.
//

#ifndef ISA_STRUKTURY_DANYCH_PQHEAP_H
#define ISA_STRUKTURY_DANYCH_PQHEAP_H


template<typename T>
struct Node {
    int priority;
    T elem;
};


template<typename T>
class PQheap{

public:
    PQheap();
    ~PQheap();

    void insert(const int prio,const T& t);
    void modifyKey(const int prio,const T& t);
    T pop();
    T getMax();

    int getSize();
    void printQueue();

    // DODATKOWA DLA TESTOW CZY DOBRZE SORTUJE
    T popWithPrio(); // Usuwa element i zwraca jego piorytet
private:
    Node<T>* array;
    int size;
    int maxSize;

    // UTILITIES
    void siftUp(int i);
    void siftDown(int i);
    void resize();
};



#endif //ISA_STRUKTURY_DANYCH_PQHEAP_H
