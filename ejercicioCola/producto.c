#include "producto.h"

void mostrarProd(const void* prod){
const tProd* p=prod;
printf("%s-%c-%s-%d\n",p->prod,p->mov,p->dept,p->cant);
}
