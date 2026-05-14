#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int n;
    struct Nodo *sig;
    struct Nodo *ant;
};

typedef struct Nodo Nodo;

Nodo *lista = NULL;


void liberarLista(){

    if(lista == NULL)
        return;

    Nodo *actual = lista->sig;

    while(actual != lista){

        Nodo *temp = actual;
        actual = actual->sig;
        free(temp);
    }

    free(lista);
    lista = NULL;
}

int main(){

    int opcion;

    do{

        printf("\n===== Lista Circular =====\n");
        printf("1. Insertar un elemento\n");
        printf("2. Eliminar un elemento\n");
        printf("3. Mostrar elementos\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion){

            case 1: {

                printf("\nIngrese el valor: ");

                Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));

                if(nuevo == NULL){
                    printf("Error de memoria.\n");
                    break;
                }

                scanf("%d", &nuevo->n);

                
                if(lista == NULL){

                    nuevo->sig = nuevo;
                    nuevo->ant = nuevo;
                    lista = nuevo;

                }else{

                    Nodo *ultimo = lista->ant;

                    nuevo->sig = lista;
                    nuevo->ant = ultimo;

                    ultimo->sig = nuevo;
                    lista->ant = nuevo;
                }

                printf("Elemento insertado correctamente.\n");
                break;
            }

            case 2: {

                if(lista == NULL){

                    printf("\nLa lista esta vacia.\n");

                }else{

                    int valor;
                    int encontrado = 0;

                    printf("\nValor a eliminar: ");
                    scanf("%d", &valor);

                    Nodo *actual = lista;

                    do{

                        if(actual->n == valor){

                            encontrado = 1;

                            
                            if(actual->sig == actual){

                                lista = NULL;

                            }else{

                                actual->ant->sig = actual->sig;
                                actual->sig->ant = actual->ant;

                                
                                if(actual == lista){
                                    lista = actual->sig;
                                }
                            }

                            free(actual);

                            printf("Elemento eliminado correctamente.\n");
                            break;
                        }

                        actual = actual->sig;

                    }while(actual != lista);

                    if(!encontrado){
                        printf("No se encontro el valor.\n");
                    }
                }

                break;
            }

            case 3: {

                if(lista == NULL){

                    printf("\nLa lista esta vacia.\n");

                }else{

                    Nodo *temp = lista;

                    printf("\nElementos de la lista:\n");

                    do{

                        printf("%d <-> ", temp->n);
                        temp = temp->sig;

                    }while(temp != lista);

                    printf("(regresa al inicio)\n");
                }

                break;
            }

            case 4: {

                liberarLista();
                printf("\nMemoria liberada correctamente.\n");
                printf("Saliendo del programa...\n");
                break;
            }

            default:
                printf("\nOpcion invalida.\n");
        }

    }while(opcion != 4);

    return 0;
}