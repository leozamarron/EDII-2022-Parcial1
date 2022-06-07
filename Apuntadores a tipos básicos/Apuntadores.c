/*
Objetivo: manejo basico de un apuntador
Autor: LZR
Fecha: 06/06/2022
Nota(s): Apuntador a tipos de variables
*/

#include <stdio.h>
#include <stdlib.h>

//funciones

int main()
{
    int *ptrX;
    int rtn;

    rtn = assignMry(&ptrX);
    if (rtn==1)
    {
        assignDate(ptrX, 100);
        showDate(ptrX);
        scanDate(ptrX);
        showDate(ptrX);
        increaseDate(ptrX);
        showDate(ptrX);
        cleanMry(ptrX);
    }
    else
        printf("No hay memoria");
    
    return 0;
}

int assignMry(int **x)
{
    int a = 0;
    *x = (int*)malloc(sizeof(int));
    if (*x)
        a = 1;
    return a;
}

void assignDate(int *x, int value)
{
    //  *x   print datos
    //   x   print dirección
    *x = value;
}

void scanDate(int *x)
{
    printf("Dame el dato: ");
    scanf("%d", x);
}

void showDate(int *x)
{
    printf("El dato es: %d\n", *x);
}

void increaseDate(int *x)
{
    (*x)++;
}

void cleanMry(int *x)
{
    free(x);
}