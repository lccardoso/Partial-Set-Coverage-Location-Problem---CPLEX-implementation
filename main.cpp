// Projeto1.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <ilcplex/ilocplex.h>
using namespace std;

#include "Arquivos.h"
#include "Util.h"

int main()

{

    int n,                  // numero de facilidades
        m,					//numero de clientes
        demanda,            //demanda total do problema
        * c,				//vetor de custo de instalação das facilidades
        * d,				//vetor de demanda dos clientes
        ** A;               //matriz de adjacências
    float** F,			    // matriz nx2 com as coordenadas das facilidades
        ** C,				//matriz mx2 com as coordenadas dos clientes
        ** D;				//Matriz de adjacências (distâncias)
    clock_t inicio_CPU,     // clock no inicio da aplicacao do metodo
        fim_CPU;            // clock no final da aplicacao do metodo
    float demand;           //valor da demanda a ser atendida
    float fo;               //valorda função objetivo
    int ninst;              //Número de instalçoes ativadas
    int ncli;               //Número de clientes cobertos

//Ler aquivo e montar matrizes e vetores
    float raio = 5.5;

    char arquivo[] = "inst1.TXT";

    obter_parametros_fl(arquivo, &m, &n);

    printf("Facilidades - Clientes: %d - %d\n\n", n, m);

    F = cria_matriz_float(n, 2); //matriz de coordenadas das Facilidades
    C = cria_matriz_float(m, 2); //matriz de coordenadas dos clientes
    D = cria_matriz_float(m, n); //matriz de distâncias
    c = cria_vetor(n); //vetor de custo das instalações
    d = cria_vetor(m); //vetor de demandas dos clientes

    A = cria_matriz(m, n); //matriz de Adjacências


    le_arq_matrizfl(arquivo, m, n, F, C, c, d);
    D = cria_matriz_distfl(m, n, F, C);
    cria_matriz_adj(m, n, raio, D, A);

    //imprime_matriz_float(D, m, n);
    //imprime_matriz(A, m, n);
    //imprime_vetor(y, n);

    //Calculo da demanda total a ser atendida
    demanda = 0;
    for (int j = 0; j < m; j++) {
        demanda = demanda + d[j];
    }
    printf(" O valor da demanda total  e %d \n", demanda);
    printf("\n");

    //Calculo d do percentual da  demanda a atendida
    demand = (demanda) * 0.5;
    printf(" O Valor de demanda minima a ser atendida e %f \n", demand);
    printf("\n");

    /*
    //Calculo do vetor de cobertura z[i]
    for (int i = 0; i < m; i++) {
        int soma = 0;
        z[i] = 0; //inicialmente, o vértice i não é coberto
        for (int j = 0; j < n; j++) {
            soma = soma + A[i][j] * y[j];
        }
        if (soma > 0) z[i] = 1; //Caso o nó i seja coberto por alguma facilidade, z[i] será trocado para 1
        //printf(" %d", z[i]);
    }
    */

    //system("PAUSE");


    /**================================
        *  Declaração do modelo CPLEX
    *=============================== */

    IloEnv env;
    IloModel model(env);
    IloCplex cplex(model);
    IloNumVarArray y(env, n, 0, 1, ILOINT); // Declaração de um vetor de variáveis de decisão - Facilidades Ativas
    IloNumVarArray z(env, m, 0, 1, ILOINT); // Declaração de um vetor de variáveis de decisão - Clientes Atendidos

    // ====================================
    // minimize sum(i in 1..n) y[i] * c[i] 
    // ====================================
    IloExpr expfo(env); 
    for (int i = 0; i < n; i++) {
            expfo += y[i] * c[i];
    }
    IloAdd(model, IloMinimize(env, expfo));
    expfo.end();

    //=================================================================
    // forall(i in 1..n) sum(i in 1..n)  y[i] >= forall(j in 1..m) z[j]
    //=================================================================
    for (int j = 0; j < m; j++) {
        IloExpr r1(env);
        for (int i = 0; i < n; i++) { 
            r1 += y[i]*A[j][i];
        }
        model.add(r1 >= z[j]);
        r1.end();
    }

    //=================================================================
    // forall(j in 1..m) sum(i in 1..m) d[j]*z[j] >= D
    //=================================================================
    IloExpr r2(env);
    for (int j = 0; j < m; j++) {
        r2 += d[j] * z[j];
    }
    model.add(r2 >= demand);
    r2.end();


    ///==============================
    /// Resolvendo o problema
    ///==============================

    //cplex.setWarning(env.getNullStream()); // Eliminar warnings
    IloTimer crono(env);// Variável para coletar o tempo
    crono.start();
    cplex.solve();
    crono.stop();
    double otimo = 0.0;

    if (cplex.getStatus() == IloAlgorithm::Optimal) {
        otimo = cplex.getObjValue();
    }
    else {
        cout << "Problema inviável" << endl;
    }
 
    float fixed = 0.0;

    cout << "Facilidades: ";
    for (int i = 0; i < n; i++) {
        fixed += c[i] * cplex.getValue(y[i]);
        if (cplex.getValue(y[i]) >= 0.01) {
            cout << i << "\t";
        }
    }
    cout << endl;
    printf("Custo de Abertura das Facilidades: %1.4f" , fixed);
   


}

