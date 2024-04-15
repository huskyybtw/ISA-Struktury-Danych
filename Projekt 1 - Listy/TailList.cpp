#include "TailList.h"

#include <ctime>
#include <cstddef>
#include <iostream>
#include <stdexcept>



template class TailList<int>; // BLAD Z TEMPLATE'AMI KTOREGO NIE UMIEM NAPRAWIC LISTA DZIALA TYLKO NA INT'ACH

// USTAWIA WSKAZNIK I WIELKOSC STRUKTURY
template <typename T>
TailList<T>::TailList() : head(NULL), tail(NULL) {
    size = 0;
}

// USUWA POKOLEI WSZYSTKIE ELEMENTY Z PRZODU
template <typename T>
TailList<T>::~TailList(){
    while(!empty()){
        removeFront();
    }
};
// SPRAWDZA CZY HEAD NA COS WSKAZUJE
// ZWRACA FALSZ JEZELI LISTA MA JAKIES ELEMENTY
template <typename T>
bool TailList<T>::empty() const{
    if (head == NULL){
        return true;
    }
    return false;
}

// ZWRACA WARTOSC W PIERWSZEGO WEZLA
template <typename T>
const T& TailList<T>::first() const {
    return head->elem;
}

// ZWRACA WARTOSC OSTATNIEGO WEZLA
template <typename T>
const T& TailList<T>::last() const{
    if(head == NULL){
        throw std::logic_error("TailList is empty");
    }

    return tail->elem;
}

// ZWRACA LOSOWY ELEMENT Z PRZEDZIALU OD 0 DO SIZE
template <typename T>
const T& TailList<T>::random() const {
    if(head == NULL){
        throw std::logic_error("TailList is empty");
    }

    SNode<T>* temp = head;
    std::srand(std::time(nullptr));
    int random = std::rand() % size; // GENERUJE LICZBE Z PRZEDZIALU OD 0 DO SIZE-1

    for(int i=0; i<random; i++){ // PRZESTAWIA WSKAZNIK NA WYGENEROWANY ELEMENT
        temp = temp->next;
    }
    return temp->elem;
}

// DODAJE ELEMENT NA POCZATKU LISTY
template <typename T>
void TailList<T>::addFront(const T& t) {
    if (head == NULL){
        SNode<T>* node = new SNode<T>;
        node->elem = t;
        node->next = head;
        head = node;
        tail = node;
        size++;
        return;
    }

    SNode<T>* node = new SNode<T>;
    node->elem = t;
    node->next = head;
    head = node;

    size++;
}

// USUWA ELEMENT Z POCZATKU LISTY
template<typename T>
void TailList<T>::removeFront() {
    if(head == NULL){ // JESLI LISTA JEST PUSTA
        return;
    }
    SNode<T>* temp = head;
    if(temp->next != NULL) {
        head = temp->next;
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
void TailList<T>::addEnd(const T& t) {
    if(head == NULL){ // JESLI LISTA NIE MA ELEMENTOW
        SNode<T>* node = new SNode<T>;
        node->elem = t;
        node->next = NULL;
        head = node;
        tail = node;
        size++;
        return;
    }
    SNode<T>* temp = tail;
    SNode<T>* node = new SNode<T>;
    node->elem = t;
    node->next = NULL;

    temp->next = node;
    tail = node;
    size++;
}

// USUWA OSTATNI ELEMENT
template<typename T>
void TailList<T>::removeEnd(){
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
    SNode<T>* temp = head;
        while(temp->next != tail){ // PRZESTAWIA WSKAZNIK DOPOKI NIE ZNAJDZIE PRZEDOSTATNIEGO ELEMENTU
         temp = temp->next;
        }

    delete tail;  // USUWA OSTATNI ELEMENT
    tail = temp;  // PRZEDOSTATNI ELEMENT STAJE SIE OSTATNIM
    tail->next = NULL; // AKTUALIZACJA WSKAZNIKA NEXT OSTATNIEGO ELEMENTU
    size--;
}

// DODAJE ELEMENT PO LOSOWYM ELEMENCIE
template<typename T>
void TailList<T>::addRandom(const T &t,int random) {

    if(head == NULL){ // JESLI LISTA JEST PUSTA
        this->addFront(t);
        return;
    }

    if(random >= size){
        return;
    }

    SNode<T>* temp = head;

    if(random == size-1){ // JESLI DODAJE NA OSTATNIM ELEMENCIE
        this->addEnd(t);
        return;
    }

    for(int i=0; i<random; i++){ // USTAWIA WSKAZNIK NA LOSOWA POZYCJE
        temp = temp->next;
    }

    SNode<T>* node = new SNode<T>;
    node->elem = t;
    node->next = temp->next;

    temp->next = node;

    if (temp == tail) // JESLI DODAJEMY NA PRZEDOSTATNIM ELEMENCIE
        tail = node;
    size++;
}

// USUWA WEZEL PO LOSOWYM ELEMENCIE
template<typename T>
void TailList<T>::removeRandom(int random) {
    if(head == NULL){ // JESLI LISTA JEST PUSTA
        return;
    }

    if(random >= size){
        return;
    }

    SNode<T>* temp = head;

    if(random == 0){ // JESLI WYLOSOWANO PIERWSZY ELEMENT
        this->removeFront();
        return;
    }

    if (random == size - 1){    //JESLI WYLOSOWANO OSTATNI ELEMENT
        this->removeEnd();
        return;
    }

    for(int i=0; i<random-1; i++){ // PRZESTAWIAMY WSKAZNIK TAK BY POKAZYWAL NA PRZEDOSTATNI ELEMENT LOSOWY
        temp = temp->next;
    }

    SNode<T>* temp_next = temp->next; // PRZECHOWUJE WSKAZNIK NA NASTEPNY WEZEL

    temp->next = temp->next->next; // PRZESTAWIA WSKAZNIK NA WEZEL ZA USUWANYM WEZLEM
    delete temp_next; // USUWA WEZEL
    size--;

    if (temp->next == NULL) // JESLI USUWANY BYL OSTATNI ELEMENT AKTUALIZUJE TAIL
        tail = temp;
}

// WYPISUJE WYSZYSTKIE WARTOSCI ELEMENT
template<typename T>
void TailList<T>::printList() {
    if(head == NULL){ // JESLI LISTA JEST PUSTA
        return;
    }

    SNode<T>* temp = head;
    while(temp->next != NULL){ // PRZESTAWIA WSKAZNIK DOPOKI NIE ZNAJDZIE OSTATNIEGO ELEMENTU
        std::cout<< temp->elem << std::endl; // WYPISUJE ELEMENTY
        temp = temp->next;
    }
    std::cout<< temp->elem << std::endl; // WYPISUJE OSTATNI ELEMENT
}

// WYPISUJE LOSOWY ELEMENT
template<typename T>
void TailList<T>::printRandom() {
    if(head == NULL){
        return;
    }

    SNode<T>* temp = head;
    std::srand(std::time(nullptr));
    int random = std::rand() % size; // GENERUJE LOSOWA LICZBE Z PRZEDZIALO OD 0 DO SIZE-1

    for(int i=0; i<random; i++){ // PRZESTAWIA WSKAZNIK NA LOSOWY ELEMENT
        temp = temp->next;
    }

    std::cout<< temp->elem << std::endl;
}

// ZWRACA WIELKOSCI LISTY
template <typename T>
int TailList<T>::getSize() {
    return size;
}

