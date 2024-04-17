#ifndef PILADINAMICA_H_INCLUDED
#define PILADINAMICA_H_INCLUDED

#include <stdlib.h>
#include <string.h>

#define MINIMO(x,y) ((x)<(y)?(x):(y))

#define SIN_ELEM 3
#define SIN_MEM 2
#define TODO_OK 1
#define ERROR 0

typedef struct sNodo{
    void *dato;
    unsigned tam;
    struct sNodo *sig;
}tNodo;

typedef tNodo* tPila;

void crearPila(tPila *p);
int pilaVacia(const tPila *p);
int pilaLlena(const tPila* p,unsigned tam);
int apilar(tPila* p,const void *d,unsigned tam);
int desapilar(tPila* p,void *d,unsigned tam);
int verTope(tPila* p,void *d,unsigned tam);
void vaciarPila(tPila *p);


#endif // PILADINAMICA_H_INCLUDED
