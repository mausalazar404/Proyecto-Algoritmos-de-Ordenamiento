# Gestión de Vuelos
Este proyecto es un sistema de gestión de vuelos que permite administrar una colección de rutas aéreas de manera eficiente. El sistema ofrece la posibilidad de agregar, ordenar, obtener y eliminar vuelos en base a atributos clave como número, destino, hora y precio, facilitando la organización de la información. Cuenta con un menú interactivo que garantiza la persistencia de los datos mediante la lectura y sobrescritura de un archivo de texto.
Para gestionar los datos, el sistema utiliza una Lista Doblemente Enlazada (DListVuelo), una estructura que optimiza las operaciones de inserción y eliminación en los extremos de la lista, asegurando que estas se realicen de manera eficiente.
Para el ordenamiento de los datos, el sistema utiliza el algoritmo Merge Sort. Este algoritmo se implementa para ordenar los vuelos según criterios como el precio o el destino, demostrando la capacidad del sistema para reordenar la estructura de datos.
# Descripción de Avances 
## Descripción del Avance 1: 
### Implementación de la Lógica de Datos y Ordenamiento
En este primer avance, se estableció la base del proyecto, enfocándose en la definición de la estructura de datos que representa los vuelos y la lógica fundamental para el ordenamiento.   
- Clase Vuelo: Se creó la clase para gestionar la información individual de cada vuelo, incluyendo atributos como número, destino, horaSalida y precio, junto con sus métodos getters y el método mostrar().
- Funciones de Ordenamiento (sorts.h y sorts.cpp): Se definieron e implementaron las funciones bubbleSortPrecio y bubbleSortDestino. Estas funciones aplican el algoritmo Bubble Sort para ordenar una colección de vuelos, demostrando la capacidad de reordenamiento de los datos del proyecto.2. 
## Descripción del Avance 2: Implementación de la Estructura Dinámica (Lista Doblemente Enlazada)
En este segundo avance, se integró una estructura de datos dinámica para gestionar la colección de vuelos de manera flexible.
- Clases DLinkVuelo y DListVuelo:DLinkVuelo (Nodo): Representa cada nodo de la lista, conteniendo el objeto Vuelo y punteros a los nodos next (siguiente) y prev (anterior), lo que la define como doblemente enlazada.DListVuelo (Lista): Gestiona la colección de nodos.
- Operaciones Fundamentales: Se implementaron los mecanismos de gestión esenciales de la lista doblemente enlazada:
Inserción en Extremos: addFirst() y add() (que inserta al final).
Remoción en Extremos: removeFirst() y removeLast().
Consultas: getFirst(), getLast(), length(), empty().Utilidades: mostrar() y clear().
- Integración: Las funciones de ordenamiento implementadas en el Avance 1 se adaptaron para operar directamente sobre la nueva estructura DListVuelo, permitiendo el ordenamiento de la colección dinámica.
## Razón de cambios:
La implementación de DlistVuelo permite gestionar un número variable de vuelos de forma eficiente, logrando inserciones/eliminaciones en los extremos en O(1).

## Descripción del Avance 3:
Durante este avance se implementó el merge sort quitando completamente el bubble sort. Así mismo se agregaron los metodos de serHead() y updateTail() para permitir que el merge sort reordene la estructura. La razón de cambios sobre el segundo avance es la mejora de la complejidad de O(n^2) a O(nlogn)
# Instrucciones para Compilar y Ejecutar
Para compilar este proyecto, se requiere un compilador C++ (se recomienda C++11 o superior). Debes asegurarte de compilar todos los archivos de implementación (.cpp) juntos.Instrucciones para compilar el avance de proyecto:Ejecuta el siguiente comando en la terminal (asegúrate de que todos los archivos .cpp estén en el directorio): 
`g++ dlistVuelo.cpp main.cpp sorts.cpp vuelo.cpp -o programa`
## Instrucciones para ejecutar el avance de proyecto:
Ejecuta el siguiente comando en la terminal: `programa.exe`
# Descripción de las entradas del proyecto
El programa requiere un archivo de entrada y salida llamado `vuelos.txt`, que contiene el inventario de vuelos en formato txt con el siguiente formato por línea: número, desnito, hora, precio.
# Descripción de las salidas 
La salida principal es la consola, que muestra:

El menú interactivo y mensajes de confirmación, 

la lista completa de vuelos mostrando: Número | Destino | Hora | $Precio.

La sobrescritura del archivo vuelos.txt con el estado actual de la lista (Opción 6)
# Desarrollo de Competencias 
## (Análisis de Complejidad)SICT0301: 
Merge sort: Ordenamiento, mejor caso O(nlogn), peor caso O(nlogn).
## Determinación de la Complejidad Final del Programa
La operación dominante en el programa es el ordenamiento mediante merge Sort, lo cual establece el límite superior de la complejidad.
### Complejidad Final del Programa: O(nlogn)
### Justificación: El Merge Sort tiene una complejidad cuadrática O(n^2) en el caso promedio y peor. Aunque las operaciones de la lista son rápidas (O(1)), el ordenamiento domina la complejidad global.
## SICT0302: Toma decisiones
## Selección de Estructura de Datos (Lista Doblemente Enlazada)
Se seleccionó la Lista Doblemente Enlazada (DListVuelo) porque proporciona O(1) en las operaciones de inserción y eliminación en los extremos (addFirst, removeLast) y O(n) en (mostrar, guardarDatos y updateTail). Esto es superior a la complejidad O(n) que presentaría un vector al insertar o eliminar elementos al inicio, ya que el vector requiere mover todos los elementos restantes.
## Selección de Algoritmo de Ordenamiento (Merge Sort)

Se seleccionó y aplicó Merge Sort O(nlog n). Este es el algoritmo más adecuado porque es altamente eficiente y maneja muy bien la manipulación de punteros en listas enlazadas.
## SICT0303: Implementa acciones científicas
### Mecanismos de Consulta: 
- Consulta por Recorrido: La función mostrar() recorre la lista de forma iterativa usando el puntero next.
- Manejo de Excepciones: Las funciones getFirst() y removeFirst() (entre otras) utilizan throw runtime_error("Lista vacía") para manejar científicamente la condición de lista vacía, previniendo fallos de acceso a punteros nulos (nullptr).
## Mecanismos de lectura
- Validación de Archivo: Se verifica la apertura con archivo.is_open().
- Procesamiento txt: Se utiliza std::stringstream con getline para procesar el formato txt, separando cada atributo por la coma.
## Mecanismos de escritura
- Sobrescritura Segura: Se abre el archivo vuelos.txt con std::ofstream para sobrescribir el contenido existente.
- Formato Consistente: Se recorre la lista (usando actual = lista.getHead()) y se escriben los datos en el archivo manteniendo rigurosamente el formato txt (numero,destino,hora,precio), lo cual es el formato esperado por la función de lectura.
