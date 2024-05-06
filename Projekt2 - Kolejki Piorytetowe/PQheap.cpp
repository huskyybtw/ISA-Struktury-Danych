#include <iostream>
#include <vector>
#include "PQheap.h"

template class PQheap<int>; // EXPLICIT
template class PQheap<char>; // EXPLICIT

template<typename T>
PQheap<T>::PQheap(){
    array = new Node<T>[5];
    maxSize = 5;
    size = -1; // SIZE ++ PRZY DODAWANIU ELEMENTU BY ZACZĄĆ OD [0]
}

template<typename T>
PQheap<T>::~PQheap(){
    delete[] array;
}

template<typename T>
T PQheap<T>::getMax() {
    if(size >= 0){
        return array[0].elem;
    }
    else{
        throw std::logic_error("Heap is empty");
    }
}

template<typename T>
int PQheap<T>::getSize() {
    return size;
}

template<typename T>
void PQheap<T>::insert(const int prio, const T& t) {
    if (size + 1 >= maxSize) { // SPRAWDZA CZY POTRZEBA DYNAMICZNIE ROSZERZYC TABLICE
        resize();
    }
    size++;
    Node<T>* temp = new Node<T>;
    temp->priority = prio;
    temp->elem = t;
    array[size] = *temp;
    siftUp(size); // PRZYWRACA SPÓJNOŚĆ DRZEWA
}

template<typename T>
T PQheap<T>::pop() {
    if (size < 0) {
        throw std::out_of_range("PQheap is empty");
    }

    Node<T> temp = array[0];
    array[0] = array[size];
    array[size] = temp;
    size--;

    siftDown(0); // PRZYWRACA SPÓJNOŚĆ DRZEWA
    return temp.elem;
}

// DODATKOWA FUNCKJA TYLKO NA POTRZEBY TEGO ZADANIA
template<typename T>
T PQheap<T>::popWithPrio() {
    if (size < 0) {
        throw std::out_of_range("PQheap is empty");
    }

    Node<T> temp = array[0];
    array[0] = array[size];
    array[size] = temp;
    size--;

    siftDown(0);
    return temp.priority;
}

template<typename T>
void PQheap<T>::printQueue() {
    if (size == -1) {
        std::cout << "Empty heap" << std::endl;
        return;
    }

    for(int i=0 ; i<=size ; i++){
        std::cout << array[i].elem << "->" << array[i].priority << std::endl;
    }
}

template<typename T>
void PQheap<T>::modifyKey(const int prio, const T& t) {
    int index = -1;
    for (int i = 0; i <= size; ++i) {
        if (array[i].elem == t) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        return;
    }
    array[index].priority = prio;

    int parentIndex = (index - 1) / 2;
    if (index > 0 && array[index].priority < array[parentIndex].priority) {
        siftUp(index);
    } else {
        siftDown(index);
    }
}

template<typename T>
void PQheap<T>::siftUp(int i) {
    int parentIndex = (i-1)/2 ;

    while (i != 0 && array[i].priority > array[parentIndex].priority){
        std::swap(array[i],array[parentIndex]);

        i = parentIndex;
        parentIndex = (i-1) / 2;
    }
}

template<typename T>
void PQheap<T>::siftDown(int i) {
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    while ((leftChild <= size && array[i].priority < array[leftChild].priority) ||
           (rightChild <= size && array[i].priority < array[rightChild].priority)) {

        int largest = i;
        if (leftChild <= size && array[leftChild].priority > array[largest].priority) {
            largest = leftChild;
        }
        if (rightChild <= size && array[rightChild].priority > array[largest].priority) {
            largest = rightChild;
        }

        if (largest != i) {
            std::swap(array[i], array[largest]);
            i = largest;
            leftChild = 2 * i + 1;
            rightChild = 2 * i + 2;
        } else {
            break;
        }
    }
}

template<typename T>
void PQheap<T>::resize(){
    Node<T>* arrayTemp = new Node<T>[maxSize*2];
    maxSize = maxSize *2;

    for(int i=0; i<size+1; i++){
        arrayTemp[i] = array[i];
    }
    delete[] array;
    array = arrayTemp;
}