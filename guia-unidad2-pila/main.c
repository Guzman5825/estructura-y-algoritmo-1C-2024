#include <stdio.h>
#include <stdlib.h>
#include "../estatica/pilaEstatica.h"

void imprimirDatoNumero(void* dato){
printf("%d ", *((int*)dato) );
}

void desapilarYmostrarDatos(tPila* p){
int dato;
while(!pilaVacia(p)){
    desapilar(p,&dato,sizeof(int) );
    imprimirDatoNumero(&dato);
}
}

int cmpInt(void * n1,void *n2){
int* num1=(int*) n1;
int* num2=(int*) n2;
return *num1-*num2;
}


void ejercicio6(){
    // estrategia, utilizar 2 pila, 1 cargada con los valores,  la otra como una pila auxiliar ,mandadole a la pila auxiliar
    //los valores o datos menores , creando asi en la pila auxiliar en donde cada vez se posicion a lo ultimo de la pila los valores menores
    int numeros [10]={10,5,9,1,15,12,19,20,21,13};

    tPila pila1,pilaAux;

    crearPila(&pila1);
    crearPila(&pilaAux);

    for(int i=0;i<10 && !pilaLlena(&pila1,sizeof(int) ) ;i++)
        apilar(&pila1,&(numeros[i]) ,sizeof(int) );

    int datoComparacion,datoAMover;

    if(!pilaVacia(&pila1)){ //el primer dato
        desapilar(&pila1,&datoAMover,sizeof(int) ); // se puede meter pila llena
        apilar(&pila1,&datoAMover,sizeof(int));
    }
    //////////////////////////////
    while(!pilaVacia(&pila1)){  //entra en el bucle
        desapilar(&pila1,&datoComparacion,sizeof(int) );

        verTope(&pilaAux,&datoAMover,sizeof(int) );

        while(!pilaVacia(&pilaAux) && cmpInt(&datoComparacion,&datoAMover)<=0){
            //imprimirDatoNumero(&datoAMover);
            desapilar(&pilaAux,&datoAMover,sizeof(int) );
            apilar(&pila1,&datoAMover,sizeof(int));     //lo mismo pila llena aca tambien
            verTope(&pilaAux,&datoAMover,sizeof(int) );
        }

        apilar(&pilaAux,&datoComparacion,sizeof(int) ); //y aca tambien pila llena

    }

    puts("valores ordenados:");
    desapilarYmostrarDatos(&pilaAux);
}



void ejercicio7(){
char num1[50]="1234564567897891234567899654654654";  //esto se podria pedir por teclado;
char num2[50]="1241454654165161231321531";
tPila pila1;
tPila pila2;
crearPila(&pila1);
crearPila(&pila2);

char* pNum=num1;

while(*pNum!='\0' && !pilaLlena(&pila1,sizeof(int)) ){
    int dato=*pNum-'0';
    apilar(&pila1,&dato,sizeof(int));
    pNum++;
    }

if(*pNum!='\0'){     //si no llego al final del dato, retornar
    puts("error, memoria llena");
    vaciarPila(&pila1);
    return;
    }
//desapilarYmostrarDatos(&pila1);
pNum=num2;
while(*pNum!='\0' && !pilaLlena(&pila2,sizeof(int)) ){
    int dato=*pNum-'0';
    apilar(&pila2,&dato,sizeof(int));
    pNum++;
    }

if(*pNum!='\0'){     //si no llego al final del dato, retornar
    puts("error, memoria llena");
    vaciarPila(&pila1);
    vaciarPila(&pila2);
    return;
    }
//desapilarYmostrarDatos(&pila2);

int acarreo=0,n1,n2,nRes;

tPila pilaResultado;
crearPila(&pilaResultado);

while( !pilaVacia(&pila1) && !pilaVacia(&pila2) ){
    desapilar(&pila1,&n1,sizeof(int) );
    desapilar(&pila2,&n2,sizeof(int) );
    if( (n1+n2+acarreo) >= 10){
        nRes=n1+n2+acarreo-10;
        acarreo=1;
    }else{
        nRes=n1+n2+acarreo;
        acarreo=0;
    }
    apilar(&pilaResultado,&nRes,sizeof(int) );

    }

while( !pilaVacia(&pila1) && pilaVacia(&pila2) ){
    desapilar(&pila1,&n1,sizeof(int) );
    if( (n1+acarreo)>=10 ){
        nRes=n1+acarreo-10;
        acarreo=1;
        }else{
        nRes=n1+acarreo;
        acarreo=0;
        }
    apilar(&pilaResultado,&nRes,sizeof(int) );
    }
while( pilaVacia(&pila1) && !pilaVacia(&pila2) ){
    desapilar(&pila2,&n2,sizeof(int) );
    if( (n2+acarreo)>=10 ){
        nRes=n2+acarreo-10;
        acarreo=1;
        }else{
        nRes=n2+acarreo;
        acarreo=0;
    }
    apilar(&pilaResultado,&nRes,sizeof(int) );
    }

if(acarreo==1)  //si quedo un ultimo acarreo , entonces eso se lo incluye al dato
    apilar(&pilaResultado,&acarreo,sizeof(int) );

printf("%s + %s : ",num1,num2);
desapilarYmostrarDatos(&pilaResultado);     //aca los vacia
puts("");
}

int main()
{
    //ejercicio6();
    ejercicio7();
    return 0;
}
