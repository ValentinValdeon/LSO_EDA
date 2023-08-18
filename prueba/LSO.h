#ifndef LSO_H_INCLUDED
#define LSO_H_INCLUDED
#include "envios.h"
#define MAX 2
typedef struct{
    int cant;
    envio arr[MAX];
}lista;
void initLSO(lista *lso){
    int i;
    (*lso).cant=0;
    for(i=0;i<=MAX;i++)
        strcpy((*lso).arr[i].codigo,"z");
}


int localizarLSO(char cod[],lista *lso,int *pos){
    int i=0;
    int b;
    while(i<=MAX && (strcmp((*lso).arr[i].codigo,cod)<0)){
        i++;
    }
    (*pos)=i;
    if ((strcmp((*lso).arr[i].codigo,cod)==0)){
        printf("Te encontre puto");
        return 1;
    }else{
        return 0;
    }
}

int altaLSO(lista *lso,envio env){
    int pos,exito,i;
    exito = localizarLSO(env.codigo,lso,&pos);
    if(exito == 0){
        if((*lso).cant==0){
            (*lso).arr[pos] = env;
            (*lso).cant++;
            return 1; //exito alta, caso especial
        }else{
            if((*lso).cant<MAX){
                for(i=(*lso).cant;i>=pos;i--){
                    (*lso).arr[i+1]=(*lso).arr[i];
                }
                (*lso).arr[pos] = env;
                (*lso).cant++;
                return 1;//exito alta
            }else{
                return 2;//Si esta llena
            }
        }
    }else{
        return 0;//si el elemento esta en la lista
    }
}

int bajaLSO(lista *lso,char codigo[]){
    int pos,exito,i,confirmar=0;
    exito=localizarLSO(codigo,lso,&pos);
    if(exito == 1){
        printf("Envio N: %d \n",pos+1);
        printf("Codigo: %s \n",(*lso).arr[pos].codigo);
        printf("Documento del receptor: %d \n",(*lso).arr[pos].documentoRece);
        printf("Nombre y Apellido del receptor: %s \n",(*lso).arr[pos].nomyapeRece);
        printf("Domicilio del receptor: %s \n",(*lso).arr[pos].domicilioRece);
        printf("Documento del remitente: %d \n",(*lso).arr[pos].documentoRemi);
        printf("Nombre y Apellido del remitente: %s \n",(*lso).arr[pos].nomyapeRemi);
        printf("Fecha de envio: %s \n",(*lso).arr[pos].fechaEnv);
        printf("Fecha de recepcion: %s \n",(*lso).arr[pos].fechaRece);
        printf("Desea eliminar este envio? <1>Si <2>No \n");
        scanf("%d",&confirmar);
        while(confirmar < 1 || confirmar > 2){
            printf("Ingrese una opcion correcta <1>SI <2>NO");
            scanf("%d",&confirmar);
        }
        if(confirmar==1){
            /*if((*lso).cant == MAX && pos == (*lso).cant-1){ //Pregunta por el if de LISTA LLENA
                strcpy((*lso).arr[pos].codigo,"0");
            }else{*/
                for(i=pos;i<(*lso).cant;i++){
                    (*lso).arr[i]=(*lso).arr[i+1];
                }
                strcpy((*lso).arr[(*lso).cant].codigo,"z");
            //}
            (*lso).cant--;
            return 1; //Baja exitosa
        }else{
            return 2;
        }
    }else{
        return 0; //el elemento no se encuentra en la lista
    }
}

envio evocacionLSO(char cod[], lista lso,int *exito){
    int pos;
    *exito = localizarLSO(cod,&lso,&pos);
    if(*exito == 1)
        return lso.arr[pos];
}

#endif // LSO_H_INCLUDED
