/*
Objetivo: Arreglos dinamicos
Autor: LZR
Fecha: 11/06/2022
Nota(s): Tipo char
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int scanN();
int assignMem(char **ptrArr, int N);
void scanArr(char *ptrArr, int N);
void showArr(char *ptrArr, int N);
void cleanMry(char *ptrArr);

int main()
{
    char *ptrArray;
    int ret, nElem;

    nElem = scanN();
    ret = assignMem(&ptrArray, nElem);

    if (ret == 1)
    {
        scanArr(ptrArray, nElem);
        showArr(ptrArray, nElem);
        cleanMry(ptrArray);
    }
    else
        printf("No hay memoria");

    return 0;
}

int scanN()
{
    int N;

    printf("Dame el tamano del arreglo: ");
    scanf("%d", &N);

    return N;
}

int assignMem(char **ptrArr, int N)
{
    int res = 0;

    *ptrArr = (char*)malloc(N * sizeof(char)); 
    if(*ptrArr)
        res = 1;
    return res; 
}

void scanArr(char *ptrArr, int N)
{
    int i;
    for (i = 0; i < N-1; i++)
    {
        printf("Dato No. %d: ", i+1);
        scanf("%c ", (ptrArr+i));
    }
}

void showArr(char *ptrArr, int N)
{
    int i;
    printf("%s\n", ptrArr);
}

void cleanMry(char *ptrArr)
{
    free(ptrArr);
}
