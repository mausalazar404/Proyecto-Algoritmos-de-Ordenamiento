# Gestión de Vuelos
Este proyecto es un sistema de gestión de vuelos que permite administrar una colección de rutas aéreas de manera eficiente. El sistema ofrece la posibilidad de agregar, ordenar, obtener y eliminar vuelos en base a atributos clave como número, destino, hora y precio, facilitando la organización de la información.
Para gestionar los datos, el sistema utiliza una Lista Doblemente Enlazada (DListVuelo), una estructura que optimiza las operaciones de inserción y eliminación en los extremos de la lista, asegurando que estas se realicen de manera eficiente.
Para el ordenamiento de los datos, el sistema utiliza el algoritmo Bubble Sort. Este algoritmo se implementa para ordenar los vuelos según criterios como el precio o el destino, demostrando la capacidad del sistema para reordenar la estructura de datos.
Este sistema combina la gestión dinámica de una Lista Doblemente Enlazada con el algoritmo de ordenamiento Bubble Sort, proporcionando una herramienta funcional y modular para la administración de rutas aéreas.
# Descripción de Avances1. 
## Descripción del Avance 1: 
### Implementación de la Lógica de Datos y Ordenamiento
En este primer avance, se estableció la base del proyecto, enfocándose en la definición de la estructura de datos que representa los vuelos y la lógica fundamental para el ordenamiento.   
- Clase Vuelo: Se creó la clase para gestionar la información individual de cada vuelo, incluyendo atributos como número, destino, horaSalida y precio, junto con sus métodos getters y el método mostrar().
- Funciones de Ordenamiento (sorts.h y sorts.cpp): Se definieron e implementaron las funciones bubbleSortPrecio y bubbleSortDestino. Estas funciones aplican el algoritmo Bubble Sort para ordenar una colección de vuelos, demostrando la capacidad de reordenamiento de los datos del proyecto.2. 
## Descripción del Avance 2: Implementación de la Estructura Dinámica (Lista Doblemente Enlazada)
En este segundo avance, se integró una estructura de datos dinámica para gestionar la colección de vuelos de manera flexible.
- Clases DLinkVuelo y DListVuelo:DLinkVuelo (Nodo): Representa cada nodo de la lista, conteniendo el objeto Vuelo y punteros a los nodos next (siguiente) y prev (anterior), lo que la define como doblemente enlazada.DListVuelo (Lista): Gestiona la colección de nodos.
- Operaciones Fundamentales: Se implementaron los mecanismos de gestión esenciales de la lista doblemente enlazada:
-- Inserción en Extremos: addFirst() y add() (que inserta al final).Remoción en Extremos: removeFirst() y removeLast().Consultas: getFirst(), getLast(), length(), empty().Utilidades: mostrar() y clear().
- Integración: Las funciones de ordenamiento implementadas en el Avance 1 se adaptaron para operar directamente sobre la nueva estructura DListVuelo, permitiendo el ordenamiento de la colección dinámica.
# Instrucciones para Compilar y Ejecutar
Para compilar este proyecto, se requiere un compilador C++ (se recomienda C++11 o superior). Debes asegurarte de compilar todos los archivos de implementación (.cpp) juntos.Instrucciones para compilar el avance de proyecto:Ejecuta el siguiente comando en la terminal (asegúrate de que todos los archivos .cpp estén en el directorio):Bashg++ -std=c++11 main.cpp vuelo.cpp dlistvuelo.cpp sorts.cpp -o gestor_vuelos
## Instrucciones para ejecutar el avance de proyecto:
Ejecuta el siguiente comando en la terminal:Bash./gestor_vuelos
# Desarrollo de Competencias 
## (Análisis de Complejidad)SICT0301: 
Evalúa los componentesAnálisis de Complejidad de ComponentesComponenteOperaciónMejor CasoPeor CasoJustificaciónDListVuelo (Lista)addFirst, removeLast$O(1)$$O(1)$Se manipulan directamente los punteros head o tail.DListVuelo (Lista)length, empty$O(1)$$O(1)$Acceso directo al contador size.Bubble SortOrdenamiento$O(n)$$O(n^2)$En el mejor caso (lista ordenada), recorre $O(n)$. En el peor caso, realiza $O(n^2)$ comparaciones.
## Determinación de la Complejidad Final del Programa
La operación dominante en el programa es el ordenamiento mediante Bubble Sort, lo cual establece el límite superior de la complejidad.Complejidad Final del Programa: $O(n^2)$Justificación: El Bubble Sort tiene una complejidad cuadrática $O(n^2)$ en el caso promedio y peor. Aunque las operaciones de la lista son rápidas ($O(1)$), el ordenamiento domina la complejidad global.
## SICT0302: Toma decisiones
## Selección de Estructura de Datos (Lista Doblemente Enlazada)
Se seleccionó la Lista Doblemente Enlazada (DListVuelo) porque proporciona $O(1)$ en las operaciones de inserción y eliminación en los extremos (addFirst, removeLast). Esto es superior a la complejidad $O(n)$ que presentaría un vector al insertar o eliminar elementos al inicio, ya que el vector requiere mover todos los elementos restantes.
## Selección de Algoritmo de Ordenamiento (Bubble Sort)
Se eligió Bubble Sort por su facilidad de implementación sobre una lista enlazada, ya que la estrategia de intercambiar solo los valores del objeto Vuelo dentro de los nodos es sencilla de codificar. Si bien se sacrifica la eficiencia (complejidad $O(n^2)$), se logra una solución simple y directa para el requisito de ordenamiento.
## SICT0303: Implementa acciones científicas
Mecanismos de Consulta: La consulta a los extremos (getFirst, getLast) se realiza con eficiencia $O(1)$ al devolver directamente el contenido de los punteros head y tail.Mecanismos de Validación: El código implementa manejo de errores lanzando std::runtime_error en las funciones de consulta y remoción (getFirst, removeLast, etc.) si la lista se encuentra vacía.Implementación del Ordenamiento: La lógica de Bubble Sort se implementa correctamente sobre la lista al intercambiar los objetos Vuelo con la función std::swap, lo que reordena lógicamente los datos sin la complejidad de manipular los punteros next y prev de los nodos.
