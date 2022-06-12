/*
Objetivo: Arreglos bidimensionales
Autor: LZR
Fecha: 11/06/2022
Nota(s): Tipo signed char
*/
#include <stdio.h>
#include <stdlib.h>

void scanRC(int *R, int *C);
int asignMem(signed char ***ptrArrBi, int nR, int nC);
void scanArr(signed char **ptrArrBi, int nR, int nC);
void showArr(signed char **ptrArrBi, int nR, int nC);
void imprimeRenglon(signed char **ptrArrBi, int nR, int nC);
void cleanMry(signed char **ptrArrBi, int nR);

int main()
{
    signed char **ptrArrayBi;
    int ret, renglones, columnas;

    scanRC(&renglones, &columnas);
    ret = asignMem(&ptrArrayBi, renglones, columnas);
    if (ret == 1)
    {
        scanArr(ptrArrayBi, renglones, columnas);
        showArr(ptrArrayBi, renglones, columnas);
        imprimeRenglon(ptrArrayBi, renglones, columnas);
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

int asignMem(signed char ***ptrArrBi, int nR, int nC)
{
    int res = 0;
    int i;

    *ptrArrBi = (signed char**)malloc(nR * sizeof(signed char*));
    if(*ptrArrBi)
    {
        res = 1;
        for (i = 0; i < nR; i++)
        {
            *(*ptrArrBi+i) = (signed char*)malloc(nC * sizeof(signed char));
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

void scanArr(signed char **ptrArrBi, int nR, int nC)
{
    int i, j;
    for (j = 0; j < nR; j++)
    {
        for (i = 0; i < nC; i++)
        {
            printf("Dato No. [%d.%d]: ", j+1, i+1);
            scanf(" %c", *(ptrArrBi+j)+i);
        }
    }
}

void showArr(signed char **ptrArrBi, int nR, int nC)
{
    int i, j;
    printf("\n");
    for (j = 0; j < nR; j++)
    {
        for (i = 0; i < nC; i++)
        {
            printf("%5c ", *(*(ptrArrBi+j)+i));
        }
    }
    printf("\n");
}

void imprimeRenglon(signed char **ptrArrBi, int nR, int nC)
{
    int i, j;
    for (j = 0; j < nR; j++)
    {
        printf("\nLa fila de caracteres No. %d es: ",j+1);
        for (i = 0; i < nC; i++)
        {
            printf("%c", *(*(ptrArrBi+j)+i));
        }
    }
}

void cleanMry(signed char **ptrArrBi, int nR)
{
    int i;
    for (i = 0; i < nR; i++)
        free(*ptrArrBi);
    free(ptrArrBi);
}