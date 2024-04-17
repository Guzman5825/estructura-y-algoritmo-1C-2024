#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "../dinamica/pilaDinamica.h"

typedef int (*Cmp) (const void*,const void*);
typedef void (*Mostrar) (const void*);

int cmpInt(const void * n1,const void *n2);
void imprimirDatoNumero(const void* dato);

void crearArchivoNumeros();
void ejercicio6();
int ejercicio6_cargarArchPilaOrd(char* nombreArch,tPila* pilaOrd,unsigned tam,Cmp cmp);
void desapilarYmostrarDatos(tPila* p,Mostrar fMostrar);
void ejercicio7();

#endif // FUNCIONES_H_INCLUDED
