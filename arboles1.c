#include <stdio.h>

struct arbol{
    int d;
    struct arbol *izq, *der;
};

struct arbol* crearnodo();

int main(void){
    struct arbol *raiz, *ptrtemp, *ptrsig, *copraiz;
    raiz=NULL;
    copraiz=raiz;
    int op;

    printf("--MENU--\n");
    printf("[1].Insertar\n[2].Eliminar\n[3].Salir\n");
    printf("Escoja una opcion: ");
    scanf("%d", &op);

    do{
        switch(op){
            case 1:
            ptrtemp=crearnodo();
            if(ptrtemp==NULL){
                printf("No se creo el nodo\n");
            }else{
                if(raiz==NULL){
                    raiz=ptrtemp;
                }else{
                    if(ptrtemp->d<copraiz->d){
                        if(copraiz->izq==NULL){
                            copraiz->izq=ptrtemp->d;
                        }else{
                            copraiz=copraiz->izq;
                        }
                    }else if(ptrtemp>copraiz){
                        if(copraiz->der==NULL){
                            copraiz->der=ptrtemp;
                        }else{
                            copraiz=copraiz->der;
                        }
                    }
                }
            }

            break;
            case 2:
            printf("Ingrese el elemento a eliminar: \n");
rama->izq = NULL;
            break;
            case 3:
            printf("Saliendo...");
            break;
            default:
            printf("Opcion invalida\n");
        }
    }while(op!=3);
    
    return 0;
}


struct arbol* crearnodo(){
    struct arbol *rama= (struct arbol*) malloc (sizeof(struct arbol));
    if (rama==NULL){
        return NULL;
    }
    printf("Ingrese un numero: ");
    scanf("%d", &rama->d);

    rama->izq = NULL;
    rama->der = NULL;

    return rama;
}