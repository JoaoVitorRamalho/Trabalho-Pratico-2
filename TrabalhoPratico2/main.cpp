#include <iostream>
#include <windows.h>
#include <fstream>
#include "funcoesPilha.cpp"

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    //Criando a pilha de pedidos e de entrefa
    TPilha entrega;
    Pedido pedidos;

    //iniciando a pilha de entrega
    TPilha_Inicializa(&entrega);

    //criando a pilha auxiliar para organizar a pilha
    TPilha aux;
    //criando a variável de tamanho para sempre saber o tamanho atual da pilha 
    int tamanho;
    //ela recebe qual a maior distancia
    int MaiorDistancia;
    //tamanho atual da pilha de entrega
    int TamanhoPilhaEntrega;
    //criando a variavel que recebe o código do pedido e do produto 
    int codPedido = 0, codProduto = 0; 
    //variavel de procura do id
    int idDesejado;
    //variavel que retira o item da pilha
    int item;
    //variaveis para interagir com o menu
    int opcao, id;
    
    //aqui criamos o arquivo se ele já existir o programa apenas abre ele
    FILE *file = fopen("lanchonete.bin", "r");
    if (file != NULL)
    {
        while (fread(&pedidos, sizeof(Pedido), 1, file))
        {
            if (pedidos.codigo > codPedido)
            {
                codPedido = pedidos.codigo;
            }
            TPilha_Empilha(&entrega, pedidos);
        }
    }
    //aqui é onde o programa faz o auto incremento no código do pedido
    codPedido++;
    //esse do while irá se repetir enquanto não for digitada a opção de saida
    do
    {
        system("cls");
        //imprimindo o menu
        Menu();
        cout << "Opção: ";
        cin >> opcao;
        switch (opcao)
        {
        case 1:
                //limpando a tela e imprimindo o cardapio
                system("cls");
                Cardapio();
                //recebendo o codigo auto incrementado
                pedidos.codigo = codPedido;
                //essas duas variaveis tem que ser iniciadas em 0 para o programa não receber nichos de memória
                pedidos.tamanhoPedido = 0;
                pedidos.valor_pedido = 0;

                cout << "Digite o código do produto: ";
                cin >> codProduto;
                //aqui um switch case para saber o preço de cada produto
                //e no final empilhando o pedido na lista
                switch (codProduto)
                {
                case 1:
                {
                    pedidos.produtos[pedidos.tamanhoPedido] = codProduto;
                    pedidos.tamanhoPedido++;
                    pedidos.valor_pedido = pedidos.valor_pedido + 40;
                    cout << "Digite em km a distância da sua casa até a pizzaria: ";
                    cin >> pedidos.distancia;
                    TPilha_Empilha(&entrega, pedidos);
                    codPedido = codPedido + 1;
                    cout << "Pedido feito com sucesso!\n";
                    system("pause");
                }
                break;
                case 2:
                {
                    pedidos.produtos[pedidos.tamanhoPedido] = codProduto;
                    pedidos.tamanhoPedido++;
                    pedidos.valor_pedido = pedidos.valor_pedido + 30;
                    cout << "Digite em km a distância da sua casa até a pizzaria: ";
                    cin >> pedidos.distancia;
                    TPilha_Empilha(&entrega, pedidos);
                    codPedido = codPedido + 1;
                    cout << "Pedido feito com sucesso!\n";
                    system("pause");
                }
                break;
                case 3:
                {
                    pedidos.produtos[pedidos.tamanhoPedido] = codProduto;
                    pedidos.tamanhoPedido++;
                    pedidos.valor_pedido = pedidos.valor_pedido + 35;
                    cout << "Digite em km a distância da sua casa até a pizzaria: ";
                    cin >> pedidos.distancia;
                    TPilha_Empilha(&entrega, pedidos);
                    codPedido = codPedido + 1;
                    cout << "Pedido feito com sucesso!\n";
                    system("pause");
                }
                break;

                case 4:
                {
                    pedidos.produtos[pedidos.tamanhoPedido] = codProduto;
                    pedidos.tamanhoPedido++;
                    pedidos.valor_pedido = pedidos.valor_pedido + 45;
                    cout << "Digite em km a distância da sua casa até a pizzaria: ";
                    cin >> pedidos.distancia;
                    TPilha_Empilha(&entrega, pedidos);
                    codPedido = codPedido + 1;
                    cout << "Pedido feito com sucesso!\n";
                    system("pause");
                }
                break;

                case 5:
                {
                    pedidos.produtos[pedidos.tamanhoPedido] = codProduto;
                    pedidos.tamanhoPedido++;
                    pedidos.valor_pedido = pedidos.valor_pedido + 50;
                    cout << "Digite em km a distância da sua casa até a pizzaria: ";
                    cin >> pedidos.distancia;
                    TPilha_Empilha(&entrega, pedidos);
                    codPedido = codPedido + 1;
                    cout << "Pedido feito com sucesso!\n";
                    system("pause");
                }
                break;

                default:
                    cout << "Produto inexistente";
                    break;
                }

            break;

        case 2:
            //aqui o programa verifica se está vazia a pilha
            system("cls");
            if (TPilha_Vazia(&entrega))
            {
                cout << "Lista de pedidos vazia.\n\n";
                system("pause");
            }
            else
            {
                //se não estiver imprime todos os pedidos
                TPilha_Imprime(&entrega);
                system("pause");
            }
            break;
        case 3:
            //imprimindo o cardapio
            system("cls");
            Cardapio();
            system("pause");
            break;
        case 4:
            //aqui o programa percorre a pilha inteira procurando se o pedido com o id digitado
            system("cls");
            cout << "Digite o ID do pedido: ";
            cin >> id;

            idDesejado = TPilha_ProcuraPorID(&entrega, id);
            cout << "ID do pedido: " << entrega.pilha[idDesejado].codigo << endl;
            cout << "Distância: " << entrega.pilha[idDesejado].distancia << endl;
            cout << "Valor total do pedido: " << entrega.pilha[idDesejado].valor_pedido << endl;
            cout << "Código do item pedido: "<< entrega.pilha[idDesejado].produtos[idDesejado] << endl;;
            
            system("pause");
            break;
        case 5:
            //após verificar se a pilha está vazia
            //o programa cria a variável auxiliar e desempilha os itens da pilha principal e empilha nela
            //após isso só é empilhado na pilha principal o item que possui a maior distância
            //em seguida é retirado da pilha auxiliar os itens adicionados
            system("cls");
            if (TPilha_Vazia(&entrega))
            {
                cout << "Lista de Pedidos vazia!\n";
            }
            else
            {
                TPilha aux;
                TPilha_Inicializa(&aux);
                tamanho = entrega.topo;
                for (int i = 0; i < tamanho; i++)
                {
                    TPilha_Desempilha(&entrega, &pedidos);
                    TPilha_Empilha(&aux, pedidos);
                }
                tamanho = aux.topo;
                for (int j = 0; j < tamanho; j++)
                {
                    MaiorDistancia = 0;
                    for (int i = 0; i < aux.topo; i++)
                    {
                        if (MaiorDistancia < aux.pilha[i].distancia)
                        {
                            MaiorDistancia = aux.pilha[i].distancia;
                            item = aux.pilha[i].codigo;
                        }
                    }
                    TPilha_Empilha(&entrega, RemoverItem(&aux, item));
                }
                cout << "A ordem de entrega foi organizada.\n";
                TPilha_Imprime(&entrega);
            }
            system("pause");
            system("cls");
            break;
        case 6:
            //aqui ele verifica se ela está vazia e se não estiver ele desempilha o topo que após ser organizado será o mais perto
            system("cls");
            if (TPilha_Vazia(&entrega))
            {
                cout << "Pilha vazia.\n";
            }
            else
            {
                TPilha_Desempilha(&entrega, &pedidos);
                cout << "ID do pedido entregue: " << pedidos.codigo << endl
                     << endl;
            }
            system("pause");
            system("cls");
            break;

        case 7:
            //nesse caso ele vai sair do ciclo de repetição e salva os dados no arquivo binário
            file = fopen("lanchonete.bin", "w");
            tamanho = entrega.tamanhoPilha;
            for (int i = 0; i < tamanho; i++)
            {
                TPilha_Desempilha(&entrega, &pedidos);
                fwrite(&pedidos, sizeof(Pedido), 1, file);
            }
            cout << "Saindo...";
            Sleep(1000);
            break;
        default:
            break;
        }
    } while (opcao != 7);

    return 0;
}