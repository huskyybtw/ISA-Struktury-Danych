#ifndef ISA_STRUKTURY_DANYCH_LIST_H
#define ISA_STRUKTURY_DANYCH_LIST_H

#include "Node.h"

template <typename T>
class List {
public:

    List();
    ~List();

    bool empty() const;
    const T& first() const;
    const T& last() const;

    void addFront (const T& t);
    void removeFront ();
    void addEnd(const T& t);
    void removeEnd();

    void printList();

private:
    Node<T>* head;
};


#endif //ISA_STRUKTURY_DANYCH_LIST_H
