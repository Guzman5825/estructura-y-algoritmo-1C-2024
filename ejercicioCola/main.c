#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../estatica/colaEstatica.h"
#include "producto.h"

void crearListaProductos();
void dividirArchivo();



int main()
{
    crearListaProductos();
    dividirArchivo();
    return 0;
}

void dividirArchivo(){
    FILE* archMov=fopen("movStock.bin","rb");
    tProd dato,frente,datoImprimir;
    int cantReg,cantMov=0;

    fseek(archMov,0L,SEEK_END);
    cantReg=ftell(archMov)/sizeof(tProd);
    fseek(archMov,0L,SEEK_SET);

    tCola cola;
    crearCola(&cola);

    for(int i=0;i<cantReg;i++){
        fread(&dato,sizeof(tProd),1,archMov);
        if(colaVacia(&cola)) //si es cola vacia
            encolar(&cola,&dato,sizeof(tProd));//lo agrego a la cola
        else{//else
            verFrente(&cola,&frente,sizeof(tProd));
            if(strcmp(dato.prod,frente.prod)==0){//coincicide con el frente
                encolar(&cola,&dato,sizeof(tProd));//agrego a la cola
                //se le suma a cantMov+=dato.cant
            }
            else{
                //aca habra quje ver los numeros
                //si
                while(!colaVacia(&cola) ){
                    sacarCola(&cola,&datoImprimir,sizeof(tProd) );
                    mostrarProd(&datoImprimir);
                }
                encolar(&cola,&dato,sizeof(tProd));
                cantMov=dato.cant;
            }

        }
        mostrarProd(&dato);
    }

    fclose(archMov);
}


void crearListaProductos(){
FILE *arch=fopen("movStock.bin","wb");
tProd productos[]={ {"a",'e',"x1",10},
                    {"a",'s',"x2",50},
                    {"a",'e',"x3",40},
                    {"a",'e',"x1",10},
                    {"a",'s',"x5",25},
                    {"b",'e',"x2",20},
                    {"b",'e',"x1",10},
                    {"c",'s',"x4",50},
                    {"c",'s',"x2",20},
                    };
fwrite(productos,sizeof(productos),1,arch );
fclose(arch);
}
