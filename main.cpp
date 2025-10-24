#include <iostream>
#include "Vuelo.h"
#include "dlistVuelo.h"
#include "sorts.h"

using namespace std;

int main() {
    DListVuelo lista;

    lista.add(Vuelo("AMX123", "Cancun", "14:30", 4200));
    lista.add(Vuelo("IB456", "Madrid", "09:15", 8900));
    lista.add(Vuelo("VIV789", "Monterrey", "21:00", 1500));

    cout << "Vuelos originales:" << endl;
    lista.mostrar();

    bubbleSortPrecio(lista);
    cout << "Vuelos ordenados por precio:" << endl;
    lista.mostrar();

    bubbleSortDestino(lista);
    cout << "Vuelos ordenados por destino:" << endl;
    lista.mostrar();

    cout << "Primer vuelo: "; lista.getFirst().mostrar();
    cout << "Ultimo vuelo: "; lista.getLast().mostrar();

    lista.removeFirst();
    cout << "Despues de remover el primer vuelo:" << endl;
    lista.mostrar();

    lista.clear();
    cout << "Despues de limpiar la lista:" << endl;
    lista.mostrar();

    return 0;
}
