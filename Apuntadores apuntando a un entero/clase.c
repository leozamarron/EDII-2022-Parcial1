#include <stdio.h>
#include <stdlib.h>

int asignaMem(int ***ptrInt);
void assignFact(int **ptrInt, int value);
void scanFact(int **ptrInt);
void showFact(int **ptrInt);
void increaseFact(int **ptrInt);
void cleanMry(int **ptrInt);

int main()
{
    int **ptr;
    int ret; //return

    ret = asignaMem(&ptr);

    if (ret == 1)
    {
        assignFact(ptr, 12);
        showFact(ptr);
        scanFact(ptr);
        showFact(ptr);
        increaseFact(ptr);
        showFact(ptr);
        cleanMry(ptr);
    }
    else
        printf("No hay memoria");

    return 0;
}

int asignaMem(int ***ptrInt)
{
    int res = 0;
    //Apuntador a entero: int*
    // Apuntador a apuntador int**
    *ptrInt = (int**)malloc(sizeof(int*)); 
    if(*ptrInt) 
    {
        **ptrInt = (int*)malloc(sizeof(int));
        if(**ptrInt)
            res=1;
        else
            cleanMry(*ptrInt);
    }
    return res; 
}

 void assignFact(int **ptrInt, int value)
{
    //  **ptrInt   print datos
    //   *ptrInt   print dirección del entero
    //    ptrInt   print dirección del puntero
    **ptrInt = value;
}

void scanFact(int **ptrInt)
{
    printf("Dame el dato: ");
    scanf("%d", *ptrInt);
}

void showFact(int **ptrInt)
{
    printf("El dato es: %d\n", **ptrInt);
}

void increaseFact(int **ptrInt)
{
    (**ptrInt)++;
}

void cleanMry(int **ptrInt)
{
    free(*ptrInt);
    free(ptrInt);
}
