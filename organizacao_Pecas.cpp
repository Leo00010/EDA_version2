#include "organizacao_Pecas.h"
#include <iostream>
#include <cstdlib>
#include "structs.h"
#include "Abertura_de_ficheiro.h"
#include <algorithm>
#define MAX 50
using namespace std;

bool serie_existe(int *numeros_de_series_ja_saidos, int &numero_da_serie) {
    for (int i = 0; numeros_de_series_ja_saidos[i] != 0; i++) { //loop sobre todos os números já saídos diferentes de 0 
        if (numeros_de_series_ja_saidos[i] == numero_da_serie) { //verifica se o número de série é igual a um número de série que já saiu
            return true; //se tal se verificar, retorna verdadeiro 
        }
    }
    return false; //caso contrário retorna falso
}
int criar_serie(int *numeros_de_series_ja_saidos, int &tamanho) {
    int numero_da_serie = (rand() % 9000) + 1000; //gera um número aleatório entre 1000 e 9999
    while (serie_existe(numeros_de_series_ja_saidos, numero_da_serie)) { //loop que verifica se o número de série já saiu
        numero_da_serie = (rand() % 9000) + 1000; //caso já exista, gera outro número aleatório 
    }
    tamanho++; 
    numeros_de_series_ja_saidos[tamanho-1] = numero_da_serie; //adiciona o novo número de série à ultima posição do array
    return numeros_de_series_ja_saidos[tamanho-1]; //retorna o último número de série adicionado ao array
}

bool comparaMarca(const peca& a, const peca& b) { 
    return a.marca < b.marca; //compara as peças pela sua marca e verifica se estão ordenadas por ordem alfabética
}
void ordenarPorMarca(peca lista_chegada[],int tamanho_lista_chegada) {
    sort(lista_chegada, lista_chegada + tamanho_lista_chegada, comparaMarca); //ordena
}


int preco_peca (){
    return ((rand()%179) + 2) * 5; //10-900
}
int atribuicao_de_probabilade() {
    int probabilidade = rand() % 46 + 5; // [0,45] -> [5,50]
    return probabilidade;
}
peca criarPeca_de_categoria_seccao(int numeros_de_series_ja_saidos[], int &tamanho, string categoria_da_seccao) {
    peca novaPeca;
    novaPeca.categoria = categoria_da_seccao;
    novaPeca.marca = Marca_ou_categoria_aleatoria("marcas.txt");
    novaPeca.preco = preco_peca ();
    novaPeca.numero_de_serie = criar_serie(numeros_de_series_ja_saidos,tamanho);
    novaPeca.probabilidade_de_ser_vendida = atribuicao_de_probabilade();
    return novaPeca;
}
void deposito_de_pecas_na_lista_de_chegada(peca lista_chegada[MAX],int quantidade_de_pecas, int &numero_seccoes, seccao * armazem,int* &numeros_saidos,int &tamanho_dos_numeros_saidos,int &tamanho_da_lista_de_chegada){
    for (int index = 0; index < quantidade_de_pecas; index++){
        int a = rand()%numero_seccoes;
        lista_chegada[index] = criarPeca_de_categoria_seccao(numeros_saidos,tamanho_dos_numeros_saidos,armazem[a].categoria);
        tamanho_da_lista_de_chegada++;
    }
}
