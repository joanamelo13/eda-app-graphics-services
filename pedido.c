#include"pedido.h"

int altura_AVL(TnoPedido *a){
    int alt_esq=0, alt_dir=0;
    if (a == NULL)
        return 0;
    else{
        alt_esq = altura_AVL(a->esq);
        alt_dir = altura_AVL(a->dir);
        if (alt_esq > alt_dir)
            return (1 + alt_esq);
        else
            return (1 + alt_dir);
    }
}



int calcula_FB(TnoPedido *a){
    return (altura_AVL(a->esq) - altura_AVL(a->dir));
}

TnoPedido* rotacao_simples_esquerda(TnoPedido* a){
  TnoPedido *aux;
  aux = a->dir;
  a->dir = aux->esq;
  aux->esq = a;
  a = aux;
  return a;
}
TnoPedido * rotacao_simples_direita(TnoPedido *a){
  TnoPedido *aux;

  aux = a->esq;
  a->esq = aux->dir;
  aux->dir = a;
  a = aux;
  return a;
}
TnoPedido * balanceio_esquerda(TnoPedido *a){
  int fator = calcula_FB(a->esq );
  if (fator > 0){
    return rotacao_simples_direita(a);
  }
  else if (fator < 0)// Rotação Dupla Direita 
  { 
    a->esq = rotacao_simples_esquerda(a->esq);
    a = rotacao_simples_direita(a); 
	return a;	
  }
  else
  	return a;
}

TnoPedido * balanceio_direita(TnoPedido *a){
  int fator = calcula_FB(a->dir);
  if ( fator< 0 )
  {
    return rotacao_simples_esquerda(a);
  }
  else if (fator > 0 )// Rotação Dupla Esquerda
  { 
    a->dir = rotacao_simples_direita(a->dir);
    a = rotacao_simples_esquerda(a); 
	  return a;
  }
  else
  	return a;
}
TnoPedido* balanceamento(TnoPedido* a){
	int fator = calcula_FB(a);
	if ( fator > 1)
		return balanceio_esquerda(a);
	else if (fator < -1 )
		return balanceio_direita(a);
	return a;
}
TnoPedido* inserirPedido(TnoPedido* arvorePedidos, int ordemServico, int descPedido, int quantidade, int status, int cpfCliente){
  if (arvorePedidos == NULL){
    arvorePedidos = (TnoPedido *)malloc(sizeof(TnoPedido));
    arvorePedidos->ordemServico = ordemServico;
    arvorePedidos->descPedido = descPedido;
    arvorePedidos->quantidade = quantidade;
    arvorePedidos->status = status;
    arvorePedidos->cpfCliente = cpfCliente;
    
    arvorePedidos->esq = NULL;
    arvorePedidos->dir = NULL;
    return arvorePedidos;
  }
  else 
  	if ( arvorePedidos->ordemServico > ordemServico )  {
    	arvorePedidos->esq = inserirPedido(arvorePedidos->esq, ordemServico, descPedido, quantidade, status, cpfCliente);
    	arvorePedidos = balanceamento(arvorePedidos);
	}
    else{
    	arvorePedidos->dir = inserirPedido(arvorePedidos->dir, ordemServico, descPedido, quantidade, status, cpfCliente);
    	arvorePedidos = balanceamento(arvorePedidos);
	} 
}

TnoPedido* alteraPedido(TnoPedido* arvorePedidos, int ordemServico) {
	if ( arvorePedidos == NULL ) return NULL ;
	else if ( arvorePedidos->ordemServico == ordemServico ) {
		if(arvorePedidos->status == 3){
			int opcao;
			printf("Status atual: %d, Quantidade atual: %d.\n Digite 1 para alterar o Status ou 2 para alterar a quantidade\n", arvorePedidos->status, arvorePedidos->quantidade);
			scanf("%d", &opcao);
			switch(opcao)
        	{
				case 1:{
					int status;
					printf("Informe o status do pedido: \n");
    				printf("\tcancelado = 1, Entregue = 2 , Andamento = 3 \n");
    				scanf("%d", &status);
					arvorePedidos->status = status;
					printf("O status do pedido foi atualizado.\n");
					break;
				}
				case 2:{
					int quantidade;
					printf("Informe a quantidade do pedido: \n");
    				scanf("%d", &quantidade);
					arvorePedidos->quantidade = quantidade;
					printf("A quantidade do pedido foi alterada.\n");
					break;
				}
				default:{
					printf("OPCAO INCORRETA");
					break;
				}
			}
		}
	}
	else if ( arvorePedidos->ordemServico > ordemServico ) return alteraPedido(arvorePedidos->esq, ordemServico) ;
	else return alteraPedido (arvorePedidos->dir, ordemServico ) ;
}

void imprime(TnoPedido* a){
    if (a == NULL){
		return;
	}
	printf("%d",a->ordemServico);
 
    if(a->esq != NULL)
        printf("(E:%d)",a->esq->ordemServico);
    if(a->dir != NULL)
        printf("(D:%d)",a->dir->ordemServico);
    printf("\n");
 
    imprime(a->esq);
    imprime(a->dir);
}







