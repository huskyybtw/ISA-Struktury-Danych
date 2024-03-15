#ifndef ISA_STRUKTURY_DANYCH_NODE_H
#define ISA_STRUKTURY_DANYCH_NODE_H

/*
 * Node class storing a object + a pointer to the next element
 */
template <typename T>
class Node {
public:

  //  Node();
    // ~Node();

    T elem;
    Node<T>* next;
};


#endif //ISA_STRUKTURY_DANYCH_NODE_H
