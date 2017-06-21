#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

#define NUMERO_MAXIMO_DOMINOS 100000

int casos;

typedef vector<int> vector_enteros;
typedef stack<int> pila_enteros;
typedef vector<vector_enteros> grafo_enteros;

// Variables para cada caso
int numero_dominos, lineas;
grafo_enteros dominos;
vector_enteros dominos_iniciadores;

bool Backtrack(int numero_toques, int domino) {

}

int ejecutar() {

	scanf("%d", &casos);

	// Por cada caso
	for (int c = 0; c < casos; c++) {
		scanf("%d %d", &numero_dominos, &lineas);

		dominos = grafo_enteros(numero_dominos);

		// Almacenar los dominos en el grafo
		for (int i = 0; i < lineas; i++) {
			int dominio_a, domino_b;

			scanf("%d %d", &dominio_a, &domino_b);
			dominos[dominio_a].push_back(domino_b);
		}

		int numero_toques_ideal = 1;

		do {
			if (Backtrack(numero_toques_ideal)) {
				printf("%d", numero_toques_ideal);
				return;
			}
			else {
				numero_toques_ideal += 1;
			}

		} while (numero_toques_ideal <= numero_dominos);

		// Salto de linea para cada caso
		printf("\n");
	}
}

/*
LINK: https://uva.onlinejudge.org/external/115/11504.pdf
INPUT
2
3 2
1 2
2 3
10 10
4 9
6 8
9 5
8 1
3 10
5 9
5 6
8 6
10 7
1 8
OUTPUT
1
3
*/