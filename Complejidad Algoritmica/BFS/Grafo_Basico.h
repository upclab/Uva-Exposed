using namespace std;

#include <stdio.h>
#include <vector>
#include <queue>

typedef vector<int> Vi;
typedef vector<Vi> Gi;

Gi grafo;
Vi distancia;
int N, u, v, r;
int INFINITO = -1;

void BFS(int s)
{
	queue<int> cola;
	cola.push(s);
	distancia[s] = 0;

	while (!cola.empty())
	{
		int nodo = cola.front(); cola.pop();
		for (int i = 0; i < grafo[nodo].size(); i++)
		{
			int adyacente = grafo[nodo][i];

			if (distancia[adyacente] == INFINITO)
			{
				cola.push(adyacente);
				distancia[adyacente] = distancia[nodo] + 1;
			}
		}
	}
}

int ejecutar()
{
/*
7 14
0 1
0 6
1 0
1 3
2 5
2 6
3 0
3 1
3 2
3 4
5 2
5 4
5 6
6 1
*/

	scanf("%d %d", &N, &r);

	grafo = Gi(N);
	distancia = Vi(N, INFINITO);

	for (int i = 0; i < r; i++)
	{
		scanf("%d %d", &u, &v);
		grafo[u].push_back(v);
	}

	BFS(0);

	for (int i = 0; i < N; i++)
	{
		printf("%d %d -> %d\n", 0, i, distancia[i]);
	}

	return 0;
}