#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define TAMANIO_MAXIMO_LABERINO 100
#define AUN_NO_SE_CALCULAN_LOS_PASOS -1

typedef pair<int, int> punto;

int casos;

// Variables por cada laberinto
int filas, columnas;
punto inicio, fin;
char laberinto[TAMANIO_MAXIMO_LABERINO][TAMANIO_MAXIMO_LABERINO];
int pasos_hasta[TAMANIO_MAXIMO_LABERINO][TAMANIO_MAXIMO_LABERINO];

void BFS(punto comienzo) {
	queue<punto> por_explorar_adyacentes;

	por_explorar_adyacentes.push(comienzo);
	pasos_hasta[comienzo.first][comienzo.second] = 0;

	while (!por_explorar_adyacentes.empty()) {
		
		punto activo = por_explorar_adyacentes.front();
		por_explorar_adyacentes.pop();

		// Exploramos sus 4 adyacentes (no diagonales)
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {

				int numero_pasos_actual = pasos_hasta[activo.first][activo.second];

				// Validaciones
				if (abs(i) == abs(j)) continue;
				if (laberinto[activo.first + i][activo.second + j] == 'X') continue;
				if (pasos_hasta[activo.first + i][activo.second + j] != AUN_NO_SE_CALCULAN_LOS_PASOS) continue;

				// Asignar el numero de paso correspondiente
				pasos_hasta[activo.first + i][activo.second + j] = numero_pasos_actual + 1;
				por_explorar_adyacentes.push(punto(activo.first + i, activo.second + j));
			}
		}	
	}
}

void dibujar_laberinto() {
	printf("Solucion del laberinto\n");
	for (int f = 0; f < filas; f++) {
		for (int c = 0; c < columnas; c++) {
			// Para dibujar X, S, T
			if (laberinto[f][c] != '.')
				printf("|%c%c|", laberinto[f][c], laberinto[f][c]);
			// Para dibujar los pasos
			else
				printf("|%02d|", pasos_hasta[f][c], pasos_hasta[f][c]);
		}
		printf("\n");
	}
}

// Reemplazar 'ejecutar' por 'main' si se quiere crear un nuevo proyecto
int ejecutar() {
	
	scanf("%d", &casos);
	
	// Procedimiento repetitivo para cada ejercicio
	for (int k = 0; k < casos; k++) {
		scanf("%d %d", &filas, &columnas);

		// Procedimiento repetitivo por cada fila
		for (int f = 0; f < filas; f++) {
			scanf("%s", &laberinto[f]);
		}

		// Encontrando el inicio y el fin del laberinto
		// Inicializando matriz de pasos
		for (int f = 0; f < filas; f++) {
			for (int c = 0; c < columnas; c++) {
				pasos_hasta[f][c] = AUN_NO_SE_CALCULAN_LOS_PASOS;

				if (laberinto[f][c] == 'S')
					inicio = punto(f, c);
				else if (laberinto[f][c] == 'F')
					fin = punto(f, c);
			}
		}

		// Empezando con el BFS
		// Dibujar el laberinto con su solucion
		BFS(inicio);
		dibujar_laberinto();
	}

	return 0;
}

// Input Output Ejemplo
/*
INPUT
1
8 12
XXXXXXXXXXXX
X.S.X..X.X.X
XXX.X......X
X...X..XXX.X
X.XXX..X...X
X...X..XX.XX
X.X....X..TX
XXXXXXXXXXXX

OUTPUT
"Se debe mostrar el laberinto pero con todos los caminos recorridos"
*/