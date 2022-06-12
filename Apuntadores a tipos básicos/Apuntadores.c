/*
Objetivo: manejo basico de un apuntador
Autor: LZR
Fecha: 06/06/2022
Nota(s): Apuntador a tipos de variables, no funciona en algunos compiladores solo en clion a lo mejor por el tipo de instalación
*/

#include <stdio.h>
#include <stdlib.h>

int assignMry(long double **x);
void assignFact(long double *x, long double value);
void scanFact(long double *x);
void showFact(long double *x);
void increaseFact(long double *x);
void cleanMry(long double *x);

int main()
{
    long double *ptrX;
    int rtn;    // valor de retorno

    rtn = assignMry(&ptrX);
    if (rtn==1)
    {
        assignFact(ptrX, 123.1231);
        showFact(ptrX);
        scanFact(ptrX);
        showFact(ptrX);
        increaseFact(ptrX);
        showFact(ptrX);
        cleanMry(ptrX);
    }
    else
        printf("No hay memoria");

    return 0;
}

int assignMry(long double **x)
{
    int a = 0;
    *x = (long double*)malloc(sizeof(long double));
    if (*x)
        a = 1;
    return a;
}

void assignFact(long double *x, long double value)
{
    //  *x   print datos
    //   x   print dirección
    *x = value;
    printf("%Lf", x);
}

void scanFact(long double *x)
{
    printf("Dame el dato: ");
    scanf("%Lf", x);
}

void showFact(long double *x)
{
    printf("El dato es: %Lf\n", *x);
}

void increaseFact(long double *x)
{
    (*x)++;
}

void cleanMry(long double *x)
{
    free(x);
}