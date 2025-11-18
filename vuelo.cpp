#include "vuelo.h"
#include <iostream>


// Complejidad: O(1)
Vuelo::Vuelo(string num, string dest, string hora, double prec) {
    numero = num;
    destino = dest;
    horaSalida = hora;
    precio = prec;
}

// Complejidad: O(1)
string Vuelo::getNumero(){
    return numero; 
}

// Complejidad: O(1)
string Vuelo::getDestino(){
    return destino; 
}

// Complejidad: O(1)
string Vuelo::getHora(){
    return horaSalida; 
}

// Complejidad: O(1)
double Vuelo::getPrecio(){
    return precio; 
}

// Complejidad: O(1)
void Vuelo::mostrar() {
    cout << numero << " | " << destino << " | " << horaSalida << " | $" << precio << endl;
}
