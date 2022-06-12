/*
Objetivo: arreglo bidimensional dinámico de estructuras PER.
Autor: LZR
Fecha: 12/06/2022
Nota(s): Tipo PER
*/

typedef struct
{
    char nom[30];
    int edad;
    float est, peso, imc;
} PER;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int asignMem(void **ptrGen);
void asignaDato(void *ptrPen, char *no, int ed, float es, float pe);
void scanArr(void *ptrGen);
void showArr(void *ptrGen);
void calculaIMC(void *ptrGen);
void muestraMayMen(void *ptrGen);
void cleanMry(void *ptrGen);

int main()
{
    int resp;
    void *ptrGenerico;
    resp = asignaMem(&ptrGenerico);
    if(resp)
    {
        asignaDato(ptrGenerico, "Juan Perez", 25, 1.72, 56);
        calculaIMC(ptrGenerico);
        muestraDatos(ptrGenerico);
        capturaDatos(ptrGenerico);
        calculaIMC(ptrGenerico);
        muestraDatos(ptrGenerico);
        muestraMayMen(ptrGenerico);
        liberaMem(ptrGenerico);
    }
    else
        printf("No hay memoria");
}

int asignaMem(void **ptrGen)
{
    int res = 0;
    *ptrGen = malloc(sizeof(PER));
    if(*ptrGen)
        res = 1;
    return res;
}

void asignaDato (void *ptrGen, char *no, int ed, float es, float pe)
{
    strcpy(((PER*)ptrGen)->nom, no);
    ((PER*)ptrGen)->edad = ed;
    ((PER*)ptrGen)->est = es;
    ((PER*)ptrGen)->peso = pe;
    ((PER*)ptrGen)->imc = 0;
}

void muestraDatos(void *ptrGen)
{
    printf("Nombre: %s\t", ((PER*)ptrGen)->nom);
    printf("Edad: %d\t", ((PER*)ptrGen)->edad);
    printf("Estatura: %.2f\t", ((PER*)ptrGen)->est);
    printf("Peso: %.2f\t", ((PER*)ptrGen)->peso);
    printf("IMC: %.2f\t\n", ((PER*)ptrGen)->imc);
}

void capturaDatos(void *ptrGen)
{
    printf ("introduzca el nombre: ");
    gets(((PER*)ptrGen)->nom);
    printf("introduzca la edad: ");
    scanf("%d", &((PER*)ptrGen)->edad);
    printf("introduzca la estatura: ");
    scanf("%f", &((PER*)ptrGen)->est);
    printf("introduzca el peso: ");
    scanf("%f", &((PER*)ptrGen)->peso);
    ((PER*)ptrGen)->imc = 0;
}

void calculaIMC(void *ptrGen)
{
    ((PER*)ptrGen)->imc = ((PER*)ptrGen)->peso/(((PER*)ptrGen)->est*((PER*)ptrGen)->est);
}

void muestraMayMen(void *ptrGen)
{
    if(((PER*)ptrGen)->edad> 17)
    printf("Mayor de edad\n");
    else
    printf("Menor de edad\n");
}

void liberaMem(void *ptrGen)
{
    free(ptrGen);
}
