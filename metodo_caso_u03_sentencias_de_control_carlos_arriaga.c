// Incluye la biblioteca estándar de entrada/salida
#include <stdio.h>

// Declaración de prototipos de funciones para modularizar los bloques de código
void ejemplo_control_stock();
void ejemplo_sistema_login();
void ejemplo_switch_eficiencia();
void ejemplo_do_while_procesamiento();

// =========================================================================
// BLOQUE 1: Control de Stock (If-Else) - Mover lógica fuera de main()
// =========================================================================
void ejemplo_control_stock() {
    printf("\n=== EJEMPLO 1: Control de Stock (If-Else) ===\n");
    
    // Declara una constante 'stock_threshold' (umbral de stock) con valor 50.
    const int stock_threshold = 50;

    // Declara una variable 'current_stock' (stock actual) y la inicializa en 45.
    int current_stock = 45; 
    
    // Declara una variable 'reorder_amount' (cantidad a reordenar) y la inicializa en 0.
    int reorder_amount = 0; 

    // Inicia una sentencia de control IF.
    if (current_stock < stock_threshold) { 
        printf("Stock actual: %d / Umbral: %d.\n", current_stock, stock_threshold);
        reorder_amount = stock_threshold - current_stock; 
        printf("Reorder %d items to reach the stock threshold.\n", reorder_amount);
    } else { 
        printf("Stock level is sufficient.\n");
    }
}

// =========================================================================
// BLOQUE 2: Sistema de Login (While Loop) - Modificado de main() a función
// =========================================================================
void ejemplo_sistema_login() {
    printf("\n=== EJEMPLO 2: Sistema de Login (While Loop) ===\n");
    
    // Declara una constante para el número máximo de intentos permitidos
    const int max_attempts = 3; 
    
    // Declara un contador para los intentos; se inicializa en 0
    int attempt = 0;
    int password_correct = 0; 
    int user_input; 
    
    printf("--- Pruebe la funcionalidad de Login. (Contraseña: 1234) ---\n");
    
    while (attempt < max_attempts && !password_correct) {
        
        printf("Enter password (1234): "); 
        
        // Lee la entrada del usuario. ¡El programa esperará aquí!
        if (scanf("%d", &user_input) != 1) {
             printf("Error de lectura o entrada no válida. Saltando ejemplo.\n");
             // Limpiar el buffer de entrada para evitar problemas de scanf
             while(getchar() != '\n'); 
             break;
        }

        if (user_input == 1234) { 
            password_correct = 1; 
            printf("Access granted.\n"); 
        } else { 
            attempt++;
            printf("Incorrect password. Attempt %d of %d.\n", attempt, max_attempts);
        }
    } 

    if (!password_correct && attempt == max_attempts){
        printf("Access denied. Too many incorrect attempts.\n");
    }
}

// =========================================================================
// BLOQUE 3: Mejora de Eficiencia (Switch) - Modificado de main() a función
// =========================================================================
void ejemplo_switch_eficiencia() {
    printf("\n=== EJEMPLO 3: Mejora de Eficiencia (Switch) ===\n");
    
    // Declara una constante para la eficiencia "antes" (70%)
    const int efficiency_before = 70; 
    
    // Declara una constante para la eficiencia "después" (95%)
    const int efficiency_after = 95; 
    
    int improvement =  efficiency_after - efficiency_before;

    printf("Eficiencia antes: %d%%. Eficiencia después: %d%%.\n", efficiency_before, efficiency_after);
    printf("Efficiency improved by %d%% after implementing control statements.\n", improvement);

    switch (improvement) { 
        case 25: 
            printf("Resultado Switch: Improvement is average compared to other companies.\n");
            break; 
        case 30:
            printf("Resultado Switch: Improvement is above average compared to other companies.\n");
            break; 
        default:
            printf("Resultado Switch: Improvement is significant.\n");
            break;
    }
}

// =========================================================================
// BLOQUE 4: Procesamiento de Ítems (Do-While) - Modificado de main() a función
// =========================================================================
void ejemplo_do_while_procesamiento() {
    printf("\n=== EJEMPLO 4: Procesamiento de Ítems (Do-While) ===\n");
    
    // Declara una constante para el número máximo de ítems a procesar
    const int max_items = 10;
    
    // Declara un contador para los ítems procesados, inicializado en 0
    int item_count = 0;

    do {
        printf("Processing item %d\n", item_count + 1);
        item_count++;
    } while (item_count < max_items);

    printf("All items processed. Consider using advanced data structures for more complex tasks.\n");
}


// =========================================================================
// FUNCIÓN PRINCIPAL ÚNICA (Punto de Entrada)
// =========================================================================
int main() {
    
    printf("INICIANDO EJECUCIÓN DE LOS CUATRO EJEMPLOS DE C...\n");

    // Llama a las funciones en el orden original
    ejemplo_control_stock();
    ejemplo_sistema_login(); // ¡Este ejemplo esperará tu entrada por teclado!
    ejemplo_switch_eficiencia();
    ejemplo_do_while_procesamiento();

    printf("\nFIN DE LA EJECUCIÓN DE TODOS LOS EJEMPLOS.\n");
    
    // Esta sentencia indica al sistema operativo que el programa terminó exitosamente.
    return 0;
}
