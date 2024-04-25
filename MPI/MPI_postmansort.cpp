#include <mpi.h>
#include <stdio.h>

void arrange(int,int);
int array[100], array1[100];
int i, j, temp, max, count, maxdigits = 0, c = 0;

int main(int argc, char** argv) {
    // Inicializa MPI
    MPI_Init(NULL, NULL);

    // Obtiene el número total de procesos
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Obtiene el rango del proceso actual
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    int t1, t2, k, t, n = 1;

    // El proceso 0 recibe los datos del usuario
    if (world_rank == 0) {
        printf("Enter size of array :");
        scanf("%d", &count);
        printf("Enter elements into array :");
        for (i = 0; i < count; i++)
        {
            scanf("%d", &array[i]);
            array1[i] = array[i];            
        }
    }

    // Se envían los datos a todos los procesos
    MPI_Bcast(&count, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(array, count, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(array1, count, MPI_INT, 0, MPI_COMM_WORLD);
    // Aquí comienza el algoritmo de ordenamiento Postman
    // El código a continuación es muy similar a tu código original, pero se ejecuta en paralelo en varios procesos

    for (i = 0; i < count; i++)
    {
        t = array[i];        /*first element in t */
        while(t > 0)
        {
            c++;
            t = t / 10;        /* Find MSB */
        }
        if (maxdigits < c) 
            maxdigits = c;   /* number of digits of a each number */
        c = 0;
    }
    while(--maxdigits) 
        n = n * 10;      

    for (i = 0; i < count; i++)
    {
        max = array[i] / n;        /* MSB - Dividnng by perticular base */
        t = i;
        for (j = i + 1; j < count;j++)    
        {
            if (max > (array[j] / n))
            {
                max = array[j] / n;   /* greatest MSB */
                t = j;
            }
        }
        temp = array1[t];
        array1[t] = array1[i];
        array1[i] = temp;
        temp = array[t];
        array[t] = array[i];
        array[i] = temp;
    }
    while (n >= 1)
    {
        for (i = 0; i < count;)
        {
            t1 = array[i] / n;
            for (j = i + 1; t1 == (array[j] / n); j++);
                arrange(i, j);
            i = j;
        }
        n = n / 10;
    }
    if (world_rank == 0) {
        printf("\nSorted Array (Postman sort) :");    
        for (i = 0; i < count; i++)
            printf("%d ", array1[i]);
        printf("\n");
    }

    // Finaliza MPI
    MPI_Finalize();
}

/* Función para organizar la secuencia que tiene la misma base */
void arrange(int k,int n)
{
        for (i = k; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (array1[i] > array1[j])
            {
                temp = array1[i];
                array1[i] = array1[j];
                array1[j] = temp;
                temp = (array[i] % 10);
                array[i] = (array[j] % 10);
                array[j] = temp;
            }
        }
    }
}

