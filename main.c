#include"cliente.h"
#include"pedido.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
Wesley Bezerra Farias - 495771
Joana Maria Chaves Melo - 415604
*/

int main(int argc, char const *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	int op;
	TListaCliente L;
	Tcliente cliente;
	criar(&L);
	int hash;
	TnoPedido *arvorePedidos = NULL;
	
	int ordemServico, quantidade, status, descPedido, cpfCliente;
	
	do{    
    //Exibir menu
        system("cls");
        printf("\n\t\t\t\GESTAO DE CLIENTES\n");
        printf("\t1  - EXIBIR PEDIDOS DE UM CLIENTE\n\t2  - CADASTRAR CLIENTE\n\t3  - CADASTRAR PEDIDO\n\t4  - ATUALIZAR PEDIDO\n\t0  - SAIR");
        printf("\nINFORME SUA OPCAO: ");
        scanf("%d", &op);//Escolha da Opcao
        printf("\n");
    	switch(op)
        {
			case 1:{
				imprime(arvorePedidos);
				break;
			}
			
			case 2:{
			
				//preenchendo cliente                
				printf("\nInforme o cpf: \n");
				scanf("%d", &cliente.cpf);
				
				printf("Informe um nome: \n");
				scanf(" %[^\n]", cliente.nome);

				printf("Informe um ENDERECO: \n");
				scanf(" %[^\n]", cliente.endereco);
				
				//preenchendo primeiro pedido do cliente 
				
				printf("\n***********INFORME OS DADOS DO SEU PRIMEIRO PEDIDO %s ***********\n\n", cliente.nome);
				
				printf("Informe a ordem de servico: ");
    			scanf("%d", &ordemServico);
    			   			
    			printf("Digite a quantidade do pedido: ");
    			scanf("%d", &quantidade);
    			
       			printf("Informe a descrição do pedido: \n");
    			printf("\tBanner = 1, Logo = 2 , Cracha = 3, Catalogo = 4, Outro = 5  \n");
				scanf("%d", &descPedido);
    			
    			printf("Informe o status do pedido: \n");
    			printf("\tcancelado = 1, Entregue = 2 , Andamento = 3  \n");
    			scanf("%d", &status);
    			
    			int cpfCliente = cliente.cpf; //cpf pedido será usada para relacionar cada pedido a um cliente.
    			
    			arvorePedidos = inserirPedido(arvorePedidos, ordemServico, descPedido, quantidade, status, cpfCliente);
									
				hash = hashing(cliente.cpf);
				inserirCliente(&L,hash, cliente);
				break;
			}
			case 3:{
				
				printf("Informe o cpf do cliente: ");
				scanf("%d", &cliente.cpf);
																		
				printf("Informe a ordem de servico: ");
    			scanf("%d", &ordemServico);
    			   			
    			printf("Digite a quantidade do pedido: ");
    			scanf("%d", &quantidade);
    			
       			printf("Informe a descrição do pedido: \n");
    			printf("\tBanner = 1, Logo = 2 , Cracha = 3, Catalogo = 4, Outro = 5  \n");
				scanf("%d", &descPedido);
    			
    			printf("Informe o status do pedido: \n");
    			printf("\tcancelado = 1, Entregue = 2 , Andamento = 3  \n");
    			scanf("%d", &status);
    			
				arvorePedidos = inserirPedido(arvorePedidos, ordemServico, descPedido, quantidade, status, cpfCliente);	
				break;

			}
			case 4:{
				printf("Informe a ordem de servico: \n");
    			scanf("%d", &ordemServico);
    			
    			alteraPedido(arvorePedidos, ordemServico);
    			break;
    			
			}
        	// TODO - Outra opcao nao oferecida
    		default:
    			printf("OPCAO INCORRETA,TENTAR NOVAMENTE.");
				break;			
        }
	getch();
    }while(op!=0);
  
  system("PAUSE");	
  return 0;
}


