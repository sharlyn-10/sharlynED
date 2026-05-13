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
struct Dato* contar(struct Dato *Ptr);
struct Dato* reemplazar(struct Dato *Ptr);
struct Dato* ordenar(struct Dato *Ptr);
struct Dato* ordenarr(struct Dato *Ptr);

int main()
{
    struct Dato *Ptr=NULL;
    int op, opcion, valor, nnodos=0;
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
                            printf("Ingresa el valor a buscar:");
                            scanf("%d",&valor);

                            Ptraux = Ptr;
                            while(Ptraux != NULL){
                                if(Ptraux->d == valor){
                                    printf("Dato encontrado\n");
                                    break;
                                }
                                Ptraux = Ptraux->Ptrsig;
                            }
                            if(Ptraux == NULL){
                                printf("Dato no encontrado\n");
                            }
                            break;
                        case 2:
                            Ptr=contar(Ptr);
                            break;
                        case 3:
                            Ptr=reemplazar(Ptr);
                            break;
                        case 4:
                            Ptr=ordenar(Ptr);
                            printf("\nNodos ordenados correctamente.\n");
                            break;
                        case 5:
                            Ptr=ordenarr(Ptr);
                            break;
                        case 6:
                            printf("Regresando...\n");
                            break;
                        default:
                            printf("\nOpcion no valida en el submenu.\n");
                    }
                }while(opcion!=6);
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
                    printf("%d->", Ptr->d);
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
    printf("[5].Ordenarr\n");
    printf("[6].Regresar\n");
    printf("Escoja una opcion, porfas\n");
    scanf("%d", &opcion);

    return opcion;

}

// Función para buscar un nodo por su valor


//Función contar nodos
struct Dato* contar(struct Dato *Ptr){
    int contN=0;
    struct Dato *ptraux;
    ptraux = Ptr;
    if(ptraux==NULL){
        printf("No existen Nodos\n");
    }else{
        while(ptraux!=NULL){
            contN++;
            ptraux = ptraux->Ptrsig;
        }
        printf("El número de nodos es: %d", contN);
    }
    return contN;
}
// Función para reemplazar un nodo por otro valor
struct Dato* reemplazar(struct Dato *Ptr){
    int viejo, nuevo;
    struct Dato *ptraux;

    if(Ptr == NULL){
        printf("La lista esta viacia\n");
        return;
    }

    printf("Ingresa el dato que deseas reemplazar: ");
    scanf("%d", &viejo);

    printf("Ingresa el nuevo dato: ");
    scanf("%d", &nuevo);

    ptraux = Ptr;

    while(ptraux !=NULL){
        if(ptraux->d == viejo){
            ptraux->d = nuevo;
            printf("El dato fue reemplazado\n");
            return;
        }
        ptraux = ptraux->Ptrsig;
    }
    printf("El dato no existe en la lista\n");
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


// Función para ordenar los nodos moviendo punteros (método burbuja)
struct Dato* ordenarr(struct Dato *Ptr){
    struct Dato *i, *j, *anti, *antj, *temp, *sigj;
    int camb;
    
    if(Ptr==NULL || Ptr->Ptrsig==NULL){
        printf("\nNo hay suficientes nodos para ordenar.\n");
        return Ptr;
    }
    
    camb = 1;

    struct Dato *daux = (struct Dato*)malloc(sizeof(struct Dato));
    daux->Ptrsig = Ptr;
    
    while(camb){
        camb = 0;
        anti = daux;
        i = daux->Ptrsig;
        
        while(i != NULL && i->Ptrsig != NULL){
            j = i->Ptrsig;
            antj = i;
            
            if(i->d > j->d){
                camb = 1;
                
                sigj = j->Ptrsig;
                
                // Reorganizamos los punteros
                anti->Ptrsig = j; 
                j->Ptrsig = i; 
                i->Ptrsig = sigj;
                
                anti = j; 
            } else {
                anti = i;
                i = i->Ptrsig;
            }
        }
    }
    
    Ptr = daux->Ptrsig;
    free(daux); // Liberamos el nodo daux
    
    printf("\nLista ordenada de menor a mayor:\n");
    mostrar(Ptr);
    
    return Ptr;
}

/*for(;ptraux->ptrsig!=NULL;){
    if(ptraux->dato>(ptraux->ptrsig)->dato){
        ptrtemp=ptraux;
        ptraux=ptraux->ptrsig;
        ptrtemp->ptrsig=ptraux->ptrsig;
        ptraux->ptrsig=ptrtemp;
        ptrant->ptrsig=ptraux;
    }
    Ptrant=Ptraux;
    ptraux=ptraux->ptrsig;
}*/