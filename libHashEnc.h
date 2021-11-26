#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX 23
struct cliente{
	char *cpf[12]; //chave = cpf
	char *nome[80];
	char *endereco[80];
};

typedef struct cliente Tcliente; //antes era Tdado.

struct no{
        Tcliente cliente;
        struct no *proximo;
};

typedef struct no* Tno;

typedef struct{
        Tno elemento[MAX];
        int n;
} TListaCliente; //antes era Tlista

int criar(TListaCliente *L);
int inserir(TListaCliente *L, int hash, Tcliente dado);
int hashing(int cpf);

//************** AVL *******************

typedef struct pedido{
	int NumOrdemServico; //changed from fator_b
	enum desc {banner = 1, logo = 2, cracha = 3, catalogos = 4, outro = 5};
	enum status {andamento = 1, cancelado = 2, entregue = 3};
        int quant;
        //link to cliente
}Tpedido;

typedef struct noPedido{ //changed from no
	struct Tpedido pedido;
	struct noPedido* esq;
	struct noPedido* dir;

}ArvPedido; //changed from Tno

void menu();
int altura_AVL(Tno *a);
int calcula_FB(Tno *a);
Tno* rotacao_simples_esquerda(Tno *a);
Tno* rotacao_simples_diretira(Tno *a);
Tno* balanceamento(Tno* a);
Tno* inserir(Tno* a, int elemento);
void imprime(Tno* a);
