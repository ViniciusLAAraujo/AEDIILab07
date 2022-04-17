#include "quicksort.h"
#include <stdio.h>
#include <stdint.h>
//=============================================================================
void quicksortRec(uint64_t *array, uint64_t esq, uint64_t dir)
{
    uint64_t i = esq, j = dir;
    uint64_t pivo = array[(dir + esq) / 2];

    while ((int)i <= (int)j)
    {
        while (array[i] < pivo)
            i++;

    
        while (array[j] > pivo)
            j--;

        if ((int)i <= (int)j)
        {
            swap2(array + i, array + j);
            i++;
            j--;
        }
    }
    if ((int)esq < (int)j)
    {
        quicksortRec(array, esq, j);
    }
    if ((int)i < (int)dir)
    {
        quicksortRec(array, i, dir);
    }
}
//=============================================================================
void quicksort(uint64_t *array, uint64_t n)
{
    quicksortRec(array, 0, n - 1);
}
//=============================================================================
