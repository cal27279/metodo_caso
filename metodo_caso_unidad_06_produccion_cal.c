/*
 * ===================================================================================
 * Metodo_caso_unidad_06_produccion_cal(sistema_produccion.c)
 *
 * Descripcion:  Simulación de Sistema Modular para el Departamento de Producción
 * de "La Farmacéutica"
 * Materia: Programación I
 *===================================================================================
 */

// --- Inclusión de Funciones Predefinidas (Bibliotecas) ---
// stdio.h: Para funciones de entrada/salida (printf, scanf)
// stdlib.h: Para funciones generales (rand, srand, exit)
// time.h:   Para inicializar el generador de números aleatorios (time)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// --- Declaración de Constantes (Ámbito Global) ---
// Buenas Prácticas de Manufactura (GMP)
#define LOTE_STANDARD 100      // Unidades por lote para control de calidad
#define MINIMO_GMP 90          // Puntaje mínimo para Aseguramiento de Calidad
#define MATERIA_PRIMA_LOTE 500 // Cantidad de MP (simulada) en inventario

// --- Se hace la de declaración de Variables Globales ---
// Estas son para el módulo de reportes.
int g_unidadesProducidas = 0;
int g_lotesRechazados = 0;

// --- Prototipos de Funciones, tambien la podemos llamr Declaración de Módulos ---
// Módulo Principal (Menú)
void mostrarMenu();

// Módulos de Producción
void moduloFabricacion();

// Módulos de Control de Calidad
void moduloControlCalidad();
// Función auxiliar que usa "paso por referencia"
void inspeccionarLote(int *defectosEncontrados);

// Módulos de Aseguramiento de Calidad
void moduloAseguramiento();
// Función auxiliar que usa "paso por valor"
int evaluarGMP(int puntaje);

// Módulos del Sistema
void moduloReportes();
int obtenerOpcion();

/*
 * =====================================================================================
 * FUNCIÓN PRINCIPAL (main)
 * =====================================================================================
 */
int main()
{
    int opcion;
    // Iniciamos el generador de números aleatorios (función predefinida)
    srand(time(NULL));

    // --- Uso de Loop 'do-while' ---
    // El menú principal se repite hasta que el usuario elija "Salir" (opción 0)
    do
    {
        mostrarMenu();
        opcion = obtenerOpcion(); // Módulo de Entrada

        // --- Uso de 'switch' (alternativa a if-else anidado) ---
        // Gestiona la selección del módulo
        switch (opcion)
        {
        case 1:
            moduloFabricacion(); // Módulo de Procesamiento
            break;
        case 2:
            moduloControlCalidad(); // Módulo de Procesamiento
            break;
        case 3:
            moduloAseguramiento(); // Módulo de Procesamiento
            break;
        case 4:
            moduloReportes(); // Módulo de Reportes
            break;
        case 0:
            printf("\nSaliendo del sistema...\n");
            break;
        default:
            printf("\nError: Opcion invalida. Intente otra vez.\n");
            break;
        }

    } while (opcion != 0);

    return 0;
}

/*
 * ===================================================================================
 * MÓDULOS DEL SISTEMA
 ===================================================================================
 */

/**
 * @brief Muestra el menú principal (Módulo de Salida)
 */
void mostrarMenu()
{
    printf("\n--- Sistema de Gestion de Produccion 'La Farmaceutica' ---\n");
    printf("1. Modulo de Fabricacion\n");
    printf("2. Modulo de Control de Calidad\n");
    printf("3. Modulo de Aseguramiento de la Calidad\n");
    printf("4. Modulo de Reportes\n");
    printf("0. Salir\n");
    printf("----------------------------------------------------------\n");
}

/**
 * @brief Obtiene la entrada del usuario (Módulo de Entrada)
 * @return La opción seleccionada por el usuario.
 */
int obtenerOpcion()
{
    int opcion;
    printf("Seleccione una opcion: ");
    // Uso de función predefinida 'scanf'
    scanf("%d", &opcion);
    return opcion;
}

/**
 * @brief Módulo 1: Simula la fabricación de productos.
 * Demuestra el uso de 'for' y 'if-else'.
 */
void moduloFabricacion()
{
    // 'lotesAFabricar' es una variable local (Ámbito de Función)
    int lotesAFabricar;
    printf("\n[Modulo de Fabricacion]\n");
    printf("Cuantos lotes desea fabricar?: ");
    scanf("%d", &lotesAFabricar);

    int materiaPrimaRequerida = lotesAFabricar * 10; // 10 unidades de MP por lote

    // --- Uso de Sentencia 'if-else' ---
    // Verifica si hay suficiente materia prima (simulada)
    if (materiaPrimaRequerida <= MATERIA_PRIMA_LOTE)
    {
        printf("Iniciando fabricacion...\n");

        // --- Uso de Bucle 'for' ---
        // Simula el tiempo de producción de cada lote
        for (int i = 0; i < lotesAFabricar; i++)
        {
            printf("... Lote %d/%d fabricado.\n", i + 1, lotesAFabricar);
            // Actualiza la variable global
            g_unidadesProducidas += LOTE_STANDARD;
        }
        printf("Fabricacion completada. Total de unidades: %d\n", lotesAFabricar * LOTE_STANDARD);
    }
    else
    {
        printf("Error: Materia prima insuficiente. Se requieren %d y solo hay %d.\n",
               materiaPrimaRequerida, MATERIA_PRIMA_LOTE);
    }
}

/**
 * @brief Módulo 2: Simula el control de calidad de un lote.
 * Demuestra el "paso por referencia".
 */
void moduloControlCalidad()
{
    printf("\n[Modulo de Control de Calidad]\n");
    printf("Inspeccionando un lote estandar de %d unidades...\n", LOTE_STANDARD);

    // 'defectos' es una variable local
    int defectuosos = 0;

    // --- Paso de Parámetros por Referencia ---
    // Pasamos la dirección de memoria de 'defectuosos' (&defectuosos).
    // La función 'inspeccionarLote' modificará directamente el valor
    // de la variable 'defectuosos' de esta función.
    inspeccionarLote(&defectuosos);

    printf("Inspeccion terminada. Unidades defectuosas encontradas: %d\n", defectuosos);

    // --- Uso de 'if-else' ---
    if (defectuosos > 5)
    { // 5 es el límite de tolerancia (ejemplo)
        printf("Resultado: LOTE RECHAZADO (Excede tolerancia).\n");
        g_lotesRechazados++; // Actualiza variable global
    }
    else
    {
        printf("Resultado: LOTE APROBADO.\n");
    }
}

/**
 * @brief Función auxiliar que simula la inspección.
 * Demuestra el 'while' y el uso de punteros.
 * @param defectosEncontrados Puntero a una variable int (paso por referencia)
 */
void inspeccionarLote(int *defectosEncontrados)
{
    // 'unidadesInspeccionadas' es una variable local
    int unidadesInspeccionadas = 0;

    // --- Uso de Bucle 'while' ---
    // Inspecciona mientras no se haya revisado el lote completo
    while (unidadesInspeccionadas < LOTE_STANDARD)
    {
        // Simula un defecto (función predefinida 'rand')
        // rand() % 100 genera un número entre 0 y 99.
        // Si es menor que 3 (3% de probabilidad), es defectuoso.
        if (rand() % 100 < 3)
        {
            // Usa el operador de desreferenciación (*) para modificar
            // el valor en la dirección de memoria que nos pasaron.
            (*defectosEncontrados)++;
        }
        unidadesInspeccionadas++;
    }
}

/**
 * @brief Módulo 3: Simula el aseguramiento de calidad (GMP).
 * Demuestra el "paso por valor".
 */
void moduloAseguramiento()
{
    printf("\n[Modulo de Aseguramiento de la Calidad (GMP)]\n");
    // Simula un puntaje aleatorio de auditoría
    int puntajeAuditoria = 85 + (rand() % 16); // Puntaje entre 85 y 100

    printf("Realizando auditoria de Buenas Practicas de Manufactura (GMP)...\n");
    printf("Puntaje de auditoria obtenido: %d\n", puntajeAuditoria);

    // --- Paso de Parámetros por Valor ---
    // Se pasa una COPIA del valor de 'puntajeAuditoria'.
    // La función 'evaluarGMP' no puede modificar la variable
    // 'puntajeAuditoria' original de esta función.
    int esAprobado = evaluarGMP(puntajeAuditoria);

    // --- Uso de 'if-else' ---
    if (esAprobado == 1)
    {
        printf("Resultado: El proceso CUMPLE con los estandares GMP.\n");
    }
    else
    {
        printf("Resultado: El proceso NO CUMPLE. Requiere revision.\n");
    }
}

/**
 * @brief Evalúa si un puntaje cumple el mínimo de GMP.
 * @param puntaje Copia del puntaje (paso por valor).
 * @return 1 si es aprobado, 0 si no.
 */
int evaluarGMP(int puntaje)
{
    // 'puntaje' aquí es una copia local.
    // Si la modificáramos (ej. puntaje = 0;),
    // no afectaría a la variable 'puntajeAuditoria' de la otra función.
    if (puntaje >= MINIMO_GMP)
    {
        return 1; // Aprobado
    }
    else
    {
        return 0; // No aprobado
    }
}

/**
 * @brief Módulo 4: Muestra un reporte simple usando variables globales.
 */
void moduloReportes()
{
    printf("\n[Modulo de Reportes del Sistema]\n");
    printf("======================================\n");
    printf("Total Unidades Producidas: %d\n", g_unidadesProducidas);
    printf("Total Lotes Rechazados:    %d\n", g_lotesRechazados);
    printf("======================================\n");
}
