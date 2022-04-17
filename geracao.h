#ifndef GERACAO_H
#define GERACAO_H
//=============================================================================
#include <stdbool.h>
#include <stdint.h>
//=============================================================================
void swap(int *i, int *j);
void swap2(uint64_t *i, uint64_t *j);
//=============================================================================
void crescente(int *v, int n);
void crescente2(uint64_t *v, uint64_t n);
//=============================================================================
void decrescente(int *v, int n);
void decrescente2(uint64_t *v, uint64_t n);
//=============================================================================
void aleatorio(int *v, int n);
void aleatorio2(uint64_t *v, uint64_t n);
//=============================================================================
void mostrar(int *v, int n);
//=============================================================================
bool isOrdenado(int *v, int n);
//=============================================================================
#endif