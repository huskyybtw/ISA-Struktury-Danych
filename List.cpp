#include "Node.h"
#include "List.h"

#include <ctime>
#include <cstddef>
#include <iostream>
#include <stdexcept>

template class List<int>;


template <typename T>
List<T>::List() : head(NULL) {
    size = 0;
}

template <typename T>
List<T>::~List(){
    while(!empty()){
        removeFront();
    }
};

template <typename T>
bool List<T>::empty() const{
    if (head == NULL){
        return true;
    }
    return false;
}

template <typename T>
const T& List<T>::first() const {
    return head->elem;
}

template <typename T>
const T& List<T>::last() const{
    if(head == NULL){
        throw std::logic_error("List is empty");
    }

    Node<T>* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    return temp->elem;
}

template <typename T>
const T& List<T>::random() const {
    if(head == NULL){
        throw std::logic_error("List is empty");
    }
    Node<T>* temp = head;
    std::srand(std::time(nullptr));
    int random = std::rand() % size; //generates number from 0 to size-1

    for(int i=0; i<random; i++){ // get access to the n element
            temp = temp->next;
    }
    return temp->elem;
}

template <typename T>
void List<T>::addFront(const T& t) {
    Node<T>* node = new Node<T>;
    node->elem = t;
    node->next = head;
    head = node;

    size++;
}

template<typename T>
void List<T>::removeFront() {
    Node<T>* temp = head;
    head = temp->next;
    delete temp;

    size--;
}

template<typename T>
void List<T>::addEnd(const T& t) {
    if(head == NULL){
        Node<T>* node = new Node<T>;
        node->elem = t;
        node->next = NULL;
        head = node;
        size++;
        return;
    }

    Node<T>* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    Node<T>* node = new Node<T>;
    node->elem = t;
    node->next = NULL;

    temp->next = node;
    size++;
}

template<typename T>
void List<T>::removeEnd(){
    if(head == NULL){
        return;
    }

    if(head->next == NULL){
        delete head;
        head = NULL;
        size--;
        return;
    }

    Node<T>* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
    size--;
}

template<typename T>
void List<T>::addRandom(const T &t) {

    if(head == NULL){
        Node<T>* node = new Node<T>;
        node->elem = t;
        node->next = NULL;
        head = node;
        size++;
        return;
    }

    Node<T>* temp = head;
    std::srand(std::time(nullptr));
    int random = std::rand() % size; //generates number from 0 to size-1

    if(random == size-1){ // if adding at the end
        this->addEnd(t);
        return;
    }

    for(int i=0; i<random; i++){ // move pointer to the random position
        temp = temp->next;
    }

    Node<T>* node = new Node<T>;
    node->elem = t;
    node->next = temp->next;

    temp->next = node;
    size++;
}

template<typename T>
void List<T>::removeRandom() {
    if(head == NULL){
        return;
    }

    Node<T>* temp = head;
    std::srand(std::time(nullptr));
    int random = std::rand() % size-1;

    if(random == 0){ // if removes first element
        this->removeFront();
    }

    for(int i=0; i<random; i++){
        temp = temp->next;
    }

    Node<T>* temp_next = temp->next; // for pointer with node for deletion

    if (random == size-2){ // if removes last element
        temp->next = NULL;
        delete temp_next;
        size--;
    }

    temp->next = temp->next->next;
    delete temp_next;
    size--;
}

template<typename T>
void List<T>::printList() {
    if(head == NULL){
        return;
    }

    Node<T>* temp = head;
    while(temp->next != NULL){
        std::cout<< temp->elem << std::endl;
        temp = temp->next;
    }
    std::cout<< temp->elem << std::endl;
}

template<typename T>
void List<T>::printRandom() {
    if(head == NULL){
        return;
    }

    Node<T>* temp = head;
    std::srand(std::time(nullptr));
    int random = std::rand() % size;

    for(int i=0; i<=random; i++){
        temp = temp->next;
    }

    std::cout<< temp->elem << std::endl;
}
template <typename T>
int List<T>::getSize() {
    return size;
}

