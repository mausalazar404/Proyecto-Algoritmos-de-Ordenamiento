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

    // Complejidad: O(1) 
    DLinkVuelo(Vuelo v);
};

class DListVuelo {
public:
    // Complejidad: O(1) 
    DListVuelo();


    // Complejidad: O(1)
    void addFirst(Vuelo v);
    
    // Complejidad: O(1) 
    void add(Vuelo v);
    
    // Complejidad: O(1) 
    Vuelo getFirst();
    
    // Complejidad: O(1)
    Vuelo removeFirst();
    
    // Complejidad: O(1) 
    Vuelo getLast() ;
    
    // Complejidad: O(1) 
    Vuelo removeLast();
    
    // Complejidad: O(1) 
    int length();
    
    // Complejidad: O(1) 
    bool empty();
    
    // Complejidad: O(n) 
    void clear();
    
    // Complejidad: O(n) 
    void mostrar();
    
    // Complejidad: O(1)
    DLinkVuelo* getHead(){ 
        return head;
    }
    
    // Complejidad: O(1) - Asignación a 'head'.
    void setHead(DLinkVuelo* newHead) { 
        head = newHead; 
    }
    
    // Complejidad: O(n) 
    void updateTail();

private:
    DLinkVuelo* head;
    DLinkVuelo* tail;
    int size;
};

#endif
