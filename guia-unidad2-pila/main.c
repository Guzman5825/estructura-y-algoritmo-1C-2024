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
    int topeOrd,topeAux, numeros [10]={10,5,9,1,15,12,19,20,21,13};


    tPila pilaOrd,pilaAux;


    crearPila(&pilaOrd);
    crearPila(&pilaAux);

    for(int i=0;i<10;i++){    //poner la condicion de pila llena
        verTope(&pilaOrd,&topeOrd,sizeof(int));
        while(!pilaVacia(&pilaOrd) && numeros[i]<topeOrd){  //condicion de pila vacia
            desapilar(&pilaOrd,&topeOrd,sizeof(int));
            apilar(&pilaAux,&topeOrd,sizeof(int));
            verTope(&pilaOrd,&topeOrd,sizeof(int));
            }
        verTope(&pilaAux,&topeAux,sizeof(int));
        while(!pilaVacia(&pilaAux) &&numeros[i]>topeAux){
            desapilar(&pilaAux,&topeAux,sizeof(int));
            apilar(&pilaOrd,&topeAux,sizeof(int));
            verTope(&pilaAux,&topeAux,sizeof(int));
            }
        apilar(&pilaOrd,&numeros[i],sizeof(int));
        }


    while(!pilaVacia(&pilaAux)){        //los elementos restantes de la pila auxiliar
        desapilar(&pilaAux,&topeAux,sizeof(int));
        apilar(&pilaOrd,&topeAux,sizeof(int));
    }

    puts("valores ordenados:");
    desapilarYmostrarDatos(&pilaOrd);
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
    puts("ejercicio 6");
    ejercicio6();
    /**
    puts("\nejercicio 7");
    ejercicio7();
    */
    return 0;
}
