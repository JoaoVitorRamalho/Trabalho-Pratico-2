#ifndef PILHA_H
#define PILHA_H

#include <iostream>
//essa primeira parte foi retirada da sugestão de struct que o próprio trabalho sugeria
using namespace std;

# define MAXTAM 10
# define MAX_ENTREGA 7

typedef struct {
int codigo ;
int produtos [ MAXTAM ]; 
float valor_pedido ;
float distancia ;
int tamanhoPedido=0;
} Pedido ;

typedef struct {
Pedido pilha [ MAX_ENTREGA ];
int topo ;
int tamanhoPilha;
} TPilha ;

//Declarando as funções

void Menu();

void Cardapio();

void TPilha_Inicializa ( TPilha *p) ;

bool TPilha_Vazia ( TPilha * p) ;

bool TPilha_Cheia ( TPilha * p) ;

void TPilha_Empilha ( TPilha *p , Pedido x) ;

void TPilha_Desempilha(TPilha *pilha, Pedido *x);

void TPilha_Imprime ( TPilha * p) ;

int TPilha_ProcuraPorID(TPilha *p, int codigo);

Pedido RemoverItem(TPilha *pilha, int a);

#endif