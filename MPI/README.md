Integrantes
Javier Andrés Peña Vargas - 2204123
Santiago Yarce Prince - 2204122

Codigo Postmansort en MPI 

Este código implementa el algoritmo de ordenamiento Postman utilizando MPI.
El algoritmo Postman es un algoritmo de ordenamiento que funciona dividiendo los números en grupos basados en sus dígitos más significativos (MSB),
y luego ordenando esos grupos. En este código, cada proceso se encarga de ordenar una parte de los datos.

El código comienza inicializando MPI y obteniendo el número total de procesos y el rango del proceso actual. 
Luego, el proceso 0 recibe los datos del usuario y los envía a todos los demás procesos utilizando la función MPI_Bcast.

A continuación, el código implementa el algoritmo de ordenamiento Postman.
Este algoritmo funciona dividiendo los números en grupos basados en sus dígitos más significativos (MSB),
y luego ordenando esos grupos. En este código, cada proceso se encarga de ordenar una parte de los datos.

Finalmente, el código finaliza MPI y termina.
![image](https://github.com/SC3UIS/IntroPP2204123./assets/143100480/90f4640f-889c-4449-9314-634ce1a44b6d)

Codigo Binary Search

Inicialización de MPI: El programa comienza inicializando MPI y obtiene el rango del proceso actual y el tamaño del comunicador MPI.

Generación de datos aleatorios: En el proceso 0, se genera aleatoriamente el tamaño de la lista y la clave de búsqueda. Estos valores se transmiten a todos los demás procesos utilizando la función MPI_Bcast.

Generación y ordenamiento de la lista local: Cada proceso genera su propia lista de números aleatorios de tamaño local y la ordena utilizando el algoritmo de ordenación de burbuja.

Recolección de listas locales: Las listas locales ordenadas se recopilan en el proceso 0 utilizando la función MPI_Gather, donde se combinan en una lista global.

Búsqueda binaria: En el proceso 0, se realiza la búsqueda binaria en la lista global para encontrar la clave de búsqueda.

Medición del tiempo de ejecución: El programa utiliza la función MPI_Wtime() para medir el tiempo de ejecución desde la generación de los datos hasta la finalización de la búsqueda binaria en el proceso 0. El tiempo de ejecución se imprime al final.

Finalización de MPI y liberación de memoria: Finalmente, se finaliza MPI y se libera la memoria asignada para las listas locales y globales.

![image](https://github.com/SC3UIS/IntroPP2204123./assets/143100480/72189e59-ef9e-4f58-b313-5aeec7560ce9)

*Ejecucion en guane MPI

Para ejecutar los codigos en MPI se debe seguir los siguientes pasos

1.Se crea y se entra en la carpeta adecuada
```
mkdir parcial2
cd parcial2
```
2. luego se debe crear el archivo con nano 

```
nano nombreArchivo.cpp
```

3. usamos el srun
```
srun -n 4 -w guane10 --pty /bin/bash
```
4.se usa el siguiente codigo
```
module load devtools/mpi/openmpi/3.1.4
```
5. al final para hacer la ejecucion se usan los siguientes comandos, donde el primero crea las banderas y el segundo se encarga de ejecutar
```
mpic++ MPI_binary_search.cpp -o MPI_binary_search
mpirun -np 4 ./MPI_binary_search ./time

```
