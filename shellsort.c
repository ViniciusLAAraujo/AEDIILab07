#include "shellsort.h"
#include <stdio.h>
#include <stdint.h>
//=============================================================================
void insercaoPorCor(uint64_t *array, uint64_t n, uint64_t cor, uint64_t h){
    printf("entrei no inspc\n");
    for (uint64_t i = (h + cor); i < n; i+=h) {
        printf("cor inspc=%ld\n",cor);
        uint64_t tmp = array[i];
        printf("i=%ld\n",i);
        uint64_t j = i - h;
        printf("j=%ld\n",j);
        while ((j >= 0) &&(array[j] > tmp)) {
             printf("j do while=%ld\n",j);
            array[j + h] = array[j];
            printf("j+h=%ld\n",j+h);
            j-=h;
            printf("j=%ld\n",j);
        }
        printf("Sai do While\n");
        array[j + h] = tmp;
    }
}
//=============================================================================
void shellsort(uint64_t *array, uint64_t n)
{
 int i , j , value;
 int gap = 1;
  
 do {
  gap = 3*gap+1;
 } while(gap < n);
  
 do {
  gap /= 3;
  for(i = gap; i < n; i++) {
   value = array[i];
   j = i - gap;
    
   while (j >= 0 && value < array[j]) {
    array[j + gap] = array[j];
    j -= gap;
   }
   array[j + gap] = value;
  }
 }while(gap > 1);
}
//=============================================================================
