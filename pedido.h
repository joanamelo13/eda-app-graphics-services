#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct noPedido{
	int ordemServico;
	int quantidade;
	int descPedido; //{Banner = 1, Logo = 2 , Cracha = 3, Catalogo = 4, Outro = 5};
	int status;
	int cpfCliente; //{cancelado = 1, Entregue = 2 , Andamento = 3};

	int elemento;
	int fator_b;
	
	struct noPedido* esq;
	struct noPedido* dir;

}TnoPedido;

void menu();
int altura_AVL(TnoPedido *a);
int calcula_FB(TnoPedido *a);
TnoPedido* rotacao_simples_esquerda(TnoPedido *a);
TnoPedido* rotacao_simples_diretira(TnoPedido *a);
TnoPedido* balanceamento(TnoPedido* a);
TnoPedido* inserirPedido(TnoPedido* arvorePedidos, int ordemServico, int descPedido, int quantidade, int status, int cpfCliente);
TnoPedido* alteraPedido(TnoPedido* arvorePedidos, int ordemServico);
void imprime(TnoPedido* a);




