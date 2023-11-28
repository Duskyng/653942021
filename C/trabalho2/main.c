/*

O Programa deverá ter um MENU PRINCIPAL com as seguintes Opções.:
1) Cadastrar Pergunta no Início -- OK
2) Cadastrar Pergunta no Final -- OK
3) Cadastrar Pergunta em uma Posição
4) Remover Pergunta no Início -- OK
5) Remover Pergunta no Final -- OK
6) Remover Pergunta em uma Posição
7) Consultar o cadastro das Perguntas
8) Alterar uma Pergunta
9) JOGAR SHOW DO MILHAO
10) Finalizar Programa

O SUBMENU de consulta deverá ter as Seguintes Opções
1) Consultar em Ordem de Código
2) Consultar em Ordem de Nível de Dificuldade
3) Consultar do UlƟmo para o Primeiro

*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


typedef struct TipoItem *TipoApontador;

typedef struct {

    int id_questao;
    char ds_pergunta[100];
    char ds_alternativa1[100];
    char ds_alternativa2[100];
    char ds_alternativa3[100];
    char ds_alternativa4[100];
    int nivel_pergunta;
    int resp_ok;
    int pergunta_feita;

} reg_questoes;

typedef struct TipoItem {

    TipoApontador anterior;
    reg_questoes conteudo;
    TipoApontador proximo;

} TipoItem;

typedef struct {

    TipoApontador Primeiro;
    TipoApontador Ultimo;

} TipoLista;

void inicializarLista(TipoLista *lista) {
    lista->Primeiro = NULL;
    lista->Ultimo = NULL;
}

//OPÇÃO 1 DO MENU
void inserirNoFinal(TipoLista *lista, reg_questoes pergunta) {
    TipoApontador novoNo = (TipoApontador)malloc(sizeof(TipoItem));
    novoNo->conteudo = pergunta;
    novoNo->anterior = NULL;
    novoNo->proximo = NULL;

    if (lista->Ultimo == NULL) {
        lista->Primeiro = novoNo;
        lista->Ultimo = novoNo;
    } else {
        novoNo->anterior = lista->Ultimo;
        lista->Ultimo->proximo = novoNo;
        lista->Ultimo = novoNo;
    }
}

//OPÇÃO 2 DO MENU
void inserirNoInicio(TipoLista *lista, reg_questoes pergunta) {
    TipoApontador novoNo = (TipoApontador)malloc(sizeof(TipoItem));
    novoNo->conteudo = pergunta;
    novoNo->anterior = NULL;
    novoNo->proximo = NULL;

    if (lista->Primeiro == NULL) {
        lista->Primeiro = novoNo;
        lista->Ultimo = novoNo;
    } else {
        novoNo->proximo = lista->Primeiro;
        lista->Primeiro->anterior = novoNo;
        lista->Primeiro = novoNo;
    }
}

//OPÇÃO 4 DO MENU
void removerPrimeiro(TipoLista *lista) {
    if (lista->Primeiro == NULL) {
        printf("A lista está vazia. Não há elementos para remover.\n");
        return;
    }

    TipoApontador primeiro = lista->Primeiro;

    if (primeiro->proximo != NULL) {
        primeiro->proximo->anterior = NULL;
        lista->Primeiro = primeiro->proximo;
    } else {
        lista->Primeiro = NULL;
        lista->Ultimo = NULL;
    }

    free(primeiro);
}

//OPÇÃO 5 DO MENU
void removerNoFinal(TipoLista *lista) {
    if (lista->Ultimo == NULL) {
        printf("A lista está vazia. Não há elementos para remover.\n");
        return;
    }

    TipoApontador ultimo = lista->Ultimo;

    if (ultimo->anterior != NULL) {
        ultimo->anterior->proximo = NULL;
        lista->Ultimo = ultimo->anterior;
    } else {
        lista->Primeiro = NULL;
        lista->Ultimo = NULL;
    }

    free(ultimo);
}

