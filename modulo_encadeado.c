#include"libHashEnc.h"

int criar(TListaCliente *L){
	int i;
	for(i=0;i<MAX;i++){
		L->elemento[i] = NULL;
	}
	L->n=0;
}

int inserir(TListaCliente *L, int hash, Tcliente cliente){
	Tno novo;
    novo = (Tno *) malloc (sizeof(Tno));
    novo->cliente =cliente;
	if(L->elemento[hash]==NULL){
		novo->proximo = NULL;
		L->elemento[hash] = novo;
		L->n=1;
	}
	else{
		novo->proximo = L->elemento[hash];
		L->elemento[hash]= novo;
		L->n +=1;
	}	
}

void exibir(TListaCliente L){
    Tno aux;
    int i;
    if(L.n!=0){
        for(i=0;i<MAX;i++){
            if(L.elemento[i]!=NULL){
                printf("-------------i = %d --------------\n", i);
                aux =L.elemento[i];
                while(aux!=NULL){
                    printf("cpf = %d\n", L.elemento[i]->cliente.cpf);
                    printf("nome = %s\n\n", L.elemento[i]->cliente.nome);
                    printf("endereco = %s\n\n", L.elemento[i]->cliente.endereco);
                    aux = aux->proximo;
                }
            }
        }
    }
    else
        printf("tabela vazia");
}

int hashing(int cpf){
	int h = 0;
	h = cpf % MAX;
	return h;
}