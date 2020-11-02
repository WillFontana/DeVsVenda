/*
 * Integrantes
 * Carlos Henrique Moreira Diniz ---- 2000118
 * Luana Maria Albertoni ---- 2012683
 * Willyan Fontana do Prado ---- 2008381
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definimos a estrutura dos clientes
struct contato
{
  char telefone[12], // Telefone fixo do cliente
      celular[13]    // Celular do cliente
};
struct cliente
{
  int cdCliente,         // Codigo do cliente
      comprasRealizadas; // Compras realizadas
  char nomeCliente[50],  // Nome do Cliente
      sexoCliente[2],    // Sexo do Cliente
      emailCliente[50];  // Email do Cliente
  double cpfCliente;     // CPF do cliente
  struct contato tel;
};
typedef struct cliente client;
// -----------------------------------

// Definimos a estrutura dos produtos
struct produto
{
};
// -----------------------------------

// Definimos a estrutura das compras
struct compra
{
  int qtComprasARealizar,  // Quantidades de compras que o usuario deseja fazer
      cdCompra,            // Identificação da compra do produto
      relacaoCliente,      // Relação da compra com o  usuario
      relacaoProduto,      // Relação da compra com o produto
      qtVenda;             // Quantidade de produtos vendidos
  double subTotalCompra,   // Subtotal padrao do produto
      prcntDescontoCompra, // Porcentagem do desconto
      valorTotalVenda;     // Valor final da venda
};

// Interações do cliente
void cadastraCliente(struct cliente *cliente, int contador), // Cadastro de cliente
    listarClientes(struct cliente *cliente);                 // Listagem de cliente
// ---------------------

// Interações do produto
void cadastraProdutos(struct produto *produto, int contador), // Cadastro de produtos
    listarProdutos(struct produto *produto);                  // Listagem de produtos
// ---------------------

// Realocamento de tamanho das structs
void RealocaTamanhoStruct(struct estrutura *estrutura, int multiploRealocamento)
{
  estrutura = realloc(estrutura, multiploRealocamento * sizeof(estrutura));
  if (estrutura == NULL)
  {
    printf("Limite disponivel no banco de dados atingido");
  }
  return;
};

// Resposta do usuario
int promptCompare(char prompt[2])
{
  if (strcmp(prompt, "s") == 0)
    return 1;
  else
    return 0;
}

void main()
{
  printf("---{ Iniciando o sistema! }---\n");
  // Declaração das variáveis de controle gerais
  char promptSimNao[2]; // Resposta do usuário (Qualquer caractere diferente de s é considerado não pelo sistema);
  int filaCliente = 1,  // Contador de clientes
      filaProdutos = 1, // Contador de produtos
      escolhaMenu;      // Escolha do menu
  client *clientes;
  clientes = (client *)malloc(filaCliente * sizeof(client));
  if (clientes == NULL)
  {
    printf("Erro ao alocar espaco para os clientes");
  }

  printf("Bem vindo ao MVP do Sr. Oswaldo!\n");
  do
  {
    // Menu de escolha do sistema
    printf("\n############# Menu de controle ##############\n");
    printf("#############################################\n\n");
    printf("       --- { O que deseja fazer? }---\n\n");
    printf("1 Vizualizar Produdos");
    printf("\t|\t2 Vizualizar Clientes\n");
    printf("3 Importar Produdos");
    printf("\t|\t4 Importar Clientes\n");
    printf("5 Cadastrar Produtos");
    printf("\t|\t6 Cadastrar Clientes\n");
    printf("7 Realizar venda");
    printf("\t|\t8 Finzalizar o programa\n");
    printf("Escolha uma opcao: -- ");
    scanf("%d", &escolhaMenu);
    fflush(stdin);
    switch (escolhaMenu)
    {
    case 1: // Listagem de produtos
      if (filaProdutos == 1)
      {
        printf("Parece que nao existem produtos cadastrados\n");
        printf("Cadastrar um Produto agora (S/n)? ");
        fflush(stdin);
        strlwr(gets(promptSimNao));
        if (promptCompare(promptSimNao) == 1)
        {
          // Realiza cadastro de produtos
          printf("\nO usuario disse sim");
        }
        else
        {
          // Importar produtos
          printf("\nVoce tambem pode importar os produtos do banco de dados!\n");
          printf("Importar os produtos (S/n)? ");
          fflush(stdin);
          strlwr(gets(promptSimNao));
          if (promptCompare(promptSimNao) == 1)
          {
            // Importamos os clientes
          }
        }
      }
      else
      {
      }
      break;
    case 2: // Listagem de clientes
      if (filaCliente == 1)
      {
        printf("Parece que nao existem clientes cadastrados\n");
        printf("Cadastrar um cliente agora (S/n)? ");
        fflush(stdin);
        strlwr(gets(promptSimNao));
        if (promptCompare(promptSimNao) == 1)
        {
          do
          {
            RealocaTamanhoStruct(clientes, filaCliente);
            cadastraCliente(&clientes[filaCliente], filaCliente);            
            filaCliente++;
            printf("Cadastrar um novo cliente(S/n)? ");
            fflush(stdin);
            strlwr(gets(promptSimNao));
          } while (promptCompare(promptSimNao) == 1);
        }
        else
        {
          // Importar produtos
          printf("\nVoce tambem pode importar os clientes do banco de dados!\n");
          printf("Importar os clientes (S/n)? ");
          fflush(stdin);
          strlwr(gets(promptSimNao));
          if (promptCompare(promptSimNao) == 1)
          {
            // Importamos os clientes
          }
        }
      }
      else
      {
        for (size_t i = 1; i < filaCliente; i++)
        {
          listarClientes(&clientes[i]);
        }
      }
      break;
    case 6: // Cadastro direto de cliente
      do
      {
        RealocaTamanhoStruct(clientes, filaCliente);
        cadastraCliente(&clientes[filaCliente], filaCliente);
        filaCliente++;
        printf("Cadastrar um novo cliente(S/n)? ");
        fflush(stdin);
        strlwr(gets(promptSimNao));
      } while (promptCompare(promptSimNao) == 1);
    default:
      break;
    }
  } while (escolhaMenu != 8);
}

void cadastraCliente(struct cliente *cliente, int contador)
{  
  cliente->cdCliente = contador;
  // Nome do cliente:
  printf("\nInsira o nome do cliente: ");
  fflush(stdin);
  gets(cliente->nomeCliente);
  // CPF do cliente:
  printf("\nInsira o cpf do cliente: ");
  fflush(stdin);
  scanf("%lf", &cliente->cpfCliente);
  // Email do cliente:
  printf("\nInsira o email do cliente: ");
  fflush(stdin);
  gets(cliente->emailCliente);
  // Telefone do cliente
  printf("\nInsira o telefone fixo do cliente: ");
  fflush(stdin);
  gets(cliente->tel.telefone);
  // Celular do cliente
  printf("\nInsira o celular do cliente: ");
  fflush(stdin);
  gets(cliente->tel.celular);
  // Sexo do cliente:
  printf("\nInsira o sexo do cliente (F/M): ");
  fflush(stdin);
  gets(cliente->sexoCliente);

  printf("\nO cliente foi cadastrado com sucesso!\n");
  printf("\n\nDados do cadastro!\n\n");
  listarClientes(cliente);
}

void listarClientes(struct cliente *cliente)
{  
  // Codigo do cliente:
  printf("#########################");
  printf("\n# Codigo do cadastro do cliente: %d", cliente->cdCliente);
  // Nome do cliente:
  printf("\n\n# Nome do cliente: %s", cliente->nomeCliente);
  // CPF do cliente:
  printf("\n\n# Cpf do cliente: %.0lf", cliente->cpfCliente);
  // Email do cliente:
  printf("\n\n# Email do cliente: %s", cliente->emailCliente);
  // Telefone do cliente
  printf("\n\n# Telefone fixo do cliente: %s", cliente->tel.telefone);
  // Telefone do cliente
  printf("\n\n# Celular do cliente: %s", cliente->tel.celular);
  // Sexo do cliente:
  printf("\n\n# Sexo do cliente (F/M): %s", cliente->sexoCliente);
  printf("\n\n#########################\n\n");
}