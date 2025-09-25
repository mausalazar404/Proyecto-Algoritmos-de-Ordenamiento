#include <iostream>
#include <vector>
#include "vuelo.h"
#include "sorts.h"

using namespace std;

void mostrarVuelos(vector<Vuelo> &vuelos) {
    for (auto &v : vuelos) {
        v.mostrar();
    }
    cout << "----------------------" << endl;
}

int main() {
    vector<Vuelo> vuelos;

    vuelos.push_back(Vuelo("AMX123", "Cancún", "14:30", 4200));
    vuelos.push_back(Vuelo("IB456", "Madrid", "09:15", 8900));
    vuelos.push_back(Vuelo("VIV789", "Monterrey", "21:00", 1500));

    cout << "Vuelos originales:" << endl;
    mostrarVuelos(vuelos);

    // Ordenar por precio
    bubbleSortPrecio(vuelos);
    cout << "Vuelos ordenados por precio:" << endl;
    mostrarVuelos(vuelos);

    // Ordenar por destino
    bubbleSortDestino(vuelos);
    cout << "Vuelos ordenados por destino:" << endl;
    mostrarVuelos(vuelos);

    return 0;
}
