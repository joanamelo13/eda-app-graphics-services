#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 23
struct cliente{
	int cpf; //chave = cpf
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
