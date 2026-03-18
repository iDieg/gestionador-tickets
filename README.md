# Sistema Gestor de Requerimientos (Tickets)

Un sistema de consola robusto y eficiente desarrollado en lenguaje C para la creación, lectura, actualización y eliminación (CRUD) de tickets de propósito general. 

Este proyecto fue diseñado tomando inspiración de los flujos operativos reales de los call centers y mesas de ayuda, enfocándose en la rapidez y la organización para optimizar la atención de solicitudes, quejas, tareas o pedidos dentro de un entorno empresarial.

## Autores
* **Diego Romero**
* **Ricardo Herrera**
* **Adriana Cuevas**

## Características y Funcionalidades
El sistema opera a través de un menú interactivo en la terminal que permite realizar las siguientes acciones en tiempo real:
* **Generar Tickets:** Registro de nuevas solicitudes asignando automáticamente un número de ID único, almacenando el título y una descripción detallada.
* **Listado General:** Visualización completa de todos los tickets registrados en memoria, mostrando su ID, título y estado operativo actual.
* **Actualización de Estado:** Búsqueda optimizada por ID para modificar el ciclo de vida del ticket (ej. pasar de "Abierto" a "En Proceso" o "Cerrado").

## Tecnologías y Conceptos Aplicados
Este proyecto consolida conceptos clave de la programación estructurada:
* **Lenguaje C** (C11 / Estándar ANSI C).
* Uso de `structs` para la encapsulación de datos (ID, Título, Descripción, Estado).
* Manejo de arreglos de memoria estática para el almacenamiento temporal de la base de datos de requerimientos.
* Modularización del código mediante funciones específicas para cada operación del ciclo CRUD.
* Limpieza de buffers de entrada para un manejo seguro de cadenas de texto con `fgets`.

## Instalación y Uso

### Descargar el ejecutable (Solo Windows)
1. Ve a la sección de [Releases](../../releases) de este repositorio.
2. Descarga el archivo `tickets.exe` de la última versión.
3. Haz doble clic sobre el archivo descargado para iniciar el sistema en tu terminal.

### Opción 2: Compilar desde el código fuente
Si deseas compilar el código por tu cuenta, necesitas tener instalado un compilador de C (como GCC vía MinGW/MSYS2 en Windows, o GCC estándar en Linux/macOS).

1. Clona este repositorio:
   ```bash
   git clone [https://github.com/TU_USUARIO/TU_REPOSITORIO.git](https://github.com/TU_USUARIO/TU_REPOSITORIO.git)