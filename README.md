# Sistema de Gestión de Vuelos


Este proyecto es un sistema para guardar y ordenar información de vuelos de aerolíneas. La idea es que se puedan cargar los vuelos y después verlos ordenados de distintas formas.

# Ejemplo de uso

Cargar vuelos desde el archivo vuelos.csv.

AMX123, Cancún, 14:30, 4200
IB456, Madrid, 09:15, 8900
VIV789, Monterrey, 21:00, 1500


Mostrar vuelos en el orden en que están.

Elegir cómo ordenarlos:

Por precio (de barato a caro).

Por hora de salida (cronológico).

Por destino (alfabético).

Escoger el algoritmo de ordenamiento:

Bubble Sort (lento pero fácil de entender).

Merge Sort (rápido para muchos datos).

Ejemplo ordenado por precio:

VIV789, Monterrey, 21:00, 1500
AMX123, Cancún, 14:30, 4200
IB456, Madrid, 09:15, 8900


También hay funciones para agregar nuevos vuelos y ver reportes ordenados.

Sub-competencias
SICT0302B: Toma decisiones

Uso una lista (vector) para guardar los vuelos porque es fácil recorrerla y acceder por posición.

Para ordenar probé Bubble Sort y Merge Sort. Me quedo con Merge Sort porque es mucho más rápido en la mayoría de los casos.

También probé un árbol binario de búsqueda (BST) para organizar los vuelos por precio y poder buscar vuelos con precios similares más fácil.

SICT0301B: Evalúa los componentes

Hice pruebas en pruebas.cpp donde checo:

Insertar y borrar vuelos.

Ordenarlos por destino, precio y hora.

Buscar en el árbol por precio.

Complejidad (resumen):

Acceso en lista: O(1).

Insertar/borrar: O(n).

Bubble Sort: O(n²).

Merge Sort: O(n log n).

Árbol (BST): inserción y búsqueda O(log n) en promedio.

SICT0303B: Implementa acciones científicas

Se pueden consultar vuelos por destino.

Se pueden generar reportes ordenados.

Los vuelos se leen al inicio desde vuelos.csv.

Los vuelos nuevos se guardan al final del archivo para no tener que capturarlos otra vez.
