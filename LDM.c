/* 
Lonesome-Dungeon-Madness
Cristobal Vasquez
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char aTILDE = 160, eTILDE = 130, iTILDE = 161, oTILDE = 162, uTILDE = 163;


/*
0 = pocion
1 = ogro (1 dadoATA)
2 = lobo (2)
3 = esqueleto (3)
4 = guerrero (4)
5 = murcielago (5)
6 = ciclope (6)
7 = elfo oscuro (7)
8 = lord esqueleto (8)
9 = mago (9)
10 = demonio (10)
11 = Dracula (9 + 9 dadoDEF)
12 = vacio
13 = tesoro
*/



int CASILLA[11][6] = {
	{0, 1, 1, 1, 12, 13} ,
	{1, 2, 12, 12, 12, 13} ,
	{1, 2, 3, 13, 0, 12} ,
	{1, 2, 3, 4, 13, 12} ,
	{2, 3, 4, 5, 13, 12} ,
	{3, 4, 5, 6, 13, 0} ,
	{4, 5, 6, 7, 13, 12} ,
	{5, 6, 7, 8, 13, 12} ,
	{6, 7, 8, 9, 13, 0} ,
	{7, 8, 9, 10, 13, 12} ,
	{11, 11, 11, 11, 11, 11} 
};

/*
precios {objeto, precio}
1 = Escudo de madera     dadoDEF +1 (info[6]++)
2 = pocion               pociones +1 (info[3]++)
3 = escudo de hierro     dadoDEF +2 (info[6] = info[6] + 2)
4 = 3 pociones           pociones +3 (info[3] = info[3] + 3)
5 = espada               dadoATA +1 (info[5]++)
6 = 6 pociones           pociones +6 (info[3] = info[3] + 6)
7 = hacha guerrera       dadoATA +2 (info[5] = info[5] + 2)
8 = armadura con espinas dadoATA +2, dadoDEF +1 (info[5] = info[5] + 2, info[6]++)
9 = armadura magica      dadoDEF +5 (info[6] = info[6] + 5)

*/

int PRECIOS[10][2] = {
	{1, 1} ,
	{2, 1} ,
    {3, 2} ,
    {4, 2} ,
    {5, 3} ,
    {6, 3} ,
    {7, 4} ,
    {8, 5} ,
    {9, 6} ,
    {0, -2}
};



void titulo(){
	printf(" _\n");
	printf("| |\n");
	printf("| |     ___  _ __   ___  ___  ___  _ __ ___   ___\n");
	printf("| |    / _ \\| '_ \\ / _ \\/ __|/ _ \\| '_ ` _ \\ / _ \\\n");
	printf("| |___| (_) | | | |  __/\\__ \\ (_) | | | | | |  __/\n");
	printf("|______\\___/|_| |_|\\___||___/\\___/|_| |_| |_|\\___|\n");
	printf("|  __ \\\n");
	printf("| |  | |_   _ _ __   __ _  ___  ___  _ __\n");
	printf("| |  | | | | | '_ \\ / _` |/ _ \\/ _ \\| '_ \\\n");
	printf("| |__| | |_| | | | | (_| |  __/ (_) | | | |\n");
	printf("|_____/ \\__,_|_| |_|\\__, |\\___|\\___/|_| |_|\n");
	printf("|  \\/  |         | | __/ |\n");
	printf("| \\  / | __ _  __| ||___/  ___  ___ ___\n");
	printf("| |\\/| |/ _` |/ _` | '_ \\ / _ \\/ __/ __|\n");
	printf("| |  | | (_| | (_| | | | |  __/\\__ \\__ \\\n");
	printf("|_|  |_|\\__,_|\\__,_|_| |_|\\___||___/___/\n\n\n");
	printf("Presione Enter para comenzar ");
	getc(stdin);
	printf("\n\n");
}

void mega_salto(){
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

int contar_elementos_arreglo(char *arr){
	int cont = 0, i = 0;
	while (arr[i]!=0){
		cont++;
		i++;
	}
	if (arr[0]==52 && arr[1]==50){
		cont=1;
	}
	return cont;
}
void reiniciar_arreglo(char *arr, int len){
	int i;
	for (i=0; i<len; i++){
		arr[0] = 0;
	}
}


/* 
Esta funcion recibe la fila y la columna a la que el jugador se movera
y el puntero a la posicion (0,0) del tablero. Actualiza el tablero y lo muestra
en pantalla
*/

void mostrar_tablero(int fila, int columna, int tablero[][11]){
	int i, j;
	printf("\n");
	for (i=11; i>=0; i--){
		for (j=0; j<11; j++){
            if (fila==i && columna==j){
				tablero[i][j] = 74;
				printf("| %c |", tablero[i][j]);
			}
			else if (fila+1==i && columna-1==j && (tablero[i][j]<48 || tablero[i][j]==70)){
				printf("| 1 |");

			}
			else if (fila+1==i && columna==j && (tablero[i][j]<48 || tablero[i][j]==70)){
				printf("| 2 |");

			}
			else if (fila+1==i && columna+1==j && (tablero[i][j]<48 || tablero[i][j]==70)){
				printf("| 3 |");

			}
			else if (fila==i && columna+1==j && tablero[i][j]<48){
				printf("| 4 |");

			}
			else if (fila-1==i && columna+1==j && tablero[i][j]<48){
				printf("| 5 |");

			}
			else if (fila-1==i && columna==j && tablero[i][j]<48){
				printf("| 6 |");

			}
			else if (fila-1==i && columna-1==j && tablero[i][j]<48){
				printf("| 7 |");

			}
			else if (fila==i && columna-1==j && tablero[i][j]<48){
				printf("| 8 |");

			}
			else if (tablero[i][j]==74){
				tablero[i][j] = 88;
				printf("| %c |", tablero[i][j]);
			}						
			else{
				if (tablero[i][j] == 58){
					printf("|L10|");
				}
				else if (tablero[i][j] == 48){
					printf("| X |");
				}
				else if (tablero[i][j]>48 && tablero[i][j]<58){
					printf("| L%c|", tablero[i][j]);
				}
				else{
					printf("| %c |", tablero[i][j]);
				}
			}			
		}
		printf("\n");
	}	
}

void mostrar_stats(int* info){
	printf("\nPuntos de vida: %d  Tesoros: %d\nDados de ataque: %d  Dados de defensa:\
 %d\nPociones: %d         ", info[7], info[4], info[5], info[6], info[3]);
	printf("Escudo: ");
	if(info[0]==1){
		printf("Escudo de madera\n");
	}
	else if(info[0]==2){
		printf("Escudo de hierro\n");
	}
	else{
		printf("Ninguno\n");
	}
	printf("Arma: ");
	if (info[1]==1){
		printf("Espada  ");
	}
	else if(info[1]==2){
		printf("Hacha Guerrera  ");
	}
	else{
		printf("Ninguna       ");
	}
	printf("Armadura: ");
	if (info[2]==1){
		printf("Armadura con espinas\n");
	}
	else if(info[2]==2){
		printf("Armadura m%cgica\n", aTILDE);
	}
	else{
		printf("Ninguna\n");
	}
}

void mostrar_tienda(){
	printf("\n              OBJETO                        TESOROS");
	printf("\n(1) ESCUDO DE MADERA    (D-DEF +1)             1");
	printf("\n(2) 1 POCION            (POCIONES +1)          1");
	printf("\n(3) ESCUDO DE HIERRO    (D-DEF +2)             2");
	printf("\n(4) 3 POCIONES          (POCIONES +3)          2");
	printf("\n(5) ESPADA              (D-ATA +1)             3");
	printf("\n(6) 6 POCIONES          (POCIONES +6)          3");
	printf("\n(7) HACHA GUERRERA      (D-ATA +2)             4");
	printf("\n(8) ARMADURA DE ESPINAS (D-ATA +2, D-DEF +1)   5");
	printf("\n(9) ARMADURA MAGICA     (D-DEF +5)             6");
	printf("\n(0) No comprar nada\n\n");
}

int verificar_movida(int fila, int columna, int tablero[][11], char *dir, int *mov){
	int dir_int;
	dir_int = dir[0] - 48;
	if (dir[0]==52 && dir[1]==50){
		dir_int=42;
	}
	if (dir_int==2){
		if (tablero[fila+1][columna]==45 || tablero[fila+1][columna]==70){
			mov[0] = fila + 1;
			mov[1] = columna;
			return 1;
		}	
	} 
	else if (dir_int==1){
		if (tablero[fila+1][columna-1]==45 || tablero[fila+1][columna]==70){
			mov[0] = fila + 1;
			mov[1] = columna-1;
			return 1;
		}
	}
	else if (dir_int==8){
		if (tablero[fila][columna-1]==45){
			mov[0] = fila;
			mov[1] = columna-1;
			return 1;
		}
	}
	else if (dir_int==7 && fila!=0){
		if (tablero[fila-1][columna-1]==45){
			mov[0] = fila - 1;
			mov[1] = columna - 1;
			return 1;
		}
	}
	else if (dir_int==6 && fila!=0){
		if (tablero[fila-1][columna]==45){
			mov[0] = fila - 1;
			mov[1] = columna;
			return 1;
		}
	}
	else if (dir_int==5 && fila!=0){
		if (tablero[fila-1][columna+1]==45){
			mov[0] = fila - 1;
			mov[1] = columna + 1;
			return 1;
		}
	}
	else if (dir_int==4){
		if (tablero[fila][columna+1]==45){
			mov[0] = fila;
			mov[1] = columna + 1;
			return 1;
		}
	}
	else if (dir_int==3 || tablero[fila+1][columna+1]==70){
		if (tablero[fila+1][columna+1]==45){
			mov[0] = fila + 1;
			mov[1] = columna + 1;
			return 1;
		}
	}
	else if (dir_int==42){
		return 42;
	}
	else{
		return 0;
	}
}

int verificar_encierro(int fila, int columna, int tablero[][11]){
	if (tablero[fila+1][columna-1]!=45 && tablero[fila+1][columna]!=45 \
	&& tablero[fila+1][columna+1]!=45 && tablero[fila][columna+1]!=45 \
	&& tablero[fila-1][columna+1]!=45 && tablero[fila-1][columna]!=45 \
	&& tablero[fila-1][columna-1]!=45 && tablero[fila][columna-1]!=45){
		if (tablero[fila+1][columna-1]==70 || tablero[fila+1][columna]==70 \
		|| tablero[fila+1][columna+1]==70){
			return 0;
		}
		else{
			return 1;
		}
	}
	else{
		return 0;
	}
}

int mostrar_dado(int dado){
	if (dado==1){
		printf(" _________ \n");
		printf("|         |\n");
		printf("|         |\n");
		printf("|    O    |\n");
		printf("|         |\n");
		printf("|_________|\n");
	}

	else if (dado==2){
		printf(" _________ \n");
		printf("|         |\n");
		printf("| O       |\n");
		printf("|         |\n");
		printf("|       O |\n");
		printf("|_________|\n");
	}
	else if (dado==3){
		printf(" _________ \n");
		printf("|         |\n");
		printf("| O       |\n");
		printf("|    O    |\n");
		printf("|       O |\n");
		printf("|_________|\n");
	}
	else if (dado==4){
		printf(" _________ \n");
		printf("|         |\n");
		printf("| O     O |\n");
		printf("|         |\n");
		printf("| O     O |\n");
		printf("|_________|\n");
	}
	else if (dado==5){
		printf(" _________ \n");
		printf("|         |\n");
		printf("| O     O |\n");
		printf("|    O    |\n");
		printf("| O     O |\n");
		printf("|_________|\n");
	}
	else if (dado==6){
		printf(" _________ \n");
		printf("|         |\n");
		printf("| O     O |\n");
		printf("| O     O |\n");
		printf("| O     O |\n");
		printf("|_________|\n");
	}

	return 0;
}

int batalla(int cont_casilla, int* items){
	char enemigo[20];
	int dados_def_enemigo = 0, dados_ata_enemigo = cont_casilla, hp_enemigo = 1, golpes_enemigo = 0; 
	int defensa_enemigo = 0, defensa = 0, golpes = 0, dados, i;
	if (cont_casilla==1){
		sprintf(enemigo, "Ogro");
	}
	else if (cont_casilla==2){
		sprintf(enemigo, "Lobo");
	}
	else if (cont_casilla==3){
		sprintf(enemigo, "Esqueleto");
	}
	else if (cont_casilla==4){
		sprintf(enemigo, "Guerrero");
	}
	else if (cont_casilla==5){
		sprintf(enemigo, "Murci%clago", eTILDE);
	}
	else if (cont_casilla==6){
		sprintf(enemigo, "C%cclope", iTILDE);
	}
	else if (cont_casilla==7){
		sprintf(enemigo, "Elfo Oscuro");
	}
	else if (cont_casilla==8){
		sprintf(enemigo, "Lord Esqueleto");
	}
	else if (cont_casilla==9){
		sprintf(enemigo, "Mago");
	}
	else if (cont_casilla==10){
		sprintf(enemigo, "Demonio");
	}
	else{
		sprintf(enemigo, "Dr%ccula", aTILDE);
		dados_ata_enemigo = 9;
		dados_def_enemigo = 9;
	}
	printf("\n%s aparece frente a ti!\n", enemigo);
	if (cont_casilla==11){
		printf("\nEs en este momento que recuerdas quien eres realmente...");
		printf("\nUn descendiente del clan Belmont!\n");
		printf("\nPor generaciones, tu familia ha derrotado a Dracula");
		printf("\ny sus criaturas de la noche. Y esta vez, es tu deber seguir la tradicion");
		printf("\n(Presiona enter para cumplir tu destino...)");
		getc(stdin);
		mega_salto();
		printf("\n\n'DIE MONSTER, YOU DON'T BELONG IN THIS WORLD\n\n");
	}

	while (hp_enemigo>0 && items[7]>0){
		for (i=0; i<dados_ata_enemigo; i++){
			dados = (rand() % 6) + 1;
			if (dados==6){
				golpes_enemigo++;
			}		
		}
		if (golpes_enemigo>0){
			if (golpes_enemigo==1){
				printf("\n%s est%c preparando %d ATAQUE DIRECTO\nHora de lanzar tus DADOS DE DEFENSA. Presiona enter...", \
			        	enemigo, aTILDE, golpes_enemigo);
				getc(stdin);
			}
			else{
				printf("\n%s est%c preparando %d ATAQUES DIRECTOS\nHora de lanzar tus DADOS DE DEFENSA. Presiona enter...", \
			        	enemigo, aTILDE, golpes_enemigo);
				getc(stdin);
			}
			mega_salto();
			for (i=0; i<items[6]; i++){
				dados = (rand() % 6) + 1;
				mostrar_dado(dados);
				if (dados==6){
					defensa++;
				}
			}
			golpes_enemigo = golpes_enemigo - defensa;
			if (golpes_enemigo<0){
				golpes_enemigo = 0;
			}
			if (golpes_enemigo==0){
				printf("\nLogras esquivar todos los ataques!");
			}
			else if(golpes_enemigo==1){
				items[7]--;
				printf("\n%s te hiere levemente a pesar de tus intentos por esquivarlo", enemigo);
			}
			else{
				items[7] = items[7] - golpes_enemigo;
				if (items[7]<0){
					items[7] = 0;
				}
				printf("\nIntentas esquivar los ataques, pero recibes %d golpes directos", golpes_enemigo);

			}
		}
		else{
			printf("\n%s est%c leyendo el manual del juego", enemigo, aTILDE);
		}
		if (items[7]==0){
			printf("\nTambaleas un poco y caes derrotado\n");
			return 2;
		}
		else{
			if (items[7]<6){
				printf("\nTus heridas tienen heridas. Sientes que no durar%cs mucho m%cs", aTILDE, aTILDE);
			}
			printf("\nHora de lanzar tus DADOS DE ATAQUE. Presiona enter...");
			getc(stdin);
			mega_salto();
			for (i=0; i<items[5]; i++){
				dados = (rand() % 6) + 1;
				mostrar_dado(dados);
				if (dados==6){
					golpes++;
				}
			}
			for (i=0; i<dados_def_enemigo; i++){
				dados = (rand() % 6) + 1;
				if (dados==6){
					defensa_enemigo++;
				}
			}
			if (golpes==0){
				printf("\nCorres hacia tu enemigo como un mani%ctico y te tropiezas con tu capa", aTILDE);

			}
			else{
				golpes = golpes - defensa_enemigo;
				if (golpes<0){
					golpes = 0;
				}
				if (golpes==0){
					printf("\n%s esquiva todos tus ataques con facilidad", enemigo);
				}
				else if (golpes==1){
					hp_enemigo--;
					if (items[1]==1){
						printf("\nAgitas tu espada firmemente y logras darle a algo.\n%s esta muerto", enemigo);
					}
					else if(items[1]==2){
						printf("\nLanzas tu hacha hacia el enemigo y se incrusta en su cabeza\n%s esta muerto", enemigo);
					}
					else{
						printf("\nEmpujas a tu enemigo contra la pared y se golpea la cabeza.\n%s esta muerto", enemigo);
					}
				}
				else{
					hp_enemigo--;
					printf("\nTe abalanzas sobre tu enemigo y liberas toda tu ira reprimida");
					printf("\nSus extremidades decoran las paredes... %s ahora esta en un mejor lugar", enemigo);
				}
			}
		}
		defensa_enemigo = 0;
		defensa = 0;
		golpes_enemigo = 0;
		golpes = 0;


	}
	printf("\n(Presiona enter para continuar...)");
	getc(stdin);
	mega_salto();
	if (cont_casilla==11){
		return 3;
	}
	return 0;


}

int beber_pocion(int* items, int max_hp){
	char respuesta[10] = {0};
	int i = 0, cont_array;
	while (items[7]!=max_hp && items[3]!=0){
		if (i==0){
			printf("\n...Pero antes, deseas beber una pocion para recuperar un punto de vida?");
			printf("\n(Puntos de vida: %d | Pociones: %d)", items[7], items[3]);
			printf("\n(1) Si\n(2)Nah\nIngresa tu respuesta: ");
		}
		else{
			printf("\nDeseas beber otra?\n(Puntos de vida: %d | Pociones: %d)", items[7], items[3]);
			printf("\n(1) Si\n(2) Nah\nIngresa tu respuesta: ");
		}
		gets(respuesta);
		cont_array = contar_elementos_arreglo(respuesta);
		while (cont_array!=1 || respuesta[0]<49 || respuesta[0]>50){
			reiniciar_arreglo(respuesta, sizeof(respuesta)/sizeof(respuesta[0]));
			printf("\nIngrese una opcion valida: ");
			gets(respuesta);
			cont_array = contar_elementos_arreglo(respuesta);
		}	
		if (respuesta[0]==49){
			items[7]++;
			items[3]--;
			printf("\nBebes una pocion y reciclas la botella.");
		}
		else{
			return 0;
		}
		if (items[7]==max_hp || items[3]==0){
			printf("\nYa no puedes beber mas pociones.\n(Presiona enter para continuar...)");
			getc(stdin);
			mega_salto();
			return 0;
		}
	i++;
	}
	return 0;
}

int comprar(int* items){
	char respuesta[10] = {0}, equipar[10] = {0};
	int i = 0, j, cont_array;
	while(items[4]>0){
		if (i==0){
			printf("\n...Pero antes, deseas intercambiar tesoros por provisiones?");
			printf("\n(Tesoros: %d)\n(1) Si\n(2) Paso\nIngresa tu respuesta: ", items[4]);
		}
		else{
			printf("\nAun te quedan tesoros (%d), deseas adquirir algo mas?", items[4]);
			printf("\n(1) Si\n(2) Paso\nIngresa tu respuesta: ");
		}
		gets(respuesta);
		cont_array = contar_elementos_arreglo(respuesta);
		while (cont_array!=1 || respuesta[0]<49 || respuesta[0]>50){
			reiniciar_arreglo(respuesta, sizeof(respuesta)/sizeof(respuesta[0]));
			printf("\nIngrese una opcion valida: ");
			gets(respuesta);
			cont_array = contar_elementos_arreglo(respuesta);
		}
		if (respuesta[0]==49){
			reiniciar_arreglo(respuesta, sizeof(respuesta)/sizeof(respuesta[0]));
			mostrar_tienda();	
			mostrar_stats(items);
			printf("\nIngresa el numero del objeto que deseas: ");
			gets(respuesta);
			cont_array = contar_elementos_arreglo(respuesta);
			while (cont_array!=1 || respuesta[0]<48 || respuesta[0]>57 || items[4]<PRECIOS[respuesta[0]-49][1]){
				reiniciar_arreglo(respuesta, sizeof(respuesta)/sizeof(respuesta[0]));
				printf("\nIngrese una opcion valida: ");
				gets(respuesta);
				cont_array = contar_elementos_arreglo(respuesta);
			}
			if (respuesta[0]==48){
				return 0;
			}
			else if(respuesta[0]==49){
				if (items[0]==1){
					printf("\nYa tienes este escudo");
				}
				else if (items[0]==2){
					printf("\nYa tienes un escudo mejor");
				}
				else{
					items[0] = 1;
					items[6]++;
					items[4]--;
					printf("\nEscudo de madera adquirido");
				}
			}
			else if (respuesta[0]==50){
				items[3]++;
				items[4]--;
				printf("\nPocion adquirida");
			}
			else if (respuesta[0]==51){
				if (items[0]==2){
					printf("\nYa tienes este escudo");
				}
				else if (items[0]==1){
					items[0] = 2;
					items[6] = items[6] + 1;
					items[4] = items[4] - 2;
					printf("\nEscudo de hierro adquirido");
				}
				else{
					items[0] = 2;
					items[6] = items[6] + 2;
					items[4] = items[4] - 2;
					printf("\nEscudo de hierro adquirido");
				}
			}
			else if (respuesta[0]==52){
				items[3] = items[3] + 3;
				items[4] = items[4] - 2;
				printf("\n3 pociones adquiridas");
			}
			else if (respuesta[0]==53){
				if (items[1]==1){
					printf("\nYa tienes esta arma");
				}
				else if (items[1]==2){
					printf("\nYa tienes un arma mejor");
				}
				else{
					items[1] = 1;
					items[5]++;
					items[4] = items[4] - 3;
					printf("\nEspada adquirida");
				}
			}
			else if (respuesta[0]==54){
				items[3] = items[3] + 6;
				items[4] = items[4] - 3;
				printf("\n6 pociones adquiridas");
			}
			else if (respuesta[0]==55){
				if (items[1]==2){
					printf("\nYa tienes esta arma");
				}
				else if(items[1]==1){
					items[1] = 2;
					items[5] = items[5] + 1;
					items[4] = items[4] - 4;
					printf("\nHacha guerrera adquirida");
				}
				else{
					items[1] = 2;
					items[5] = items[5] + 2;
					items[4] = items[4] - 4;
					printf("\nHacha guerrera adquirida");
				}
			}
			else if(respuesta[0]==56){
				if (items[2]==1 || items[2]==3){
					printf("\nYa tienes esta armadura equipada");
				}
				else if(items[2]==4){
					reiniciar_arreglo(equipar, sizeof(equipar)/sizeof(equipar[0]));
					printf("\nYa tienes esta armadura en tu inventario, deseas equiparla?");
					printf("\n(1) Si\n(2) No\nIngresa tu eleccion: ");
					gets(equipar);
					cont_array = contar_elementos_arreglo(equipar);
						while (cont_array!=1 || equipar[0]<49 || equipar[0]>50){
							reiniciar_arreglo(equipar, sizeof(equipar)/sizeof(equipar[0]));
							printf("\nIngrese una opcion valida: ");
							gets(equipar);
							cont_array = contar_elementos_arreglo(equipar);
						}
					if (equipar[0]==49){
						items[2] = 3;
						items[5] = items[5] + 2;
						items[6] = items[6] - 4;
						printf("\nArmadura con espinas ha sido equipada. Guardas la otra en tu inventario");
					}
				}
				else if(items[2]==2){
					items[2] = 3;
					items[5] = items[5] + 2;
					items[6] = items[6] + 1;
					items[4] = items[4] - 5;
					printf("\nArmadura con espinas adquirida y equipada");
				}
				else{
					items[2] = 1;
					items[5] = items[5] + 2;
					items[6] = items[6] + 1;
					items[4] = items[4] - 5;
					printf("\nArmadura con espinas adquirida y equipada");
				}
			}
			else{
				if (items[2]==2 || items[2]==4){
					printf("\nYa tienes esta armadura equipada");
				}
				else if(items[2]==3){
					reiniciar_arreglo(equipar, sizeof(equipar)/sizeof(equipar[0]));
					printf("\nYa tienes esta armadura en tu inventario, deseas equiparla?");
					printf("\n(1) Si\n(2) No\nIngresa tu eleccion: ");
					gets(equipar);
					cont_array = contar_elementos_arreglo(equipar);
						while (cont_array!=1 || equipar[0]<49 || equipar[0]>50){
							reiniciar_arreglo(equipar, sizeof(equipar)/sizeof(equipar[0]));
							printf("\nIngrese una opcion valida: ");
							gets(equipar);
							cont_array = contar_elementos_arreglo(equipar);
						}
					if (equipar[0]==49){
						items[2] = 4;
						items[5] = items[5] - 2;
						items[6] = items[6] + 4;
						printf("\nArmadura magica ha sido equipada. Guardas la otra en tu inventario");
					}
				}
				else if(items[2]==1){
					items[2] = 4;
					items[6] = items[6] + 5;
					items[4] = items[4] - 6;
					printf("\nArmadura magica adquirida y equipada");
				}
				else{
					items[2] = 2;
					items[6] = items[6] + 5;
					items[4] = items[4] - 6;
					printf("\nArmadura magica adquirida y equipada");
				}

			}



		}
		else{
			mega_salto();
			return 0;
		}
		if (items[4]==0){
			printf("\nTe has quedado sin tesoros.\n(Presiona enter para continuar....)");
			getc(stdin);
			mega_salto();
			return 0;
		}
		i++;
	}

}

void dificultad(char* dif, int* items){
	int modo = dif[0]-48;
	if (modo==1){
		items[3] = 6;
		items[4] = 4;
		items[5] = 4;
		items[6] = 4;
		items[7] = 23;
	}
	else if (modo==2){
		items[3] = 3;
		items[4] = 2;
		items[5] = 2;
		items[6] = 2;
		items[7] = 20;
	}
	else if (modo==3){
		items[3] = 0;
		items[4] = 0;
		items[5] = 1;
		items[6] = 1;
		items[7] = 17;
	}

}

int main(){
	int filaA, columnaA, valido, i, j, nivel, dado, estado, contArray, contenidoCasilla;
	estado = 0;                             		// 0 = jugando, 1 = encerrado, 2 = muerto, 3 = victoria, 42 = salir 
	int tablero[12][11];
	int movimiento[2], info[8] = {0};
	char seed[50] = {0}, direccion[50] = {0}, modo[50] = {0};          
	nivel = 48;										// fila actual
	filaA = 0;										// columna actual						
	columnaA = 5;


	titulo();
	printf("\nDificultad:\n(1) Cachorro\n(2) Normal\n(3) Profesor de Metodos de programacion");
	printf("\nElige la dificultad del juego: ");
	gets(modo);
	contArray = contar_elementos_arreglo(modo);
	while (contArray!=1 || modo[0]<49 || seed[0]>51){
		reiniciar_arreglo(modo, sizeof(modo)/sizeof(modo[0]));
		printf("\nIngrese una opci%cn v%clida: ", oTILDE, aTILDE);
		gets(modo);
		contArray = contar_elementos_arreglo(modo);
	}

	dificultad(modo, info);

	printf("\n\nWELCOME TO THE LONESOME DUNGEON\nTe encuentras al frente de un pozo, el cual no parece tener fondo.");
	printf("\nHas llegado hasta este lugar luego de meses de busqueda, y aun no\nsabes porque estas aqui. De hecho");
	printf(" ni siquiera recuerdas tu nombre.\nTu intuicion te ha traido hasta aqui y tu intuicion determinara tu destino\n");
	printf("\nUn letrero al costado del pozo dice:\n(1) Dejar tu suerte en manos del tiempo\n(2) Tu haces tu propia suerte\n\n");
	printf("Ingresa tu eleccion: ");
	gets(seed);
	contArray = contar_elementos_arreglo(seed);
	while (contArray!=1 || seed[0]<49 || seed[0]>50){
		reiniciar_arreglo(seed, sizeof(seed)/sizeof(seed[0]));
		printf("Ingresa una opcion valida: ");
		gets(seed);
		contArray = contar_elementos_arreglo(seed);
	}
	if (seed[0]==50){
		printf("Haz tu propia suerte ingresando una palabra: ");
		gets(seed);
		srand(560 + seed[0] - seed[1] + seed[2] *87);
		printf("\nGritas '%s!!!' a los cuatro vientos y sientes que este sera el mejor dia de tu vida.", seed);
	}
	else{
		srand(time(NULL));
	}

	printf("\nPor razones que aun desconoces, decides saltar dentro del pozo...\n(Presiona enter para continuar)");
	getc(stdin);
	mega_salto();
/*
	tablero = malloc((12) * sizeof(int));

	if (tablero == NULL){
		printf("Quedo la embarrada\n");
		return 0;
	}

	for (i=0; i<12; i++){
		tablero[i] = malloc((11) * sizeof(int));
	}
*/
	for (i=0; i<12; i++){
		for (j=0; j<11; j++){
			if (i==filaA && j==columnaA){
				tablero[i][j] = 74;
			}
			else if (i==11 && j==5){
				tablero[i][j] = 70;
			}
			else if (i==0 || i==11 || j==10){
				tablero[i][j] = 88;
			}
			else if (j==0){
				tablero[i][j] = nivel;
			}
			else{
				tablero[i][j] = 45;
			}
		}
		nivel++;
	}

	mostrar_tablero(filaA, columnaA, tablero);
	mostrar_stats(info);

	while (estado==0){
		char direccion[50] = {0};
		printf("\nIngresa una direccion para moverte: ");
		gets(direccion);
		mega_salto();
		contArray = contar_elementos_arreglo(direccion);
		valido = verificar_movida(filaA, columnaA, tablero, direccion, movimiento);
		if (contArray==1 && valido==1){
			filaA = movimiento[0];
			columnaA = movimiento[1];
			printf("\n\n\n\n\n\n\n\n\n\n\n\n");
			dado = (rand() % 6) + 1;
			mostrar_dado(dado);
			contenidoCasilla = CASILLA[filaA-1][dado-1];
			if (contenidoCasilla==0){
				info[3]++;
				printf("\nPociones +1\n");
			}
			else if (contenidoCasilla==13){
				info[4]++;
				printf("\nTesoros +1\n");
			}
			else if (contenidoCasilla==12){
				printf("\nTu camino esta libre\n");
			}
			else{
				estado = batalla(contenidoCasilla, info);
				if (estado!=2 && estado!=3){
					if (info[3]!=0 && info[7]<(26-(modo[0]-48)*3)){
						beber_pocion(info, 26-(modo[0]-48)*3);
					}
					if (info[4]!=0){
						comprar(info);
					}
				}
			}
			if (filaA!=11 && estado!=2){
				mostrar_tablero(filaA, columnaA, tablero);
				mostrar_stats(info);
				estado = verificar_encierro(filaA, columnaA, tablero);
			}
		}
		else if(valido==42){
			estado = 42;
		}
		else{
			printf("\nMovimiento invalido\n");
		}
	}

	if (estado==1){
		printf("\n\nLuego de estar atrapado 3 dias en una mazmorra, sin comida\n");
		printf("y sin agua, das tu ultimo respiro y maldices al creador de\n"); 
		printf("esta trampa mortal llamada Lonesome-Dungeon-Madness.\n");
	}
	else if (estado==2){
		printf("\n\nMientras yaces moribundo en el aspero suelo de este horripilante lugar\n");
		printf("reflexionas acerca de todos los errores que cometiste en tu aventura.\n");
		printf("Talvez no estabas preparado para un desafio de esta magnitud.\n");
		printf("Talvez simplemente tuviste mala suerte\n");
		printf("Talvez... talvez no debiste haber usado una capa, pero todos estos\n");
		printf("pensamientos se van esfumando a medida que tu vida se apaga y ya nada mas importa.\n");

	}
	else if (estado==3){
		printf("\nMientras el cadaver de Dracula Vlad Tepes se esfuma en el denso\n");
		printf("\naire de sus aposentos, decides retornar por donde viniste, sintiendo");
		printf("\nque finalmente sabes quien eres y cual es tu lugar en este mundo.");
		printf("\nEscalas el pozo y sales decidido a encontrar a tu siguiente objetivo.");
		printf("\nAlucard Fahrenheit Tepes.\n");
	}
	else if(estado==42){
		printf("\n\nEstar en un lugar tan sordido y violento te ha hecho\n");
        printf("reconsiderar las decisiones en tu vida que te llevaron\n");
		printf("a estar aqui. Concluyes que la vida es demasiado corta\n");
		printf("para malgastarla en una pobre imitacion de un dungeon crawler\n");
		printf("superior y decides abandonar este loco y solitario calabozo.\n");
	}

	printf("GAME OVER\nPresiona enter para salir...");
/*
	for (i=0; i<12; i++){
		free(tablero[i]);
	}

	free(tablero); 
*/
	getc(stdin);

	return 0;
}