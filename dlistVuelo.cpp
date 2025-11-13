#include "dlistVuelo.h"
#include <stdexcept>


DLinkVuelo::DLinkVuelo(Vuelo v) : vuelo(v), next(nullptr), prev(nullptr) {}
DListVuelo::DListVuelo() : head(nullptr), tail(nullptr), size(0) {}


void DListVuelo::addFirst(Vuelo v) {
    DLinkVuelo* nuevo = new DLinkVuelo(v);
    if (!head) {
        head = tail = nuevo;
    } else {
        nuevo->next = head;
        head->prev = nuevo;
        head = nuevo;
    }
    size++;
}


void DListVuelo::add(Vuelo v) {
    if (!head) {
        addFirst(v);
        return;
    }
    DLinkVuelo* nuevo = new DLinkVuelo(v);
    tail->next = nuevo;
    nuevo->prev = tail;
    tail = nuevo;
    size++;
}


Vuelo DListVuelo::getFirst(){
    if (empty()) throw runtime_error("Lista vacía");
    return head->vuelo;
}


Vuelo DListVuelo::removeFirst() {
    if (empty()) throw runtime_error("Lista vacía");
    DLinkVuelo* victima = head;
    Vuelo val = victima->vuelo;
    if (size == 1) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete victima;
    size--;
    return val;
}


Vuelo DListVuelo::getLast(){
    if (empty()) throw runtime_error("Lista vacía");
    return tail->vuelo;
}


Vuelo DListVuelo::removeLast() {
    if (empty()) throw runtime_error("Lista vacía");
    DLinkVuelo* victima = tail;
    Vuelo val = victima->vuelo;
    if (size == 1) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete victima;
    size--;
    return val;
}


int DListVuelo::length(){
    return size;
}


bool DListVuelo::empty(){
    return size == 0;
}


void DListVuelo::clear() {
    while (!empty()) removeFirst();
}


void DListVuelo::mostrar(){
    DLinkVuelo* actual = head;
    while (actual) {
        actual->vuelo.mostrar();
        actual = actual->next;
    }
    cout << "----------------------" << endl;
}

void DListVuelo::updateTail() {
    if (!head) {
        tail = nullptr;
        size = 0;
        return;
    }
    
    DLinkVuelo* current = head;
    DLinkVuelo* previous = nullptr;
    int count = 0;

    while (current != nullptr) {
        current->prev = previous; 
        previous = current;
        tail = current; 
        current = current->next;
        count++;
    }
    size = count; 
}
