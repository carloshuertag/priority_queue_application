/*************************************************************************
 * dynamic_priority_string_queue_menu
 * @author: Carlos Huerta García
 * @description: Displays a menu to manage a dynamic priority string queue
 * ***********************************************************************/
#include "dynamic_string_queue.h"
void main() {
    Queue * stringQueue = NULL;
    char go = 's', newString[255] = "";
	int option;
	while(1){
        puts("\n0 Salir");
		puts("1 Crear cola de prioridad de cadenas por orden alfabético");
		puts("2 Imprimir cola de cadenas");
		puts("3 Tomar la cadena de mayor prioridad");
		puts("4 Desencolar cadena");
		puts("5 Encolar cadena");
		puts("6 Vaciar la cola de cadenas");
        puts("\nIntroduzca la opción deseada: ");
		scanf("%d", &option);
		switch(option){
            case 0:
                clearQueue(stringQueue);
                free(stringQueue);
                exit(0);
                break;
            case 1:
                stringQueue = createQueue();
                puts("Created string priority queue");
                break;
            case 2:
                if(stringQueue)
                    printQueue(stringQueue);
                else
                    puts("Current queue is empty");
                break;
            case 3:
                if(stringQueue){
                    front(stringQueue, newString);
                    if(strcmp(newString, ""))
                        printf("\nFront: %s\n", newString);
                    else
                        puts("Current queue is empty");
                } else
                    puts("Current queue is empty");
                break;
            case 4:
                if(stringQueue){
                    deQueue(stringQueue, newString);
                    if(strcmp(newString, ""))
                        printf("\nDequeued: %s\n", newString);
                    else
                        puts("Current queue is empty");
                } else
                    puts("Current queue is empty");
                break;
            case 5:
                if(stringQueue){
					printf("Introduzca la cadena: ");
					fflush(stdin);
					gets(newString);
                    fflush(stdin);
                    gets(newString);
					enQueue(newString, stringQueue);
				} else 
					puts("Current queue is empty");
                break;
            case 6:
                if(stringQueue)
                    clearQueue(stringQueue);
                else
                    puts("Current queue is empty");
                break;
            default:
                puts("Operación inválida");
                break;
        }
    }
    clearQueue(stringQueue);
    free(stringQueue);
}
