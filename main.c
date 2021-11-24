#include"libHashEnc.h"

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	int op;
	TListaCliente L;
	Tcliente cliente;
	criar(&L);
	int hash;
	do{    
    //Exibir menu
        system("cls");
        puts("\n\t\t\t\tEDITOR DE LISTAS\n");
        puts("\t1  - EXIBIR LISTA\n\t2  - INSERIR UM ELEMENTO\n\t0  - SAIR");
        printf("\nINFORME SUA OPCAO:\n");
        scanf("%d", &op);//Escolha da Opção
        
    	switch(op)
        	{
        		case 1:{
        			printf("case 1");
					//exibir(L);
					break;
				}
				
				case 2:{	                
	                printf("Informe o cpf: \n");
	                scanf("%d", &cliente.cpf);
	                
	                printf("Informe um nome: \n");
	                scanf("%d", &cliente.nome);

	                printf("Informe um ENDERECO: \n");
					scanf("%s", &cliente.endereco);
						                
	                hash = hashing(cliente.cpf);
	                inserir(&L,hash, cliente);
					break;
				}
        	// TODO - Outra opção nao oferecida
    		default:
    			puts("OPCAO INCORRETA,TENTAR NOVAMENTE.");
				break;
    			
        }
	getch();
    }while(op!=0);
  
  system("PAUSE");	
  return 0;
}
