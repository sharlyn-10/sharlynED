#include <stdio.h>

struct Dato {
    int d;
    struct Dato *Ptrsig;
};

int main(void) {
    struct Dato *Ptr = NULL;
    int op;

    do {
        printf("--MENÚ--\n");
        printf("[1].Crear dato (Método 1 - retorna dirección)\n");
        printf("[2].Mostrar todos los datos\n");
        printf("[3].Liberar toda la lista\n");
        printf("[4].Salir\n");
        printf("\nElija una opción: ");
        scanf("%d", &op);
        printf("\n");

        switch (op) {
            case 1:
                // Método 1: La función crea el nuevo módulo y retorna la dirección de memoria
                if(Ptr == NULL) {
                    Ptr = crearDato();
                    if(Ptr != NULL) {
                        printf("Primer dato creado y asignado como cabeza de lista.\n");
                    }
                } else {
                    // Si ya hay datos, agregamos al final
                    agregarDato(&Ptr);
                }
                break;
                
            case 2:
                mostrarDatos(Ptr);
                break;
                
            case 3:
                liberarLista(&Ptr);
                break;
                
            case 4:
                printf("Saliendo...\n");
                break;
                
            default:
                printf("Opción invalida, trate de nuevo...\n");
                break;
        }
    } while (op != 4);
    
    // Liberar memoria antes de salir por si el usuario no lo hizo
    if(Ptr != NULL) {
        printf("\nLiberando memoria pendiente antes de salir...\n");
        liberarLista(&Ptr);
    }
    
    return 0;
}

// MÉTODO 1: Crea el nuevo módulo y retorna la dirección de memoria
struct Dato* crearDato(void) {
    struct Dato *nuevo = (struct Dato*)malloc(sizeof(struct Dato));
    
    if(nuevo == NULL) {
        printf("Error: No se pudo asignar memoria\n");
        return NULL;
    }
    
    printf("Ingrese el valor entero para el dato: ");
    scanf("%d", &(nuevo->d));
    
    nuevo->Ptrsig = NULL;
    
    printf("Dato creado exitosamente en dirección: %p\n", (void*)nuevo);
    return nuevo;
}

// Función para mostrar todos los datos de la lista
void mostrarDatos(struct Dato *Ptr) {
    if(Ptr == NULL) {
        printf("No hay datos para mostrar. La lista está vacía.\n");
        return;
    }
    
    printf("\n=== LISTA DE DATOS ===\n");
    int contador = 1;
    struct Dato *actual = Ptr;
    
    while(actual != NULL) {
        printf("Dato %d: Valor = %d, Dirección = %p, Siguiente = %p\n", 
               contador, actual->d, (void*)actual, (void*)actual->Ptrsig);
        actual = actual->Ptrsig;
        contador++;
    }
    printf("Total de elementos: %d\n", contador - 1);
}

// Función para liberar toda la memoria de la lista
void liberarLista(struct Dato **Ptr) {
    if(*Ptr == NULL) {
        printf("No hay memoria que liberar. La lista ya está vacía.\n");
        return;
    }
    
    struct Dato *actual = *Ptr;
    struct Dato *siguiente;
    int contador = 0;
    
    while(actual != NULL) {
        siguiente = actual->Ptrsig;
        printf("Liberando dato en dirección %p con valor %d\n", (void*)actual, actual->d);
        free(actual);
        actual = siguiente;
        contador++;
    }
    
    *Ptr = NULL;
    printf("Se liberaron %d elementos. Lista vaciada completamente.\n", contador);
}

// Función para agregar un nuevo dato al final de la lista (opal - mejora)
void agregarDato(struct Dato **Ptr) {
    struct Dato *nuevo = crearDato();
    if(nuevo == NULL) return;
    
    if(*Ptr == NULL) {
        *Ptr = nuevo;
    } else {
        struct Dato *actual = *Ptr;
        while(actual->Ptrsig != NULL) {
            actual = actual->Ptrsig;
        }
        actual->Ptrsig = nuevo;
    }
    printf("Dato agregado al final de la lista.\n");
}