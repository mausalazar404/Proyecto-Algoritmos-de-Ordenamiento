#include "dlistVuelo.h"
#include <stdexcept>

// Complejidad: O(1)
DLinkVuelo::DLinkVuelo(Vuelo v) : vuelo(v), next(nullptr), prev(nullptr) {}

// Complejidad: O(1)
DListVuelo::DListVuelo() : head(nullptr), tail(nullptr), size(0) {}

// Complejidad: O(1)
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

// Complejidad: O(1)
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

// Complejidad: O(1)
Vuelo DListVuelo::getFirst(){
    if (empty()) throw runtime_error("Lista vacía");
    return head->vuelo;
}

// Complejidad: O(1)
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

// Complejidad: O(1)
Vuelo DListVuelo::getLast(){
    if (empty()) throw runtime_error("Lista vacía");
    return tail->vuelo;
}

// Complejidad: O(1)
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

// Complejidad: O(1)
int DListVuelo::length(){
    return size;
}

// Complejidad: O(1)
bool DListVuelo::empty(){
    return size == 0;
}

// Complejidad: O(n)
void DListVuelo::clear() {
    while (!empty()) removeFirst();
}

// Complejidad: O(n)
void DListVuelo::mostrar(){
    DLinkVuelo* actual = head;
    while (actual) {
        actual->vuelo.mostrar();
        actual = actual->next;
    }
    cout << "----------------------" << endl;
}

// Complejidad: O(n)
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
