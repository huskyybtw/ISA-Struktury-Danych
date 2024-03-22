#ifndef ISA_STRUKTURY_DANYCH_SNODE_H
#define ISA_STRUKTURY_DANYCH_SNODE_H

#include "List.h"

// KLASA NA WEZLY
template <typename T>
class SNode {
private:
    T elem;
    SNode<T>* next;

    friend List<T>;
};


#endif //ISA_STRUKTURY_DANYCH_SNODE_H
