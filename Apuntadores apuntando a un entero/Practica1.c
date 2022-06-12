#include <stdio.h>
#include <stdlib.h>

int asignaMem(unsigned int ****ptrUnsigned);
void assignFact(unsigned int ***ptrUnsigned, unsigned int value);
void scanFact(unsigned int ***ptrUnsigned);
void showFact(unsigned int ***ptrUnsigned);
void increaseFact(unsigned int ***ptrUnsigned);
void cleanMry(unsigned int ***ptrUnsigned);

int main()
{
    unsigned int ***ptr;
    unsigned int ret; //return

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

int asignaMem(unsigned int ****ptrUnsigned)
{
    unsigned int res = 0;

    *ptrUnsigned = (unsigned int***)malloc(sizeof(unsigned int*));
    if (*ptrUnsigned)
    {
        **ptrUnsigned = (unsigned int**)malloc(sizeof(unsigned int*));
        if(**ptrUnsigned) 
        {
            ***ptrUnsigned = (unsigned int*)malloc(sizeof(unsigned int));
            if(***ptrUnsigned)
                res=1;
            else
                cleanMry(*ptrUnsigned);
        }
    }
    

    return res; 
}

 void assignFact(unsigned int ***ptrUnsigned, unsigned int value)
{
    //  ***ptrUnsigned   print datos
    //   *ptrUnsigned   print dirección del entero
    //    ptrUnsigned   print dirección del puntero
    ***ptrUnsigned = value;
}

void scanFact(unsigned int ***ptrUnsigned)
{
    printf("Dame el dato: ");
    scanf("%u", **ptrUnsigned);
}

void showFact(unsigned int ***ptrUnsigned)
{
    printf("El dato es: %u\n", ***ptrUnsigned);
}

void increaseFact(unsigned int ***ptrUnsigned)
{
    (***ptrUnsigned)++;
}

void cleanMry(unsigned int ***ptrUnsigned)
{
    free(*ptrUnsigned);
    free(ptrUnsigned);
}