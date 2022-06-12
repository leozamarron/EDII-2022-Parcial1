/*
Objetivo: Escriba un programa para manejar una estructura vendedor por medio de un apuntador.
Autor: LZR
Fecha: 11/06/2022
Nota(s): 
1. El programa debe contener las funciones básicas.
2. En la función asignaDatos, no se le da valor a los campos comisión y sueldo neto, solo se le asigna 0.
3. El sueldo neto y la comisión no se captura, se les asigna 0.
4. Incluir una función para calcular y asignar al campo correspondiente  la comisión.
5. Incluir una función para calcular y asignar al campo correspondiente el sueldo neto.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char clave[5];
    char nombreVendedor[25];
    float totalVendido, sueldoBase, sueldoNeto;
    int comision;
} VENDE;

int asignaMem(VENDE **ptrVen);
void asignaDato (VENDE *ptrVen, char *clv, char *no, float su, float totalV);
void capturaDatos(VENDE *ptrVen);
void muestraDatos(VENDE *ptrVen);
void calculaComision(VENDE *ptrVen);
void calculaSueldoNeto(VENDE *ptrVen);
void liberaMem(VENDE *ptrVen);

int main()
{
    int resp;
    VENDE *ptrVende;
    resp = asignaMem(&ptrVende);
    if(resp)
    {
        asignaDato(ptrVende, "AS3F", "Jose Maria", 1500, 15000);
        calculaComision(ptrVende);
        calculaSueldoNeto(ptrVende);
        muestraDatos(ptrVende);
        capturaDatos(ptrVende);
        calculaComision(ptrVende);
        calculaSueldoNeto(ptrVende);
        muestraDatos(ptrVende);
        liberaMem(ptrVende);
    }
    else
        printf("No hay memoria");
}

int asignaMem(VENDE **ptrVen)
{
    int res = 0;
    *ptrVen = (VENDE *) malloc(sizeof (VENDE));
    if(*ptrVen)
        res = 1;
    return res;
}

void asignaDato (VENDE *ptrVen, char *clv, char *no, float suB, float totalV)
{
    strcpy(ptrVen->clave, clv);
    strcpy(ptrVen->nombreVendedor, no);
    ptrVen->sueldoBase = suB;
    ptrVen->totalVendido = totalV;
    ptrVen->comision = 0;
    ptrVen->sueldoNeto = 0;
}

void muestraDatos(VENDE *ptrVen)
{
    printf("Clave: %s\t", ptrVen->clave);
    printf("Nombre: %s\t", ptrVen->nombreVendedor);
    printf("Total: %.2f\t", ptrVen->totalVendido);
    printf("Sueldo base: %.2f\t", ptrVen->sueldoBase);
    printf("Comision: %d porciento\t", ptrVen->comision);
    printf("Sueldo neto: %.2f\t\n", ptrVen->sueldoNeto);
}

void capturaDatos(VENDE *ptrVen)
{
    printf ("Introduzca la clave: ");
    gets(ptrVen->clave);
    printf ("Introduzca el nombre: ");
    gets(ptrVen->nombreVendedor);
    printf("Dame el sueldo base: ");
    scanf("%f", &ptrVen->sueldoBase);
    printf("Dame el total vendido: ");
    scanf("%f", &ptrVen->totalVendido);
}

void calculaComision(VENDE *ptrVen)
{
    if (ptrVen->totalVendido >= 0 && ptrVen->totalVendido <= 1000)
    {
        ptrVen->comision = 10;
    }
    else if (ptrVen->totalVendido > 1000 && ptrVen->totalVendido <= 3000)
    {
        ptrVen->comision = 13;
    }
    else if (ptrVen->totalVendido > 3000 && ptrVen->totalVendido <= 7000)
    {
        ptrVen->comision = 18;
    }
    else if (ptrVen->totalVendido > 7000)
    {
        ptrVen->comision = 21;
    }else {
        printf("error con los datos\n");
    }
}

void calculaSueldoNeto(VENDE *ptrVen)
{
    ptrVen->sueldoNeto = (ptrVen->totalVendido * ptrVen->comision)/100 + ptrVen->sueldoBase;
}

void liberaMem(VENDE *ptrVen)
{
    free(ptrVen);
}