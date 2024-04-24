#include "colaDinamica.h"

void crearCola(tCola *c){
    c->pri=NULL;
    c->ult=NULL;
}

int colaVacia(const tCola* c){
    return c->pri==NULL;
}

int colaLlena(const tCola* c,unsigned tam){
    //pedir memoria
    tNodo* nodo=malloc(sizeof(tNodo) );
    void* dato= malloc(sizeof(tam) );
    free(nodo);
    free(dato);
    return nodo==NULL || dato==NULL;
}

void vaciarCola(tCola* c){
    tNodo* nae;
    while(c->pri!=NULL){
        nae=c->pri;
        c->pri=nae->sig;
        free(nae->dato);
        free(nae);
    }
    c->ult=NULL;
}

int encolar(tCola* c, const void* d,unsigned tam){
    //ver si hay espacio
    tNodo* nue=malloc(sizeof(tNodo) );
    if(nue==NULL)
        return MEM_LLENA;
    nue->dato=malloc(tam);
    if(nue->dato==NULL){
        free(nue);
        return MEM_LLENA;
    }
    //copiar los datos del nue
    memcpy(nue->dato,d,tam);
    nue->tam=tam;
    nue->sig=NULL;
    //conectarlo
    if(c->ult==NULL){   //si es primer nodo
        c->pri=nue;
        c->ult=nue;
    }else{
        c->ult->sig=nue;
        c->ult=nue;
    }

    return TODO_OK;
}

int sacarCola(tCola* c,void *d,unsigned tam){
    tNodo* nae;
    //tengo que fijarme si hay un elemento
    if(c->pri==NULL)
        return SIN_ELEM;
    //copiar datos
    nae=c->pri;
    memcpy(d,nae->dato,MINIMO(nae->tam,tam));
    //desconectar nodo
    if(nae->sig==NULL){//caso que sea el ultimo nodo
        c->ult=NULL;
        c->pri=NULL;
    } else
        c->pri=nae->sig;
    //liberar nodo
    free(nae->dato);
    free(nae);
    return TODO_OK;
}

int verFrente(tCola* c,void *d,unsigned tam){
    tNodo* nodo=c->pri;
    if(c->pri==NULL)
        return SIN_ELEM;
    memcpy(d,nodo->dato,MINIMO(nodo->tam,tam));
    return TODO_OK;
}

