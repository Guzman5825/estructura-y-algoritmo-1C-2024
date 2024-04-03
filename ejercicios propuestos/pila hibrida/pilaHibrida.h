#ifndef PILAHIBRIDA_H_INCLUDED
#define PILAHIBRIDA_H_INCLUDED
#include <stdlib.h>
#include <string.h>

#define MINIMO(x,y) ( (x)<(y)?(x):(y) )
#define TODO_OK 1
#define SIN_MEM 2
#define SIN_ELEM 3
#define ERROR 0


typedef struct{
    char* vec;
    int tope;
}tPila;

void crearPila(tPila* p);
int pilaVacia(tPila* p);
int pilaLlena(const tPila* p,const void* d,unsigned tam);
int apilar(tPila* p,const void* d,unsigned tam);
int desapilar(tPila* p,void* d,unsigned tam);
int varTope(const tPila* p,void* d,unsigned tam);
void vaciarPila(tPila* p);
#endif // PILAHIBRIDA_H_INCLUDED
