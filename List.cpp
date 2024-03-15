#include "Node.h"
#include "List.h"

#include <cstddef>
#include <iostream>
#include <stdexcept>

template class List<int>;


template <typename T>
List<T>::List() : head(NULL) {}

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
void List<T>::addFront(const T& t) {
    Node<T>* node = new Node<T>;
    node->elem = t;
    node->next = head;
    head = node;
}

template<typename T>
void List<T>::removeFront() {
    Node<T>* temp = head;
    head = temp->next;
    delete temp;
}

template<typename T>
void List<T>::addEnd(const T& t) {
    if(head == NULL){
        Node<T>* node = new Node<T>;
        node->elem = t;
        node->next = NULL;
        head = node;
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
}

template<typename T>
void List<T>::removeEnd(){
    if(head == NULL){
        return;
    }

    if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }

    Node<T>* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
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

