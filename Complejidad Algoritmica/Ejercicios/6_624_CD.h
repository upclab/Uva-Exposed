#include <stdio.h>
#include <stack>

using namespace std;

#define MAX_CANCIONES_CD 20

// Variables para cada caso
int capacidad_total;
int numero_canciones;
int capacidad_ideal;

int duraciones[MAX_CANCIONES_CD];
stack<int> duraciones_optimizadas;

bool Backtrack(int capacidad, int cancion) {
	
	int duracion = duraciones[cancion];
	int siguiente_cancion = cancion + 1;

	if (duracion == capacidad) { duraciones_optimizadas.push(duracion); return true; }
	
	// Si llegamos a la ultima canción, no ha solucion para esta posibilidad
	if (siguiente_cancion == numero_canciones) return false;

	// Se debe buscar llegar a la capacidad con las siguientes canciones
	if (duracion < capacidad) {
		if (Backtrack(capacidad - duracion, siguiente_cancion)) { duraciones_optimizadas.push(duracion); return true; }
	}

	// Se cambia la cancion con la misma capacidad
	if (Backtrack(capacidad, siguiente_cancion)) return true;
}

int ejecutar() {

	while(scanf("%d", &capacidad_total) != EOF) {

		scanf("%d", &numero_canciones);

		capacidad_ideal = capacidad_total;

		for (int c = 0; c < numero_canciones; c++) {
			int duracion;

			scanf("%d", &duracion);
			duraciones[c] = duracion;
		}

		do {
			int cancion_inicial = 0;

			if (Backtrack(capacidad_ideal, cancion_inicial)) {
				while (!duraciones_optimizadas.empty()) {
					printf("%d ", duraciones_optimizadas.top());
					duraciones_optimizadas.pop();
				}

				printf("sum:%d", capacidad_ideal);
				break;
			}
			else {
				capacidad_ideal -= 1;
			}

		} while (capacidad_ideal > 0);

		// Salto de linea por cada caso
		printf("\n");

	}
	
	return 0;
}
/*
LINK: https://uva.onlinejudge.org/external/6/624.pdf
INPUT
5 3 1 3 4
10 4 9 8 4 2
20 4 10 5 7 4
90 8 10 23 1 2 3 4 5 7
45 8 4 10 44 43 12 9 8 2OUTPUT
1 4 sum:5
8 2 sum:10
10 5 4 sum:19
10 23 1 2 3 4 5 7 sum:55
4 10 12 9 8 2 sum:45
*/