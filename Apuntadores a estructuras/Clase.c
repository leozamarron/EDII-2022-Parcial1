#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nom[30];
    int edad;
    float est, peso, imc;
} PER;

int asignaMem(PER **ptrPer);
void asignaDato(PER *ptrPer, char *no, int ed, float es, float pe);
void capturaDatos(PER *ptrPer);
void muestraDatos(PER *ptrPer);
void calculaIMC(PER *ptrPer);
void cumple(PER *ptrPer);
void muestraMayMen(PER *ptrPer);
void liberaMem(PER *ptrPer);

int main()
{
    int resp;
    PER *ptrPersona;
    resp = asignaMem(&ptrPersona);
    if(resp)
    {
        asignaDato(ptrPersona, "Juan Perez", 25, 1.72, 56);
        muestraDatos(ptrPersona);
        capturaDatos(ptrPersona);
        calculaIMC(ptrPersona);
        cumple(ptrPersona);
        muestraDatos(ptrPersona);
        muestraMayMen(ptrPersona);
        liberaMem(ptrPersona);
    }
    else
        printf("No hay memoria");
}

int asignaMem(PER **ptrPer)
{
    int res = 0;
    *ptrPer = (PER *) malloc(sizeof (PER));
    if(*ptrPer)
        res = 1;
    return res;
}

void asignaDato (PER *ptrPer, char *no, int ed, float es, float pe)
{
    strcpy(ptrPer->nom, no);
    ptrPer->edad = ed;
    ptrPer->est = es;
    ptrPer->peso = pe;
    ptrPer->imc = 0;
}

void muestraDatos(PER *ptrPer)
{
    printf("Nombre: %s\t", ptrPer->nom);
    printf("Edad: %d\t", ptrPer->edad);
    printf("Estatura: %.2f\t", ptrPer->est);
    printf("Peso: %.2f\t", ptrPer->peso);
    printf("IMC: %.2f\t\n", ptrPer->imc);
}

void capturaDatos(PER *ptrPer)
{
    printf ("introduzca el nombre: ");
    gets(&ptrPer->nom);
}

void calculaIMC(PER *ptrPer)
{
    ptrPer->imc = ptrPer->peso/(ptrPer->est*ptrPer->est);
}

void cumple(PER *ptrPer)
{
    ptrPer->edad++;
}

void muestraMayMen(PER *ptrPer)
{
    if(ptrPer->edad> 17)
    printf("Mayor de edad\n");
    else
    printf("Menor de edad\n");
}

void liberaMem(PER *ptrPer)
{
    free(ptrPer);
}
