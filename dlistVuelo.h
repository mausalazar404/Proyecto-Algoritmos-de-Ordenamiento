#ifndef DLISTVUELO_H
#define DLISTVUELO_H

#include "Vuelo.h"
#include <iostream>
using namespace std;

class DLinkVuelo {
public:
    Vuelo vuelo;
    DLinkVuelo* next;
    DLinkVuelo* prev;

    DLinkVuelo(Vuelo v);
};

class DListVuelo {
public:
    DListVuelo();

    void addFirst(Vuelo v);
    void add(Vuelo v);
    Vuelo getFirst();
    Vuelo removeFirst();
    Vuelo getLast() ;
    Vuelo removeLast();
    int length();
    bool empty();
    void clear();
    void mostrar();
    DLinkVuelo* getHead(){ 
        return head;
    }
    DLinkVuelo* getTail(){ 
        return tail;
    }

private:
    DLinkVuelo* head;
    DLinkVuelo* tail;
    int size;
};

#endif
