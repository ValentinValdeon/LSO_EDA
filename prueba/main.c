#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"
#include "envios.h"
#include "LSO.h"
//GRUPO13
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
                fflush(stdin);
                switch(opcMenuOp){
                    case 1:
                        system("cls");
                        cargarEnvio(&lso);
                        break;
                    case 2:
                        system("cls");
                        eliminarEnvioLSO(&lso);
                        getchar();
                        break;
                    case 3:
                        system("cls");
                        modificarEnvio(&lso);
                        break;
                    case 4:
                        system("cls");
                        consultarEnvio(lso);
                        getchar();
                        break;
                    case 5:
                        system("cls");
                        memorizacionPrevia(&lso);
                        break;
                    case 6:
                        system("cls");
                        mostrarEstructura(lso);
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
    int exito,otro = 1,i=0;
    if((*lso).cant == 0){
        printf("No hay envios en el registro\n");
        printf("Presione ENTER para continuar");
        getchar();
    }else{
        while (otro == 1){
            do {
                printf("Ingrese el codigo del envio que desea eliminar \n");
                scanf("%s",codigo);
            }while(strlen(codigo)!= 7);
            for (i=0;i<=8 ; i++)
                codigo[i] = toupper(codigo[i]);
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
    if(lso.cant==0){
        printf("No hay envios en el registro \n");
        printf("Presione ENTER para continuar");
        getchar();
    }else{
        do {
            printf("Ingrese el envio que desea consultar \n");
            scanf("%s",codigo);
        }while(strlen(codigo)!= 7);
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
            printf("Presione ENTER para continuar");
            getchar();
        }else{
            printf("El envio no existe\n");
            printf("Presione ENTER para continuar");
            getchar();
        }
    }
}


void cargarEnvio(lista *lso){
    envio env;
    int i, exito=0;
    char codigo[8];
    fflush(stdin);
    if ((*lso).cant == MAX){
        printf("El registro de envios no tiene espacio \n");
        printf("Presione ENTER para continuar");
        getchar();
    }else{
        do {
            system("cls");
            printf("Ingrese el Codigo (7 caracteres):");
            scanf("%s",codigo);
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

        exito = altaLSO(lso,env);
        if (exito == 1){
            printf("\nEl envio se agrego correctamente \n Presione ENTER para continuar");
            getchar();
        }else{
            printf("\nError al agregar el envio.\nEl envio con ese codigo ya existe.\nPresione ENTER para continuar");
            getchar();
        }
    }
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

void memorizacionPrevia(lista *lso){
    FILE *fp;
    envio env;
    int cantPreCarga=0;

    if((fp = fopen("Envios.txt","r"))==NULL){
        printf("El archivo esta vacio\n");
        printf("Presione ENTER para continuar");
        getchar();
    }else {
        while (!(feof(fp)) && ((*lso).cant) < MAX)
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
    }
    fclose(fp);
}

void modificarEnvio(lista *lso){
    char codigo[8];
    int exito,i;
    if((*lso).cant == 0){
        fflush(stdin);
        printf("No hay envios en el registro \n");
        printf("Presione ENTER para continuar");
        getchar();
    }else{
        do{
            system("cls");
            printf("Ingrese el Codigo (7 caracteres):");
            scanf("%s",codigo);
        }while(strlen(codigo)!= 7);
        for (i=0;i<=8 ; i++)
            codigo[i] = toupper(codigo[i]);
        exito = modificarLSO(codigo,lso);
        if(exito==1){
            printf("El envio se modifico correctamente \n");
            printf("Presione ENTER para continuar");
            getchar();
        }else{
            fflush(stdin);
            printf("El envio no se encuentra en el registro\n");
            printf("Presione ENTER para continuar");
            getchar();
        }
    }
}
