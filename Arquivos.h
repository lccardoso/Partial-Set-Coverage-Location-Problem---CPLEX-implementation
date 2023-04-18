/* le um arquivo no formato num_cid coord_x coord_y e calcula as distancias d_ij  */
void le_arq_matriz(char nomearq[], int n, int** adj);

/* le um arquivo no formato "numero_cidades melhor_valor" */
void obter_parametros_pcv(char nomearq[], int* n, float* melhor_valor);

void imprime_fo(char nomearq[], float tempo, float fo, int iteracao);

/* le um arquivo no formato i, valor */
void le_arq_vetor(char nomearq[], int* vetor);

/* Nesta leitura, vetor[j] = valor para todo j=0...n */
void le_arq_vetor_denso(char nomearq[], int* vetor);

void limpa_arquivo(char nomearq[]);

//Ler parâmetros do problema de Localização
void obter_parametros_fl(char nomearq[], int* m, int* n);

//Montar matrizes de coordenadas e vetores de custo e demanda
void le_arq_matrizfl(char nomearq[], int m, int n, float** F, float** C, int* c, int* d);

//Calcular distâncias e salvar na matriz D
float** cria_matriz_distfl(int m, int n, float** F, float** C);


