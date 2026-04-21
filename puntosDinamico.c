#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    int x, y;
};

struct Point *ptr = NULL;  // Puntero global para los puntos
int total_puntos = 0;      // Cuántos puntos se han reservado/ingresado

void ReservarMemoria() {
    int nueva_cantidad;
    
    printf("\n--- Reservar memoria ---\n");
    printf("¿Cuántos puntos desea ingresar? ");
    scanf("%d", &nueva_cantidad);
    
    if (nueva_cantidad <= 0) {
        printf("ERROR: La cantidad debe ser mayor a 0.\n");
        return;
    }
    
    // Liberar memoria anterior si existe
    if (ptr != NULL) {
        free(ptr);
        printf("Memoria anterior liberada.\n");
    }
    
    // Reservar nueva memoria
    ptr = (struct Point *)malloc(nueva_cantidad * sizeof(struct Point));
    
    if (ptr == NULL) {
        printf("ERROR: No se pudo reservar memoria.\n");
        total_puntos = 0;
    } else {
        total_puntos = nueva_cantidad;
        printf("¡Memoria reservada para %d puntos correctamente!\n", total_puntos);
    }
}

void IngresarPuntos() {
    if (ptr == NULL || total_puntos == 0) {
        printf("ERROR: Primero debe reservar memoria (opción 1).\n");
        return;
    }
    
    printf("\n--- Ingresar puntos ---\n");
    for (int i = 0; i < total_puntos; i++) {
        printf("Punto %d:\n", i + 1);
        printf("  x%d = ", i + 1);
        scanf("%d", &ptr[i].x);
        printf("  y%d = ", i + 1);
        scanf("%d", &ptr[i].y);
    }
    printf("¡Puntos ingresados correctamente!\n");
}

void CalcularDistancia() {
    int P1, P2, dx, dy, dis;
    double distancia;
    
    if (ptr == NULL || total_puntos == 0) {
        printf("ERROR: No hay puntos ingresados.\n");
        return;
    }
    
    printf("\n--- Calcular distancia ---\n");
    printf("Ingrese el número del primer punto (1..%d): ", total_puntos);
    scanf("%d", &P1);
    printf("Ingrese el número del segundo punto (1..%d): ", total_puntos);
    scanf("%d", &P2);
    
    if (P1 < 1 || P1 > total_puntos || P2 < 1 || P2 > total_puntos) {
        printf("ERROR: Números de punto inválidos.\n");
        return;
    }
    
    dx = ptr[P2 - 1].x - ptr[P1 - 1].x;
    dy = ptr[P2 - 1].y - ptr[P1 - 1].y;
    
    dx = dx * dx;
    dy = dy * dy;
    
    dis = dx + dy;
    distancia = sqrt(dis);
    
    printf("Distancia entre punto %d y punto %d = %.2f\n", P1, P2, distancia);
}

void ImprimirPuntos() {
    if (ptr == NULL || total_puntos == 0) {
        printf("ERROR: No hay puntos ingresados.\n");
        return;
    }
    
    printf("\n--- Puntos ingresados ---\n");
    for (int i = 0; i < total_puntos; i++) {
        printf("Punto %d: (x = %d, y = %d)\n", i + 1, ptr[i].x, ptr[i].y);
    }
}

void LiberarMemoria() {
    if (ptr != NULL) {
        free(ptr);
        ptr = NULL;
        total_puntos = 0;
        printf("Memoria liberada correctamente.\n");
    } else {
        printf("No hay memoria reservada para liberar.\n");
    }
}

int MostrarMenu() {
    int op;
    printf("\n========== MENÚ ==========\n");
    printf("1. Reservar memoria (crear arreglo dinámico)\n");
    printf("2. Ingresar puntos\n");
    printf("3. Calcular distancia\n");
    printf("4. Imprimir puntos\n");
    printf("5. Liberar memoria\n");
    printf("6. Salir\n");
    printf("==========================\n");
    printf("Escoja una opción: ");
    scanf("%d", &op);
    return op;
}

int main() {
    int opcion;
    
    do {
        opcion = MostrarMenu();
        
        switch (opcion) {
            case 1:
                ReservarMemoria();
                break;
            case 2:
                IngresarPuntos();
                break;
            case 3:
                CalcularDistancia();
                break;
            case 4:
                ImprimirPuntos();
                break;
            case 5:
                LiberarMemoria();
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no encontrada, intente de nuevo...\n");
        }
    } while (opcion != 6);
    
    // Liberar memoria por si acaso antes de salir
    if (ptr != NULL) {
        free(ptr);
    }
    
    return 0;
}