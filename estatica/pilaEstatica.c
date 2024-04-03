#include "pilaEstatica.h"

void crearPila(tPila *p) {
    p->tope = TAM_PILA;
}

int pilaLlena(const tPila *p, unsigned cantBytes) {
    return p->tope < cantBytes + sizeof(unsigned);
}

int apilar(tPila *p, const void *d, unsigned cantBytes) {
    if (p->tope < cantBytes + sizeof(unsigned))
        return 0;

    p->tope -= cantBytes;
    memcpy(p->pila + p->tope, d, cantBytes);
    p->tope -= sizeof(unsigned);
    memcpy(p->pila + p->tope, &cantBytes, sizeof(unsigned));

    return 1;
}

int verTope(const tPila *p, void *d, unsigned cantBytes) {
    unsigned tamInfo;

    if (p->tope == TAM_PILA)
        return 0;

    memcpy(&tamInfo, p->pila + p->tope, sizeof(unsigned));
    memcpy(d, p->pila + p->tope + sizeof(unsigned), minimo(cantBytes, tamInfo));

    return 1;
}

int pilaVacia(const tPila *p) {
    return p->tope == TAM_PILA;
}

int desapilar(tPila *p, void *d, unsigned cantBytes) {
    unsigned tamInfo;

    if (p->tope == TAM_PILA)
        return 0;

    memcpy(&tamInfo, p->pila + p->tope, sizeof(unsigned));
    p->tope += sizeof(unsigned);
    memcpy(d, p->pila + p->tope, minimo(cantBytes, tamInfo));
    p->tope += tamInfo;

    return 1;
}

void vaciarPila(tPila *p) {
    p->tope = TAM_PILA;
}
