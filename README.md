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
El algoritmo Merge Sort tiene una complejidad de O(nlog n) en el mejor caso, caso promedio y peor caso. El proceso consta de dos fases principales:
- La División (Factor log n): El algoritmo divide la lista de N vuelos recursivamente en dos mitades hasta que cada sublista contiene un solo elemento. El número de veces que se puede dividir la lista es el factor log n. 
- La Fusión (Factor O(n)): En cada uno de esos log n niveles, el algoritmo realiza la operación de fusión, donde visita y compara todos los n elementos para unirlos de forma ordenada en una sola lista más grande. Esto significa que el trabajo de comparación por cada nivel es O(n).Al multiplicar el trabajo por nivel O(n) por el número de niveles log n, la complejidad total es O(nlog n). La gran ventaja del Merge Sort es que esta cantidad de trabajo es constante y no depende del estado inicial de los datos (es decir, si los vuelos están ordenados o no).

## Complejidad de lista doblemente ligada
Lista Doblemente Enlazada: Para las operaciones esenciales de gestión de inventario (añadir y remover elementos en el inicio o al final), su complejidad se mantiene en tiempo constante, O(1), tanto en el mejor caso, promedio y peor caso. Esto es posible gracias a que la estructura almacena punteros directos a head y tail, requiriendo solo un número fijo de reasignaciones de punteros (next y prev). La complejidad solo se mueve a tiempo lineal, O(N), cuando la operación, inevitablemente, debe recorrer todos los nodos de la lista, como sucede al visualizar todo el contenido (mostrar()), al vaciar completamente la lista (clear()).
## Determinación de la Complejidad Final del Programa
La complejidad final del programa de gestión de vuelos está determinada por el algoritmo con la tasa de crecimiento más alta, que es el Merge Sort con O(Nlog N). Aunque las operaciones de datos (cargarDatos y guardarDatos) y la visualización (mostrar) requieren un recorrido completo de la lista, resultando en una complejidad de O(N), y la inserción/eliminación en los extremos es O(1), el ordenamiento es el componente dominante. Dado que O(Nlog N) crece más rápido que O(N) o O(1), la complejidad de todo el sistema se cataloga como O(Nlog N), asegurando que el programa es eficiente y escalable para un gran volumen de vuelos.

# SICT0302: Toma decisiones
## Selección de Estructura de Datos (Lista Doblemente Enlazada)
La Lista Doblemente Enlazada fue seleccionada como la estructura de datos ideal porque proporciona una eficiencia de tiempo constante, O(1), en las cuatro operaciones fundamentales de gestión de inventario: agregar y eliminar tanto en el inicio (addFirst, removeFirst) como en el final (add, removeLast). Esta característica la hace superior a otras estructuras dinámicas: se descartó el Vector Dinámico porque la inserción o eliminación de elementos al inicio arruinaban el rendimiento con una complejidad O(N) al requerir mover todos los elementos en memoria. Y se descartó la lista simplemente Enlazada porque, aunque ofrece O(1) para el inicio, la eliminación al final, requeriría recorrer toda la lista para encontrar el nodo anterior. Haciendo de DListVuelo la única estructura que cumple con la máxima eficiencia para las necesidades operacionales del sistema de vuelos.
## Selección de Algoritmo de Ordenamiento (Merge Sort)

La selección de Merge Sort como algoritmo de ordenamiento se justifica por su eficiencia superior para la estructura de datos elegida. Primero, proporciona una complejidad de O(Nlog N) en sus casos mejor, promedio y peor, lo que representa un salto masivo de rendimiento respecto a la complejidad cuadrática O(N^2) de algoritmos básicos como Bubble Sort, eliminando la lentitud para un gran número de vuelos. En segundo lugar, a diferencia de Quick Sort, cuya eficiencia puede bajar a O(N^2) en el peor caso, Merge Sort ofrece un rendimiento predecible y consistente. Finalmente, su característica más importante es su compatibilidad con la Lista Doblemente Enlazada: Merge Sort opera de manera óptima en listas enlazadas porque solo requiere acceso secuencial y manipulación de punteros, evitando los  accesos aleatorios que harían ineficientes a otros algoritmos como Heap Sort o la implementación estándar de Quick Sort en esta estructura.
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
