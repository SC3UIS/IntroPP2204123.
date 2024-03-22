El algoritmo Postman, también conocido como "Bucket Sort" o "Radix Sort", es un algoritmo de ordenamiento que clasifica los elementos de un arreglo basándose en los dígitos individuales de los números. Es particularmente útil cuando se tienen números con un número fijo de dígitos.

Para ejecutar este programa es necesario entrar a guaneExa

```
ssh guane
```

Para compilar el código secuencial se tiene que ejecutar el siguiente comando (Se hará uso de OpenMP para medir los tiempos):

```
srun -n 10 -w ExaDELL --pty /bin/bash
gcc -fopenmp postmansort.c -o postmansort
./postmansort
```
Para ejecutar el codigo paralelizado se hace uso de este comando:
```
sbatch postmansort.sbatch
```

**RESULTADOS**

**SECUANCIAL**

![postmansort](https://github.com/javierPena28/IntroPP2204123/assets/143100480/1a9c7567-3246-4b6c-9f72-c619b4bd10f7)

**PARALELIZADO**

![omp_postmansort](https://github.com/javierPena28/IntroPP2204123/assets/143100480/0064c9a8-9c32-4b5e-8f71-4a3241675f64)

