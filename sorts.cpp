#include "sorts.h"
#include <iostream>
#include <string>

// Complejidad: O(n)
DLinkVuelo* sortedMergePrecio_simple(DLinkVuelo* a, DLinkVuelo* b);

// Complejidad: O(n)
DLinkVuelo* sortedMergeDestino_simple(DLinkVuelo* a, DLinkVuelo* b);

// Complejidad: O(n)
void splitList(DLinkVuelo* head, DLinkVuelo** frontRef, DLinkVuelo** backRef);

// Complejidad: O(n log n)
DLinkVuelo* mergeSortRecursive(DLinkVuelo* head, bool sortByPrecio);

// Complejidad: O(n log n)
void mergeSortPrecio(DListVuelo& lista) {
    if (lista.empty()) return;

    DLinkVuelo* newHead = mergeSortRecursive(lista.getHead(), true);
    lista.setHead(newHead);
    lista.updateTail(); // O(n)
    std::cout << "\nLista ordenada por Precio." << std::endl;
}

// Complejidad: O(n log n)
void mergeSortDestino(DListVuelo& lista) {
    if (lista.empty()) return;

    DLinkVuelo* newHead = mergeSortRecursive(lista.getHead(), false);
    lista.setHead(newHead);
    lista.updateTail(); // O(n)
    std::cout << "Lista ordenada por Destino." << std::endl;
}

// Complejidad: O(n log n)
DLinkVuelo* mergeSortRecursive(DLinkVuelo* head, bool sortByPrecio) {
    if (!head || !head->next) {
        return head;
    }

    DLinkVuelo *a, *b;
    splitList(head, &a, &b); // O(n)

    a = mergeSortRecursive(a, sortByPrecio); 
    b = mergeSortRecursive(b, sortByPrecio); 

    if (sortByPrecio) {
        return sortedMergePrecio_simple(a, b); // O(n)
    } else {
        return sortedMergeDestino_simple(a, b); // O(n)
    }
}

// Complejidad: O(n)
void splitList(DLinkVuelo* head, DLinkVuelo** frontRef, DLinkVuelo** backRef) {
    DLinkVuelo* fast;
    DLinkVuelo* slow;

    if (head == nullptr || head->next == nullptr) {
        *frontRef = head;
        *backRef = nullptr;
        return;
    }

    slow = head;
    fast = head->next;

    
    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = head;
    *backRef = slow->next; 
    slow->next = nullptr; 
}

// Complejidad: O(n)
DLinkVuelo* sortedMergePrecio_simple(DLinkVuelo* a, DLinkVuelo* b) {
    DLinkVuelo* result = nullptr;

    if (a == nullptr) return b;
    if (b == nullptr) return a;

    if (a->vuelo.getPrecio() <= b->vuelo.getPrecio()) { 
        result = a;
        result->next = sortedMergePrecio_simple(a->next, b);
    } else {
        result = b;
        result->next = sortedMergePrecio_simple(a, b->next);
    }
    

    return result;
}

// Complejidad: O(n)
DLinkVuelo* sortedMergeDestino_simple(DLinkVuelo* a, DLinkVuelo* b) {
    DLinkVuelo* result = nullptr;

    if (a == nullptr) return b;
    if (b == nullptr) return a;

    if (a->vuelo.getDestino() <= b->vuelo.getDestino()) { 
        result = a;
        result->next = sortedMergeDestino_simple(a->next, b);
    } else {
        result = b;
        result->next = sortedMergeDestino_simple(a, b->next);
    }
    
    return result;
}
