#ifndef COLADINAMICA_H_INCLUDED
#define COLADINAMICA_H_INCLUDED
#include <stdlib.h>
#include <string.h>

#define SIN_ELEM 3
#define MEM_LLENA 2
#define TODO_OK 1
#define ERROR 0

#define MINIMO(x,y) ((x)<(y)?(x):(y))

typedef struct sNodo{
    void* dato;
    unsigned tam;
    struct sNodo *sig;
}tNodo;

typedef struct{
    tNodo* pri;
    tNodo* ult;
}tCola;

void crearCola(tCola *c);
int colaVacia(const tCola* c);
int colaLlena(const tCola* c,unsigned tam);
void vaciarCola(tCola* c);
int encolar(tCola* c, const void* d,unsigned tam);
int sacarCola(tCola* c,void *d,unsigned tam);
int verFrente(tCola* c,void *d,unsigned tam);

#endif // COLADINAMICA_H_INCLUDED
