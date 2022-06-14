/*
Objetivo: Escriba un programa para manejar un arreglo genérico de estructuras persona(PER).
Autor: LZR
Fecha: 13/06/2022
Nota(s): La estructura persona está formada por: nombre, edad, estatura, peso e imc.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int edad;
    float estatura, peso, imc;
}PER;

typedef struct
{
    float cal1, cal2, cal3;
    float prom;
}ALU;

typedef struct
{
    float sueldo, sueldoHr;
    int hrTrab;
    char sec;
}PROF;

typedef struct
{
    float sBase, bono, sNeto;
    int dpto;
}EMPLE;

typedef struct
{
    char nom[25];
    char dom[25];
    char tel[15];
    int tipo;
    void *ptrGen;
}GEN;

int pideN();
int asignaMem(GEN **ptrArrGen, int n);
void capturaDatos(GEN *ptrArrGen, int n);
void calculaProm(GEN *ptrArrGen, int n);
void calculaSueldo(GEN *ptrArrGen, int n);
void contadorTipo(GEN *ptrArrGen, int n, int *cAlumnos, int *cProfesores, int *cEmpleados);
void aprobadosReprobados(GEN *ptrArrGen, int n, int *aprobados, int *reprobados);
void calculaIMC(GEN *ptrArrGen, int n);
void liberaMem(GEN *PtrArrGen, int n);

int main()
{
    GEN *ptrArrayGen;
    int N, ret;
    int cAlu, cProf, cEmple;
    int aprob, reprob;

    N = pideN();
    ret = asignaMem(&ptrArrayGen, N);
    if (ret)
    {
        capturaDatos(ptrArrayGen, N);
        calculaProm(ptrArrayGen, N);
        calculaSueldo(ptrArrayGen, N);
        contadorTipo(ptrArrayGen, N, &cAlu, &cProf, &cEmple);
        aprobadosReprobados(ptrArrayGen, N, &aprob, &reprob);
        calculaIMC(ptrArrayGen, N);
        liberaMem(ptrArrayGen, N);
    }
    else
        printf("No hay memoria");

    return 0;
}

int pideN()
{
    int n;
    printf("Dame el tamaño del arreglo: ");
    scanf("%d", &n);

    return n;
}

int asignaMem(GEN **ptrArrGen, int n)
{
    int res = 0, i, bandera;

    *ptrArrGen = (GEN*)malloc(n*sizeof(GEN));
    if(*ptrArrGen)
    {
        res = 1;
        for (i = 0; i < n && res; i++)
        {
            bandera = 0;
            do
            {
                printf("Tipo: ");
                scanf("%d", &(*ptrArrGen + i)->tipo);      
                switch ((*ptrArrGen + i)->tipo)
                {
                case 1: (*ptrArrGen + i)->ptrGen = malloc(sizeof(ALU));  bandera = 1; break;
                case 2: (*ptrArrGen + i)->ptrGen = malloc(sizeof(PROF));  bandera = 1; break;
                case 3: (*ptrArrGen + i)->ptrGen = malloc(sizeof(EMPLE));  bandera = 1; break;
                case 4: (*ptrArrGen + i)->ptrGen = malloc(sizeof(PER));  bandera = 1; break;
                default: printf("Debes de ingras del 1 al 4\n"); break;
                }
            } while (!bandera);
            if (!(*ptrArrGen + i)->ptrGen)
            {
                res = 0;
                while (--i >= 0)
                    free((*ptrArrGen + i)->ptrGen);
                free(*ptrArrGen);
            }
        }
    }
    return res;
}

void capturaDatos(GEN *ptrArrGen, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Dato No. %d\n", i);
        fflush(stdin);
        printf("Nombre: ");
        gets((ptrArrGen+i)->nom);
        printf("Domicilio: ");
        gets((ptrArrGen+i)->dom);
        printf("Telefono: ");
        gets((ptrArrGen+i)->tel);
        switch ((ptrArrGen+i)->tipo)
        {
        case 1: //Alumno
            printf("introduzca la 1ra calificacion: ");
            scanf("%f", &(((ALU*)(ptrArrGen->ptrGen))->cal1));
            printf("introduzca la 2da calificacion: ");
            scanf("%f", &(((ALU*)(ptrArrGen->ptrGen))->cal2));
            printf("introduzca la 3ra calificacion: ");
            scanf("%f", &(((ALU*)(ptrArrGen->ptrGen))->cal3));
            break;
        case 2: //Profesores
            printf("introduzca el sueldo por hora: ");
            scanf("%f", &(((PROF*)(ptrArrGen->ptrGen))->sueldoHr));
            printf("introduzca horas trabajadas: ");
            scanf("%d", &(((PROF*)(ptrArrGen->ptrGen))->hrTrab));
            printf("introduzca la seccion: ");
            scanf("%s", &(((PROF*)(ptrArrGen->ptrGen))->sec));
            break;
        case 3: //Empleado
            printf("introduzca el sueldo base: ");
            scanf("%f", &(((EMPLE*)(ptrArrGen->ptrGen))->sBase));
            printf("introduzca el bono: ");
            scanf("%f", &(((EMPLE*)(ptrArrGen->ptrGen))->bono));
            printf("introduzca el departamento: ");
            scanf("%d", &(((EMPLE*)(ptrArrGen->ptrGen))->dpto));
            break;
        case 4: //Persona
            printf("introduzca la edad: ");
            scanf("%d", &(((PER*)(ptrArrGen->ptrGen))->edad));
            printf("introduzca la estatura: ");
            scanf("%f", &(((PER*)(ptrArrGen->ptrGen))->estatura));
            printf("introduzca el peso: ");
            scanf("%f", &(((PER*)(ptrArrGen->ptrGen))->peso));
        }
    }
}

void calculaProm(GEN *ptrArrGen, int n)
{
    int i;
    for (i = 0; i < n; i++)
        if((ptrArrGen + i)->tipo == 1)
            ((ALU*)(ptrArrGen->ptrGen))->prom = (((ALU*)(ptrArrGen->ptrGen))->cal1 + ((ALU*)(ptrArrGen->ptrGen))->cal2 + ((ALU*)(ptrArrGen->ptrGen))->cal3)/3;
}

void calculaSueldo(GEN *ptrArrGen, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        switch ((ptrArrGen+i)->tipo)
        {
        case 2: 
            ((PROF*)(ptrArrGen+i)->ptrGen)->sueldo = ((PROF*)(ptrArrGen+i)->ptrGen)->sueldoHr * ((PROF*)(ptrArrGen+i)->ptrGen)->hrTrab;
            break;
        case 3:
            ((EMPLE*)(ptrArrGen+i)->ptrGen)->sNeto = ((EMPLE*)(ptrArrGen+i)->ptrGen)->sBase + ((EMPLE*)(ptrArrGen+i)->ptrGen)->bono;
            break;
        }
    }
}

void contadorTipo(GEN *ptrArrGen, int n, int *cAlumnos, int *cProfesores, int *cEmpleados)
{
    int i;
    *cAlumnos = *cProfesores = *cEmpleados = 0;
    for (i = 0; i < n; i++)
    {
        switch ((ptrArrGen + i)->tipo)
        {
        case 1: (*cAlumnos)++; break;
        case 2: (*cProfesores)++; break;
        case 3: (*cEmpleados)++; break;
        }
    }
}

void aprobadosReprobados(GEN *ptrArrGen, int n, int *aprobados, int *reprobados)
{
    int i;
    *aprobados = *reprobados = 0;
    for (i = 0; i < n; i++)
    {
        if ((ptrArrGen+i)->tipo == 1)
        {
            if (((ALU*)(ptrArrGen+i)->ptrGen)->prom >= 6)
                (*aprobados)++;
            else
                (*reprobados)++;
        }
    }
}

void calculaIMC(GEN *ptrArrGen, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if ((ptrArrGen+i)->tipo == 4)
        {
            ((PER*)(ptrArrGen+i)->ptrGen)->imc = ((PER*)(ptrArrGen+i)->ptrGen)->peso/(((PER*)(ptrArrGen+i)->ptrGen)->estatura * ((PER*)(ptrArrGen+i)->ptrGen)->estatura);
        }
    }
    
}

void liberaMem(GEN *ptrArrGen, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        free((ptrArrGen+i)->ptrGen);
    }
    free(ptrArrGen);
}