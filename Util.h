
/*cria matriz de adjacências*/
void cria_matriz_adj(int m, int n, float raio, float** D, int** A);

/* cria memoria para um vetor de tam posicoes */
int* cria_vetor(int tam);

/* cria memoria para um vetor de tam posicoes */
float* cria_vetor_float(int tam);

/* Cria matriz de ponteiros para inteiros com nlinhas e ncolunas */
int** cria_matriz(int nlinhas, int ncolunas);

/* Cria matriz de ponteiros para inteiros com nlinhas e ncolunas */
float** cria_matriz_float(int nlinhas, int ncolunas);

/* libera memoria de um vetor */
void libera_vetor(int* vetor);

void libera_matriz(int** matriz, int nlinhas);

void libera_matriz_float(float** matriz, int nlinhas);

/* imprime a solucao */
void imprime_vetor(int* s, int n);

/* imprime matriz */
void imprime_matriz(int** adj, int m, int n);

/* imprime matriz */
void imprime_matriz_float(float** adj, int m, int n);

/*Função Calcula Demanda*/

