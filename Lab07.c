#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include <stdint.h>
#include "shellsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include "heapsort.h"

int main()
{
    clock_t start_time, end_time;
    double cpu_time_used, memory_used;
    size_t peakSize;
    struct rusage r_usage;
    srand(time(0));
    uint64_t *V;
    printf("V\tA\tN\tT\tM\n");
    
    for (uint64_t n = 2000; n <= 1000000000; n *= 2)
    {
   
        V = (uint64_t*)malloc(n * sizeof(uint64_t));

        // MELHOR CASO / JA ORDENADO
        //crescente2(V, n);printf("A\t");//Acending 
        // DECRESCENTE
        //decrescente2(V, n); printf("D\t");//Dcending
        // PERMUTADO
        aleatorio2(V, n); printf("R\t");//Randon

        // ShellSort
        /*
        start_time = clock();
        shellsort(V,n);
        end_time = clock();
        cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        getrusage(RUSAGE_SELF, &r_usage);
        printf("S\t%ld\t%0.2f\t%ld\n", n, cpu_time_used, r_usage.ru_maxrss);
        */
        // MergeSort
        /*
        start_time = clock();
        mergesort(V, n);
        end_time = clock();
        cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        getrusage(RUSAGE_SELF, &r_usage);
        printf("M\t%ld\t%0.2f\t%ld\n", n, cpu_time_used, r_usage.ru_maxrss);
        */
        //QuickSort
        
        start_time = clock();
        quicksort(V, n);
        end_time = clock();
        cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        getrusage(RUSAGE_SELF, &r_usage);
        printf("Q\t%ld\t%0.2f\t%ld\n", n, cpu_time_used, r_usage.ru_maxrss);
        
        //HeapSort
        /*
        start_time = clock();
        heapsort(V, n);
        end_time = clock();
        cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        getrusage(RUSAGE_SELF, &r_usage);
        printf("H\t%ld\t%0.2f\t%ld\n", n, cpu_time_used, r_usage.ru_maxrss);
        */

        free(V);
    }
}