#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define MAXIMO_DE_EMPLEADOS 2500
#define MAXIMO_DE_AMIGOS 15
#define MAXIMO_DE_CASOS 60

#define NO_BOOMS_EN_ESTE_DIA 0
#define NO_SE_SABE_DIA_BOOM -1

typedef vector<int> vector_enteros;
typedef vector<vector_enteros> grafo_enteros;

int casos;
int numero_trabajadores;
grafo_enteros amistades;

// Variables para cado caso
int fuente;
vector_enteros booms_x_dia;
vector_enteros dia_boom_x_persona;
int primer_boom_total;
int tamanio_boom_total;

void BFS(int fuente) {
	queue<int> les_dira_a_sus_amigos;

	// Empezamos con los amigos de la fuente
	// Asignamos el valor de 0 al dia de inicio
	les_dira_a_sus_amigos.push(fuente);
	dia_boom_x_persona[fuente] = 0;
	booms_x_dia[0] = 0;

	while (!les_dira_a_sus_amigos.empty()) {
		int trabajador_actual = les_dira_a_sus_amigos.front();
		les_dira_a_sus_amigos.pop();

		int dia_boom_actual = dia_boom_x_persona[trabajador_actual];

		// Iteracion por cada amigo que tiene un trabajador
		for (int a = 0; a < amistades[trabajador_actual].size(); a++) {
			int amigo = amistades[trabajador_actual][a];

			// Si no se sabe el dia del boom del amigo es porque todavia no sabe el chisme
			if (dia_boom_x_persona[amigo] == NO_SE_SABE_DIA_BOOM) {
				int dia_boom_amigo = dia_boom_actual + 1;

				dia_boom_x_persona[amigo] = dia_boom_amigo;

				// Aumentamos el numero de booms para el dia del amigo
				booms_x_dia[dia_boom_amigo] += 1;
				les_dira_a_sus_amigos.push(amigo);
			}
			// else : Si el amigo ya tiene dia de boom (ya sabe) entonces no se le agregara ala cola (les_dira_a_sus_amigos)
		}
	}
}
int ejecutar() {
	scanf("%d", &numero_trabajadores);
	amistades = grafo_enteros(numero_trabajadores);

	// Iteracion por cada trabajador
	for (int trabajador = 0; trabajador < numero_trabajadores; trabajador++) {
		int numero_amigos;

		scanf("%d", &numero_amigos);

		// Conocer los amigos del trabajador
		for (int a = 0; a < numero_amigos; a++) {
			int amigo;

			scanf("%d", &amigo);
			amistades[trabajador].push_back(amigo);
		}
	}

	scanf("%d", &casos);

	// Iteracion por cada caso (fuente diferente)
	for (int c = 0; c < casos; c++) {
		scanf("%d", &fuente);

		booms_x_dia = vector_enteros(numero_trabajadores, NO_BOOMS_EN_ESTE_DIA);
		dia_boom_x_persona = vector_enteros(numero_trabajadores, NO_SE_SABE_DIA_BOOM);
		BFS(fuente);

		// Se calcularan los datos del boom total
		// Es necesario limpiar las variables
		primer_boom_total = 0;
		tamanio_boom_total = booms_x_dia[0];

		// Iteracion por cada dia
		//IMPORTANTE ==> SE DEDUCE QUE EL DIA DEL PRIMER BOOM TOTAL NO PUEDE SER MAYOR QUE EL NUMERO DE TRABAJADORES
		for (int d = 1; d < numero_trabajadores; d++) {
			if (booms_x_dia[d] > tamanio_boom_total) {
				primer_boom_total = d;
				tamanio_boom_total = booms_x_dia[d];
			}
		}

		if (primer_boom_total == 0)
			printf("0");
		else
			printf("%d %d", tamanio_boom_total, primer_boom_total);

		// Salto de linea para cada caso
		printf("\n");
	}

	return 0;
}


/*
LINK: https://uva.onlinejudge.org/external/9/924.pdf
INPUT
6
2 1 2
2 3 4
3 0 4 5
1 4
0
2 0 2
3
0
4
5
OUTPUT
3 2
0	
2 1
*/