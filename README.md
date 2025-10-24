# Sistema de Gestión de Vuelos


Este proyecto es un sistema para guardar y ordenar información de vuelos de aerolíneas. La idea es que se puedan cargar los vuelos y después verlos ordenados de distintas formas.

## Ejemplo de uso:
Cargar vuelos desde el archivo. 
AMX123, Cancún, 14:30, 4200
IB456, Madrid, 09:15, 8900
VIV789, Monterrey, 21:00, 1500

Mostrar vuelos en el orden en que están.

## Elegir cómo ordenarlos:
Por precio (de barato a caro).
Por hora de salida (cronológico).
Por destino (alfabético).

## Escoger el algoritmo de ordenamiento:
Bubble Sort (lento pero fácil de entender).
Merge Sort (rápido para muchos datos).

## Ejemplo ordenado por precio:
VIV789, Monterrey, 21:00, 1500
AMX123, Cancún, 14:30, 4200
IB456, Madrid, 09:15, 8900


También hay funciones para agregar nuevos vuelos.

## Sub-competencias

## SICT0302B: Toma decisiones
Uso una lista vector para guardar los vuelos porque es fácil recorrerla y acceder por posición.
Para ordenar Bubble Sort y Merge Sort


## SICT0301B: Evalúa los componentes
Acceso en lista: O(1).
Insertar/borrar: O(n).
Bubble Sort: O(n²).
Merge Sort: O(n log n).


## Avance del Proyecto
Descripción del avance

En este avance, se implementó una estructura de datos lista doblemente ligada para almacenar objetos de tipo Vuelo.
Cada nodo contiene la información de un vuelo, permitiendo recorrer los elementos en ambas direcciones.
Además, se incorporaron dos algoritmos de ordenamiento Bubble Sort adaptados para listas doblemente ligadas: uno que ordena los vuelos por precio y otro que los ordena por destino.

La estructura reemplaza al uso previo de vector, ofreciendo mayor control sobre la inserción y eliminación de elementos, y una mejor representación de una colección dinámica de datos.

## Cómo usar el programa

Al ejecutar el programa, se crea una lista doblemente ligada de vuelos.

Se agregan varios vuelos mediante el método add().

El programa muestra la lista original.

Luego, se puede ver los vuelos ordenados por precio y posteriormente por destino.

## SICT0301: Evalúa los componentes

Se analizó la complejidad de las estructuras y algoritmos:
DListVuelo

Inserción al inicio o final: O(1)

Búsqueda de un elemento: O(n)

Eliminación: O(1) si se tiene el nodo, o O(n) si se busca.

Bubble Sort (por precio y destino)

Comparación e intercambio: O(n²) en el peor y promedio de los casos.

## SICT0302: Toma decisiones

Se seleccionó la lista doblemente ligada en lugar de un vector porque:

Permite una gestión dinámica de memoria.

Facilita la inserción y eliminación sin necesidad de desplazar elementos.

Se adapta mejor a estructuras de información que cambian constantemente, como una lista de vuelos disponibles.

## SICT0303: Implementa acciones científicas

Se implementaron mecanismos de consulta mediante recorridos completos de la lista, como en mostrar() y los algoritmos de ordenamiento.
