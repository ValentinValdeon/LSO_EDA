#ifndef LSO_H_INCLUDED
#define LSO_H_INCLUDED
#include "envios.h"
#define MAX 300
typedef struct{
    int cant;
    envio arr[MAX];
}lista;
void initLSO(lista *lso){
    int i;
    (*lso).cant=0;
    for(i=0;i<=MAX;i++)
        strcpy((*lso).arr[i].codigo,"0");
}


int localizarLSO(envio elem,lista *lso,int *pos){
    int i=0;
    while(i<=MAX && (*lso).arr[i].codigo<elem.codigo){
        i++;
    }
    *pos=i;
    if (elem.codigo == (*lso).arr[i].codigo){
        return 1;
    }else{
        return 0;
    }
}
int altaLSO(lista *lso,envio env){
    int pos,exito,i;
    exito = localizarLSO(env,lso,&pos);
    if(exito == 0){
            if((*lso).cant<MAX){
                for(i=(*lso).cant-1;i>=pos;i--){
                    (*lso).arr[i+1]=(*lso).arr[i];
                }
                (*lso).arr[pos] = env;
                (*lso).cant++;
                return 1;//exito alta
            }else{
                return 2;//Si esta llena
            }
    }else{
        return 0;//si el elemento esta en la lista
    }
}

#endif // LSO_H_INCLUDED
