/* 

Lonesome-Dungeon-Maul
Cristobal Vasquez

*/

#include <stdio.h>
#include <stdlib.h>


/* 
Esta funcion recibe la fila y la columna a la que el jugador se movera
y el puntero a la posicion (0,0) del tablero. Actualiza el tablero y lo muestra
en pantalla
*/



int mostrar_T(int fila, int columna, int** tablero){
	int i, j;

	for (i=0; i<12; i++){
		for (j=0; j<11; j++){
            if (fila==i && columna==j){
				tablero[i][j] = 74;
				printf("| %c |", tablero[i][j]);
			}

			else if (tablero[i][j]==74){
				tablero[i][j] = 88;
				printf("| %c |", tablero[i][j]);
			}
			
			else{
				if (tablero[i][j] == 58){
					printf("|10 |");
				}
				else if (tablero[i][j] == 48){
					printf("| X |");
				}
				else{
					printf("| %c |", tablero[i][j]);


				}
			}
			
		}
		printf("\n");
	}
	printf("\n");
	return 0;	
}

int main(){
	int fila, columna;
	int i, j, nivel;
	int** tablero;
	nivel = 48;

	tablero = malloc((12) * sizeof(int));

	if (tablero == NULL){
		printf("Quedo la caga\n");
		return 0;
	}

	for (i=0; i<12; i++){
		tablero[i] = malloc((11) * sizeof(int));
	}


	for (i=0; i<12; i++){
		for (j=0; j<11; j++){
			if (i==0 && j==5){
				tablero[i][j] = 74;
				printf("| %d |", tablero[i][j]);
			}
			else if (i==0 || i==11){
				tablero[i][j] = 48;
				printf("| %d |", tablero[i][j]);
			}
			else if (j==0 || j==10){
				tablero[i][j] = 48;
				printf("| %d |", tablero[i][j]);
			}
			else{
				tablero[i][j] = nivel;
				if (i == 10){
					printf("| %d |", tablero[i][j]);
				}
				else{
					printf("| %d |", tablero[i][j]);
				}
			}
		}
		printf("\n");
		nivel++;
	}
	printf("\n");	



	fila = 0;
	columna = 5;
	mostrar_T(fila, columna, tablero);
	fila = 1;
	columna = 4;
	mostrar_T(fila, columna, tablero);
	fila = 1;
	columna = 5;
	mostrar_T(fila, columna, tablero);
	fila = 2;
	columna = 5;
	mostrar_T(fila, columna, tablero);
	fila = 2;
	columna = 4;
	mostrar_T(fila, columna, tablero);
	for (i=0; i<12; i++){
		free(tablero[i]);
	}

	free(tablero); 

	return 0;
}