#ifndef ISA_STRUKTURY_DANYCH_SNODE_H
#define ISA_STRUKTURY_DANYCH_SNODE_H


// KLASA NA WEZLY
template <typename T>
struct SNode {
public:
    T elem;
    SNode<T>* next;
};


#endif //ISA_STRUKTURY_DANYCH_SNODE_H
