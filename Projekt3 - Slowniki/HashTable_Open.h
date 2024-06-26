
#ifndef ISA_STRUKTURY_DANYCH_HASHTABLE_OPEN_H
#define ISA_STRUKTURY_DANYCH_HASHTABLE_OPEN_H
#include "HashTable.h"

class HashTable_Open : public HashTable {
private:
    struct Entry{
        int key;
        int value;
    };

    Entry* table;
    int size;
    int count;

    int hashCode(int key);
    void resize();


public:
    HashTable_Open();
    ~HashTable_Open();

    int getSize() override;
    void insert(int key,int value) override;
    int find(int key) override;
    void remove(int key) override;
    void print() override;
};


#endif //ISA_STRUKTURY_DANYCH_HASHTABLE_OPEN_H
