#include <stdio.h>
#include <stdlib.h>
#include "pilaHibrida.h"

void testNumeros(){
    int num,vec[]={5,96,9,4,9};
    tPila pila;
    crearPila(&pila);

    for(int i=0;i<sizeof(vec)/sizeof(int);i++)
        apilar(&pila,vec+i,sizeof(int));
    while( desapilar(&pila,&num,sizeof(int))==TODO_OK ){
        printf("-num:%d ",num);
    }

    for(int i=0;i<sizeof(vec)/sizeof(int);i++)
        apilar(&pila,vec+i,sizeof(int));

    vaciarPila(&pila);

    if(pilaVacia(&pila))
        printf("es pila vacia \n");

}

void testTexto(){
    char texto[100],palabras[5][50]={"miguel","sanchez","espagueti","pizza-napolitana","a"};
    tPila pila;
    crearPila(&pila);
    for(int i=0;i<5;i++)
        apilar(&pila,palabras[i],strlen(palabras[i])+1 );
    while( desapilar(&pila,texto,100)==TODO_OK )
        printf("texto:%s \n",texto);

}

int main()
{
    puts("pila de numeros");
    testNumeros();
    puts("pila de texto");
    testTexto();
    return 0;
}
