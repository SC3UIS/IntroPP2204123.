/* 
 * C Program to Implement Postman Sort Algorithm
 */
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h> 
void arrange(int,int);
int array[100000], array1[100000];
int i, j, temp, max, count=100000, maxdigits = 0, c = 0;
double start, end; 
int generateRandom();

void main()
{
      start = omp_get_wtime(); 
      int t1, t2, k, t, n = 1;
 
//    printf("Enter size of array :");
//    scanf("%d", &count);
//    printf("Enter elements into array :");
//    for (i = 0; i < count; i++)
//    {
//        scanf("%d", &array[i]);
//        array1[i] = array[i];            
//    }
    srand(time(NULL));
    for(int i = 0; i < 100000; i++){
        array1[i]= generateRandom();
        array[i]= array1[i];
    }
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
    end = omp_get_wtime();
    printf("Work took %f seconds\n", end - start);
//   printf("\nSorted Array (Postman sort) :");    
//    for (i = 0; i < count; i++)
//        printf("%d ", array1[i]);
//    printf("\n");
}
 
/* Function to arrange the of sequence having same base */
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

int generateRandom()
{
int number = rand()%10000;
return number; 
}
