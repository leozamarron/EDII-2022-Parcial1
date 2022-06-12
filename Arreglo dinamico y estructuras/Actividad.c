/*
Objetivo: Arreglos dinamicos y estructuras
Autor: LZR
Fecha: 11/06/2022
Nota(s):
1. El programa debe contener las funciones básicas.
2. No capturar el sueldo neto, solo asignar 0.
3. Incluir una función para calcular y asignar al campo correspondiente  el sueldo neto.
4. Incluir una función para contar el No. empleados recibieron bono de productividad y el No. de empleados que no lo recibieron.
5. Incluir una función para calcula el porcentaje de empleados que recibieron bono de puntualidad.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char clave[5];
    char nombre[25];
    float sueldoBase;
    int bonoProductividad;
    float impuestos;
    char bonoPuntualidad;
    float sueldoNeto;
}EMPLE;


int scanN();
int assignMem(EMPLE **ptrArr, int N);
void scanArr(EMPLE *ptrArr, int N);
void showArr(EMPLE *ptrArr, int N);
void calculaSueldoNeto(EMPLE *ptrArr, int N);
void contadorBonoProductividad(EMPLE *ptrArr, int N, int *dados, int *noDados);
void contadorBonoPuntualidad(EMPLE *ptrArr, int N, int *dados, int *noDados);
void muestraContadores(int proDados, int proNoDados, int puntDados, int puntNoDados);
void cleanMry(EMPLE *ptrArr);

int main()
{
    EMPLE *ptrArray;
    int ret, nElem, cBProT, cBProF, cBPuntT, cBPuntF;

    nElem = scanN();
    ret = assignMem(&ptrArray, nElem);

    if (ret == 1)
    {
        scanArr(ptrArray, nElem);
        showArr(ptrArray, nElem);
        calculaSueldoNeto(ptrArray, nElem);
        showArr(ptrArray, nElem);
        contadorBonoProductividad(ptrArray, nElem, &cBProT, &cBProF);
        contadorBonoPuntualidad(ptrArray, nElem, &cBPuntT, &cBPuntF);
        muestraContadores(cBProT, cBProF, cBPuntT, cBPuntF);
        cleanMry(ptrArray);
    }
    else
        printf("No hay memoria");

    return 0;
}

int scanN()
{
    int N;

    printf("Dame el numero de emplados: ");
    scanf("%d", &N);

    N++; //N++ por el caracter vacio

    return N;
}

int assignMem(EMPLE **ptrArr, int N)
{
    int res = 0;

    *ptrArr = (EMPLE*)malloc(N * sizeof(EMPLE)); 
    if(*ptrArr)
        res = 1;
    return res; 
}

void scanArr(EMPLE *ptrArr, int N)
{
    int i;
    for (i = 0; i < N-1; i++)
    {
        fflush(stdin);
        printf ("Introduzca la clave: ");
        gets((ptrArr+i)->clave);
        printf ("Introduzca el nombre: ");
        gets((ptrArr+i)->nombre);
        printf("Dame el sueldo base: ");
        scanf("%f", &(ptrArr+i)->sueldoBase);
        printf("1- si tiene bono de productividad, 0 - si no: ");
        scanf("%d", &(ptrArr+i)->bonoProductividad);
        printf("Dame el porcentaje de impuestos: ");
        scanf("%f", &(ptrArr+i)->impuestos);
        printf("S - si tiene bono de puntualidad, N - si no: ");
        scanf(" %c", &(ptrArr+i)->bonoPuntualidad);
        (ptrArr+i)->sueldoNeto = 0;
        printf("\n");
    }
}

void showArr(EMPLE *ptrArr, int N)
{
    int i;
    for (i = 0; i < N-1; i++)
    {
        printf("Clave: %s\t", (ptrArr+i)->clave);
        printf("Nombre: %s\t", (ptrArr+i)->nombre);
        printf("Sueldo base: %.2f\t", (ptrArr+i)->sueldoBase);
        if((ptrArr+i)->bonoProductividad)
            printf("Tiene bono de productividad\t");
        else
            printf("No tiene bono de productividad\t");
        printf("Impuestos: %.2f\t", (ptrArr+i)->impuestos);
        if((ptrArr+i)->bonoPuntualidad == 's' || (ptrArr+i)->bonoPuntualidad == 'S')
            printf("Tiene bono de puntualidad\t");
        else
            printf("No tiene bono de puntualidad\t");

        printf("Sueldo neto: %.2f\t\n", (ptrArr+i)->sueldoNeto);
    }
    printf("\n");
}

void calculaSueldoNeto(EMPLE *ptrArr, int N)
{
    int i;
    for (i = 0; i < N-1; i++)
    {
        (ptrArr+i)->sueldoNeto = (ptrArr+i)->sueldoBase - ((ptrArr+i)->impuestos * (ptrArr+i)->sueldoBase)/100;
        if ((ptrArr+i)->bonoProductividad)
            (ptrArr+i)->sueldoNeto = (ptrArr+i)->sueldoNeto + .12 * (ptrArr+i)->sueldoBase;
        if((ptrArr+i)->bonoPuntualidad == 's' || (ptrArr+i)->bonoPuntualidad == 'S')
            (ptrArr+i)->sueldoNeto = (ptrArr+i)->sueldoNeto + 550;
    }
}

void contadorBonoProductividad(EMPLE *ptrArr, int N, int *dados, int *noDados)
{
    int i;
    *dados = * noDados = 0;
    for (i = 0; i < N-1; i++)
        if ((ptrArr+i)->bonoProductividad)
            (*dados)++;
        else
            (*noDados)++;
}

void contadorBonoPuntualidad(EMPLE *ptrArr, int N, int *dados, int *noDados)
{
    int i;
    *dados = * noDados = 0;
    for (i = 0; i < N-1; i++)
        if ((ptrArr+i)->bonoPuntualidad == 's' || (ptrArr+i)->bonoPuntualidad == 'S')
            (*dados)++;
        else
            (*noDados)++;
}

void muestraContadores(int proDados, int proNoDados, int puntDados, int puntNoDados)
{
    printf("El total de empleados que recibieron el bono de productividad fueron: %d\n", proDados);
    printf("El total de empleados que no recibieron el bono de productividad fueron: %d\n", proNoDados);
    printf("El total de empleados que recibieron el bono de puntualidad fueron: %d\n", puntDados);
    printf("El total de empleados que no recibieron el bono de puntualidad fueron: %d\n", puntNoDados);
    printf("\n");
}

void cleanMry(EMPLE *ptrArr)
{
    free(ptrArr);
}
