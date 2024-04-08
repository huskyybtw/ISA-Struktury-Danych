#ifndef ISA_STRUKTURY_DANYCH_DNODE_H
#define ISA_STRUKTURY_DANYCH_DNODE_H

// KLASA NA WEZLY
template <typename T>
class DNode {
public:
    T elem;
    DNode<T>* next;
    DNode<T>* prev;
};

#endif //ISA_STRUKTURY_DANYCH_DNODE_H
