#include "mergesort.h"
#include <stdlib.h>
#include <stdint.h>
//=============================================================================
void mergesort(uint64_t  *array, uint64_t  n) {
   mergesortRec(array, 0, n-1);
}
//=============================================================================
void mergesortRec(uint64_t  *array, uint64_t  esq, uint64_t  dir){
   if (esq < dir){
      uint64_t  meio = (esq + dir) / 2;
      mergesortRec(array, esq, meio);
      mergesortRec(array, meio + 1, dir);
      intercalar(array, esq, meio, dir);
   }
}
//=============================================================================
void intercalar(uint64_t * array, uint64_t  esq, uint64_t  meio, uint64_t  dir){
   uint64_t  n1, n2, i, j, k;

   //Definir tamanho dos dois subarrays
   n1 = meio-esq+1;
   n2 = dir - meio;

   uint64_t * a1 = (uint64_t *) malloc((n1+1) * sizeof(uint64_t )); 
   uint64_t * a2 = (uint64_t *) malloc((n2+1) * sizeof(uint64_t ));

   //Inicializar primeiro subarray
   for(i = 0; i < n1; i++){
      a1[i] = array[esq+i];
   }

   //Inicializar segundo subarray
   for(j = 0; j < n2; j++){
      a2[j] = array[meio+j+1];
   }

   //Sentinela no final dos dois arrays
   a1[i] = a2[j] = 0x7FFFFFFF;

   //intercalacao propriamente dita
   for(i = j = 0, k = esq; k <= dir; k++){
      array[k] = (a1[i] <= a2[j]) ? a1[i++] : a2[j++];
   }

   free(a1);
   free(a2);
}
//=============================================================================
