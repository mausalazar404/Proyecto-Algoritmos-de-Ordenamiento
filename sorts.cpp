#include "sorts.h"

void bubbleSortPrecio(vector<Vuelo> &vuelos) {
    int n = vuelos.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (vuelos[j].getPrecio() > vuelos[j+1].getPrecio()) {
                swap(vuelos[j], vuelos[j+1]);
            }
        }
    }
}

void bubbleSortDestino(vector<Vuelo> &vuelos) {
    int n = vuelos.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (vuelos[j].getDestino() > vuelos[j+1].getDestino()) {
                swap(vuelos[j], vuelos[j+1]);
            }
        }
    }
}
