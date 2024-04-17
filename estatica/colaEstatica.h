#ifndef COLAESTATICA_H_INCLUDED
#define COLAESTATICA_H_INCLUDED

#include <string.h>

#define SIN_ELEM 3
#define MEM_LLENA 2
#define TODO_OK 1
#define ERROR 0

#define TAM_COLA 10000
#define MINIMO(x,y) ((x)<(y)?(x):(y))

typedef struct{
    char cola[TAM_COLA];
    unsigned
            pri,
            ult,
            tamDisp;
}tCola;

void crearCola(tCola *c);
int colaVacia(const tCola* c);
int colaLlena(const tCola* c,unsigned tam);
void vaciarCola(tCola* c);
int encolar(tCola* c, const void* d,unsigned tam);
int sacarCola(tCola* c,void *d,unsigned tam);
int verFrente(tCola* c,void *d,unsigned tam);


#endif // COLAESTATICA_H_INCLUDED
