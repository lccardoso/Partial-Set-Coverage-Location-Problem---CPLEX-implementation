#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include "Util.h"
#include "Arquivos.h"

using namespace std;


void obter_parametros_fl(char nomearq[], int* m, int* n)
{

	FILE* arquivo;
	int num_facilidades;
	int num_clientes;

	arquivo = fopen(nomearq, "r");
	if (!arquivo) {
		printf("O Arquivo %s nao pode ser aberto.\n", nomearq);
		getchar();
		exit(1);
	}

	fscanf(arquivo, "%d %d", &num_facilidades, &num_clientes);

	*n = num_facilidades;
	*m = num_clientes;

	fclose(arquivo);
}


void le_arq_matrizfl(char nomearq[], int m, int n, float** F, float** C, int* c, int* d)
{
	int i, j, index, valor;
	float x, y;
	float** Coord;
	int* valores;
	char type[1];
	FILE* arquivo;

	Coord = cria_matriz_float(m + n + 1, 2);
	valores = cria_vetor(m + n + 1);

	i = 0;
	j = 0;

	//vet_x = cria_vetor(n);
	//vet_y = cria_vetor(n);
	arquivo = fopen(nomearq, "r");
	if (!arquivo) {
		printf("O Arquivo %s nao pode ser aberto.\n", nomearq);
		getchar();
		exit(1);
	}

	i = 0;
	while (!feof(arquivo)) {

		fscanf(arquivo, "%c %d %f %f %d \n", type, &index, &x, &y, &valor);
		Coord[i][0] = x;
		Coord[i][1] = y;
		valores[i] = valor;
		i++;
	}

	for (j = 1; j <= n; j++) {
		F[j - 1][0] = Coord[j][0];
		F[j - 1][1] = Coord[j][1];
		c[j - 1] = valores[j];
	}

	//imprime_matriz_float(F,n,2);


	for (j = 0; j < m; j++) {
		C[j][0] = Coord[j + n + 1][0];
		//printf("%.5f ",C[j][0]);
		C[j][1] = Coord[j + n + 1][1];
		//printf("%.5f ",C[j][0]);
		d[j] = valores[j + n + 1];
	}

	//imprime_matriz_float(F,m,2);

	fclose(arquivo);

}


float** cria_matriz_distfl(int m, int n, float** F, float** C) {
	float** matriz;
	matriz = cria_matriz_float(m, n);
	int i, j;
	for (i = 0; i < m; i++) {

		for (j = 0; j < n; j++) {
			matriz[i][j] = (float)sqrtf(pow(C[i][0] - F[j][0], 2) + pow(C[i][1] - F[j][1], 2));
		}
	}

	return matriz;
}



//FIM DAS NOVAS FUNÇÕES DE LEITURA    