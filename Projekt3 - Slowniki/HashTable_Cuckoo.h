#ifndef ISA_STRUKTURY_DANYCH_HASHTABLE_CUCKOO_H
#define ISA_STRUKTURY_DANYCH_HASHTABLE_CUCKOO_H

#include "HashTable.h"
#include <climits>

class HashTable_Cuckoo : public HashTable {
private:
    struct Entry{
        int key = INT_MIN;
        int value = 0;
    };
    int size;
    int count;

    Entry* arrFirst;
    Entry* arrSecond;

    int hashFirst(int key);
    int hashSecond(int key);
    void resize();

    void assign(int key,int value);
    void replace(int key,int value);
public:
    HashTable_Cuckoo();
    ~HashTable_Cuckoo();

    int getSize() override;
    void insert(int key,int value) override;
    int find(int key) override;
    void remove(int key) override;
    void print() override;
};


#endif //ISA_STRUKTURY_DANYCH_HASHTABLE_CUCKOO_H
