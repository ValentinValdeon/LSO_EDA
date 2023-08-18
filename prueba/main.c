#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "envios.h"
#include "LSO.h"
//GRUPO
//MARIANO ARBELOA GUGLIELMINO
//VALENTIN VALDEON
int main(){
    int opcMenuLista,opcMenuOp;
    lista lso;
    initLSO(&lso);
    envio env;
    envio envb;
    initEnvio(&env);
    initEnvio(&envb);
    char codigob[8];
    strcpy(codigob,"AA123CC");
    do{
        system("cls");
        printf("--------------Bienvenido al sistema de ""El Revoleo""-------------- \n\n");
        printf("Seleccione la opcion \n\n");
        printf("--------------------------------------------------------------- \n");
        printf("<1> Lista Secuencial Ordenada(LSO) \n");
        printf("<2> Salir del menu\n");
        printf("--------------------------------------------------------------- \n");
        printf("Ingrese una opcion\n");
        scanf("%d",&opcMenuLista);
        if(opcMenuLista<2){
            do{
                system("cls");
                printf("Seleccione la operacion a realizar\n");
                printf("--------------------------------------------------------------- \n");
                printf("<1> Agregar nuevos envios\n");
                printf("<2> Eliminar envios existentes\n");
                printf("<3> Modificar datos de un envio\n");
                printf("<4> Consultar informacion completa asociada a un envio\n");
                printf("<5> Memorizacion previa\n");
                printf("<6> Mostrar todos los envios\n");
                printf("<7> Volver al menu de estructuras\n");
                printf("--------------------------------------------------------------- \n");
                printf("Ingrese una opcion\n");
                scanf("%d",&opcMenuOp);
                switch(opcMenuOp){
                    case 1:
                        strcpy(env.codigo,"AA123BB");
                        altaLSO(&lso,env);
                        strcpy(envb.codigo,"AA123CC");
                        altaLSO(&lso,envb);
                        strcpy(envb.codigo,"AA123CC");
                        altaLSO(&lso,envb);
                        //printf("%s",env2.codigo);
                        printf("%s \n",lso.arr[0].codigo);
                        printf("%s \n",lso.arr[1].codigo);
                        //printf("%s \n",lso.arr[2].codigo);
                        //printf("%s \n",lso.arr[3].codigo);
                        //printf("%s \n",lso.arr[4].codigo);
                        getch();
                        break;
                    case 2:
                        bajaLSO(&lso,codigob);
                        printf("%s \n",lso.arr[0].codigo);
                        printf("%s \n",lso.arr[1].codigo);
                        //printf("%s \n",lso.arr[2].codigo);
                        //printf("%s \n",lso.arr[3].codigo);
                        //printf("%s \n",lso.arr[4].codigo);
                        getch();
                        break;
                    case 3:

                    case 4:
                    case 5:
                    case 6:
                    case 7:
                        system("cls");
                        opcMenuLista==0;
                        break;
                    default:
                        system("cls");
                        printf("-------------------Opcion Incorrecta--------------------\n");
                        printf("------Presione cualquier tecla para volver al menu------");
                        getch();
                        break;
                }
            }while(opcMenuOp !=7);
        }else if (opcMenuLista == 2){
            system("cls");
            printf("Gracias por utilizar nuestro sistema");
        }else{
            system("cls");
            printf("-------------------Opcion Incorrecta--------------------\n");
            printf("------Presione cualquier tecla para volver al menu------");
            getch();
        }
    }while(opcMenuLista !=2);
}
