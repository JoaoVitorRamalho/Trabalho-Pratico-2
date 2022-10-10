#include <iostream>
#include <windows.h>
#include "pilha.hpp"
using namespace std;


//Criando o menu
void Menu()
{
    system("cls");
    cout << "--------------------------------\n";
    cout << "         Pizzaria        \n";
    cout << "--------------------------------\n";
    cout << "1. Fazer Pedido\n";
    cout << "2. Listar Pedidos\n";
    cout << "3. Mostrar Cardápio\n";
    cout << "4. Consultar pedido\n";
    cout << "5. Imprimir lista de entrega\n";
    cout << "6. Entregar pedido\n";
    cout << "7. Sair\n\n";
}

//Criando o Cardapio
void Cardapio()
{
    system("cls");
    cout << "--------------------------------\n";
    cout << "         Cardápio        \n";
    cout << "--------------------------------\n";
    cout << "Pizzas: \n";
    cout << "1.Frango com Catupiry\tR$40\n";
    cout << "2.Calabresa\t\tR$30\n";
    cout << "3.Quatro queijos\tR$35\n";
    cout << "4.Napolitana\t\tR$45\n";
    cout << "5.Maravilhosa\t\tR$50\n";
}

//Aqui usamos as TADS para fazer as funções
void TPilha_Inicializa(TPilha *pilha)
{
    pilha->topo = 0;
}

bool TPilha_Vazia(TPilha *pilha)
{
    if (pilha->topo == 0)
        return true;
    return false;
}

bool TPilha_Cheia(TPilha *pilha)
{
    if (pilha->topo == MAXTAM)
        return true;
    return false;
}

void TPilha_Empilha(TPilha *pilha, Pedido x)
{
    if (TPilha_Cheia(pilha))
    {
        cout << "\nPilha cheia\n";
        return;
    }

    pilha->pilha[pilha->topo] = x;
    pilha->topo++;
    pilha->tamanhoPilha++;
    // cout << "\nItem empilhado com sucesso!\n";
}

void TPilha_Imprime(TPilha *pilha)
{
    for (int i = pilha->topo - 1; i >= 0; i--)
    {
        cout << "ID do pedido: " << pilha->pilha[i].codigo << endl;
        cout << "Distância: " << pilha->pilha[i].distancia << endl;
        cout << "Valor total do pedido: " << pilha->pilha[i].valor_pedido << endl;
        cout << "Código do item pedido: ";
        for (int j = 0; j < 1; j++)
        {
            cout << pilha->pilha[i].produtos[j] << " ";
        }
        cout << endl
             << endl;
    }
    cout << endl;
}

void TPilha_Desempilha(TPilha *pilha, Pedido *x)
{
    if (TPilha_Vazia(pilha)) {
        cout << "\nPilha vazia.\n";
        return;
    }

    pilha->topo--;
    *x = pilha->pilha[pilha->topo];
}

//Essa função percorre a pilha inteira para procurar se possui algum código igual se tiver retorna ele se não retorna -1
int TPilha_ProcuraPorID(TPilha *pilha, int codigo)
{
    for (int i = 0; i < pilha->tamanhoPilha; i++)
    {
        if (pilha->pilha[i].codigo == codigo)
        {
            return i;
        }
    }
    return -1;
}

//Função que remove o código da variável auxiliar da pilha
Pedido RemoverItem(TPilha *pilha, int item) {
    for(int i = 0; i < pilha->topo; i++) {
        if(pilha->pilha[i].codigo == item) {
            Pedido retirado = pilha->pilha[i];
            for(int j = i; j < pilha->topo; j++) {
                pilha->pilha[j] = pilha->pilha[j+1];
            }
            pilha->topo--;
            return retirado;
        }
    }
}