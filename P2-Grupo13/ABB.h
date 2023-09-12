#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED
#include <string.h>
#include <conio.h>
#include "envios.h"
#include <malloc.h>
typedef struct Nodo{
    envio env;
    struct Nodo *der;
    struct Nodo *izq;
}nodo;
typedef struct{
    nodo *raiz;
    nodo *pos;
    nodo *padre;
}arbol;
void initABB(arbol *a){
    (*a).pos=NULL;
    (*a).padre=NULL;
    (*a).raiz=NULL;
}

void preOrden(nodo *a){
if( a == NULL){
    }else{
        printf("%s \n", a->env.codigo);
        printf("%d \n",a->env.documentoRece);
        printf("%s \n",a->env.nomyapeRece);
        printf("%s \n",a->env.domicilioRece);
        printf("%d \n",a->env.documentoRemi);
        printf("%s \n",a->env.nomyapeRemi);
        printf("%s \n",a->env.fechaEnv);
        printf("%s \n",a->env.fechaRece);
        if( a->izq != NULL ){
            printf("\n---------------------------------------------------------------");
            printf("\nEl Codigo de su hijo izquierdo es: %s",a->izq->env.codigo);
        }else{
            printf("\n---------------------------------------------------------------");
            printf("\nNo tiene hijo izquierdo.");
        }

        if(a->der != NULL){
            printf("\n---------------------------------------------------------------");
            printf("\nEl Codigo de su hijo derecho es: %d",a->der->env.codigo);
        }else{
            printf("\n---------------------------------------------------------------");
            printf("\nNo tiene hijo derecho.");
        }
        printf("\n---------------------------------------------------------------");
        getchar();
        preOrden(a->izq);
        preOrden(a->der);
    }
}

#endif // ABB_H_INCLUDED
