#include"cliente.h"

int criar(TListaCliente *L){
	int i;
	for(i=0;i<MAX;i++){
		L->elemento[i] = NULL;
	}
	L->n=0;
}

int inserirCliente(TListaCliente *L, int hash, Tcliente cliente){
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

int hashing(int cpf){
	int h = 0;
	h = cpf % MAX;
	return h;
}


