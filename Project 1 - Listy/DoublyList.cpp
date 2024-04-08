#include "DoublyList.h"

#include <ctime>
#include <cstddef>
#include <iostream>
#include <stdexcept>



template class DoublyList<int>; // BLAD Z TEMPLATE'AMI KTOREGO NIE UMIEM NAPRAWIC LISTA DZIALA TYLKO NA INT'ACH

// USTAWIA WSKAZNIK I WIELKOSC STRUKTURY
template <typename T>
DoublyList<T>::DoublyList() {
    head = NULL;
    tail = NULL;
    size = 0;
}

// USUWA POKOLEI WSZYSTKIE ELEMENTY Z PRZODU
template <typename T>
DoublyList<T>::~DoublyList(){
    while(!empty()){
        removeFront();
    }
};

// SPRAWDZA CZY HEAD NA COS WSKAZUJE
// ZWRACA FALSZ JEZELI LISTA MA JAKIES ELEMENTY
template <typename T>
bool DoublyList<T>::empty() const{
    if (head == NULL){
        return true;
    }
    return false;
}

// ZWRACA WARTOSC W PIERWSZEGO WEZLA
template <typename T>
const T& DoublyList<T>::first() const {
    return head->elem;
}

// ZWRACA WARTOSC OSTATNIEGO WEZLA
template <typename T>
const T& DoublyList<T>::last() const{
    if(head == NULL){
        throw std::logic_error("TailList is empty");
    }

    return tail->elem;
}

// ZWRACA LOSOWY ELEMENT Z PRZEDZIALU OD 0 DO SIZE
template <typename T>
const T& DoublyList<T>::random() const {
    if(head == NULL){
        throw std::logic_error("TailList is empty");
    }

    DNode<T>* temp = head;
    std::srand(std::time(nullptr));
    int random = std::rand() % size; // GENERUJE LICZBE Z PRZEDZIALU OD 0 DO SIZE-1

    int distanceFromEnd = size - random;
    // SPRAWDZA W KTOREJ KTOREJ CZESCI LISTY ZNAJDUJE SIE WYGENEROWANA LICZBA
    if(distanceFromEnd >=  random) {
        for (int i = 1; i < random ; i++) { // USTAWIA WSKAZNIK NA LOSOWA POZYCJE
            temp = temp->next;
        }
    }
    else{
        temp = tail;
        for(int i = 0; i < distanceFromEnd ;i++){ // COFA WSKAZNIK NA LOSOWA POZYCJE
            temp = temp->prev;
        }
    }

    return temp->elem;
}

// DODAJE ELEMENT NA POCZATKU LISTY
template <typename T>
void DoublyList<T>::addFront(const T& t) {
    if (head == NULL){ // JESLI LISTA NIE MA ELEMENTOW
        DNode<T>* node = new DNode<T>;
        node->elem = t;
        node->next = NULL;
        node->prev = NULL;
        tail = node;
        head = node;
        size++;
        return;
    }

    // JESLI LISTA MA ELEMENTY
    DNode<T>* node = new DNode<T>;
    node->elem = t;
    node->next = head;
    node->prev = NULL;

    head->prev = node; //  BYL BLAD NIE MOZNA NULL->prev;
    head = node;

    size++;
}

// USUWA ELEMENT Z POCZATKU LISTY
template<typename T>
void DoublyList<T>::removeFront() {
    if(head == NULL){ // JESLI LISTA JEST PUSTA
        return;
    }
    DNode<T>* temp = head;
    if(temp->next != NULL) { // JESLI JEST WIECEJ NIZ JEDEN ELEMENT
        head = temp->next;
        head->prev = NULL;
    }
    else{
        head = NULL;
        tail = NULL;
    }
    delete temp;
    size--;
}

// DODAJE ELEMENT NA KONCU LISTY
template<typename T>
void DoublyList<T>::addEnd(const T& t) {
    if(head == NULL){ // JESLI LISTA NIE MA ELEMENTOW
        DNode<T>* node = new DNode<T>;
        node->elem = t;
        node->next = NULL;
        node->prev = NULL;
        tail = node;
        head = node;
        size++;
        return;
    }

    DNode<T>* node = new DNode<T>;
    node->elem = t;
    node->next = NULL;
    node->prev = tail;

    tail->next = node;
    tail = node; // ZMIENIA OSTATNI ELEMENT LISTY NA NOWY WEZEL

    size++;
}

// DODAJE ELEMENT PO LOSOWYM ELEMENCIE
template<typename T>
void DoublyList<T>::addRandom(const T &t) {

    if(head == NULL){ // JESLI LISTA JEST PUSTA
        this->addFront(t);
        return;
    }

    DNode<T>* temp = head;
    std::srand(std::time(nullptr));
    int random = std::rand() % (size+1); // GENERUJE LICZBE OD O DO SIZE

    if(random == 0){
        this->addFront(t);
        return;
    }

    if(random == size){ // JESLI DODAJE NA OSTATNIM ELEMENCIE
        this->addEnd(t);
        return;
    }

    int distanceFromEnd = size - random;
    // SPRAWDZA W KTOREJ KTOREJ CZESCI LISTY ZNAJDUJE SIE WYGENEROWANA LICZBA
    if(distanceFromEnd >=  random) {
        for (int i = 1; i < random ; i++) { // USTAWIA WSKAZNIK NA LOSOWA POZYCJE
            temp = temp->next;
        }
    }
    else{
        temp = tail;
        for(int i = 0; i < distanceFromEnd ;i++){ // COFA WSKAZNIK NA LOSOWA POZYCJE
            temp = temp->prev;
        }
    }

    DNode<T>* node = new DNode<T>;
    node->elem = t;
    node->next = temp->next;
    node->prev = temp;

    // WSTAWIA NOWY WEZEL POMIEDZY DWA WEZLY
    temp->next->prev = node;
    temp->next = node;
    size++;
}

// USUWA OSTATNI ELEMENT
template<typename T>
void DoublyList<T>::removeEnd(){
    if(head == NULL){ // JESLI LISTA JEST PUSTA
        return;
    }

    if(head->next == NULL){ // JESLI W LISCIE JEST TYLKO JEDEN ELEMENT
        delete head;
        head = NULL;
        tail = NULL;
        size--;
        return;
    }

    DNode<T>* temp = tail->prev; // USTAWIA WSKAZNIK NA PRZED-OSTATNI ELEMENT

    delete temp->next; // USUWA OSTATNI ELEMENT
    temp->next = NULL; // PRZEDOSTATNI ELEMENT STAJE SIE OSTATNIM
    tail = temp; // USTAWIA KONIEC LISTY NA OSTATNI ELEMENT
    size--;
}

// USUWA LOSOWY WEZEL
template<typename T>
void DoublyList<T>::removeRandom() {
    if(head == NULL){ // JESLI LISTA JEST PUSTA
        return;
    }

    if(head->next == NULL){ // JESLI SA TYLKO DWA ELEMENTY SIZE=1
        this->removeFront();
        return;
    }

    if(head->next->next == NULL){ // JESLI SA TYLKO DWA ELEMENTY SIZE=2
        this->removeEnd();
        return;
    }

    DNode<T>* temp = head;
    std::srand(std::time(nullptr));
    int random = std::rand() % (size+1); // GENERUJE LICZBE OD O DO SIZE

    if(random == 0){
        this->removeFront();
        return;
    }

    if(random == size){ // JESLI DODAJE NA OSTATNIM ELEMENCIE
        this->removeEnd();
        return;
    }

    int distanceFromEnd = size - random;
    // SPRAWDZA W KTOREJ KTOREJ CZESCI LISTY ZNAJDUJE SIE WYGENEROWANA LICZBA
    if(distanceFromEnd >=  random) {
        for (int i = 0; i < random ; i++) { // USTAWIA WSKAZNIK NA LOSOWA POZYCJE
            temp = temp->next;
        }
    }
    else{
        temp = tail;
        for(int i = 0; i < distanceFromEnd ;i++){ // COFA WSKAZNIK NA LOSOWA POZYCJE
            temp = temp->prev;
        }
    }

    temp->prev->next = temp->next; // PRZESTAWIA WSKAZNIK NA WEZEL ZA USUWANYM WEZLEM
    temp->next->prev = temp->prev;
    delete temp; // USUWA WEZEL
    size--;
}

// WYPISUJE WYSZYSTKIE WARTOSCI ELEMENT
template<typename T>
void DoublyList<T>::printList() {
    if(head == NULL){ // JESLI LISTA JEST PUSTA
        std::cout << "TailList is empty" << std::endl;
        return;
    }

    DNode<T>* temp = head;
    while(temp->next != NULL){ // PRZESTAWIA WSKAZNIK DOPUKI NIE ZNAJDZIE OSTATNIEGO ELEMENTU
        std::cout<< temp->elem << std::endl; // WYPISUJE ELEMENTY
        temp = temp->next;
    }
    std::cout<< temp->elem << std::endl; // WYPISUJE OSTATNI ELEMENT
}

// WYPISUJE LOSOWY ELEMENT
template<typename T>
void DoublyList<T>::printRandom() {
    if(head == NULL){
        return;
    }

    DNode<T>* temp = head;
    std::srand(std::time(nullptr));
    int random = std::rand() % size; // GENERUJE LOSOWA LICZBE Z PRZEDZIALO OD 0 DO SIZE-1

    // SPRAWDZA W KTOREJ CZESCI LISTY ZNAJDUJE SIE ELEMENT
    if(random <= size/2){
        for(int i=0; i<random; i++){ // PRZESTAWIAMY WSKAZNIK TAK BY POKAZYWAL NA PRZEDOSTATNI ELEMENT
            temp = temp->next;
        }
    }
    else{
        temp = tail;
        for(int i = size-1; i>random;i--){ // COFA WSKAZNIK NA LOSOWA POZYCJE
            temp = temp->prev;
        }
    }

    std::cout<< temp->elem << std::endl;
}

// ZWRACA WIELKOSCI LISTY
template <typename T>
int DoublyList<T>::getSize() {
    return size;
}

