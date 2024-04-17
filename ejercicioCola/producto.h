#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define PROD_MAX 7
#define DEPT_MAX 4

typedef struct{
    char prod[PROD_MAX];
    char mov;
    char dept[DEPT_MAX];
    int cant;
}tProd;

void mostrarProd(const void* prod);

#endif // PRODUCTO_H_INCLUDED
