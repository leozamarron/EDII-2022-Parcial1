/*
Objetivo: arreglo bidimensional dinámico de estructuras cliente.
Autor: LZR
Fecha: 12/06/2022
Nota(s): Tipo CLIENTE
*/

typedef struct
{
    char clave[5];
    char nombre[25];
    char tipoCliente;
    float totalComprado, totalPagar;
    char compraFrecuente;
}CLIENTE;


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void scanRC(int *R, int *C);
int asignMem(CLIENTE ***ptrArrBi, int nR, int nC);
void scanArr(CLIENTE **ptrArrBi, int nR, int nC);
void showArr(CLIENTE **ptrArrBi, int nR, int nC);
void calculaCompra(CLIENTE **ptrArrBi, int nR, int nC);
void cleanMry(CLIENTE **ptrArrBi, int nR);

int main()
{
    CLIENTE **ptrArrayBi;
    int ret, renglones, columnas;

    scanRC(&renglones, &columnas);
    ret = asignMem(&ptrArrayBi, renglones, columnas);
    if (ret == 1)
    {
        scanArr(ptrArrayBi, renglones, columnas);
        showArr(ptrArrayBi, renglones, columnas);
        calculaCompra(ptrArrayBi, renglones, columnas);
        showArr(ptrArrayBi, renglones, columnas);
        cleanMry(ptrArrayBi, renglones);
    }
    else
        printf("No hay memoria");

    return 0;
}

void scanRC(int *R, int *C)
{
    printf("Dame el tamano de los renglones: ");
    scanf("%d", R);
    printf("Dame el tamano de las columnas: ");
    scanf("%d", C);
}

int asignMem(CLIENTE ***ptrArrBi, int nR, int nC)
{
    int res = 0;
    int i;

    *ptrArrBi = (CLIENTE**)malloc(nR * sizeof(CLIENTE*)); 
    if(*ptrArrBi)
    {
        res = 1;
        for (i = 0; i < nR; i++)
        {
            *(*ptrArrBi+i) = (CLIENTE*)malloc(nC * sizeof(CLIENTE)); 
            if (!*(*ptrArrBi+i))
            {
                res = 0;
                while (--i >= 0)
                    free(*(*ptrArrBi+i));
                free(*ptrArrBi);
            }
        }
    }
    return res; 
}

void scanArr(CLIENTE **ptrArrBi, int nR, int nC)
{
    int i, j;
    for (j = 0; j < nR; j++)
    {
        for (i = 0; i < nC; i++)
        {
            fflush(stdin);
            printf ("Introduzca la clave: ");
            gets((*(ptrArrBi+j)+i)->clave);
            printf ("Introduzca el nombre: ");
            gets((*(ptrArrBi+j)+i)->nombre);
            printf("Introduzca el tipo de cliente, V - VIP, P - Premium, B - Basico: ");
            scanf(" %c", &(*(ptrArrBi+j)+i)->tipoCliente);
            printf("Introduzca el total comprado: ");
            scanf("%f", &(*(ptrArrBi+j)+i)->totalComprado);
            printf("S - si es cliente frecuente, N - si no: ");
            scanf(" %c", &(*(ptrArrBi+j)+i)->compraFrecuente);
            (*(ptrArrBi+j)+i)->totalPagar = 0;
            printf("\n");
        }
    }
}

void showArr(CLIENTE **ptrArrBi, int nR, int nC)
{
    int i, j;
    printf("\n");
    for (j = 0; j < nR; j++)
    {
        for (i = 0; i < nC; i++)
        {
            printf("Clave: %s\t", (*(ptrArrBi+j)+i)->clave);
            printf("Nombre: %s\t", (*(ptrArrBi+j)+i)->nombre);
            if((*(ptrArrBi+j)+i)->tipoCliente == 'v' || (*(ptrArrBi+j)+i)->tipoCliente == 'V')
                printf("Es VIP\t");
            else if((*(ptrArrBi+j)+i)->tipoCliente == 'p' || (*(ptrArrBi+j)+i)->tipoCliente == 'P')
                printf("Es Premium\t");
            else
                printf("Es Basico\t");
            printf("Total comprado: %.2f\t", (*(ptrArrBi+j)+i)->totalComprado);
            if((*(ptrArrBi+j)+i)->compraFrecuente == 's' || (*(ptrArrBi+j)+i)->compraFrecuente == 'S')
            printf("El cliente es frecuente\t");
            else
            printf("El cliente no es frecuente\t");
            printf("El total a pagar es: %.2f\t", (*(ptrArrBi+j)+i)->totalPagar);
            printf("\n");
        }
    }
    printf("\n");
}

void calculaCompra(CLIENTE **ptrArrBi, int nR, int nC)
{
    int i, j;
    for (j = 0; j < nR; j++)
    {
        for (i = 0; i < nC; i++)
        {
            (*(ptrArrBi+j)+i)->totalPagar = (*(ptrArrBi+j)+i)->totalComprado;
            if((*(ptrArrBi+j)+i)->compraFrecuente == 's' || (*(ptrArrBi+j)+i)->compraFrecuente == 'S')
                (*(ptrArrBi+j)+i)->totalPagar = (*(ptrArrBi+j)+i)->totalPagar - (*(ptrArrBi+j)+i)->totalComprado * 0.05;
            if ((*(ptrArrBi+j)+i)->tipoCliente == 'v' || (*(ptrArrBi+j)+i)->tipoCliente == 'V')
                (*(ptrArrBi+j)+i)->totalPagar = (*(ptrArrBi+j)+i)->totalPagar - (*(ptrArrBi+j)+i)->totalComprado * 0.18;
            else if ((*(ptrArrBi+j)+i)->tipoCliente == 'p' || (*(ptrArrBi+j)+i)->tipoCliente == 'P')
                (*(ptrArrBi+j)+i)->totalPagar = (*(ptrArrBi+j)+i)->totalPagar - (*(ptrArrBi+j)+i)->totalComprado * 0.13;
            else
                (*(ptrArrBi+j)+i)->totalPagar = (*(ptrArrBi+j)+i)->totalPagar - (*(ptrArrBi+j)+i)->totalComprado * 0.08;
        }
    }
}

void cleanMry(CLIENTE **ptrArrBi, int nR)
{
    int i;
    for (i = 0; i < nR; i++)
        free(*ptrArrBi);
    free(ptrArrBi);
}