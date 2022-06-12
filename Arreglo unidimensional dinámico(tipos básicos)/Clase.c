/*
Objetivo: Arreglos dinamicos
Autor: LZR
Fecha: 11/06/2022
Nota(s): Tipo entero
*/
#include <stdio.h>
#include <stdlib.h>

int scanN();
int asignMem(int **ptrArr, int N);
void scanArr(int *ptrArr, int N);
void showArr(int *ptrArr, int N);
int addArr(int *ptrArr, int N);
int findHigher(int *ptrArr, int N);
float calculaAverage(int N, int add);
void countPairOdd(int *ptrArr, int N, int *cPair, int *cOdd);
void printResults(int add, int high, float avrge, int cPair, int cOdd);
void cleanMry(int *ptrArr);

int main()
{
    int *ptrArray;
    int nElem, ret, addition, higher, countPair, countOdd;
    float average;

    nElem = scanN();
    ret = asignMem(&ptrArray, nElem);

    if (ret == 1)
    {
        scanArr(ptrArray, nElem);
        showArr(ptrArray, nElem);
        addition = addArr(ptrArray, nElem);
        higher = findHigher(ptrArray, nElem);
        average = calculaAverage(nElem, addition);
        countPairOdd(ptrArray, nElem, &countPair, &countOdd);
        printResults(addition, higher, average, countPair, countOdd);
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

int asignMem(int **ptrArr, int N)
{
    int res = 0;

    *ptrArr = (int*)malloc(N * sizeof(int)); 
    if(*ptrArr)
        res = 1;
    return res; 
}

void scanArr(int *ptrArr, int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf("Dato No. %d: ", i+1);
        scanf("%d", ptrArr+i);
    }
}

void showArr(int *ptrArr, int N)
{
    int i;
    printf("\n");
    for (i = 0; i < N; i++)
        printf("%d ", *(ptrArr+i));
    printf("\n");
}

int addArr(int *ptrArr, int N)
{
    int i, add = 0;
    for (i = 0; i < N; i++)
        add += *(ptrArr+i);
    return add;
}

int findHigher(int *ptrArr, int N)
{
    int i, high = *ptrArr;
    for (i = 0; i < N; i++)
        if(*(ptrArr+i) > high)
            high = *(ptrArr + i);
    return high;
}

float calculaAverage(int N, int add)
{
    float average; 
    average = (float)add/N;
    return average;
}

void countPairOdd(int *ptrArr, int N, int *cPair, int *cOdd)
{
    int i;
    *cPair = *cOdd = 0;

    for (i = 0; i < N; i++)
        if (!(*(ptrArr+i)%2))
            (*cPair)++;
        else
            (*cOdd)++;
}

void printResults(int add, int high, float avrge, int cPair, int cOdd)
{
    printf("La suma es: %d\n", add);
    printf("El mas alto es: %d\n", high);
    printf("El promedio es: %.2f\n", avrge);
    printf("El numero de pares total es: %d\n", cPair);
    printf("El numero de impares total es: %d\n", cOdd);
}

void cleanMry(int *ptrArr)
{
    free(ptrArr);
}
