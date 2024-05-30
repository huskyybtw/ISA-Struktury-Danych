//
// Created by marek on 30.05.2024.
//

#ifndef ISA_STRUKTURY_DANYCH_HASHTABLE_BUCKET_H
#define ISA_STRUKTURY_DANYCH_HASHTABLE_BUCKET_H

#include "HashTable.h"
#include <list>

class HashTable_Bucket : public HashTable{
private:
    struct Entry{
        int key;
        int value;
    };

    std::list<Entry>* array;
    int size;
    int count;

    int hashCode(int key);
    void resize();
public:
    HashTable_Bucket();
    ~HashTable_Bucket();

    int getSize() override;
    void insert(int key,int value) override;
    int find(int key) override;
    void remove(int key) override;
    void print() override;
};


#endif //ISA_STRUKTURY_DANYCH_HASHTABLE_BUCKET_H
