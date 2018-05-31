//
// Created by majaku on 31.05.18.
//

#ifndef HOMEWORKORDER_AISD_HASHTABLE_H
#define HOMEWORKORDER_AISD_HASHTABLE_H
#ifndef LINKEDLIST
#define LINKEDLIST
#include "LinkedList.h"
#endif
template <typename T>
class HashTable {
private:

    //variables
    int size;
    LinkedList<T> * array;

    //private methods
    int hash(int key) {
        return (key * 13)%size;
    }

public:

    HashTable(int size) {
        this->size = size;
        this->array = new LinkedList<T>[size];
    }

    void insert(T * item, int key) {
        array[hash(key)].insert(item, key);
    }
    T * search(int key) {
        return array[hash(key)].search(key);
    }
    void remove(int key) {
        array[hash(key)].remove(key);
    }
    T * pop(int key) {
        array[hash(key)].pop(key);
    }

};

#endif //HOMEWORKORDER_AISD_HASHTABLE_H

