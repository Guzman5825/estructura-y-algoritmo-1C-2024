#include "colaEstatica.h"
void crearCola(tCola *c){
    c->tamDisp=TAM_COLA;
    c->pri=0;
    c->ult=0;
}

int colaVacia(const tCola* c){
    return c->tamDisp==TAM_COLA;
}

int colaLlena(const tCola* c,unsigned tam){
    return tam+sizeof(unsigned)>c->tamDisp;
}

void vaciarCola(tCola* c){
    c->tamDisp=TAM_COLA;
    c->pri=c->ult;
}

int encolar(tCola* c, const void* d,unsigned tam){
    int ini,fin;
    //verifico si hay tamanio disponible
    if(tam+sizeof(unsigned)>c->tamDisp)
        return MEM_LLENA;

    c->tamDisp -= tam+sizeof(unsigned);

    ini=MINIMO((TAM_COLA - c->ult),sizeof(unsigned));
    if( ini!=0 )    //si ini >0 entonces hay que copiar algo
        memcpy(c->cola+c->ult,&tam,ini);   //copio la primera parte del dato
    fin= sizeof(unsigned)-ini;
    if( fin!=0 )
        memcpy(c->cola,((char*)&tam)+ini,fin);    //copiar el resto del dato
    c->ult= (fin? fin : c->ult+ini );

    ini=MINIMO( TAM_COLA - c->ult , tam);
    if( ini!=0)
        memcpy(c->cola+c->ult, d , ini);
    fin=tam-ini;
    if(fin!=0)
        memcpy(c->cola,((char*)d)+ini,fin);
    c->ult= (fin? fin : c->ult+ini );

    return TODO_OK;
}

int sacarCola(tCola* c,void *d,unsigned tam){
    int ini,fin;//verificar si hay elementos
    unsigned tamRecup,tamUsar;
    if(c->tamDisp==TAM_COLA)
        return SIN_ELEM;
    ini=MINIMO(sizeof(unsigned),TAM_COLA-c->pri);//calcular ini
    if(ini>0)
        memcpy(&tamRecup,c->cola+c->pri,ini);
    fin=sizeof(unsigned)-ini;
    if(fin>0)
        memcpy( ((char*)&tamRecup)+ini,c->cola,fin );

    c->tamDisp+=(sizeof(unsigned)+tamRecup );//ya da aca se puede calcular el tamanio disponible
    tamUsar=MINIMO(tamRecup,tam);
    c->pri= fin?fin:c->pri+ini;//desplazar la posiicon del frente

    /*recuperar el dato minimo posible( el dato puede que tenga menos espacio)
      ese recuperar, sera nuestro tam dato a usar
      */
    //mismo proceso desde ini
    ini=MINIMO(tamUsar,TAM_COLA-c->pri);
    if(ini>0)
        memcpy(d,c->cola+c->pri,ini);
    fin=tam-ini;
    if(fin>0)
        memcpy(((char*)d)+ini,c->cola,fin);
    c->pri= fin? fin: c->pri+tamRecup;

    return TODO_OK;
}

int verFrente(tCola* c,void *d,unsigned tam){
    int ini,fin,pos=c->pri;//verificar si hay elementos
    unsigned tamRecup,tamUsar;
    if(c->tamDisp==TAM_COLA)
        return SIN_ELEM;
    ini=MINIMO(sizeof(unsigned),TAM_COLA-pos);//calcular ini
    if(ini>0)
        memcpy(&tamRecup,c->cola+pos,ini);
    fin=sizeof(unsigned)-ini;
    if(fin>0)
        memcpy( ((char*)&tamRecup)+ini,c->cola,fin );

    tamUsar=MINIMO(tamRecup,tam);
    pos= fin?fin:pos+ini;//desplazar la posiicon del frente

    /*recuperar el dato minimo posible( el dato puede que tenga menos espacio)
      ese recuperar, sera nuestro tam dato a usar
      */
    //mismo proceso desde ini
    ini=MINIMO(tamUsar,TAM_COLA-pos);
    if(ini>0)
        memcpy(d,c->cola+pos,ini);
    fin=tam-ini;
    if(fin>0)
        memcpy(((char*)d)+ini,c->cola,fin);

    return TODO_OK;

}
