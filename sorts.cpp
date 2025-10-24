#include "sorts.h"
#include <utility> 

void bubbleSortPrecio(DListVuelo &lista) {
    if (lista.empty()) return;

    bool swapped;
    do {
        swapped = false;
        DLinkVuelo* actual = lista.getHead();  
        while (actual->next) {
            if (actual->vuelo.getPrecio() > actual->next->vuelo.getPrecio()) {
                swap(actual->vuelo, actual->next->vuelo);
                swapped = true;
            }
            actual = actual->next;
        }
    } while (swapped);
}

void bubbleSortDestino(DListVuelo &lista) {
    if (lista.empty()) return;

    bool swapped;
    do {
        swapped = false;
        DLinkVuelo* actual = lista.getHead();  
        while (actual->next) {
            if (actual->vuelo.getDestino() > actual->next->vuelo.getDestino()) {
                swap(actual->vuelo, actual->next->vuelo);
                swapped = true;
            }
            actual = actual->next;
        }
    } while (swapped);
}
