#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct Dato{
  int d;
  struct Dato *Ptrsig;
};

int Menu(int op);
int funciones(int opcion);
struct Dato* Crear();
void mostrar(struct Dato *Ptr);
void Liberar(struct Dato *Ptr);
void buscar(struct Dato *Ptr);
struct Dato* reemplazar(struct Dato *Ptr);
struct Dato* ordenar(struct Dato *Ptr);

int main()
{
    struct Dato *Ptr=NULL;
    int op, opcion, nnodos=0;
    int cont=0;
    struct Dato *ptrtemp, *Ptraux;
    do{
        op=Menu(op);

        switch(op){
            case 1:
            ptrtemp=Crear();
            if(ptrtemp==NULL){
                printf ("No se ha creado ningún dato aún..");
            }else{
                if(Ptr==NULL){
                    Ptr=ptrtemp;
                }else{
                    Ptraux=Ptr;
                    while(Ptraux->Ptrsig!= NULL){
                        Ptraux=Ptraux->Ptrsig;
                    }
                    Ptraux->Ptrsig=ptrtemp;
                }
            }
            nnodos++;
            cont=1;
            break;

            case 2:
            if (cont==0){
                printf ("\nERROR: No se ha creado ningun bloque todavia...\n");
            }else{
                do{
                    opcion=funciones(opcion);
                    switch(opcion){
                        case 1:
                            buscar(Ptr);
                            break;
                        case 2:
                            printf("Contando..\n");
                            printf("El numero de nodos es: %d\n", nnodos);
                            break;
                        case 3:
                            Ptr=reemplazar(Ptr);
                            break;
                        case 4:
                            Ptr=ordenar(Ptr);
                            printf("\nNodos ordenados correctamente.\n");
                            break;
                        case 5:
                            printf("Regresando...\n");
                            break;
                        default:
                            printf("\nOpcion no valida en el submenu.\n");
                    }
                }while(opcion!=5);
            }
            break;

            case 3:
            if (cont==0){
             printf ("\nERROR: No se ha creado ningun bloque todavia...\n");
            }else {
            mostrar(Ptr);
            }
            break;

            case 4:
            if (Ptr == NULL){
            printf("No ha reservado memoria, reserve memoria, porfas\n");
            } else if (Ptr->Ptrsig == NULL){
            free(Ptr);
            Ptr = NULL;
            cont=0;
            } else{
                Ptraux=Ptr;
                while ((Ptraux->Ptrsig)->Ptrsig!= NULL ){
                    Ptraux=Ptraux->Ptrsig;
                }
                free(Ptraux->Ptrsig);
                Ptraux->Ptrsig=NULL;
                Ptraux=NULL;
            }
            printf ("\n El último nodo ha sido eliminado\n");
            if(nnodos>0) nnodos--;
            if(nnodos==0) cont=0;
            break;

            case 5:
            Ptraux=Ptr;
            while (Ptr!=NULL){
                Ptraux=Ptr;
                Ptr=Ptraux->Ptrsig;
                free (Ptraux);
            }
            Ptr=NULL;
            printf ("\n Saliendo del programa...\n");
            break;

            default:
            printf ("\nOpcion no encontrada, vuelva a intentarlo...porfas.\n");

            }


    }while (op!=5);

    return 0;
}

int Menu(int op){
    printf("\n ---*MENU*---\n");
    printf("[1].Crear dato\n");
    printf("[2].Funciones\n");
    printf("[3].Mostrar dato\n");
    printf("[4].Elimnar nodo\n");
    printf("[5].Salir\n");
    printf("Escoja una opcion, porfas\n");
    scanf("%d", &op);

    return op;

}

struct Dato* Crear(){
    struct Dato *dato= (struct Dato*) malloc (sizeof(struct Dato));
    if (dato==NULL){
        return NULL;
    }
    printf("Ingrese un numero: ");
    scanf("%d", &dato->d);

    dato->Ptrsig = NULL;

    return dato;
}

void mostrar(struct Dato *Ptr){
     printf ("\n");
    if (Ptr==NULL){
        printf ("\n Ya no hay nodos... :(\n");
    }else{
        printf("Los nodos creados son: \n");
                while (Ptr != NULL ){
                    printf(" %d -> ", Ptr->d);
                    Ptr=Ptr->Ptrsig;
                }
    }


}

int funciones(int opcion){
    printf("\n --*MENU*--\n");
    printf("[1].Buscar\n");
    printf("[2].Contar\n");
    printf("[3].Reemplazar\n");
    printf("[4].Ordenar\n");
    printf("[5].Regresar\n");
    printf("Escoja una opcion, porfas\n");
    scanf("%d", &opcion);

    return opcion;

}

// Función para buscar un nodo por su valor
void buscar(struct Dato *Ptr){
    int valor, encontrado=0, posicion=1;
    
    if(Ptr==NULL){
        printf("\nLa lista esta vacia.\n");
        return;
    }
    
    printf("Ingrese el valor a buscar: ");
    scanf("%d", &valor);
    
    while(Ptr != NULL){
        if(Ptr->d == valor){
            printf("\nValor %d encontrado en la posicion %d\n", valor, posicion);
            encontrado=1;
        }
        Ptr = Ptr->Ptrsig;
        posicion++;
    }
    
    if(!encontrado){
        printf("\nValor %d no encontrado en la lista.\n", valor);
    }
}

// Función para reemplazar un nodo por otro valor
struct Dato* reemplazar(struct Dato *Ptr){
    int valorBuscar, valorReemplazar, encontrado=0;
    struct Dato *temp;
    
    if(Ptr==NULL){
        printf("\nLa lista esta vacia.\n");
        return Ptr;
    }
    
    printf("Lista actual:\n");
    temp = Ptr;
    while(temp != NULL){
        printf("%d -> ", temp->d);
        temp = temp->Ptrsig;
    }
    printf("NULL\n");
    
    printf("Ingrese el valor que desea reemplazar: ");
    scanf("%d", &valorBuscar);
    
    printf("Ingrese el nuevo valor: ");
    scanf("%d", &valorReemplazar);
    
    temp = Ptr;
    while(temp != NULL){
        if(temp->d == valorBuscar){
            temp->d = valorReemplazar;
            printf("Valor %d reemplazado por %d\n", valorBuscar, valorReemplazar);
            encontrado=1;
        }
        temp = temp->Ptrsig;
    }
    
    if(!encontrado){
        printf("\nValor %d no encontrado en la lista.\n", valorBuscar);
    }
    
    return Ptr;
}

// Función para ordenar los nodos de menor a mayor (método burbuja)
struct Dato* ordenar(struct Dato *Ptr){
    struct Dato *i, *j;
    int temp;
    
    if(Ptr==NULL || Ptr->Ptrsig==NULL){
        printf("\nNo hay suficientes nodos para ordenar.\n");
        return Ptr;
    }
    
    i = Ptr;
    while(i != NULL){
        j = i->Ptrsig;
        while(j != NULL){
            if(i->d > j->d){
                // Intercambiar solo los valores, no los punteros
                temp = i->d;
                i->d = j->d;
                j->d = temp;
            }
            j = j->Ptrsig;
        }
        i = i->Ptrsig;
    }
    
    printf("\nLista ordenada de menor a mayor:\n");
    mostrar(Ptr);
    
    return Ptr;
}