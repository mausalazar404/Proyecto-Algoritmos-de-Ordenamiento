# Sistema de Gestión de Vuelos


Este proyecto es un sistema para guardar y ordenar información de vuelos de aerolíneas. La idea es que se puedan cargar los vuelos y después verlos ordenados de distintas formas. /n

Ejemplo de uso:
Cargar vuelos desde el archivo. 
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


También hay funciones para agregar nuevos vuelos.

Sub-competencias

SICT0302B: Toma decisiones
Uso una lista vector para guardar los vuelos porque es fácil recorrerla y acceder por posición.
Para ordenar Bubble Sort y Merge Sort


SICT0301B: Evalúa los componentes
Acceso en lista: O(1).
Insertar/borrar: O(n).
Bubble Sort: O(n²).
Merge Sort: O(n log n).


