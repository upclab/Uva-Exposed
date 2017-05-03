#include <stdio.h>
#include <vector>

using namespace std;

#define MAXIMO_NUMERO_DE_CIUDADES 200
#define NO_COLOR 0
#define ROJO 1
#define AZUL 2

typedef vector<int> vector_enteros;
typedef vector<vector_enteros> grafo_enteros;

// Variables para cada caso
int numero_ciudades;
int numero_aristas;
grafo_enteros ciudades;
vector_enteros color_de_ciudad;

bool DFS(int ciudad, int color) {

	color_de_ciudad[ciudad] = color;
	
	for (int c = 0; c < ciudades[ciudad].size(); c++) {
		int ciudad_vecina = ciudades[ciudad][c];

		if (color_de_ciudad[ciudad_vecina] == NO_COLOR) {
			// Hacemos el DFS a la ciudad vecina con el color invertido
			if (DFS(ciudad_vecina, color == ROJO ? AZUL : ROJO) == false)
				return false;
		}
		else {
			if (color_de_ciudad[ciudad_vecina] == color)
				return false;
		}
	}

	return true;
}

int ejecutar() {

	do {
		scanf("%d", &numero_ciudades);

		// Cuando leamos un 0 se acaban los numeros de casos
		if (numero_ciudades == 0)
			break;

		scanf("%d", &numero_aristas);

		ciudades = grafo_enteros(numero_ciudades);
		color_de_ciudad = vector_enteros(numero_ciudades, NO_COLOR);

		// Se lee una conexion entre dos ciudades
		for (int n = 0; n < numero_aristas; n++) {
			int primera_ciudad;
			int segunda_ciudad;

			scanf("%d %d", &primera_ciudad, &segunda_ciudad);
			ciudades[primera_ciudad].push_back(segunda_ciudad);
			ciudades[segunda_ciudad].push_back(primera_ciudad);
		}

		int ciudad_inicio = 0;

		// Empezamos el DFS con cualquier color, en este caso me decidi por el rojo
		if (DFS(ciudad_inicio, ROJO))
			printf("BICOLORABLE.");
		else
			printf("NOT BICOLORABLE.");

		// Salto de linea para el siguiente caso
		printf("\n");
	} while (numero_ciudades != 0);

	return 0;
}

/*
LINK: https://uva.onlinejudge.org/external/100/10004.pdf
INPUT
3
3
0 1
1 2
2 0
3
2
0 1
1 2
9
8
0 1
0 2
0 3
0 4
0 5
0 6
0 7
0 8
0
OUTPUT
NOT BICOLORABLE.
BICOLORABLE.
BICOLORABLE.
*/