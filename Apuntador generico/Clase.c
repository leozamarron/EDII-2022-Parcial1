/*
Objetivo: Manejo básico de datos génericos
Autor: LZR
Fecha: 12/06/2022
Nota(s): A un long entero
*/

#include <stdio.h>
#include <stdlib.h>

int assignMem(void **ptrGen);
void assignFact(void *ptrGen, long int fact);
void scanFact(void *ptrGen);
void showFact(void *ptrGen);
void increasse(void *ptrGen, long int value);
void cleanMry(void *ptrGen);

int main()
{
    void *ptrGenerico;
    int value, ret;

    ret = assignMem(&ptrGenerico);
    if (ret)
    {
        assignFact(ptrGenerico, 20);
        showFact(ptrGenerico);
        scanFact(ptrGenerico);
        showFact(ptrGenerico);
        increasse(ptrGenerico, 5);
        showFact(ptrGenerico);
        cleanMry(ptrGenerico);
    }
    else
        printf("No hay memoria");

    return 0;
}

int assignMem(void **ptrGen)
{
    int res = 0;
    *ptrGen = malloc(sizeof(long int));
    if(ptrGen)
        res = 1;
    return res;
}

void showFact(void *ptrGen)
{
    printf("%ld\n", *(long int*)ptrGen);
}

void assignFact(void *ptrGen, long int fact)
{
    *(long int*)ptrGen = fact;
}

void scanFact(void *ptrGen)
{
    printf("Dame un dato: ");
    scanf("%d", (long int*)ptrGen);
}

void increasse(void *ptrGen, long int value)
{
    *(long int*)ptrGen += value;
}

void cleanMry(void *ptrGen)
{
    free(ptrGen);
}