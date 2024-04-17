#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    tPila pila;
    crearPila(&pila);
    crearArchivoNumeros();
    puts("ejercicio 6");
    ejercicio6_cargarArchPilaOrd("archNum.bin",&pila,sizeof(unsigned),cmpInt);
    desapilarYmostrarDatos(&pila,imprimirDatoNumero);

    vaciarPila(&pila);

   // puts("\nejercicio 7");
    //ejercicio7();

    return 0;
}
