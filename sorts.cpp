#include "sorts.h"
#include <iostream>
#include <string>


DLinkVuelo* sortedMergePrecio_simple(DLinkVuelo* a, DLinkVuelo* b);
DLinkVuelo* sortedMergeDestino_simple(DLinkVuelo* a, DLinkVuelo* b);
void splitList(DLinkVuelo* head, DLinkVuelo** frontRef, DLinkVuelo** backRef);
DLinkVuelo* mergeSortRecursive(DLinkVuelo* head, bool sortByPrecio);


void mergeSortPrecio(DListVuelo& lista) {
    if (lista.empty()) return;

    DLinkVuelo* newHead = mergeSortRecursive(lista.getHead(), true);
    lista.setHead(newHead);
    lista.updateTail(); 
    std::cout << "\n✅ Lista ordenada por Precio (O(n log n))." << std::endl;
}

void mergeSortDestino(DListVuelo& lista) {
    if (lista.empty()) return;

    DLinkVuelo* newHead = mergeSortRecursive(lista.getHead(), false);
    lista.setHead(newHead);
    lista.updateTail(); // Reconstruye 'prev', 'tail' y 'size'
    std::cout << "\n✅ Lista ordenada por Destino (O(n log n))." << std::endl;
}


DLinkVuelo* mergeSortRecursive(DLinkVuelo* head, bool sortByPrecio) {
    if (!head || !head->next) {
        return head;
    }

    DLinkVuelo *a, *b;
    splitList(head, &a, &b);

    a = mergeSortRecursive(a, sortByPrecio);
    b = mergeSortRecursive(b, sortByPrecio);

    if (sortByPrecio) {
        return sortedMergePrecio_simple(a, b);
    } else {
        return sortedMergeDestino_simple(a, b);
    }
}


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
