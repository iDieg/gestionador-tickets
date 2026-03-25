#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TICKETS 100
#define MAX_LONGITUD 100

// Definición de Colores ANSI
#define RESET     "\x1b[0m"
#define ROJO      "\x1b[31m"
#define VERDE     "\x1b[32m"
#define AMARILLO  "\x1b[33m"
#define AZUL      "\x1b[34m"
#define CYAN      "\x1b[36m"
#define BLANCO_B  "\x1b[1m\x1b[37m"

typedef struct {
    int id;
    char titulo[MAX_LONGITUD];
    char descripcion[MAX_LONGITUD];
    char estado[20];
} Ticket;

Ticket tickets[MAX_TICKETS];
int num_tickets = 0;
int proximo_id = 1;

// Funciones para limpiar pantalla y buffer
void limpiar_pantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cabecera() {
    // Se limpia pantalla y se muestra la cabecera del sistema
    limpiar_pantalla();
    printf(CYAN "==========================================\n" RESET);
    printf(BLANCO_B "       SISTEMA-GESTOR-DE-TICKETS \n" RESET);
    printf(CYAN "==========================================\n" RESET);
}

void generar_ticket() {
    if (num_tickets >= MAX_TICKETS) {
        printf(ROJO "Error: Limite de tickets alcanzado.\n" RESET);
        return;
    }

    Ticket nuevo;
    nuevo.id = proximo_id++;
    
    cabecera();
    printf(AMARILLO ">> CREAR NUEVO TICKET\n" RESET);
    printf("Titulo: ");
    limpiar_buffer();
    fgets(nuevo.titulo, MAX_LONGITUD, stdin);
    nuevo.titulo[strcspn(nuevo.titulo, "\n")] = 0;

    printf("Descripcion: ");
    fgets(nuevo.descripcion, MAX_LONGITUD, stdin);
    nuevo.descripcion[strcspn(nuevo.descripcion, "\n")] = 0;

    strcpy(nuevo.estado, "Abierto");
    tickets[num_tickets++] = nuevo;

    printf(VERDE "\n[!] Ticket #%d generado con exito.\n" RESET, nuevo.id);
    printf("\nPresione Enter para continuar...");
    getchar();
}

void listar_tickets() {
    limpiar_pantalla();
    cabecera();
    if (num_tickets == 0) {
        printf(AMARILLO "No hay tickets en el sistema.\n" RESET);
    } else {
        printf("%-4s | %-20s | %-10s\n", "ID", "TITULO", "ESTADO");
        printf("------------------------------------------\n");
        for (int i = 0; i < num_tickets; i++) {
            char *color = RESET;
            if (strcmp(tickets[i].estado, "Abierto") == 0) color = ROJO;
            else if (strcmp(tickets[i].estado, "Cerrado") == 0) color = VERDE;
            else color = AMARILLO;

            printf("%-4d | %-20.20s | %s%s%s\n", 
                   tickets[i].id, tickets[i].titulo, color, tickets[i].estado, RESET);
        }
    }
    printf("\nPresione Enter para volver...");
    limpiar_buffer();
    getchar();
}

void actualizar_estado() {
    int id_buscar;
    printf("\nID del ticket a actualizar: ");
    scanf("%d", &id_buscar);

    for (int i = 0; i < num_tickets; i++) {
        if (tickets[i].id == id_buscar) {
            printf("Estado actual: " CYAN "%s\n" RESET, tickets[i].estado);
            printf("Nuevo estado (Abierto/Proceso/Cerrado): ");
            limpiar_buffer();
            fgets(tickets[i].estado, 20, stdin);
            tickets[i].estado[strcspn(tickets[i].estado, "\n")] = 0;
            printf(VERDE "Estado actualizado correctamente.\n" RESET);
            return;
        }
    }
    printf(ROJO "ID no encontrado.\n" RESET);
}

void ver_ticket() {
    int id_buscar;
    limpiar_pantalla();
    cabecera();
    printf(AMARILLO ">> DETALLE DE TICKET\n" RESET);
    printf("Ingrese el ID (o 0 para ver todos): ");
    scanf("%d", &id_buscar);

    if (id_buscar == 0) {
        for (int i = 0; i < num_tickets; i++) {
            printf("\n" AZUL "------------------------------------------" RESET);
            printf("\n" BLANCO_B "ID: %d | Titulo: %s", tickets[i].id, tickets[i].titulo);
            printf("\n" BLANCO_B "Descripcion: %s", tickets[i].descripcion);
            printf("\n" BLANCO_B "Estado: %s", tickets[i].estado);
        }
        printf("\n" AZUL "------------------------------------------" RESET);
        printf("\n\n" AMARILLO"Presione Enter para continuar...");
        limpiar_buffer(); getchar();
    } else {
        for (int i = 0; i < num_tickets; i++) {
            if (tickets[i].id == id_buscar) {
                printf("\n" CYAN "DETALLES DEL TICKET #%d" RESET, tickets[i].id);
                printf("\n" BLANCO_B "Titulo: " RESET "%s", tickets[i].titulo);
                printf("\n" BLANCO_B "Descripcion: " RESET "%s", tickets[i].descripcion);
                printf("\n" BLANCO_B "Estado: " RESET "%s\n", tickets[i].estado);
                printf("\n" AMARILLO "Presione Enter para continuar...");
                limpiar_buffer(); getchar();
                return;
            }
        }
        printf(ROJO "\nTicket no encontrado.\n" RESET);
    printf("\nPresione Enter para volver...");
    limpiar_buffer(); getchar();
}


}

int main() {
    int opcion;
    do {
        limpiar_pantalla();
        cabecera();
        printf(AZUL " 1." RESET " Generar nuevo ticket\n");
        printf(AZUL " 2." RESET " Listar tickets\n");
        printf(AZUL " 3." RESET " Actualizar estado\n");
        printf(AZUL " 4." RESET " Detalle de ticket\n");
        printf(ROJO " 5." RESET " Salir\n");
        printf("\nSeleccione: ");
        
        if(scanf("%d", &opcion) != 1) {
             printf(ROJO "Error de entrada.\n" RESET);
             break;
        }

        switch (opcion) {
            case 1: 
                generar_ticket(); 
                break;
            case 2: 
                listar_tickets(); 
                break;
            case 3: 
                actualizar_estado();
                printf("\nPresione Enter para continuar...");
                limpiar_buffer(); getchar();
                break;
            case 4: 
                ver_ticket();
                break;
            case 5: 
                printf(AMARILLO "Saliendo del sistema...\n" RESET); 
                break;
            default: 
                printf(ROJO "Opcion no valida.\n" RESET);
                printf("\nPresione Enter para volver...");
                limpiar_buffer(); getchar();
        }
    } while (opcion != 5);

    return 0;
}