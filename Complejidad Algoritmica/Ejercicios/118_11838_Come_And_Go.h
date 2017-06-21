#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

#define MAXIMO_NUMERO_DE_INTERSECCIONES 2000
#define MAXIMO_NUMERO_DE_CALLES 1999000

typedef vector<int>	vector_enteros;
typedef vector<bool> vector_bools;
typedef stack<int> pila_enteros;
typedef vector<vector_enteros> grafo_enteros;

// Variables para cada caso
grafo_enteros ciudad;
grafo_enteros ciudad_invertida;
vector_bools dfs_recorridas;
vector_bools dfs_invertido_recorridas;
pila_enteros dfs_pila;
pila_enteros dfs_invertido_pila;
int intersecciones; // nodos
int calles;			// aristas

void DFS(int interseccion) {
	dfs_recorridas[interseccion] = true;
	
	for (int i = 0; i < ciudad[interseccion].size(); i++) {
		int adyacente = ciudad[interseccion][i];

		if (dfs_recorridas[adyacente] == false)
			DFS(adyacente);
	}

	dfs_pila.push(interseccion);
}

void DFS_Invertido(int interseccion) {
	dfs_invertido_recorridas[interseccion] = true;

	for (int i = 0; i < ciudad_invertida[interseccion].size(); i++) {
		int adyacente = ciudad_invertida[interseccion][i];

		if (dfs_invertido_recorridas[adyacente] == false)
			DFS_Invertido(adyacente);
	}

	dfs_invertido_pila.push(interseccion);
}

int ejecutar() {

	while (scanf("%d %d", &intersecciones, &calles) != EOF) {

		// Condicion para salir del bucle
		if (intersecciones == 0 && calles == 0)
			break;

		ciudad = grafo_enteros(intersecciones);
		ciudad_invertida = grafo_enteros(intersecciones);

		dfs_recorridas = vector_bools(intersecciones);
		dfs_invertido_recorridas = vector_bools(intersecciones);

		// Iteracion para almacenar las calles en el grafo "ciudad"
		for (int c = 0; c < calles; c++) {
			int calle_a, calle_b, sentido;

			scanf("%d %d %d", &calle_a, &calle_b, &sentido);

			calle_a --; calle_b --;

			if (sentido == 1) {
				ciudad[calle_a].push_back(calle_b);
				ciudad_invertida[calle_b].push_back(calle_a);
			}
			else if (sentido == 2) {
				ciudad[calle_a].push_back(calle_b);
				ciudad[calle_b].push_back(calle_a);
				ciudad_invertida[calle_a].push_back(calle_b);
				ciudad_invertida[calle_b].push_back(calle_a);
			}
		}

		// Se hace una iteracion para asegurar que se recorran todas las calles
		for (int i = 0; i < intersecciones; i++) {
			if (dfs_recorridas[i] == false)
				DFS(i);
		}

		int dfs_scc = 0;
		
		// Se hace lo mismo pero con el grafo invertido
		while (dfs_pila.empty() != false) {
			int interseccion = dfs_pila.top();
			dfs_pila.pop();

			if (dfs_invertido_recorridas[interseccion] == false) {
				DFS_Invertido(interseccion);
				dfs_scc++;
			}
		}

		printf("%d", dfs_scc == 1 ? 1 : 0);

		// Salto de linea para el siguiente caso
		printf("\n");
		dfs_pila = pila_enteros();
	}

	return 0;
}

/*
LINK: https://uva.onlinejudge.org/external/118/11838.pdf
INPUT
4 5
1 2 1
1 3 2
2 4 1
3 4 1
4 1 2
3 2
1 2 2
1 3 2
3 2
1 2 2
1 3 1
4 2
1 2 2
3 4 2
0 0
OUTPUT
1
1
0
0
*/