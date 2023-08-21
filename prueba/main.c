#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"
#include "envios.h"
#include "LSO.h"
//GRUPO
//MARIANO ARBELOA GUGLIELMINO
//VALENTIN VALDEON

void cargarEnvio(lista *lso);
void mostrarEstructura(lista lso);
void eliminarEnvioLSO(lista *lso);
void consultarEnvio(lista lso);


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
                        cargarEnvio(&lso);
                        getchar();
                        break;
                    case 2:
                        eliminarEnvioLSO(&lso);
                        getchar();
                        break;
                    case 3:
                        consultarEnvio(lso);
                        getchar();
                        break;
                    case 4:
                        getchar();
                        break;
                    case 5:
                        getchar();
                        break;
                    case 6:
                        mostrarEstructura(lso);
                        getchar();
                        break;
                    case 7:
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
    return 0;
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
    int exito,i;
    printf("Ingrese el envio que desea consultar \n");
    scanf("%s",codigo);
    for (i=0;i<=8 ; i++)
        codigo[i] = toupper(codigo[i]);

    env = evocacionLSO(codigo, lso, &exito);
    if (exito == 1){
        printf("Codigo: %s\n",env.codigo);
        printf("Documento del Receptor: %ld \n",env.documentoRece);
        printf("Nombre y Apellido del Receptor: %s \n",env.nomyapeRece);
        printf("Domicilio del Receptor: %s \n",env.domicilioRece);
        printf("Documento del Remitente: %ld \n",env.documentoRemi);
        printf("Nombre y Apellido del Remitente: %s \n",env.nomyapeRemi);
        printf("Fecha de envio: %s \n",env.fechaEnv);
        printf("Fecha de Recepcion: %s \n",env.fechaRece);
    }else{
        printf("El envio no existe");
    }
}


void cargarEnvio(lista *lso){
    envio env;
    int i;
    char codigo[8];

    printf("Ingrese el Codigo :");
    scanf("%[^\n]s",codigo);
    for (i=0;i<=8 ; i++)
        codigo[i] = toupper(codigo[i]);

    strcpy(env.codigo,codigo);
    getchar();

    printf("Ingrese el DNI del receptor:");
    scanf("%ld",&env.documentoRece);
     getchar();

    printf("Ingrese el Nombre y Apellido del receptor :");
    scanf("%[^\n]s",env.nomyapeRece);
     getchar();

    printf("Ingrese el Domicilio del receptor :");
    scanf("%[^\n]s",env.domicilioRece);
     getchar();

    printf("Ingrese el DNI del remitente :");
    scanf("%ld",&env.documentoRemi);
     getchar();

    printf("Ingrese el Nombre y Apellido del remitente :");
    scanf("%[^\n]s",env.nomyapeRemi);
     getchar();

    printf("Ingrese la fecha de envio (formato: DD/MM/AAAA):");
    scanf("%[^\n]s",env.fechaEnv);
     getchar();

    printf("Ingrese la fecha de llegada (formato: DD/MM/AAAA):");
    scanf("%[^\n]s",env.fechaRece);
     getchar();

    if (!altaLSO(lso,env)){
        printf("\nError al agregar el envio.\nPuede que la lista este llena o el envio con ese codigo ya existe.\nPresione ENTER para continuar");
        getchar();
    }
}

void mostrarEstructura(lista lso){
    int i,resp=0;
    for(i=0;i<=(lso.cant-1);i++){
        printf("\n---------------------------------------------------------------");
        printf("\nCodigo del envio: %s", lso.arr[i].codigo);
        printf("\n--------DATOS DEL REMITENTE--------");
        printf("\nNombre y Apellido: %s", lso.arr[i].nomyapeRemi);
        printf("\nDNI: %ld", lso.arr[i].documentoRemi);
        printf("\n--------DATOS DEL RECEPTOR--------");
        printf("\nNombre y Apellido: %s", lso.arr[i].nomyapeRece);
        printf("\nDNI: %ld", lso.arr[i].documentoRece);
        printf("\nDomicilio: %s", lso.arr[i].domicilioRece);
        printf("\n--------DATOS DEL ENVIO--------");
        printf("\nFecha de Envio: %s", lso.arr[i].fechaEnv);
        printf("\nFecha de Llegada: %s", lso.arr[i].fechaRece);
        printf("\n---------------------------------------------------------------");
        getchar();
        printf("\n<1> Seguir mostrando \n");
        printf("\n<2> Salir al menu\n");
        printf("\n--------------------------------------------------------------- ");
        printf("\nIngrese una opcion: ");
        scanf("%d",&resp);
        system("cls");
        if (resp==2)
            i=lso.cant;
    }
}
