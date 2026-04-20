#include <stdio.h>

int main(void) {
    int a, b;
    int *ptr1 = NULL;
    int *ptr2 = NULL;
    int **pptr = NULL;
    int A[5] = {1, 2, 3, 4, 5};
    
    ptr1 = &a;
    ptr2 = &b;
    ptr1 = 5;                // Línea con error
    printf("%d\n", ptr1);    // antes decía "ptr", lo cambiamos a ptr1
    *ptr2 = 5;
    *ptr1=*ptr2;
    printf("%d\n", a);
    printf("%d\n", b);
    
    pptr = ptr1;             // Línea con error (int* vs int**)
    pptr = &b;               // Línea con error (int* vs int**)
    pptr = ptr2;             // Línea con error (int* vs int**)
    **pptr += 5;
    printf("%d\n", *pptr);
    printf("%d\n", **pptr);
    
    *pptr = ptr1;
    **pptr += 10;
    printf("%d\n", a);
    printf("%d\n", b);
    
    pptr = ptr2;             // Línea con error
    ptr2 = &a;
    printf("%d\n", *ptr1);
    printf("%d\n", **ptr2 + 4);  // Línea con error (ptr2 no es doble puntero)
    
    a = 2;
    b = *ptr2 + 3;
    printf("%d\n", *pptr);
    
    printf("***pptr");
    printf("%d\n", *ptr1);
    printf("%d\n", *ptr2);
    printf("%d\n", *pptr);
    printf("%d\n", *ptr1 + 1);
    printf("%d\n", *ptr2 + 1);
    printf("%d\n", *(*pptr + 3));
    printf("%d\n", *ptr1);
    printf("%d\n", *ptr2);
    printf("%d\n", *(*pptr + 3));
    
    for(int i = 0; i < 5; i++) {
        (*pptr + i) = (*pptr + i) + 1;  // Línea con error
    }
    
    printf("%d\n", (ptr1 + 1));
    printf("%d\n", (ptr2 + 1));
    printf("%d\n", (ptr1 + 4));
    
    return 0;
}