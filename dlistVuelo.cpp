#include "vuelo.h"
#include <iostream>


Vuelo::Vuelo(string num, string dest, string hora, double prec) {
    numero = num;
    destino = dest;
    horaSalida = hora;
    precio = prec;
}


string Vuelo::getNumero(){
    return numero; 
}

string Vuelo::getDestino(){
    return destino; 
}

string Vuelo::getHora(){
    return horaSalida; 
}

double Vuelo::getPrecio(){
    return precio; 
}

void Vuelo::mostrar() {
    cout << numero << " | " << destino << " | " << horaSalida << " | $" << precio << endl;
}
