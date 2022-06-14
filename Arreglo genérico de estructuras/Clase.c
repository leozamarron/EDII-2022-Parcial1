#include <stdio.h>
#include <stdlib.h>

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
void contadorTipo(GEN *ptrArrGen, int n, int cAlumnos, int cProfesores, int cEmpleados);
void aprobadosReprobados(GEN *ptrArrGen, int n, int *aprobados, int *reprobados);

int main()
{
    GEN *ptrArrayGen;
    int N, ret;
    int cAlu, cProf, cEmple;
    int aprob, reprob;

    N = pideN();
    ret = asignaMem(ptrArrayGen, N);
    if (asignaMem)
    {
        asignaMem(ptrArrayGen, N);
        capturaDatos(ptrArrayGen, N);
        calculaProm(ptrArrayGen, N);
        calculaSueldo(ptrArrayGen, N);
        contadorTipo(ptrArrayGen, N, &cAlu, &cProf, &cEmple);
        aprobadosReprobados(ptrArrayGen, N, &aprob, &reprob);
    }
    else
        printf("No hay memoria");

    return 0;
}

int pideN()
{
    int n;
    printf("Dame el tamaño del arreglo: ");
    scanf("%d", n);

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
            printf("Tipo: ");
            scanf("%d", &(*ptrArrGen + i)->tipo);
            do
            {            
                switch ((*ptrArrGen + i)->tipo)
                {
                case 1: (*ptrArrGen + i)->ptrGen = malloc(sizeof(ALU));  bandera = 1; break;
                case 2: (*ptrArrGen + i)->ptrGen = malloc(sizeof(PROF));  bandera = 1; break;
                case 3: (*ptrArrGen + i)->ptrGen = malloc(sizeof(EMPLE));  bandera = 1; break;
                default: printf("Debes de ingras del 1 al 3\n"); break;
                }
                if (!(*ptrArrGen + i)->ptrGen)
                {
                    res = 0;
                    while (--i >= 0)
                        free((*ptrArrGen + i)->ptrGen);
                    free(*ptrArrGen);
                }
            } while (!bandera);
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