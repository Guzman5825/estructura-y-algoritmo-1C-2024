#include "funciones.h"

void imprimirDatoNumero(const void* dato)
{
    printf("%d ", *((int*)dato) );
}

void desapilarYmostrarDatos(tPila* p,Mostrar fMostrar)
{
    int dato;
    while(!pilaVacia(p))
    {
        desapilar(p,&dato,sizeof(int) );
        fMostrar(&dato);
    }
}

int cmpInt(const void * n1,const void *n2)
{
    int* num1=(int*) n1;
    int* num2=(int*) n2;
    return *num1-*num2;
}

void crearArchivoNumeros(char* nombreArch)
{
    FILE* arch=fopen(nombreArch,"wb");
    int numeros[]= {9,2,11,13,1};
    fwrite(numeros,sizeof(numeros),1,arch );
    fclose(arch);
}


void ejercicio6()
{
    int topeOrd,topeAux, numeros []= {10,5,9,20,1,1,15,12,19,20,20,21,13};
    tPila pilaOrd,pilaAux;

    crearPila(&pilaOrd);
    crearPila(&pilaAux);

    for(int i=0; i<sizeof(numeros)/sizeof(int); i++)
    {
        verTope(&pilaOrd,&topeOrd,sizeof(int));
        while(!pilaVacia(&pilaOrd) && numeros[i]<topeOrd)
        {
            desapilar(&pilaOrd,&topeOrd,sizeof(int));
            apilar(&pilaAux,&topeOrd,sizeof(int));
            verTope(&pilaOrd,&topeOrd,sizeof(int));
        }
        verTope(&pilaAux,&topeAux,sizeof(int));
        while(!pilaVacia(&pilaAux) &&numeros[i]>topeAux)
        {
            desapilar(&pilaAux,&topeAux,sizeof(int));
            apilar(&pilaOrd,&topeAux,sizeof(int));
            verTope(&pilaAux,&topeAux,sizeof(int));
        }
        apilar(&pilaOrd,&numeros[i],sizeof(int));
    }


    while(!pilaVacia(&pilaAux))         //los elementos restantes de la pila auxiliar
    {
        desapilar(&pilaAux,&topeAux,sizeof(int));
        apilar(&pilaOrd,&topeAux,sizeof(int));
    }

    puts("valores ordenados:");
    desapilarYmostrarDatos(&pilaOrd,imprimirDatoNumero);
}

int ejercicio6_cargarArchPilaOrd(char* nombreArch,tPila* pilaOrd,unsigned tam,Cmp cmp){
    tPila pilaAux;
    int cantReg,dato,topeOrd,topeAux;
    FILE* arch=fopen(nombreArch,"rb");
    if(arch==NULL)
        return 0;
    fseek(arch,0L,SEEK_END);
    cantReg=ftell(arch)/tam;
    fseek(arch,0L,SEEK_SET);

    crearPila(&pilaAux);

    for(int i=0;i<cantReg;i++){
        fread(&dato,tam,1,arch );
        verTope(pilaOrd,&topeOrd,tam);
        while(!pilaVacia(pilaOrd) && cmp(&topeOrd,&dato)<0) {
            desapilar(pilaOrd,&topeOrd,tam);
            apilar(&pilaAux,&topeOrd,tam);
            verTope(pilaOrd,&topeOrd,tam);
        }
        verTope(pilaOrd,&topeAux,tam);
        while(!pilaVacia(&pilaAux) && cmp(&dato,&topeAux)<0 ){
            desapilar(&pilaAux,&topeAux,tam);
            apilar(pilaOrd,&topeAux,tam);
            verTope(&pilaAux,&topeAux,tam);
        }
        apilar(pilaOrd,&dato,tam);
    }

    while(!pilaVacia(&pilaAux))         //los elementos restantes de la pila auxiliar
    {
        desapilar(&pilaAux,&topeAux,tam);
        apilar(pilaOrd,&topeAux,tam);
    }

    fclose(arch);

    return 1;   //para decir que termino bien
}


void ejercicio7()
{
    char num1[50]="1234564567897891234567899654654654";  //esto se podria pedir por teclado;
    char num2[50]="1241454654165161231321531";
    tPila pila1;
    tPila pila2;
    crearPila(&pila1);
    crearPila(&pila2);

    char* pNum=num1;

    while(*pNum!='\0' && !pilaLlena(&pila1,sizeof(int)) )
    {
        int dato=*pNum-'0';
        apilar(&pila1,&dato,sizeof(int));
        pNum++;
    }

    if(*pNum!='\0')      //si no llego al final del dato, retornar
    {
        puts("error, memoria llena");
        vaciarPila(&pila1);
        return;
    }
//desapilarYmostrarDatos(&pila1);
    pNum=num2;
    while(*pNum!='\0' && !pilaLlena(&pila2,sizeof(int)) )
    {
        int dato=*pNum-'0';
        apilar(&pila2,&dato,sizeof(int));
        pNum++;
    }

    if(*pNum!='\0')      //si no llego al final del dato, retornar
    {
        puts("error, memoria llena");
        vaciarPila(&pila1);
        vaciarPila(&pila2);
        return;
    }
//desapilarYmostrarDatos(&pila2);

    int acarreo=0,n1,n2,nRes;

    tPila pilaResultado;
    crearPila(&pilaResultado);

    while( !pilaVacia(&pila1) && !pilaVacia(&pila2) )
    {
        desapilar(&pila1,&n1,sizeof(int) );
        desapilar(&pila2,&n2,sizeof(int) );
        if( (n1+n2+acarreo) >= 10)
        {
            nRes=n1+n2+acarreo-10;
            acarreo=1;
        }
        else
        {
            nRes=n1+n2+acarreo;
            acarreo=0;
        }
        apilar(&pilaResultado,&nRes,sizeof(int) );

    }

    while( !pilaVacia(&pila1) && pilaVacia(&pila2) )
    {
        desapilar(&pila1,&n1,sizeof(int) );
        if( (n1+acarreo)>=10 )
        {
            nRes=n1+acarreo-10;
            acarreo=1;
        }
        else
        {
            nRes=n1+acarreo;
            acarreo=0;
        }
        apilar(&pilaResultado,&nRes,sizeof(int) );
    }
    while( pilaVacia(&pila1) && !pilaVacia(&pila2) )
    {
        desapilar(&pila2,&n2,sizeof(int) );
        if( (n2+acarreo)>=10 )
        {
            nRes=n2+acarreo-10;
            acarreo=1;
        }
        else
        {
            nRes=n2+acarreo;
            acarreo=0;
        }
        apilar(&pilaResultado,&nRes,sizeof(int) );
    }

    if(acarreo==1)  //si quedo un ultimo acarreo , entonces eso se lo incluye al dato
        apilar(&pilaResultado,&acarreo,sizeof(int) );

    printf("%s + %s : ",num1,num2);
    desapilarYmostrarDatos(&pilaResultado,imprimirDatoNumero);     //aca los vacia
    puts("");
}
