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

*Ejecucion en guane MPI

