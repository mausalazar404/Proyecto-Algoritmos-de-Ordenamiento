#ifndef VUELO_H
#define VUELO_H

#include <string>
using namespace std;

class Vuelo {
private:
    string numero;
    string destino;
    string horaSalida;
    double precio;

public:
    Vuelo(string num, string dest, string hora, double prec);
    string getDestino();
    string getHora();
    string getNumero();
    double getPrecio();
    void mostrar();
};


#endif