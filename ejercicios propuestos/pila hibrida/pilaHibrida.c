#include "pilaHibrida.h"

void crearPila(tPila* p){
    p->vec=NULL;
    p->tope=0;
}

int pilaVacia(tPila* p){
    return p->tope==0;
}

int pilaLlena(const tPila* p,const void* d,unsigned tam){
    void* aux;
    aux=realloc(p->vec,p->tope+tam+sizeof(unsigned));
    realloc(p->vec,p->tope);
    return aux==NULL;
}

int apilar(tPila* p,const void* d,unsigned tam){
    //ver si hay espacio con realloc , luego preguntar
    if(p->tope==0){
        if( (p->vec=malloc(tam+sizeof(unsigned)))==NULL )
            return SIN_MEM;
        }
    else
        if( realloc(p->vec,p->tope+tam+sizeof(unsigned) ) ==NULL )
            return SIN_MEM;
    //primer se copia el espacio y luego mover el tope
    memcpy(p->vec+p->tope,d,tam);
    p->tope+=tam;
    memcpy(p->vec+p->tope,&tam,sizeof(unsigned) );
    p->tope+=sizeof(unsigned);
    return TODO_OK;
}

int desapilar(tPila* p,void* d,unsigned tam){
    unsigned tamInfoPila;

    if(p->tope==0)
        return SIN_ELEM;

    p->tope-=sizeof(unsigned);
    memcpy(&tamInfoPila,p->vec+p->tope,sizeof(unsigned));
    p->tope-=tamInfoPila;
    memcpy(d,p->vec+p->tope,MINIMO(tam,tamInfoPila));

    realloc(p->vec,p->tope);
    return TODO_OK;
}

int varTope(const tPila* p,void* d,unsigned tam){
    unsigned tamInfoPila;
    if(p->tope==0)
        return SIN_ELEM;
    memcpy(&tamInfoPila, p->vec+p->tope-sizeof(unsigned), sizeof(unsigned));
    memcpy(d,p->vec+p->tope-tamInfoPila-sizeof(unsigned), MINIMO(tam,tamInfoPila));
    return TODO_OK;
}

void vaciarPila(tPila* p){
    free(p->vec);
    p->tope=0;
}
