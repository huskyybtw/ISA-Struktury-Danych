#include "List.h"

#include <ctime>
#include <cstddef>
#include <iostream>
#include <stdexcept>



template class List<int>; // BLAD Z TEMPLATE'AMI KTOREGO NIE UMIEM NAPRAWIC LISTA DZIALA TYLKO NA INT'ACH

// USTAWIA WSKAZNIK I WIELKOSC STRUKTURY
template <typename T>
List<T>::List() : head(NULL) {
    size = 0;
}

// USUWA POKOLEI WSZYSTKIE ELEMENTY Z PRZODU
template <typename T>
List<T>::~List(){
    while(!empty()){
        removeFront();
    }
};
// SPRAWDZA CZY HEAD NA COS WSKAZUJE
// ZWRACA FALSZ JEZELI LISTA MA JAKIES ELEMENTY
template <typename T>
bool List<T>::empty() const{
    if (head == NULL){
        return true;
    }
    return false;
}

// ZWRACA WARTOSC W PIERWSZEGO WEZLA
template <typename T>
const T& List<T>::first() const {
    return head->elem;
}

// ZWRACA WARTOSC OSTATNIEGO WEZLA
template <typename T>
const T& List<T>::last() const{
    if(head == NULL){
        throw std::logic_error("List is empty");
    }

    SNode<T>* temp = head;
    while(temp->next != NULL){ // PRZESTAWIA WSKAZNIK NA OSTATNI ELEMENT
        temp = temp->next;
    }

    return temp->elem;
}

// ZWRACA LOSOWY ELEMENT Z PRZEDZIALU OD 0 DO SIZE
template <typename T>
const T& List<T>::random() const {
    if(head == NULL){
        throw std::logic_error("List is empty");
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
void List<T>::addFront(const T& t) {
    SNode<T>* node = new SNode<T>;
    node->elem = t;
    node->next = head;
    head = node;

    size++;
}

// USUWA ELEMENT Z POCZATKU LISTY
template<typename T>
void List<T>::removeFront() {
    SNode<T>* temp = head;
    head = temp->next;
    delete temp;

    size--;
}

// DODAJE ELEMENT NA KONCU LISTY
template<typename T>
void List<T>::addEnd(const T& t) {
    if(head == NULL){ // JESLI LISTA NIE MA ELEMENTOW
        SNode<T>* node = new SNode<T>;
        node->elem = t;
        node->next = NULL;
        head = node;
        size++;
        return;
    }

    SNode<T>* temp = head;
    while(temp->next != NULL){ // PRZESTAWIA WSKAZNIK DOPUKI NIE ZNAJDZIE OSTATNIEGO ELEMENTU
        temp = temp->next;
    }

    SNode<T>* node = new SNode<T>;
    node->elem = t;
    node->next = NULL;

    temp->next = node;
    size++;
}

// USUWA OSTATNI ELEMENT
template<typename T>
void List<T>::removeEnd(){
    if(head == NULL){ // JESLI LISTA JEST PUSTA
        return;
    }

    if(head->next == NULL){ // JESLI W LISCIE JEST TYLKO JEDEN ELEMENT
        delete head;
        head = NULL;
        size--;
        return;
    }

    SNode<T>* temp = head;
    while(temp->next->next != NULL){ // PRZESTAWIA WSKAZNIK DOPUKI NIE ZNAJDZIE PRZED-OSTATNIEGO ELEMENTU
        temp = temp->next;
    }

    delete temp->next; // USUWA OSTATNI ELEMENT
    temp->next = NULL; // PRZEDOSTATNI ELEMENT STAJE SIE OSTATNIM
    size--;
}

// DODAJE ELEMENT PO LOSOWYM ELEMENCIE
template<typename T>
void List<T>::addRandom(const T &t) {

    if(head == NULL){ // JESLI LISTA JEST PUSTA
        this->addFront(t);
        return;
    }

    SNode<T>* temp = head;
    std::srand(std::time(nullptr));
    int random = std::rand() % size; // GENERUJE LICZBE OD O DO SIZE-1

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
    size++;
}

// USUWA WEZEL PO LOSOWYM ELEMENCIE
template<typename T>
void List<T>::removeRandom() {
    if(head == NULL){ // JESLI LISTA JEST PUSTA
        return;
    }

    SNode<T>* temp = head;
    std::srand(std::time(nullptr));
    int random = std::rand() % size-1; // GENERUJE LICZBE OD O DO SIZE-2
                                        // PONIEWAZ MOZEMY PRZESUNAC WSKAZNIK O JEDEN RAZ MNIEJ

    if(random == 0){ // JESLI WYLOSOWANO PIERWSZY ELEMENT
        this->removeFront();
    }

    for(int i=0; i<random; i++){ // PRZESTAWIAMY WSKAZNIK TAK BY POKAZYWAL NA PRZEDOSTATNI ELEMENT
        temp = temp->next;
    }

    SNode<T>* temp_next = temp->next; // PRZECHOWUJE WSKAZNIK NA NASTEPNY WEZEL

    if (random == size-2){ // JEZELI WYLOSOWALO USUNIECIE OSTATNIEGO WEZLA
        temp->next = NULL;
        delete temp_next;
        size--;
    }

    temp->next = temp->next->next; // PRZESTAWIA WSKAZNIK NA WEZEL ZA USUWANYM WEZLEM
    delete temp_next; // USUWA WEZEL
    size--;
}

// WYPISUJE WYSZYSTKIE WARTOSCI ELEMENT
template<typename T>
void List<T>::printList() {
    if(head == NULL){ // JESLI LISTA JEST PUSTA
        return;
    }

    SNode<T>* temp = head;
    while(temp->next != NULL){ // PRZESTAWIA WSKAZNIK DOPUKI NIE ZNAJDZIE OSTATNIEGO ELEMENTU
        std::cout<< temp->elem << std::endl; // WYPISUJE ELEMENTY
        temp = temp->next;
    }
    std::cout<< temp->elem << std::endl; // WYPISUJE OSTATNI ELEMENT
}

// WYPISUJE LOSOWY ELEMENT
template<typename T>
void List<T>::printRandom() {
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
int List<T>::getSize() {
    return size;
}

