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
    // Complejidad: O(1) 
    Vuelo(string num, string dest, string hora, double prec);
    
    // Complejidad: O(1)
    string getDestino();
    
    // Complejidad: O(1) 
    string getHora();
    
    // Complejidad: O(1) 
    string getNumero();
    
    // Complejidad: O(1) 
    double getPrecio();
    
    // Complejidad: O(1) 
    void mostrar();
};


#endif
