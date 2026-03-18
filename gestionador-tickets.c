// Sistema de Gestión de Tickets
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definiciones y estructuras
#define MAX_TICKETS 100
#define MAX_LONGITUD 100

typedef struct {
    int id;
    char titulo[MAX_LONGITUD];
    char descripcion[MAX_LONGITUD];
    char estado[20];
} Ticket;

Ticket tickets[MAX_TICKETS];
int num_tickets = 0;
int proximo_id = 1;

void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Funciones del sistema
// Generar un nuevo ticket
void generar_ticket() {
    // Verificar si se ha alcanzado el límite de tickets
    if (num_tickets >= MAX_TICKETS) {
        printf("Error: Limite de tickets alcanzado.\n");
        return;
    }

    // Crear un nuevo ticket
    Ticket nuevo_ticket;
    nuevo_ticket.id = proximo_id++;
    
    // Solicitar al usuario el título y la descripción del ticket
    printf("Ingrese el titulo del ticket: ");
    limpiar_buffer();
    fgets(nuevo_ticket.titulo, MAX_LONGITUD, stdin);
    nuevo_ticket.titulo[strcspn(nuevo_ticket.titulo, "\n")] = 0;

    // Solicitar la descripción del ticket
    printf("Ingrese la descripcion del ticket: ");
    fgets(nuevo_ticket.descripcion, MAX_LONGITUD, stdin);
    nuevo_ticket.descripcion[strcspn(nuevo_ticket.descripcion, "\n")] = 0;

    // El estado inicial del ticket es "Abierto" por defecto
    strcpy(nuevo_ticket.estado, "Abierto");

    // Agregar el nuevo ticket al arreglo o estructura de datos
    tickets[num_tickets++] = nuevo_ticket;
    printf("Ticket generado con exito. ID: %d\n", nuevo_ticket.id);
}

// Listar todos los tickets
void listar_tickets() {
    // Verificar si hay tickets registrados
    if (num_tickets == 0) {
        printf("No hay tickets registrados.\n");
        return;
    }

    // Mostrar la lista de tickets
    printf("\n##### - LISTA DE TICKETS - #####\n");
    for (int i = 0; i < num_tickets; i++) {
        printf("ID: %d | Título: %s | Estado: %s\n", 
               tickets[i].id, tickets[i].titulo, tickets[i].estado);
    }
}

// Actualizar el estado de un ticket
void actualizar_estado() {
    // Se solicita el ID del ticket a actualizar
    int id_buscar;
    printf("Ingrese el ID del ticket a actualizar: ");
    scanf("%d", &id_buscar);

    // Buscar el ticket por ID y actualizar su estado
    for (int i = 0; i < num_tickets; i++) {
        if (tickets[i].id == id_buscar) {
            printf("Estado actual: %s\n", tickets[i].estado);
            printf("Ingrese el nuevo estado (ej. Cerrado, En Proceso): ");
            limpiar_buffer();
            fgets(tickets[i].estado, 20, stdin);
            tickets[i].estado[strcspn(tickets[i].estado, "\n")] = 0;
            printf("Estado actualizado.\n");
            return;
        }
    }
    printf("Ticket no encontrado.\n");
}

// Ver la descripción de un ticket
void ver_ticket() {
    // Se solicita el ID del ticket para mostrar su descripción
    int id_buscar;
    printf("Ingrese el ID del ticket para visualizarlo de manera detallada (si desea verlos todos ingrese 0): ");
    scanf("%d", &id_buscar);

    if (id_buscar == 0) {
        // Mostrar todos los tickets de manera detallada
        printf("\n##### - TODOS LOS TICKETS - #####\n");
        for (int i = 0; i < num_tickets; i++) {
            printf("\n##### - TICKET: %s (ID: %d) - #####\n", tickets[i].titulo, tickets[i].id);
            printf("Descripcion: %s\n", tickets[i].descripcion);
            printf("Estado: %s\n", tickets[i].estado);
        }
        return;
    }
    // Busqueda de un ticket específico por ID
    for (int i = 0; i < num_tickets; i++) {
        if (tickets[i].id == id_buscar) {
            printf("\n##### - TICKET: %s (ID: %d) - #####\n", tickets[i].titulo, tickets[i].id);
            printf("Descripcion: %s\n", tickets[i].descripcion);
            return;
        }
    }
    printf("Ticket no encontrado.\n");
}

// Función principal
int main() {
    // Declaración de variable
    int opcion;

    // Menú principal
    do {
        printf("\n##### - SISTEMA GESTOR DE TICKETS - #####\n"); 
        printf("1. Generar nuevo ticket\n");
        printf("2. Listar tickets\n");
        printf("3. Actualizar estado de ticket\n");
        printf("4. Ver ticket de manera detallada\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        
        if(scanf("%d", &opcion) != 1) {
             printf("Entrada invalida. Saliendo...\n");
             break;
        }
        // Procesar la opción seleccionada
        switch (opcion) {
            case 1: generar_ticket(); break;
            case 2: listar_tickets(); break;
            case 3: actualizar_estado(); break;
            case 4: ver_ticket(); break;
            case 5: printf("Saliendo del sistema...\n"); break;
            default: printf("Opcion no valida.\n");
        }
    } while (opcion != 5);

    return 0;
}