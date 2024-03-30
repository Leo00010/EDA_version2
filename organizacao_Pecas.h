//
// Created by octav on 28/03/2024.
//

#ifndef PROJETOEDA_ORGANIZACAO_PECAS_H
#define PROJETOEDA_ORGANIZACAO_PECAS_H
#include "structs.h"
#define MAX 50
bool serie_existe(int *numeros_de_series_ja_saidos, int &numero_da_serie);
int criar_serie(int *numeros_de_series_ja_saidos,int &tamanho);
int atribuicao_de_probabilade();
bool comparaMarca(const peca& a, const peca& b);
void ordenarPorMarca(peca lista_chegada[],int tamanho_lista_chegada);
peca criarPeca_de_categoria_seccao(int numeros_de_series_ja_saidos[], int &tamanho, string categorias);
void deposito_de_pecas_na_lista_de_chegada(peca *lista_chegada,int quantidade_de_pecas, int &numero_seccoes, seccao * armazem,int* &numeros_saidos,int &tamanho_dos_numeros_saidos,int &tamanho_da_lista_de_chegada);
void apagar_peca1(peca pecas[], int& tamanho_array, int indice);
void apagar_peca(peca &uma_peca);
void vendas(seccao *armazem,int numero_seccoes, int &total_de_faturacao);
void remocao_de_peca_para_o_armazem(seccao *&armazem, peca *&lista_de_pecas,int n_de_pecas_para_entrar,int numero_seccoes,int &tamanho_lista_chegada);
void alterar_categoria(seccao *&armazem, int &numero_de_seccoes);
void alterar_categoria1(char id_local, string nova_categoria, seccao *&armazem, int &numero_de_seccoes);
void ordenar_pecas_existentes(peca *&lista_de_pecas, int &quantidade_da_seccao);
void vendaManual(seccao* armazem, int numero_de_seccoes, int &total_de_faturacao);
#endif //PROJETOEDA_ORGANIZACAO_PECAS_H
