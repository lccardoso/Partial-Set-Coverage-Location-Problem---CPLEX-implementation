#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include "Util.h"
//#include "Estruturas.h"
//#include "Listas.h"


void cria_matriz_adj(int m, int n, float raio, float** D, int** A) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            A[i][j] = 0;
            if (D[i][j] <= raio) A[i][j] = 1;
        }
    }

}

/* cria memoria para um vetor de tam posicoes */
int* cria_vetor(int tam)
{
    int* vetor;

    vetor = (int*)malloc(tam * sizeof(int));
    if (!vetor) {
        printf("Falta memoria para alocar o vetor de ponteiros");
        exit(1);
    }
    return vetor;
}


/* cria memoria para um vetor de tam posicoes */
float* cria_vetor_float(int tam)
{
    float* vetor;

    vetor = (float*)malloc(tam * sizeof(float));
    if (!vetor) {
        printf("Falta memoria para alocar o vetor de ponteiros");
        exit(1);
    }
    return vetor;
}


/* Cria matriz de ponteiros para inteiros com nlinhas e ncolunas */
int** cria_matriz(int nlinhas, int ncolunas)
{
    register int i;
    int** matriz;

    matriz = (int**)malloc(nlinhas * sizeof(int*));
    if (!matriz) {
        printf("Falta memoria para alocar a matriz de ponteiros\n");
        exit(1);
    }
    for (i = 0; i < nlinhas; i++) {
        matriz[i] = (int*)malloc(ncolunas * sizeof(int));
        if (!matriz[i]) {
            printf("Falta memoria para alocar a matriz de ponteiros.\n");
            exit(1);
        }
    }
    return matriz;
}

/* Cria matriz de ponteiros para inteiros com nlinhas e ncolunas */
float** cria_matriz_float(int nlinhas, int ncolunas)
{
    register int i;
    float** matriz;

    matriz = (float**)malloc(nlinhas * sizeof(float*));
    if (!matriz) {
        printf("Falta memoria para alocar a matriz de ponteiros\n");
        exit(1);
    }
    for (i = 0; i < nlinhas; i++) {
        matriz[i] = (float*)malloc(ncolunas * sizeof(float));
        if (!matriz[i]) {
            printf("Falta memoria para alocar a matriz de ponteiros.\n");
            exit(1);
        }
    }
    return matriz;
}


/* libera memoria de um vetor */
void libera_vetor(int* vetor)
{
    free(vetor);
}


void libera_matriz(int** matriz, int nlinhas)
{
    register int i;

    for (i = nlinhas - 1; i >= 0; i--)
        free((int*)matriz[i]);
    free((int*)matriz);
}


void libera_matriz_float(float** matriz, int nlinhas)
{
    register int i;

    for (i = nlinhas - 1; i >= 0; i--)
        free((float*)matriz[i]);
    free((float*)matriz);
}



/* imprime a solucao */
void imprime_vetor(int* s, int n)
{
    for (int j = 0; j < n; j++) {
        printf("s[%2d]=%d \n", j, s[j]);
        //system("PAUSE");
    }
}

/*imprimir matriz*/
void imprime_matriz(int** adj, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) printf("%d ", adj[i][j]);
        printf("\n");
        //system("PAUSE");
    }
}


void imprime_matriz_float(float** adj, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) printf("%f, ", adj[i][j]);
        printf("\n");
        //system("PAUSE");
    }
}


/* Gera numero aleatorio entre min e max */
float randomico(float min, float max)
{
    if (min == max) return min;
    return ((float)(rand() % 10000 / 10000.0) * (max - min) + min);
}

//Função Calcula Demanda




