#include <iostream>
#include <fstream>      
#include <sstream>      
#include <limits>      
#include "Vuelo.h"
#include "dlistVuelo.h"
#include "sorts.h"

using namespace std;


const string NOMBRE_ARCHIVO = "vuelos.txt";


void cargarDatos(DListVuelo &lista) {
    ifstream archivo(NOMBRE_ARCHIVO);
    string linea;
    
    if (!archivo.is_open()) {
        cout << "AVISO: Archivo " << NOMBRE_ARCHIVO << " no encontrado. Iniciando con lista vacía." << endl;
        // Se agregan vuelos de prueba si el archivo no existe
        lista.add(Vuelo("AMX123", "Cancun", "14:30", 4200));
        lista.add(Vuelo("IB456", "Madrid", "09:15", 8900));
        lista.add(Vuelo("VIV789", "Monterrey", "21:00", 1500));
        cout << "Vuelos de muestra agregados." << endl;
        return;
    }

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string num, dest, hora, prec_str;
        double precio;

        if (getline(ss, num, ',') &&
            getline(ss, dest, ',') &&
            getline(ss, hora, ',') &&
            getline(ss, prec_str)) {
            
            try {
                precio = stod(prec_str);
                lista.add(Vuelo(num, dest, hora, precio));
            } catch (const invalid_argument& e) {
                cerr << "ERROR: Datos inválidos en la línea: " << linea << endl;
            }
        }
    }

    archivo.close();
    cout << "DATOS CARGADOS: " << lista.length() << " vuelos cargados desde " << NOMBRE_ARCHIVO << endl;
}

void guardarDatos(DListVuelo &lista) {
    ofstream archivo(NOMBRE_ARCHIVO); 

    if (!archivo.is_open()) {
        cerr << "ERROR: No se pudo abrir el archivo " << NOMBRE_ARCHIVO << " para escribir." << endl;
        return;
    }

    DLinkVuelo* actual = lista.getHead(); 
    while (actual) {
        archivo << actual->vuelo.getNumero() << ","
                << actual->vuelo.getDestino() << ","
                << actual->vuelo.getHora() << ","
                << actual->vuelo.getPrecio() << endl;
        
        actual = actual->next;
    }

    archivo.close();
    cout << "✅ DATOS GUARDADOS: " << lista.length() << " vuelos guardados exitosamente en " << NOMBRE_ARCHIVO << endl;
}



void mostrarMenu() {
    cout << "\n==================================" << endl;
    cout << "  SISTEMA DE GESTIÓN DE VUELOS" << endl;
    cout << "==================================" << endl;
    cout << "1. Mostrar todos los vuelos" << endl;
    cout << "2. Agregar nuevo vuelo" << endl;
    cout << "3. Ordenar por Precio" << endl;
    cout << "4. Ordenar por Destino" << endl;
    cout << "5. Remover el primer vuelo" << endl;
    cout << "6. Guardar datos en archivo" << endl;
    cout << "7. Salir del programa" << endl;
    cout << "----------------------------------" << endl;
    cout << "Seleccione una opción: ";
}

void agregarVuelo(DListVuelo &lista) {
    string num, dest, hora;
    double precio;

    cout << "\n--- AGREGAR NUEVO VUELO ---" << endl;
    cout << "Número de vuelo: ";
    cin >> num;
    cout << "Destino: ";
    cin >> dest;
    cout << "Hora de salida (HH:MM): ";
    cin >> hora;
    cout << "Precio: $";
    
    
    while (!(cin >> precio) || precio <= 0) {
        cout << "Entrada inválida. Ingrese un precio válido: $";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    lista.add(Vuelo(num, dest, hora, precio));
    cout << "✈️ Vuelo " << num << " agregado exitosamente al final de la lista." << endl;
}



int main() {
    DListVuelo lista;
    int opcion;

    // Carga inicial de datos
    cargarDatos(lista);

    do {
        mostrarMenu();

        // Validación de entrada para la opción del menú
        if (!(cin >> opcion)) {
            cout << "\n Entrada inválida. Intente de nuevo." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcion = 0; // Asegura que el loop continúe
            continue;
        }

        switch (opcion) {
            case 1: // Mostrar todos
                if (lista.empty()) {
                    cout << "\nLa lista de vuelos está vacía." << endl;
                } else {
                    cout << "\n--- LISTA ACTUAL DE VUELOS (" << lista.length() << " elementos) ---" << endl;
                    lista.mostrar();
                }
                break;
            case 2: // Agregar
                agregarVuelo(lista);
                break;
            case 3: // Ordenar por Precio
                if (lista.length() <= 1) {
                    cout << "\nLa lista debe tener al menos 2 vuelos para ordenar." << endl;
                } else {
                    mergeSortPrecio(lista);
                    cout << "\n--- VUELOS ORDENADOS POR PRECIO (ASCENDENTE) ---" << endl;
                    lista.mostrar();
                }
                break;
            case 4: // Ordenar por Destino
                if (lista.length() <= 1) {
                    cout << "\nLa lista debe tener al menos 2 vuelos para ordenar." << endl;
                } else {
                    mergeSortDestino(lista);
                    cout << "\n--- VUELOS ORDENADOS POR DESTINO (ALFABÉTICO) ---" << endl;
                    lista.mostrar();
                }
                break;
            case 5: // Remover el primer vuelo
                try {
                    Vuelo removido = lista.removeFirst();
                    cout << "\n Vuelo " << removido.getNumero() << " removido exitosamente de la cabeza de la lista." << endl;
                } catch (const runtime_error& e) {
                    cout << "\n ERROR: " << e.what() << endl;
                }
                break;
            case 6: // Guardar datos
                guardarDatos(lista);
                break;
            case 7: // Salir
                cout << "\nSaliendo del programa. ¡Hasta pronto!" << endl;
                break;
            default:
                cout << "\n Opción no válida. Por favor, seleccione un número del 1 al 7." << endl;
                break;
        }
    } while (opcion != 7);

    return 0;
}
