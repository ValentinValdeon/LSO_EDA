#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"
#include "envios.h"
#include "LSO.h"
#include "LSOBB.h"
#include "ABB.h"
//GRUPO13
//MARIANO ARBELOA GUGLIELMINO
//VALENTIN VALDEON


void mostrarEstructura(lista lso);
void mostrarEstructuraLSOBB(listabb lsobb);
void memorizacionPrevia(lista *lso);

int main(){
    int opcMenuLista,opcMenuOp;
    lista lso;
    listabb lsobb;
    arbol arbolito;
    initLSO(&lso);
    initLSOBB(&lsobb);
    initABB(&arbolito);
    envio env;
    do{
        system("cls");
        printf("--------------Bienvenido al sistema de ""El Revoleo""-------------- \n\n");
        printf("Seleccione la opcion \n\n");
        printf("--------------------------------------------------------------- \n");
        printf("<1> Lista Secuencial Ordenada con examinacion secuencial(LSO) \n");
        printf("<2> Lista Secuencial Ordenada con busqueda binaria(LSOBB) \n");
        printf("<3> Arbol Binario de Busqueda(ABB) \n");
        printf("<4> Salir del menu\n");
        printf("--------------------------------------------------------------- \n");
        printf("Ingrese una opcion\n");
        scanf("%d",&opcMenuLista);
        if(opcMenuLista<2){
            do{
                system("cls");
                memorizacionPrevia(&lso);
                printf("Seleccione la operacion a realizar\n");
                printf("--------------------------------------------------------------- \n");
                printf("<1> Comparacion de estructuras\n");
                printf("<2> Mostrar todos los envios (LSO)\n");
                printf("<3> Mostrar todos los envios (LSOBB)");
                printf("<4> Mostrar todos los envios (ABB)\n");
                printf("<5> Volver al menu de estructuras\n");
                printf("--------------------------------------------------------------- \n");
                printf("Ingrese una opcion\n");
                scanf("%d",&opcMenuOp);
                fflush(stdin);
                switch(opcMenuOp){
                    case 1:
                        system("cls");

                        break;
                    case 2:
                        system("cls");
                        mostrarEstructura(lso);
                        getchar();
                        break;
                    case 3:
                        system("cls");
                        mostrarEstructuraLSOBB(lsobb);
                        break;
                    case 4:
                        system("cls");
                        preOrden(arbolito.raiz);
                        getchar();
                        break;
                    case 5:
                        system("cls");
                        opcMenuLista==0;
                        break;
                    default:
                        system("cls");
                        printf("-------------------Opcion Incorrecta--------------------\n");
                        printf("------Presione cualquier tecla para volver al menu------");
                        getchar();
                        break;
                }
            }while(opcMenuOp !=5);
        }else if (opcMenuLista == 2){
            system("cls");
            printf("Gracias por utilizar nuestro sistema");
        }else{
            system("cls");
            printf("-------------------Opcion Incorrecta--------------------\n");
            printf("------Presione cualquier tecla para volver al menu------");
            getchar();
        }
    }while(opcMenuLista !=4);
    return 0;
}

void mostrarEstructura(lista lso){
    int i;
    if(lso.cant==0){
        printf("No hay envios en el registro \n");
        printf("Presione ENTER para continuar");
        getchar();
    }else{
        for(i=0;i<=lso.cant-1;i++){
            printf("\n---------------------------------------------------------------");
            printf("\nCodigo del envio: %s", lso.arr[i].codigo);
            printf("\n--------DATOS DEL RECEPTOR--------");
            printf("\nNombre y Apellido: %s", lso.arr[i].nomyapeRece);
            printf("\nDNI: %ld", lso.arr[i].documentoRece);
            printf("\nDomicilio: %s", lso.arr[i].domicilioRece);
            printf("\n--------DATOS DEL REMITENTE--------");
            printf("\nNombre y Apellido: %s", lso.arr[i].nomyapeRemi);
            printf("\nDNI: %ld", lso.arr[i].documentoRemi);
            printf("\n--------DATOS DEL ENVIO--------");
            printf("\nFecha de Envio: %s", lso.arr[i].fechaEnv);
            printf("\nFecha de Llegada: %s", lso.arr[i].fechaRece);
            printf("\nPresione ENTER para continuar");
            getchar();
        }
    }
}

void mostrarEstructuraLSOBB(listabb lsobb){
    int i;
    if(lsobb.cant==0){
        printf("No hay envios en el registro \n");
        printf("Presione ENTER para continuar");
        getchar();
    }else{
        for(i=0;i<=lsobb.cant-1;i++){
            printf("\n---------------------------------------------------------------");
            printf("\nCodigo del envio: %s", lsobb.arr[i].codigo);
            printf("\n--------DATOS DEL RECEPTOR--------");
            printf("\nNombre y Apellido: %s", lsobb.arr[i].nomyapeRece);
            printf("\nDNI: %ld", lsobb.arr[i].documentoRece);
            printf("\nDomicilio: %s", lsobb.arr[i].domicilioRece);
            printf("\n--------DATOS DEL REMITENTE--------");
            printf("\nNombre y Apellido: %s", lsobb.arr[i].nomyapeRemi);
            printf("\nDNI: %ld", lsobb.arr[i].documentoRemi);
            printf("\n--------DATOS DEL ENVIO--------");
            printf("\nFecha de Envio: %s", lsobb.arr[i].fechaEnv);
            printf("\nFecha de Llegada: %s", lsobb.arr[i].fechaRece);
            printf("\nPresione ENTER para continuar");
            getchar();
        }
    }
}

void memorizacionPrevia(lista *lso){
    FILE *fp;
    envio env;
    int cantPreCarga=0, i=0;

    if((fp = fopen("Envios.txt","r"))==NULL){
        printf("El archivo esta vacio\n");
        printf("Presione ENTER para continuar");
        getchar();
    }else {
        while (!(feof(fp)) && ((*lso).cant) < MAX)
        {
            do{
                fscanf(fp," %[^\n]s",env.codigo); //El control obliga que el codigo sea de 7 digitos
            }while(strlen(env.codigo)!= 7);
            for (i=0;i<=8 ; i++)
                env.codigo[i] = toupper(env.codigo[i]);
            fscanf(fp," %ld",&env.documentoRece);
            fscanf(fp," %[^\n]s",env.nomyapeRece);
            fscanf(fp," %[^\n]s",env.domicilioRece);
            fscanf(fp," %ld",&env.documentoRemi);
            fscanf(fp," %[^\n]s",env.nomyapeRemi);
            fscanf(fp," %[^\n]s",env.fechaEnv);
            fscanf(fp," %[^\n]s",env.fechaRece);


            if (altaLSO(lso,env))
            {
                cantPreCarga++;
            }
        }

        if (!(feof(fp)))
        {
            printf("Se llego al limite de Envios, quedaron vendedores sin cargar del archivo.\n");
        }
        printf("Se cargaron correctamente %d envios\n",cantPreCarga);
        printf("En total hay %d envios cargados en la estructura\n",(*lso).cant);
        printf("Presione ENTER para continuar");
        fflush(stdin);
        getchar();
        system("cls");
    }
    fclose(fp);
}

void memorizacionPreviaLSOBB(listabb *lsobb){
    FILE *fp;
    envio env;
    int cantPreCarga=0, i=0;

    if((fp = fopen("Envios.txt","r"))==NULL){
        printf("El archivo esta vacio\n");
        printf("Presione ENTER para continuar");
        getchar();
    }else {
        while (!(feof(fp)) && ((*lsobb).cant) < MAX)
        {
            do{
                fscanf(fp," %[^\n]s",env.codigo); //El control obliga que el codigo sea de 7 digitos
            }while(strlen(env.codigo)!= 7);
            for (i=0;i<=8 ; i++)
                env.codigo[i] = toupper(env.codigo[i]);
            fscanf(fp," %ld",&env.documentoRece);
            fscanf(fp," %[^\n]s",env.nomyapeRece);
            fscanf(fp," %[^\n]s",env.domicilioRece);
            fscanf(fp," %ld",&env.documentoRemi);
            fscanf(fp," %[^\n]s",env.nomyapeRemi);
            fscanf(fp," %[^\n]s",env.fechaEnv);
            fscanf(fp," %[^\n]s",env.fechaRece);


            if (altaLSOBB(lsobb,env))
            {
                cantPreCarga++;
            }
        }

        if (!(feof(fp)))
        {
            printf("Se llego al limite de Envios, quedaron vendedores sin cargar del archivo.\n");
        }
        printf("Se cargaron correctamente %d envios\n",cantPreCarga);
        printf("En total hay %d envios cargados en la estructura\n",(*lsobb).cant);
        printf("Presione ENTER para continuar");
        fflush(stdin);
        getchar();
        system("cls");
    }
    fclose(fp);
}
