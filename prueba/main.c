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

                        getch();
                        break;
                    case 2:
                        eliminarEnvioLSO(&lso);
                        getch();
                        break;
                    case 3:
                        consultarEnvio(lso);
                        getch();
                        break;
                    case 4:
                        getch();
                        break;
                    case 5:
                        getch();
                        break;
                    case 6:
                        getch();
                        break;
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

void eliminarEnvioLSO(lista *lso){
    char codigo[8];
    int exito,otro = 1;
    if((*lso).cant == 0){
        printf("No hay envios\n");
    }else{
        while (otro == 1){
            printf("Ingrese el codigo del envio que desea eliminar \n");
            scanf("%s",codigo);
            exito = bajaLSO(lso,codigo);
            if (exito == 1){
                printf ("El envio se elimino con exito \n");
                printf ("Desea eliminar otro envio? <1>SI <2>NO \n");
                scanf("%d", &otro);
            }else if (exito == 0){
                printf("El envio no existe \n");
                printf ("Desea eliminar otro envio? <1>SI <2> NO \n");
                scanf("%d", &otro);
            }else{
                printf("Se cancelo la eliminacion de su envio\n");
                printf ("Desea eliminar otro envio? <1>SI <2> NO \n");
                scanf("%d", &otro);
            }
        }
    }
}

void consultarEnvio(lista lso){
    char codigo[8];
    envio env;
    int exito;
    printf("Ingrese el envio que desea consultar \n");
    scanf("%s",codigo);
    env = evocacionLSO(codigo, lso, &exito);
    if (exito == 1){
        printf("Codigo: %s\n",env.codigo);
        printf("Documento del Receptor: %d \n",env.documentoRece);
        printf("Nombre y Apellido del Receptor: %s \n",env.nomyapeRece);
        printf("Domicilio del Receptor: %s \n",env.domicilioRece);
        printf("Documento del Remitente: %d \n",env.documentoRemi);
        printf("Nombre y Apellido del Remitente: %s \n",env.nomyapeRemi);
        printf("Fecha de envio: %s \n",env.fechaEnv);
        printf("Fecha de Recepcion: %s \n",env.fechaRece);
    }else{
        printf("El envio no existe");
    }
}
