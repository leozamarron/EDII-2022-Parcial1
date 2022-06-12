/*
Objetivo: Arreglos bidimensionales
Autor: LZR
Fecha: 11/06/2022
Nota(s): Tipo entero
*/
#include <stdio.h>
#include <stdlib.h>

void scanRC(int *R, int *C);
int asignMem(int ***ptrArrBi, int nR, int nC);
int asignMemSuma(int **ptrArr, int *N, int nR);
void scanArr(int **ptrArrBi, int nR, int nC);
void showArr(int **ptrArrBi, int nR, int nC);
void sumaRenglones(int **ptrArrBi, int nR, int nC, int *ptrArrSuma, int *N);
void muestraSuma(int *ptrArrSuma, int N);
void cleanMry(int **ptrArrBi, int nR, int *ptrArrSuma);

int main()
{
    int **ptrArrayBi, *ptrArraySuma;
    int ret, renglones, columnas, nElem;

    scanRC(&renglones, &columnas);
    ret = asignMem(&ptrArrayBi, renglones, columnas);
    if (ret == 1)
    {
        scanArr(ptrArrayBi, renglones, columnas);
        showArr(ptrArrayBi, renglones, columnas);
        ret = asignMemSuma(&ptrArraySuma, &nElem, renglones);
        if (ret == 1)
        {
            sumaRenglones(ptrArrayBi, renglones, columnas, ptrArraySuma, &nElem);
            muestraSuma(ptrArraySuma, nElem);
        }
        cleanMry(ptrArrayBi, renglones, ptrArraySuma);
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

int asignMem(int ***ptrArrBi, int nR, int nC)
{
    int res = 0;
    int i;
    nR++;
    nC++;

    *ptrArrBi = (int**)malloc(nR * sizeof(int*)); 
    if(*ptrArrBi)
    {
        res = 1;
        for (i = 0; i < nR; i++)
        {
            *(*ptrArrBi+i) = (int*)malloc(nC * sizeof(int)); 
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

int asignMemSuma(int **ptrArr, int *N, int nR)
{
    int res = 0;
    *N = nR;
    *ptrArr = (int*)malloc(*N * sizeof(int));
    if (*ptrArr)
        res = 1;
    return res;
}

void scanArr(int **ptrArrBi, int nR, int nC)
{
    int i, j;
    for (j = 0; j < nR; j++)
    {
        for (i = 0; i < nC; i++)
        {
            printf("Dato No. [%d.%d]: ", j+1, i+1);
            scanf("%d", *(ptrArrBi+j)+i);
        }
    }
}

void showArr(int **ptrArrBi, int nR, int nC)
{
    int i, j;
    printf("\n");
    for (j = 0; j < nR; j++)
    {
        for (i = 0; i < nC; i++)
        {
            printf("%5d ", *(*(ptrArrBi+j)+i));
        }
    }
    printf("\n\n");
}

void sumaRenglones(int **ptrArrBi, int nR, int nC, int *ptrArrSuma, int *N)
{
    int i, j, suma, ret;
    for (j = 0; j < nR; j++)
    {
        suma = 0;
        for (i = 0; i < nC; i++)
        {
            suma += *(*(ptrArrBi+j)+i);
        }
        *(ptrArrSuma+j) = suma;
    }  
}

void muestraSuma(int *ptrArrSuma, int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf("Suma de la fila No. %d: %d\n",i+1 ,*(ptrArrSuma+i));
    }
}

void cleanMry(int **ptrArrBi, int nR, int *ptrArrSuma)
{
    int i;
    for (i = 0; i < nR; i++)
        free(*ptrArrBi);
    free(ptrArrBi);
    free(ptrArrSuma);
}