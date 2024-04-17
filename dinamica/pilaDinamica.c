#include "pilaDinamica.h"

void crearPila(tPila *p){
    *p=NULL;
}

int pilaVacia(const tPila *p){
    return *p==NULL;
}

int pilaLlena(const tPila *p,unsigned tam){
    void* nue=malloc(sizeof(tNodo) );
    void* dato=malloc(tam);
    free(nue);
    free(dato);
    return nue==NULL || dato==NULL;
}

int apilar(tPila* p,const void *d,unsigned tam){
    //ver si hay memoria
    tNodo* nue=malloc(sizeof(tNodo));
    if(nue==NULL)
        return SIN_MEM;
    nue->dato=malloc(tam);
    if(nue->dato==NULL){
        free(nue);
        return SIN_MEM;
    }
    //copio la imformacion del dato
    memcpy(nue->dato,d,tam);
    nue->tam=tam;
    //conecto al nodo al tope de la pila
    nue->sig=*p;
    //pila apunte al nuevo nodo
    *p=nue;
    return TODO_OK;
}

int desapilar(tPila* p,void *d,unsigned tam){
    tNodo* nae;
    //verificar si existe un nodo
    if(*p==NULL)
        return SIN_ELEM;
    //copio los datos
    nae=*p;
    memcpy(d,nae->dato,MINIMO(tam,nae->tam ) );
    //desconecto el nodo
    *p=nae->sig;
    //borro el nodo y el dato
    free(nae->dato);
    free(nae);

    return TODO_OK;
}

void vaciarPila(tPila *p){
    tNodo* nae;
    //mientras pila no este vacia borrar nodos y datos
    while(*p!=NULL){
        nae=*p;
        *p=nae->sig;
        free(nae->sig);
        free(nae);
    }
    //y dejar en como si fuera usarlo en crear pila
    *p=NULL;
}

int verTope(tPila* p,void *d,unsigned tam){
    //necesito copiar obtener los datos del tope
    //pregunto hay elemento
    if(*p==NULL)
        return SIN_ELEM;
    //si hay elemento , copio solamente el dato el dato del tope
    memcpy(d,(*p)->dato,MINIMO(tam,(*p)->tam));
    return TODO_OK;
}
