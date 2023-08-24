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
void modificarEnvio(lista *lso);
void memorizacionPrevia(lista *lso);

int main(){
    int opcMenuLista,opcMenuOp;
    lista lso;
    initLSO(&lso);
    envio env;
    strcpy(env.codigo,"AABBCC1");
    strcpy(env.domicilioRece,"por ahi");
    strcpy(env.fechaEnv,"11/11/1111");
    strcpy(env.fechaRece,"11/11/1111");
    strcpy(env.nomyapeRece,"Pepe");
    strcpy(env.nomyapeRemi,"Papa");
    env.documentoRece = 111111;
    env.documentoRemi = 111111;

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
                        modificarLSO(env,&lso);
                        getchar();
                        break;
                    case 4:
                        consultarEnvio(lso);
                        getchar();
                        break;
                    case 5:
                        memorizacionPrevia(&lso);
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
            getchar();
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

    fflush(stdin);
    do {
        printf("Ingrese el Codigo (7 caracteres):");
        scanf("%[^\n]s",codigo);
        system("cls");
    }while(strlen(codigo)!= 7);

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
    int i,j,cant=0,resp=0;
    system("cls");
    for(i=0;i<=(lso.cant-1)/3;i++){
        for (j=cant;j<(3+cant);j++ ){
            printf("\n---------------------------------------------------------------");
            printf("\nCodigo del envio: %s", lso.arr[j].codigo);
            printf("\n--------DATOS DEL REMITENTE--------");
            printf("\nNombre y Apellido: %s", lso.arr[j].nomyapeRemi);
            printf("\nDNI: %ld", lso.arr[j].documentoRemi);
            printf("\n--------DATOS DEL RECEPTOR--------");
            printf("\nNombre y Apellido: %s", lso.arr[j].nomyapeRece);
            printf("\nDNI: %ld", lso.arr[j].documentoRece);
            printf("\nDomicilio: %s", lso.arr[j].domicilioRece);
            printf("\n--------DATOS DEL ENVIO--------");
            printf("\nFecha de Envio: %s", lso.arr[j].fechaEnv);
            printf("\nFecha de Llegada: %s", lso.arr[j].fechaRece);
            printf("\n---------------------------------------------------------------");
        }
            cant+=3;
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
    if (resp != 2){
        printf("Se termino la estructura. Presione ENTER para volver al menu.");
        getchar();
    }
}

void memorizacionPrevia(lista *lso){
    FILE *fp;
    envio env;
    int cantPreCarga=0;

    if((fp = fopen("Envios.txt","r"))==NULL){
        printf("El txt esta vacio\n");
        getchar();
        //return 0;
    }else {
        while (!(feof(fp)) && ((*lso).cant) < MAX-1)
        {
            fscanf(fp," %[^\n]s",env.codigo);
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
        //return 1;
    }
    fclose(fp);
}
