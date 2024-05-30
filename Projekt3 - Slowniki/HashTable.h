#ifndef ISA_STRUKTURY_DANYCH_HASHTABLE_H
#define ISA_STRUKTURY_DANYCH_HASHTABLE_H
#include <list>

class HashTable {
public:
    virtual int getSize() = 0;
    virtual void insert(int key,int value) = 0;
    virtual int find(int key) = 0;
    virtual void remove(int key) = 0;
    virtual void print() = 0;
};


#endif //ISA_STRUKTURY_DANYCH_HASHTABLE_H
