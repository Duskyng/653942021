/*

O Programa deverá ter um MENU PRINCIPAL com as seguintes Opções.:
1) Cadastrar Pergunta no Início -- OK
2) Cadastrar Pergunta no Final -- OK
3) Cadastrar Pergunta em uma Posição
4) Remover Pergunta no Início -- OK
5) Remover Pergunta no Final -- OK
6) Remover Pergunta em uma Posição -- OK
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
#include<string.h>


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

void gotoxy(int x,int y) {
    printf("%c[%d;%df",0x1B,y,x);
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
void removerNoInicio(TipoLista *lista) {
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

//OPÇÃO 6 DO MENU
void removerNoEspecifico(TipoLista *lista, int posicao) {
    if (lista->Primeiro == NULL) {
        printf("A lista esta vazia. Nao ha nada para remover.\n");
        return;
    }

    if (posicao < 1) {
        printf("Posicao invalida. A posicao deve ser maior ou igual a 1.\n");
        return;
    }

    TipoApontador atual = lista->Primeiro;
    int contador = 1;

    while (atual != NULL && contador < posicao) {
        atual = atual->proximo;
        contador++;
    }

    if (atual == NULL) {
        printf("Posicao invalida. Nao ha elemento na posicao %d.\n", posicao);
        return;
    }

    if (atual->anterior != NULL) {
        atual->anterior->proximo = atual->proximo;
    } else {
        lista->Primeiro = atual->proximo;
    }

    if (atual->proximo != NULL) {
        atual->proximo->anterior = atual->anterior;
    } else {
        lista->Ultimo = atual->anterior;
    }

    free(atual);

    printf("Elemento na posicao %d removido com sucesso.\n", posicao);
}

void inserirPerguntaUsuario(TipoLista *lista) {
    reg_questoes novaPergunta;
    int opcao;

    printf("Informe o ID da questao: ");
    scanf("%d", &novaPergunta.id_questao);

    printf("Informe a pergunta: ");
    getchar();
    fgets(novaPergunta.ds_pergunta, sizeof(novaPergunta.ds_pergunta), stdin);
    novaPergunta.ds_pergunta[strcspn(novaPergunta.ds_pergunta, "\n")] = '\0';

    printf("Informe a alternativa 1: ");
    getchar();
    fgets(novaPergunta.ds_alternativa1, sizeof(novaPergunta.ds_alternativa1), stdin);
    novaPergunta.ds_alternativa1[strcspn(novaPergunta.ds_alternativa1, "\n")] = '\0';

    printf("Informe a alternativa 2: ");
    getchar();
    fgets(novaPergunta.ds_alternativa2, sizeof(novaPergunta.ds_alternativa2), stdin);
    novaPergunta.ds_alternativa2[strcspn(novaPergunta.ds_alternativa2, "\n")] = '\0';

    printf("Informe a alternativa 3: ");
    getchar();
    fgets(novaPergunta.ds_alternativa3, sizeof(novaPergunta.ds_alternativa3), stdin);
    novaPergunta.ds_alternativa3[strcspn(novaPergunta.ds_alternativa3, "\n")] = '\0';

    printf("Informe a alternativa 4: ");
    getchar();
    fgets(novaPergunta.ds_alternativa4, sizeof(novaPergunta.ds_alternativa4), stdin);
    novaPergunta.ds_alternativa4[strcspn(novaPergunta.ds_alternativa4, "\n")] = '\0';

    printf("Informe a dificuldade da questao de 1 a 3: ");
    scanf("%d", &novaPergunta.nivel_pergunta);
    
    printf("Informe a alternativa correta: ");
    scanf("%d", &novaPergunta.resp_ok);
    
    novaPergunta.pergunta_feita = 0;

    printf("1 - Inserir no inicio da lista\n");
    printf("2 - Inserir no final da lista\n");
    printf("Selecione a opcao desejada: ");
    scanf("%d", &opcao);
    if (opcao = 1) {
        inserirNoInicio(lista, novaPergunta);
    } 
    else if (opcao = 2) {
        inserirNoFinal(lista, novaPergunta);
    }

}

void imprimirLista(TipoLista *lista) {
    TipoApontador atual = lista->Primeiro;

    while (atual != NULL) {
        printf("ID: %d\n", atual->conteudo.id_questao);
        printf("Pergunta: %s\n", atual->conteudo.ds_pergunta);

        atual = atual->proximo;

        printf("\n");
    }
}

void imprimirMenu() {
    printf("\n-- Menu --\n");
    printf("1) Cadastrar Pergunta \n");
    //Ao finalizar o cadastro pode escolher onde quer inserir, se no inicio ou final
    printf("2) Remover Pergunta no Inicio\n");
    printf("3) Remover Pergunta no Final\n");
    printf("4) Remover Pergunta em uma Posicao\n");
    printf("5) Consultar o cadastro das Perguntas\n");
    printf("6) Alterar uma Pergunta\n");
    printf("0) Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {


    TipoLista lista;
    inicializarLista(&lista);

    int opcao, exclusao;

    printf("Pressione qualquer tecla para jogar");

    do {
        getchar();
        system("cls");
        imprimirMenu();
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                inserirPerguntaUsuario(&lista);
                break;
            case 2:
                removerNoInicio(&lista);
                break;
            case 3:
                removerNoFinal(&lista);
                break;
            case 4:
                printf("Digite o numero da posicao que deseja excluir: ");
                scanf("%d", &exclusao);
                removerNoEspecifico(&lista, exclusao);
                break;
            case 5:
                imprimirLista(&lista);
                break;
            case 6:
                break;
            case 0:
                printf("Saindo do programa. Obrigado!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
