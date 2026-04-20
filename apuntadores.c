#include <stdio.h>
#include <stdlib.h>

int main (void){
    int *ptr=NULL;

    ptr=(int *)malloc(sizeof(int));
    *ptr =10;
    
    printf("Valor de ptr:%d",*ptr);
    printf("\ndireccion de la variable apuntador: %p",&ptr);
    printf("\nDireccion de memoria de reservada: %p",ptr);
    free(ptr);
    
    return 0;

}