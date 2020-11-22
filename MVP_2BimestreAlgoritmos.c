/*
 * Integrantes
 * Carlos Henrique Moreira Diniz ---- 2000118
 * Luana Maria Albertoni ---- 2012683
 * Willyan Fontana do Prado ---- 2008381
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>;

// Definimos a estrutura dos clientes
struct contato
{
	char telefone[20], // Telefone fixo do cliente
			celular[20];	 // Celular do cliente
};
struct cliente
{
	int cdCliente,									 // Codigo do cliente
			posicaoFila,								 // Posição da pessoa na fila
			comprasRealizadas;					 // Compras realizadas
	char nomeCliente[50],						 // Nome do Cliente
			sexoCliente[2],							 // Sexo do Cliente
			emailCliente[50];						 // Email do Cliente
	double cpfCliente;							 // CPF do cliente
	struct contato tel;							 // Telefones do cliente
	struct cliente *proximoCliente;	 // Proximo cliente na fila
	struct cliente *clienteAnterior; // Cliente anterior na fila
};
typedef struct cliente client;
// -----------------------------------

// Definimos a estrutura dos produtos
struct modelo
{
	char marcaproduto[20], //marca do produto
			modeloproduto[20]; //modelo do produto
};
struct produto
{
	int cdProduto,									 //codigo do produto
			posicaoFila;								 // Posição do produto na fila
	char nomeProduto[50];						 //nome do produto
	double valorProduto;						 // valor do produto
	struct modelo model;						 // variações do produto
	struct produto *proximoProduto;	 // Proximo produto na fila
	struct produto *produtoAnterior; // Produto anterior na fila
};
typedef struct produto product;
// -----------------------------------

// Definimos a estrutura das compras
struct produtosNaCompra
{
	struct produto *mercadoria1;
	struct produto *mercadoria2;
};

struct compra
{
	struct cliente *comprador;
	struct produtosNaCompra produtosAComprar;
	int cdCompra,						 // Identificação da compra do produto
			relacaoCliente,			 // Relação da compra com o  usuario
			relacaoProduto1,		 // Relação da compra com o produto 1
			relacaoProduto2,		 // Relação da compra com o produto 2
			qtVenda1,						 // Quantidade de produtos 1 vendidos
			qtVenda2;						 // Quantidade de produtos 2 vendidos
	double subTotalCompra,	 // Subtotal padrao do produto
			subTotalProduto1,		 // Quantidade de produtos 1 vendidos
			prcntDescontoCompra, // Porcentagem do desconto
			subTotalProduto2,		 // Quantidade de produtos 1 vendidos
			valorTotalVenda;		 // Valor final da venda
};
typedef struct compra purchase;

struct listagemCLientes
{
	struct cliente *primeiroCliente; // Proximo cliente na fila
	struct cliente *ultimoCliente;	 // Cliente anterior na fila
};

void listarFilaClientes(struct listagemCLientes *listagemCLientes);

// Interações do cliente
void cadastraCliente(struct cliente *cliente, int contador), // Cadastro de cliente
		listarClientes(struct cliente *cliente);								 // Listagem de cliente
// Atribuição do cdCliente pelo cpf
int generateCdCliente(double cpfCliente);
// Encontra o cliente por cpf
int encontraCliente(int maxVal, struct cliente *cliente);
// ---------------------

// Interações do produto
void cadastraProdutos(struct produto *produto, int contador), // Cadastro de produtos
		listarProdutos(struct produto *produto);									// Listagem de produtos
// Gera o código do produto
int generateCdProduto(char marcaProduto[20], char modeloProduto[20]);
// Encontra o produto
int encontraProduto(int maxVal, struct produto *produto);
// ---------------------

// Listagens de clientes
struct listagemCLientes *criarListagemDeClientes();

void inserirClienteNaListagem(struct listagemCLientes *listagemCLientes, struct cliente *cliente);

// Importação dos clientes
int importClientes(struct cliente *cliente, int contador, struct listagemCLientes *listagemCLientes);
// Ordenação de clientes nas filas
void ordenaCliente(struct cliente *cliente, int contador);
// Ordenação de produtos
void ordenaProdutos(struct produto *produto, int contador);
// Inserção de clientes no final da fila
void inserirClienteNaFila(struct cliente *cliente, int contador);
// Inserção de produtos no final da fila
void inserirProdutosNaFila(struct produto *produto, int contador);
// Importação dos produtos
int importProdutos(struct produto *produto, int contador);
// Realização de compras
void realizaCompra(struct compra *compra, int produtosNaCompra);
// Validação de email'
int validaEmail(char email[50])
{
	// Se o @ e o .com não existir invalida o email
	if (strstr(email, "@") == NULL && strstr(email, ".com") == NULL)
	{
		printf("\nO email inserido nao eh valido\n\n");
		return 0;
	}
	// Se o @ existir e o .com não existir invalida o email
	else if (strstr(email, "@") != NULL && strstr(email, ".com") == NULL)
	{
		printf("\nO email inserido nao eh valido\n\n");
		return 0;
	}
	// Se o @ não existir e o .com existir invalida o email
	else if (strstr(email, "@") == NULL && strstr(email, ".com") != NULL)
	{
		printf("\nO email inserido nao eh valido\n\n");
		return 0;
	}
	// Se houver @ e .com o email é valido
	else
	{
		return 1;
	}
}
// Validação do sexo
int validaSexo(char sexo[2])
{
	if (strcmp(strlwr(sexo), "f") != 0 && strcmp(strlwr(sexo), "m") != 0 && strcmp(strlwr(sexo), "o") != 0)
	{
		printf("Opcao sexual invalida");
		return 0;
	}
	else
	{
		return 1;
	}
};
// Resposta do usuario
int promptCompare(char prompt[2])
{
	if (strcmp(prompt, "s") == 0)
		return 1;
	else
		return 0;
}

void mascaraTelefone(char telefone[20], struct cliente *cliente);
void mascaraCelular(char celular[20], struct cliente *cliente);

void main()
{

	printf("---{ Iniciando o sistema! }---\n");
	// Declaração das variáveis de controle gerais
	char promptSimNao[2];				// Resposta do usuário (Qualquer caractere diferente de s é considerado não pelo sistema);
	int filaClientes = 0,				// Contador de clientes
			filaProdutos = 0,				// Contador de produtos
			contadorPadrao,					// Contador padrão para laços
			clientesImportados = 0, // Verificamos se os clientes já foram importados
			produtosImportados = 0, // Verificamos se os produtos já foram importados
			ableToProceed = 0,			// Controle para habilitar procedência de etapas
			ClienteEncontrado,			// Cliente encontrado na busca por CPF
			ProdutoEncontrado,			// Produto encontrado pelo código de cadastro
			produtosNaCompra,				// Quantia de produtos diferentes vendidos
			escolhaMenu;						// Escolha do menu

	// Variáveis para busca binária
	int base = 0, maxProdutos = filaProdutos, maxClientes = filaClientes;

	// Criamos nossas listagens
	struct listagemCLientes *listaDeClientes = criarListagemDeClientes();

	client *clientes; // Definimos nossa tabela de clientes
	// typecast
	clientes = (client *)calloc(50, sizeof(client)); // Alocamos espaço para o cliente
	if (clientes == NULL)
	{
		printf("Erro ao alocar espaco para os clientes");
		return;
	}

	clientes->proximoCliente = NULL;
	clientes->clienteAnterior = NULL;

	product *produtos;
	produtos = (product *)calloc(50, sizeof(product)); // Alocamos espaço para o produto
	if (produtos == NULL)
	{
		printf("Erro ao alocar espaco para os produtos");
		return;
	}
	produtos->proximoProduto = NULL;
	produtos->produtoAnterior = NULL;

	purchase *carrinho;
	carrinho = (purchase *)calloc(1, sizeof(purchase)); // Alocamos um espaço para a compra
	if (carrinho == NULL)
	{
		printf("Erro ao alocar espaco para o carrinho");
		return;
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
		printf("5 Ordenar Produdos");
		printf("\t|\t6 Ordenar Clientes\n");
		printf("7 Encontrar Produtos");
		printf("\t|\t8 Encontrar Clientes\n");
		printf("9 Cadastrar Produtos");
		printf("\t|\t10 Cadastrar Clientes\n");
		printf("11 Realizar venda");
		printf("\t|\t12 Finzalizar o programa\n");
		printf("Escolha uma opcao: -- ");
		scanf("%d", &escolhaMenu);
		fflush(stdin);
		switch (escolhaMenu)
		{
		case 1: // Listagem de produtos
			if (filaProdutos == 0)
			{
				printf("Parece que nao existem produtos cadastrados\n");
				printf("Cadastrar um Produto agora (S/n) ? ");
				fflush(stdin);
				strlwr(gets(promptSimNao));
				fflush(stdin);
				if (promptCompare(promptSimNao) == 1)
				{
					do
					{
						cadastraProdutos(&produtos[filaProdutos], filaProdutos);
						inserirProdutosNaFila(produtos, filaProdutos);
						filaProdutos++;
						maxProdutos = filaProdutos;
						printf("Cadastrar um novo produto(S/n) ? ");
						fflush(stdin);
						strlwr(gets(promptSimNao));
						fflush(stdin);
					} while (promptCompare(promptSimNao) == 1);
				}
				else
				{
					// Importar produtos
					printf("\nVoce tambem pode importar os produtos do banco de dados!\n");
					printf("Importar os produtos (S/n) ? ");
					fflush(stdin);
					strlwr(gets(promptSimNao));
					if (promptCompare(promptSimNao) == 1)
					{
						produtosImportados = importProdutos(produtos, filaProdutos);
						// Somamos a fila de produtos com as novas adições
						// Utilizamos o +1 pois a fila de novos produtos começa em 0
						filaProdutos = filaProdutos + produtosImportados + 1;
						maxProdutos = filaProdutos;
						printf("\nProdutos inseridos no sistema");
						printf("\nNumero de produtos cadastrados no sistema: %d\n", filaProdutos);
					}
				}
			}
			else
			{
				for (size_t i = 0; i < filaProdutos; i++)
				{
					listarProdutos(&produtos[i]);
				}
			}
			break;
		case 2: // Listagem de clientes
			if (filaClientes == 0)
			{
				printf("Parece que nao existem clientes cadastrados\n");
				printf("Cadastrar um cliente agora (S/n) ? ");
				fflush(stdin);
				strlwr(gets(promptSimNao));
				fflush(stdin);
				if (promptCompare(promptSimNao) == 1)
				{
					do
					{
						cadastraCliente(&clientes[filaClientes], filaClientes);
						inserirClienteNaFila(clientes, filaClientes);
						inserirClienteNaListagem(listaDeClientes, &clientes[filaClientes]);
						filaClientes++;
						maxClientes = filaClientes;
						printf("Cadastrar um novo cliente(S/n) ? ");
						fflush(stdin);
						strlwr(gets(promptSimNao));
						fflush(stdin);
					} while (promptCompare(promptSimNao) == 1);
				}
				else
				{
					// Importar produtos
					printf("\nVoce tambem pode importar os clientes do banco de dados!\n");
					printf("Importar os clientes (S/n) ? ");
					fflush(stdin);
					strlwr(gets(promptSimNao));
					if (promptCompare(promptSimNao) == 1)
					{
						clientesImportados = importClientes(clientes, filaClientes, listaDeClientes);
						// Somamos a fila de clientes com as novas adições
						// Utilizamos o +1 pois a fila de novos clientes começa em 0
						filaClientes = filaClientes + clientesImportados;
						inserirClienteNaFila(clientes, filaClientes);
						// Inserimos os clientes na fila
						filaClientes = filaClientes + 1;
						maxClientes = filaClientes;
						printf("\nClientes inseridos no sistema");
						printf("\nNumero de clientes cadastrados no sistema: %d\n", filaClientes);
					}
				}
			}
			else
			{
				listarFilaClientes(listaDeClientes);
			}
			break;
		case 3:
			// Verificamos se os produtos foram importados
			if (produtosImportados == 0)
			{
				produtosImportados = importProdutos(produtos, filaProdutos);
				// Somamos a fila de produtos com as novas adições
				// Utilizamos o +1 pois a fila de novos produtos começa em 0
				filaProdutos = filaProdutos + produtosImportados + 1;
				maxProdutos = filaProdutos;
				printf("\nProdutos inseridos no sistema");
				printf("\nNumero de produtos cadastrados no sistema: %d\n", filaProdutos);
			}
			else
			{
				printf("\nOs clientes ja foram exportados do banco!\n");
			}
			printf("\nRetornando ao menu inicial\n");
			break;
		case 4: // Importação de clientes
			// Verificamos se os clientes foram importados
			if (clientesImportados == 0)
			{
				clientesImportados = importClientes(clientes, filaClientes, listaDeClientes);
				// Somamos a fila de clientes com as novas adições
				// Utilizamos o +1 pois a fila de novos clientes começa em 0
				filaClientes = filaClientes + clientesImportados;
				inserirClienteNaFila(clientes, filaClientes);
				// Inserimos os clientes na fila
				filaClientes = filaClientes + 1;
				maxClientes = filaClientes;
				printf("\nClientes inseridos no sistema");
				printf("\nNumero de clientes cadastrados no sistema: %d\n", filaClientes);
			}
			else
			{
				printf("\nOs clientes ja foram exportados do banco!\n");
			}
			printf("\nRetornando ao menu inicial\n");
			break;
		case 5: // Ordenação de clientes por CPF
			if (filaProdutos == 0)
			{
				printf("\nO sistema ainda nao possui produtos para ordenar!\n");
			}
			else
			{
				ordenaProdutos(produtos, filaProdutos);
				printf("Produtos ordenados com sucesso!");
			}
			break;
		case 6: // Ordenação de clientes por CPF
			if (filaClientes == 0)
			{
				printf("\nO sistema ainda nao possui clientes para ordenar!\n");
			}
			else
			{
				ordenaCliente(clientes, filaClientes);
				printf("Clientes ordenados com sucesso!");
			}
			break;
		case 7: // Busca do produto pelo código
			// Verificamos existencia de produtos
			if (filaProdutos == 0)
			{
				printf("\n\nNao existem produtos cadastrados no sistema para encontrar");
				return;
			}
			else
			{
				// Ordenamos os produtos para que a busca binária funcione
				ordenaProdutos(produtos, filaProdutos);
				ProdutoEncontrado = encontraProduto(filaProdutos, produtos);
				// Caso o produto exista
				if (ProdutoEncontrado >= 0)
				{
					printf("\n\nProduto encontrado!\n");
					printf("Dados do produto:\n");
					listarProdutos(&produtos[ProdutoEncontrado]);
				}
				else
				{
					printf("\n\nProduto nao encontrado!\n");
				}
			}
			break;
			break;
		case 8: // Busca por cliente pelo CPF
			// Verificamos a exitencia de clientes
			if (filaClientes == 0)
			{
				printf("\n\nNao existem clientes cadastrados no sistema para encontrar");
				return;
			}
			else
			{
				// Ordenamos os clientes para que a busca binária funcione
				ordenaCliente(clientes, filaClientes);
				ClienteEncontrado = encontraCliente(filaClientes, clientes);
				// Caso o cliente exista
				if (ClienteEncontrado >= 0)
				{
					printf("\n\nCliente encontrado!\n");
					printf("Dados do cliente:\n");
					listarClientes(&clientes[ClienteEncontrado]);
				}
				else
				{
					printf("\n\nCliente nao encontrado!\n");
				}
			}
			break;
		case 9: // Cadastro direto de produtos
			do
			{
				cadastraProdutos(&produtos[filaProdutos], filaProdutos);
				inserirProdutosNaFila(produtos, filaProdutos);
				filaProdutos++;
				maxProdutos = filaProdutos;
				printf("Cadastrar um novo produto(S/n) ? ");
				fflush(stdin);
				strlwr(gets(promptSimNao));
				fflush(stdin);
			} while (promptCompare(promptSimNao) == 1);
			break;
		case 10: // Cadastro direto de cliente
			do
			{
				cadastraCliente(&clientes[filaClientes], filaClientes);
				inserirClienteNaFila(clientes, filaClientes);
				inserirClienteNaListagem(listaDeClientes, &clientes[filaClientes]);
				filaClientes++;
				maxClientes = filaClientes;
				printf("Cadastrar um novo cliente(S/n) ? ");
				fflush(stdin);
				strlwr(gets(promptSimNao));
				fflush(stdin);
			} while (promptCompare(promptSimNao) == 1);
			break;
		case 11: // Realização de compras
			if (filaClientes == 0)
			{
				printf("\n\nNao eh possivel realizar uma venda pois nao existem clientes cadastrados\n");
				printf("Cadastrar um Cliente agora (S/n) ? ");
				fflush(stdin);
				strlwr(gets(promptSimNao));
				fflush(stdin);
				if (promptCompare(promptSimNao) == 1)
				{
					do
					{
						cadastraCliente(&clientes[filaClientes], filaClientes);
						inserirClienteNaFila(clientes, filaClientes);
						inserirClienteNaListagem(listaDeClientes, &clientes[filaClientes]);
						filaClientes++;
						maxClientes = filaClientes;
						printf("Cadastrar um novo cliente(S/n) ? ");
						fflush(stdin);
						strlwr(gets(promptSimNao));
						fflush(stdin);
					} while (promptCompare(promptSimNao) == 1);
				}
				else
				{
					// Importar produtos
					printf("\nVoce tambem pode importar os clientes do banco de dados!\n");
					printf("Importar os clientes (S/n) ? ");
					fflush(stdin);
					strlwr(gets(promptSimNao));
					if (promptCompare(promptSimNao) == 1)
					{
						clientesImportados = importClientes(clientes, filaClientes, listaDeClientes);
						// Somamos a fila de clientes com as novas adições
						// Utilizamos o +1 pois a fila de novos clientes começa em 0
						filaClientes = filaClientes + clientesImportados;
						inserirClienteNaFila(clientes, filaClientes);
						// Inserimos os clientes na fila
						filaClientes = filaClientes + 1;
						maxClientes = filaClientes;
						printf("\nClientes inseridos no sistema");
						printf("\nNumero de clientes cadastrados no sistema: %d\n", filaClientes);
					}
				}
			}
			else if (filaProdutos == 0)
			{
				printf("\n\nNao eh possivel realizar uma venda pois nao existem produtos cadastrados\n");
				printf("Cadastrar um Produto agora (S/n) ? ");
				strlwr(gets(promptSimNao));
				fflush(stdin);
				if (promptCompare(promptSimNao) == 1)
				{
					do
					{
						cadastraProdutos(&produtos[filaProdutos], filaProdutos);
						inserirProdutosNaFila(produtos, filaProdutos);
						filaProdutos++;
						maxProdutos = filaProdutos;
						printf("Cadastrar um novo produto(S/n) ? ");
						fflush(stdin);
						strlwr(gets(promptSimNao));
						fflush(stdin);
					} while (promptCompare(promptSimNao) == 1);
				}
				else
				{
					// Importar produtos
					printf("\nVoce tambem pode importar os produtos do banco de dados!\n");
					printf("Importar os produtos (S/n) ? ");
					fflush(stdin);
					strlwr(gets(promptSimNao));
					if (promptCompare(promptSimNao) == 1)
					{
						produtosImportados = importProdutos(produtos, filaProdutos);
						// Somamos a fila de produtos com as novas adições
						// Utilizamos o +1 pois a fila de novos produtos começa em 0
						filaProdutos = filaProdutos + produtosImportados + 1;
						maxProdutos = filaProdutos;
						printf("\nProdutos inseridos no sistema");
						printf("\nNumero de produtos cadastrados no sistema: %d\n", filaProdutos);
					}
				}
			}
			else
			{
				printf("\nPor favor insira o codigo de cadastro do cliente: ");
				fflush(stdin);
				scanf("%d", &carrinho->relacaoCliente);
				contadorPadrao = 0;
				while (contadorPadrao < filaClientes)
				{
					if (carrinho->relacaoCliente == clientes[contadorPadrao].cdCliente)
					{
						// printf("Valor do ponteiro do cliente: %p", clientes[contadorPadrao]);
						carrinho->comprador = &clientes[contadorPadrao];
						printf("Cliente encontrado: %s\n", carrinho->comprador->nomeCliente);
						ableToProceed = 1;
						contadorPadrao = filaClientes + 1;
					}
					else
					{
						ableToProceed = 0;
						contadorPadrao++;
					}
				}
				if (ableToProceed < 1)
				{
					printf("\nNao foram encontrados clientes com o codigo inserido!\n");
					printf("Deseja listar todos os produtos cadastrados (S/n) ? \n");
					fflush(stdin);
					strlwr(gets(promptSimNao));
					fflush(stdin);
					if (promptCompare(promptSimNao) == 1)
					{
						for (size_t i = 1; i < filaClientes; i++)
						{
							listarClientes(&clientes[i]);
						}
					}
					printf("\n\nVoltando ao menu inicial");
				}
				else
				{
					printf("\nPor favor insira o codigo de cadastro do produto: ");
					fflush(stdin);
					scanf("%d", &carrinho->relacaoProduto1);
					contadorPadrao = 0;
					while (contadorPadrao < filaProdutos)
					{
						if (carrinho->relacaoProduto1 == produtos[contadorPadrao].cdProduto)
						{
							carrinho->produtosAComprar.mercadoria1 = &produtos[contadorPadrao];
							printf("Produto encontrado: %s\n", carrinho->produtosAComprar.mercadoria1->nomeProduto);
							ableToProceed = 1;
							contadorPadrao = filaProdutos + 1;
							produtosNaCompra = 1;
						}
						else
						{
							ableToProceed = 0;
							contadorPadrao++;
						}
					}
					if (ableToProceed < 1)
					{
						printf("\nNao foram encontrados produtos com o codigo inserido!\n");
						printf("Deseja listar todos os produtos cadastrados (S/n) ? \n");
						fflush(stdin);
						strlwr(gets(promptSimNao));
						fflush(stdin);
						if (promptCompare(promptSimNao) == 1)
						{
							for (size_t i = 1; i < filaProdutos; i++)
							{
								listarProdutos(&produtos[i]);
							}
						}
						printf("\nVoltando ao menu inicial");
					}
					else
					{
						contadorPadrao = 0;
						printf("\nDeseja adicionar mais um produto (S/n)? ");
						fflush(stdin);
						strlwr(gets(promptSimNao));
						fflush(stdin);
						if (promptCompare(promptSimNao) == 1)
						{
							printf("\nPor favor insira o codigo de cadastro do produto: ");
							fflush(stdin);
							scanf("%d", &carrinho->relacaoProduto2);
							contadorPadrao = 1;
							while (contadorPadrao < filaProdutos)
							{
								if (carrinho->relacaoProduto2 == produtos[contadorPadrao].cdProduto)
								{
									carrinho->produtosAComprar.mercadoria2 = &produtos[contadorPadrao];
									printf("Produto encontrado: %s\n", carrinho->produtosAComprar.mercadoria2->nomeProduto);
									ableToProceed = 1;
									contadorPadrao = filaProdutos + 1;
									produtosNaCompra = 2;
								}
								else
								{
									ableToProceed = 0;
									contadorPadrao++;
								}
							}
							if (ableToProceed < 1)
							{
								printf("\nNao foram encontrados produtos com o codigo inserido!\n");
								printf("Deseja listar todos os produtos cadastrados (S/n) ? \n");
								fflush(stdin);
								strlwr(gets(promptSimNao));
								fflush(stdin);
								if (promptCompare(promptSimNao) == 1)
								{
									for (size_t i = 1; i < filaProdutos; i++)
									{
										listarProdutos(&produtos[i]);
									}
								}
								printf("\nVoltando ao menu inicial");
								return;
							}
						}
						printf("Deseja vender %s ", carrinho->produtosAComprar.mercadoria1->nomeProduto);
						if (produtosNaCompra == 2)
						{
							printf("e %s ", carrinho->produtosAComprar.mercadoria2->nomeProduto);
						}
						printf("para o cliente %s (S/n) ? ", carrinho->comprador->nomeCliente);
						fflush(stdin);
						strlwr(gets(promptSimNao));
						fflush(stdin);
						if (promptCompare(promptSimNao) == 1)
						{
							realizaCompra(carrinho, produtosNaCompra);
							printf("\n#########################\n\n");
							printf("\nCompra finalizada com sucesso!\n\n");
							printf("Retornando ao menu inicial!\n\n");
						}
						else
						{
							printf("\nCompra cancelada");
							printf("\n\nRetornando ao menu principal");
						}
					}
				}
			}
			break;
		default:
			break;
		}
	} while (escolhaMenu != 12);
	free(clientes);
	free(produtos);
	free(carrinho);
}

// Manipulação de clientes
void cadastraCliente(struct cliente *cliente, int contador)
{
	int ableToProceed;
	// Código do cliente
	cliente->comprasRealizadas = 0;
	cliente->posicaoFila = contador;
	// Nome do cliente:
	printf("\nInsira o nome do cliente: ");
	fflush(stdin);
	gets(cliente->nomeCliente);
	do
	{

		// CPF do cliente:
		printf("\nInsira o cpf do cliente: ");
		fflush(stdin);
		scanf("%lf", &cliente->cpfCliente);
		if (cliente->cpfCliente == 0)
		{
			printf("\nCpf inserido invalido!");
			ableToProceed = 0;
		}
		else
		{
			cliente->cdCliente = generateCdCliente(cliente->cpfCliente);
			ableToProceed = 1;
		}

	} while (ableToProceed = 0);

	do
	{
		printf("\nInsira o email do cliente: ");
		fflush(stdin);
		gets(cliente->emailCliente);
	} while (validaEmail(cliente->emailCliente) == 0);
	// Telefone do cliente
	printf("\nInsira o telefone fixo do cliente (com DDD): ");
	fflush(stdin);
	gets(cliente->tel.telefone);
	if (cliente->tel.telefone[0] != '\0')
	{
		mascaraTelefone(cliente->tel.telefone, cliente);
	}
	else
	{
		printf("\nTelefone nao informado");
		strcpy(cliente->tel.telefone, "Desconhecido");
	}

	// Celular do cliente
	printf("\nInsira o celular do cliente (com DDD): ");
	fflush(stdin);
	gets(cliente->tel.celular);
	if (cliente->tel.celular[0] != '\0')
	{
		mascaraCelular(cliente->tel.celular, cliente);
	}
	else
	{
		printf("\nCelular nao informado");
		strcpy(cliente->tel.celular, "Desconhecido");
	}
	// Sexo do cliente:
	do
	{
		printf("\nInsira o sexo do cliente (F/M/O): ");
		fflush(stdin);
		gets(cliente->sexoCliente);
	} while (validaSexo(cliente->sexoCliente) == 0);
	printf("\nO cliente foi cadastrado com sucesso!\n");
	printf("\n\nDados do cadastro!\n\n");
	listarClientes(cliente);
	return;
}
void listarClientes(struct cliente *cliente)
{
	// printf("\nDentro da listagem %p", cliente);
	// Codigo do cliente:
	printf("\n\n#########################");
	printf("\n# Codigo do cadastro do cliente: %d", cliente->cdCliente);
	// Nome do cliente:
	printf("\n\n# Nome do cliente: %s", cliente->nomeCliente);
	// CPF do cliente:
	printf("\n\n# Cpf do cliente: %.0lf", cliente->cpfCliente);
	// Email do cliente:
	printf("\n\n# Email do cliente: %s", cliente->emailCliente);
	// Telefone do cliente
	printf("\n\n# Telefone fixo do cliente: %s", cliente->tel.telefone);
	// Posição do cliente na fila
	printf("\n\n# Posicao do cliente na fila: %d", cliente->posicaoFila);
	// Telefone do cliente
	printf("\n\n# Celular do cliente: %s", cliente->tel.celular);
	// Sexo do cliente:
	printf("\n\n# Sexo do cliente (F/M/O): %s", cliente->sexoCliente);
	printf("\n#########################\n\n");
	return;
}
// Importação de clientes
int importClientes(struct cliente *cliente, int contador, struct listagemCLientes *listagemCLientes)
{
	// Setamos a quantia de clientes importados
	int clientesImportados = 0;
	FILE *clientBackUp;
	// Abrimos o arquivo de leitura
	clientBackUp = fopen("clientes_bd.csv", "r");
	// Caso não seja possivel ler o arquivo
	if (!clientBackUp)
	{
		printf("\nNao foi possivel importar os clientes\n");
		return 0;
	}
	else
	{
		printf("\nIniciando a importacao.....\n");
		// Definimos nossas variaveis de caracteres e strings dinâmicas
		char c;
		char *dado = calloc(255, 1);
		char *texto = calloc(255, 1);
		do
		{
			// Percorremos nossos caracteres
			c = fgetc(clientBackUp);
			// Caso altere o campo de valor
			if (c != ';')
			{
				// Caso seja um novo usuário
				if (c == '\n')
				{
					inserirClienteNaFila(cliente, contador + clientesImportados);
					inserirClienteNaListagem(listagemCLientes, &cliente[contador + clientesImportados]);
					// Somamos a quantia de clientes no banco
					clientesImportados++;
					printf("\n\nClientes novo adicionado com sucesso\n\n");
				}
				else
				{
					// Copiamos o valor lido no arquivo para nossas variaveis dinamicas
					texto[strlen(texto)] = c;
					// Adicionamos o \0 no final de cada string
					texto[strlen(texto) + 1] = '\0';
				}
			}
			else
			{
				// Pegamos qual o campo de dados do usuário
				char *field = strtok(texto, ":");
				// Enquanto existirem valores
				while (field != NULL)
				{
					// Nome do usuário
					if (strcmp(strlwr(field), "nome") == 0)
					{
						field = strtok(NULL, ":");
						printf("Nome do usuario usuario: %s\n", field);
						strcpy(cliente[contador + clientesImportados].nomeCliente, field);
						// Colocamos aqui qual o código do cliente
						cliente[contador + clientesImportados].posicaoFila = contador + clientesImportados;
					}
					// Email do usuário
					if (strcmp(strlwr(field), "email") == 0)
					{
						field = strtok(NULL, ":");
						printf("Email do usuario usuario: %s\n", field);
						strcpy(cliente[contador + clientesImportados].emailCliente, field);
					}
					// CPF do usuario
					else if (strcmp(strlwr(field), "cpf") == 0)
					{
						field = strtok(NULL, ":");
						double value = atof(field);
						printf("CPF do usuario: %0.0lf\n", value);
						cliente[contador + clientesImportados].cpfCliente = value;
						cliente[contador + clientesImportados].cdCliente = generateCdCliente(value);
					}
					// Compras do usuário
					else if (strcmp(strlwr(field), "compras") == 0)
					{
						field = strtok(NULL, ":");
						int value = atoi(field);
						printf("Compras realizadas: %d\n", value);
						cliente[contador + clientesImportados].comprasRealizadas = value;
					}
					// Sexo do usuário
					else if (strcmp(strlwr(field), "sexo") == 0)
					{
						field = strtok(NULL, ":");
						printf("Sexo do usuario: %s\n", field);
						strcpy(cliente[contador + clientesImportados].sexoCliente, field);
					}
					// Telefone do usuário
					else if (strcmp(strlwr(field), "telefone") == 0)
					{
						field = strtok(NULL, ":");
						strcpy(cliente[contador + clientesImportados].tel.telefone, field);
						mascaraTelefone(cliente[contador + clientesImportados].tel.telefone, &cliente[contador + clientesImportados]);
						printf("Telefone do usuario: %s\n", cliente[contador + clientesImportados].tel.telefone);
					}
					// Celular do usuário
					else if (strcmp(strlwr(field), "celular") == 0)
					{
						field = strtok(NULL, ":");
						strcpy(cliente[contador + clientesImportados].tel.celular, field);
						mascaraCelular(cliente[contador + clientesImportados].tel.celular, &cliente[contador + clientesImportados]);
						printf("Celular do usuario: %s\n", cliente[contador + clientesImportados].tel.celular);
					}
					else
					{
						field = strtok(NULL, ":");
					}
				}
				// Limpamos a variavel de texto
				free(texto);
				texto = calloc(255, 1);
			}
		} while (c != EOF);

		fclose(clientBackUp);
		// retornamos a nova quantia de clientes
		return clientesImportados;
	}
};

// Manipulação de produtos
void cadastraProdutos(struct produto *produto, int contador)
{
	int abbleToProceed = 0;
	// Nome do produto
	printf("\nInsira o nome do produto: ");
	fflush(stdin);
	gets(produto->nomeProduto);
	// Marca do produto
	do
	{
		printf("\nInsira a marca do produto: ");
		fflush(stdin);
		gets(produto->model.marcaproduto);
		if (!produto->model.marcaproduto)
		{
			printf("\nMarca Inserida invalida!\n");
			abbleToProceed = 0;
		}
		else
		{
			abbleToProceed = 1;
		}
	} while (abbleToProceed = 0);
	// Modelo do produto
	abbleToProceed = 0;
	do
	{

		printf("\nInsira o modelo do produto: ");
		fflush(stdin);
		gets(produto->model.modeloproduto);
		if (!produto->model.modeloproduto)
		{
			printf("\nModelo inserido invalida!\n");
			abbleToProceed = 0;
		}
		else
		{
			abbleToProceed = 1;
		}
	} while (abbleToProceed = 0);
	// Valor do produto
	produto->cdProduto = generateCdProduto(produto->model.marcaproduto, produto->model.modeloproduto);
	printf("\nInsira o valor do produto R$: ");
	fflush(stdin);
	scanf("%lf", &produto->valorProduto);
	// Finalização do cadastro de produtos
	printf("\nO seu produto foi cadastrado com sucesso!!!\n");
	printf("\n\nDados do cadastro!\n\n");
	fflush(stdin);
	listarProdutos(produto);
	return;
}
void listarProdutos(struct produto *produto)
{
	// printf("Dentro da funcao de listagem %p", produto);
	// Codigo do produto:
	printf("\n\n#########################");
	printf("\n# Codigo do cadastro do produto: %d", produto->cdProduto);
	// Nome do produto:
	printf("\n\n# Nome do produto: %s", produto->nomeProduto);
	// CPF do produto:
	printf("\n\n# Modelo do produto: %s", produto->model.modeloproduto);
	// Email do produto:
	printf("\n\n# Marca do produto: %s", produto->model.marcaproduto);
	// Telefone do produto
	printf("\n\n# Valor do produto R$: %0.2lf", produto->valorProduto);
	printf("\n#########################\n\n");
	return;
}
// Importação dos produtos
int importProdutos(struct produto *produto, int contador)
{
	// Setamos a quantia de clientes importados
	int produtosImportados = 0;
	FILE *produtosBackUp;
	// Abrimos o arquivo de leitura
	produtosBackUp = fopen("produtos_bd.csv", "r");
	// Caso não seja possivel ler o arquivo
	if (!produtosBackUp)
	{
		printf("\nNao foi possivel importar os produtos\n");
		return 0;
	}
	else
	{
		printf("\nIniciando a importacao.....\n");
		// Definimos nossas variaveis de caracteres e strings dinâmicas
		char c;
		char *dado = calloc(255, 1);
		char *texto = calloc(255, 1);
		do
		{
			// Percorremos nossos caracteres
			c = fgetc(produtosBackUp);
			// Caso altere o campo de valor
			if (c != ';')
			{
				// Caso seja um novo usuário
				if (c == '\n')
				{
					// Somamos a quantia de clientes no banco
					produtosImportados++;
					printf("\n\nProduto novo adicionado com sucesso\n\n");
				}
				else
				{
					// Copiamos o valor lido no arquivo para nossas variaveis dinamicas
					texto[strlen(texto)] = c;
					// Adicionamos o \0 no final de cada string
					texto[strlen(texto) + 1] = '\0';
				}
			}
			else
			{
				// Pegamos qual o campo de dados do usuário
				char *field = strtok(texto, ":");
				// Enquanto existirem valores
				while (field != NULL)
				{
					// Nome do produto
					if (strcmp(strlwr(field), "nome") == 0)
					{
						field = strtok(NULL, ":");
						printf("Nome do produto: %s\n", field);
						strcpy(produto[contador + produtosImportados].nomeProduto, field);
						// Colocamos aqui qual o código do produto
						// produto[contador + produtosImportados].cdProduto = contador + produtosImportados;
					}
					// Modelo do produto
					else if (strcmp(strlwr(field), "modelo") == 0)
					{
						field = strtok(NULL, ":");
						printf("Modelo do produto: %s\n", field);
						strcpy(produto[contador + produtosImportados].model.modeloproduto, field);
					}
					// Marca do produto
					else if (strcmp(strlwr(field), "marca") == 0)
					{
						field = strtok(NULL, ":");
						printf("Marca do produto: %s\n", field);
						strcpy(produto[contador + produtosImportados].model.marcaproduto, field);
						// Definimos o codigo do produto
						produto[contador + produtosImportados].cdProduto = generateCdProduto(produto[contador + produtosImportados].model.marcaproduto,
																																								 produto[contador + produtosImportados].model.modeloproduto);
					}
					// Valor do produto
					else if (strcmp(strlwr(field), "valor") == 0)
					{
						field = strtok(NULL, ":");
						double value = atof(field);
						printf("Valor do usuario: %0.2lf\n", value);
						produto[contador + produtosImportados].valorProduto = value;
					}
					else
					{
						field = strtok(NULL, ":");
					}
				}
				// Limpamos a variavel de texto
				free(texto);
				texto = calloc(255, 1);
			}
		} while (c != EOF);

		fclose(produtosBackUp);
		// retornamos a nova quantia de clientes
		return produtosImportados;
	}
};

// Realização da compra
void realizaCompra(struct compra *compra, int produtosNaCompra)
{
	// printf("\nPonteiro compra: %p", compra);
	compra->qtVenda1 = 0;
	compra->qtVenda2 = 0;
	compra->prcntDescontoCompra = 0;
	char promptSimNao[2];
	double valor_produto1 = compra->produtosAComprar.mercadoria1->valorProduto;
	double valor_produto2,
			subTotalProduto2,
			subTotalProduto1;
	// Validação da quantidade mínima de produtos a serem vendidos
	do
	{
		printf("Quantas unidades do produto %s o cliente deseja levar (min 1)? ", compra->produtosAComprar.mercadoria1->nomeProduto);
		fflush(stdin);
		scanf("%d", &compra->qtVenda1);
		if (compra->qtVenda1 <= 0)
		{
			printf("O valor minimo para a compra eh 1\n");
			fflush(stdin);
		}
	} while (compra->qtVenda1 <= 0);
	subTotalProduto1 = valor_produto1 * compra->qtVenda1;
	compra->subTotalProduto1 = subTotalProduto1;
	// Verificamos se o produto possuirá desconto
	printf("O produto %s %s possui desconto (S/n)? ", compra->produtosAComprar.mercadoria1->nomeProduto, compra->produtosAComprar.mercadoria1->model.modeloproduto);
	fflush(stdin);
	strlwr(gets(promptSimNao));
	fflush(stdin);
	if (promptCompare(promptSimNao) == 1)
	{
		do
		{
			printf("\nInsira a porcentagem de desconto: ");
			fflush(stdin);
			scanf("%lf", &compra->prcntDescontoCompra);
			// Validamos a existencia de uma porcentagem negativa
			if (compra->prcntDescontoCompra < 0)
			{
				printf("Porcentagem negativa nao aceita!");
			} // Porcentagem 0, desconto 0
			else if (compra->prcntDescontoCompra == 0)
			{
				printf("Porcentagem zerada, nao sera aplicado nenhum desconto ao produto!");
			} // Geramos o valor com desconto
			else
			{
				compra->prcntDescontoCompra = compra->prcntDescontoCompra / 100;
				compra->subTotalProduto1 = subTotalProduto1 - (subTotalProduto1 * compra->prcntDescontoCompra);
			}

		} while (compra->prcntDescontoCompra < 0);
	}
	// Somamos o valor do produto 1 ao valor total da compra
	compra->subTotalCompra = compra->subTotalProduto1;

	// Se forem dois produtos na compra
	if (produtosNaCompra == 2)
	{
		valor_produto2 = compra->produtosAComprar.mercadoria2->valorProduto;
		// Validação da quantidade mínima de produtos a serem vendidos
		do
		{
			printf("\nQuantas unidades do produto %s o cliente deseja levar (min 1)? ", compra->produtosAComprar.mercadoria2->nomeProduto);
			fflush(stdin);
			scanf("%d", &compra->qtVenda2);
			if (compra->qtVenda2 <= 0)
			{
				printf("O valor minimo para a compra eh 1\n");
				fflush(stdin);
			}
		} while (compra->qtVenda2 <= 0);
		subTotalProduto2 = valor_produto2 * compra->qtVenda2;
		compra->subTotalProduto2 = subTotalProduto2;
		compra->prcntDescontoCompra = 0;
		// Verificamos se existe desconto para o produto 2
		printf("\nO produto %s %s possui desconto (S/n)? ", compra->produtosAComprar.mercadoria2->nomeProduto, compra->produtosAComprar.mercadoria2->model.modeloproduto);
		fflush(stdin);
		strlwr(gets(promptSimNao));
		fflush(stdin);
		if (promptCompare(promptSimNao) == 1)
		{
			do
			{
				printf("\nInsira a porcentagem de desconto: ");
				fflush(stdin);
				scanf("%d", &compra->prcntDescontoCompra);
				// Validamos a existencia de uma porcentagem negativa
				if (compra->prcntDescontoCompra < 0)
				{
					printf("Porcentagem negativa nao aceita!");
				} // Porcentagem 0, desconto 0
				else if (compra->prcntDescontoCompra == 0)
				{
					printf("Porcentagem zerada, nao sera aplicado nenhum desconto ao produto!");
				} // Geramos o valor com desconto
				else
				{
					compra->prcntDescontoCompra = compra->prcntDescontoCompra / 100;
					compra->subTotalProduto2 = subTotalProduto2 - (subTotalProduto2 * compra->prcntDescontoCompra);
				}
			} while (compra->prcntDescontoCompra < 0);
			// Somamos o valor dos dois produtos
			compra->subTotalCompra = compra->subTotalProduto1 + compra->subTotalProduto1;
		}
	}
	compra->valorTotalVenda = compra->subTotalCompra;
	printf("\nForam vendidos:\n%d unidades do produto %s no valor de %0.2lf", compra->qtVenda1, compra->produtosAComprar.mercadoria1->nomeProduto, compra->subTotalProduto1);
	if (produtosNaCompra == 2)
	{
		printf(" e tambem: \n%d unidades do produto %s no valor de %0.2lf", compra->qtVenda2, compra->produtosAComprar.mercadoria2->nomeProduto, compra->subTotalProduto2);
	}
	printf(";\nPara o cliente %s\n", compra->comprador->nomeCliente);

	printf("\n\n#### --- =========== --- ####\n");
	printf("\n\n#### --- Nota fiscal --- ####\n");
	printf("\n# - Nome do produto: %s", compra->produtosAComprar.mercadoria1->nomeProduto);
	printf("\n# - Modelo do produto: %s", compra->produtosAComprar.mercadoria1->model.modeloproduto);
	printf("\n# - Marca do produto: %s", compra->produtosAComprar.mercadoria1->model.marcaproduto);
	printf("\n# - Valor do produto: %0.2lf * %d", compra->produtosAComprar.mercadoria1->valorProduto, compra->qtVenda1);
	printf("\n\n#### --- =========== --- ####\n");
	if (produtosNaCompra == 2)
	{
		printf("\n# - Nome do produto: %s", compra->produtosAComprar.mercadoria2);
		printf("\n# - Modelo do produto: %s", compra->produtosAComprar.mercadoria2->model.modeloproduto);
		printf("\n# - Marca do produto: %s", compra->produtosAComprar.mercadoria2->model.marcaproduto);
		printf("\n# - Valor do produto: %0.2lf * %d", compra->produtosAComprar.mercadoria2->valorProduto, compra->qtVenda1);
	}
	printf("\n\n#### --- =========== --- ####\n");
	printf("\n\n# - Valor final:  %0.2lf\n", compra->valorTotalVenda);
	printf("\n\n#### --- =========== --- ####\n");
	printf("\n\n#### --- =Comprador= --- ####\n");
	printf("\n# - Nome do cliente: %s", compra->comprador->nomeCliente);
	printf("\n# - CPF do cliente: %0.0lf", compra->comprador->cpfCliente);
	printf("\n# - Contato do cliente: %s", compra->comprador->tel.telefone);
	printf("\n\n#### --- =========== --- ####\n");
	// Esse aqui é só pela imersão
	printf("Comprovante da compra enviado para o email: %s", compra->comprador->emailCliente);
	return;
}

// Buscas Binárias
int encontraProduto(int maxVal, struct produto *produto)
{
	int minVal = 0,
			meioFila = (minVal + maxVal) / 2;
	int codProduto;
	printf("\nInsira o codigo do produto a ser encontrado: ");
	scanf("%d", &codProduto);
	while (minVal <= maxVal && produto[meioFila].cdProduto != codProduto)
	{
		if (codProduto < produto[meioFila].cdProduto)
		{
			maxVal = meioFila - 1;
		}
		else
		{
			minVal = meioFila + 1;
		}
		meioFila = (minVal + maxVal) / 2;
	}
	if (codProduto == produto[meioFila].cdProduto)
	{
		return meioFila;
	}
	else
	{
		return 0;
	}
};
int encontraCliente(int maxVal, struct cliente *cliente)
{
	int minVal = 0,
			meioFila = (minVal + maxVal) / 2;
	double cpfCliente;
	printf("\nInsira o cpf do cliente a ser encontrado: ");
	scanf("%lf", &cpfCliente);
	while (minVal <= maxVal && cliente[meioFila].cpfCliente != cpfCliente)
	{
		if (cpfCliente < cliente[meioFila].cpfCliente)
		{
			maxVal = meioFila - 1;
		}
		else
		{
			minVal = meioFila + 1;
		}
		meioFila = (minVal + maxVal) / 2;
	}
	if (cpfCliente == cliente[meioFila].cpfCliente)
	{
		return meioFila;
	}
	else
	{
		meioFila = -1;
	}
	return meioFila;
};

// Ordenação de filas
void ordenaCliente(struct cliente *cliente, int contador)
{
	// Criamos um inteiro para guardar a posição na fila de cada elemento
	int posicaoAuxiliar;

	// Criamos os ponteiros auxiliares para alterar as posições na fila
	struct cliente *ponteiroAuxiliarClienteAnterior = (struct cliente *)calloc(1, sizeof(struct cliente *));
	struct cliente *ponteiroAuxiliarProximoCliente = (struct cliente *)calloc(1, sizeof(struct cliente *));
	// Criamos um ponteiro intermediario para troca de dados
	struct cliente ponteiroAntigo;

	for (size_t i = 0; i < contador - 1; i++)
	{
		for (size_t j = 0; j < (contador - 1 - i); j++)
		{
			if (cliente[j].cpfCliente > cliente[j + 1].cpfCliente)
			{
				// Atribuimos o valor do ponteiro a ser modificado
				ponteiroAntigo = cliente[j];

				// Salvamos os ponteiros da fila encadeada
				ponteiroAuxiliarProximoCliente = &cliente[j + 1].proximoCliente;
				ponteiroAuxiliarClienteAnterior = &cliente[j + 1].clienteAnterior;
				// Pegamos a posição do elemento na fila
				posicaoAuxiliar = cliente[j + 1].posicaoFila;

				// Fazemos a troca de valores entre as structs
				cliente[j] = cliente[j + 1];
				cliente[j + 1] = ponteiroAntigo;

				// Atualizamos o cliente  anterior de acordo com a nova ordenação
				cliente[j].clienteAnterior = &ponteiroAntigo.clienteAnterior;
				// Atualizamos o prómixo fila de acordo com a nova ordenação
				cliente[j].proximoCliente = &cliente[j + 1];

				// Atualizamos o anterior da fila de acordo com a nova ordenação
				cliente[j + 1].clienteAnterior = &cliente[j];

				// Atualizamos a fila no cliente jogado para frente
				cliente[j + 1].proximoCliente = ponteiroAuxiliarProximoCliente;

				// Atualizamos as posições na fila
				cliente[j].posicaoFila = ponteiroAntigo.posicaoFila;
				cliente[j + 1].posicaoFila = posicaoAuxiliar;
			}
		}
	}

	// Definimos o ultimo e o primeiro cliente da fila novamente
	cliente[contador].proximoCliente = NULL;
	cliente[0].clienteAnterior = NULL;
	// for (size_t k = 0; k < contador; k++)
	// {
	// 	listarClientes(&cliente[k]);
	// }
	printf("Clientes ordenados com sucesso!");
};
void ordenaProdutos(struct produto *produto, int contador)
{
	// Criamos um inteiro para guardar a posição na fila de cada elemento
	int posicaoAuxiliar;

	// Criamos os ponteiros auxiliares para alterar as posições na fila
	struct produto *ponteiroAuxiliarProdutoAnterior = (struct produto *)calloc(1, sizeof(struct produto *));
	struct produto *ponteiroAuxiliarProximoProduto = (struct produto *)calloc(1, sizeof(struct produto *));
	// Criamos um ponteiro intermediario para troca de dados
	struct produto ponteiroAntigo;

	for (size_t i = 0; i < contador - 1; i++)
	{
		for (size_t j = 0; j < (contador - 1 - i); j++)
		{
			if (produto[j].cdProduto > produto[j + 1].cdProduto)
			{
				// Atribuimos o valor do ponteiro a ser modificado
				ponteiroAntigo = produto[j];

				// Salvamos os ponteiros da fila encadeada
				ponteiroAuxiliarProximoProduto = &produto[j + 1].proximoProduto;
				ponteiroAuxiliarProdutoAnterior = &produto[j + 1].produtoAnterior;
				// Pegamos a posição do elemento na fila
				posicaoAuxiliar = produto[j + 1].posicaoFila;

				// Fazemos a troca de valores entre as structs
				produto[j] = produto[j + 1];
				produto[j + 1] = ponteiroAntigo;

				// Atualizamos o cliente  anterior de acordo com a nova ordenação
				produto[j].produtoAnterior = &ponteiroAntigo.produtoAnterior;
				// Atualizamos o prómixo fila de acordo com a nova ordenação
				produto[j].proximoProduto = &produto[j + 1];

				// Atualizamos o anterior da fila de acordo com a nova ordenação
				produto[j + 1].produtoAnterior = &produto[j];

				// Atualizamos a fila no cliente jogado para frente
				produto[j + 1].proximoProduto = ponteiroAuxiliarProximoProduto;

				// Atualizamos as posições na fila
				produto[j].posicaoFila = ponteiroAntigo.posicaoFila;
				produto[j + 1].posicaoFila = posicaoAuxiliar;
			}
		}
	}

	// Definimos o ultimo e o primeiro cliente da fila novamente
	produto[contador].proximoProduto = NULL;
	produto[0].produtoAnterior = NULL;
	// for (size_t k = 0; k < contador; k++)
	// {
	// 	listarProdutos(&produto[k]);
	// }
	printf("Produtos ordenados com sucesso!");
};

// Criação de filas
void inserirClienteNaFila(struct cliente *cliente, int contador)
{
	// printf("\nPonteiro do cliente %p\n", &cliente[contador]);

	// Verificamos se o cliente não é o primeiro da lista
	if (contador > 0)
	{
		// Apontamos o cliente atual como próximo cliente da fila
		cliente[contador - 1].proximoCliente = &cliente[contador];
		// Colocamos o cliente anterior como o cliente anterior na fila
		cliente[contador].clienteAnterior = &cliente[contador - 1];
		// printf("\nPonteiro desse cliente: %p\n", cliente[contador - 1].proximoCliente);
	}
	// Definimos para o último cliente o próximo como null
	cliente[contador].proximoCliente = NULL;
};
void inserirProdutosNaFila(struct produto *produto, int contador)
{
	// printf("\nPonteiro do produto %p\n", &produto[contador]);

	// Verificamos se o cliente não é o primeiro da lista
	if (contador > 0)
	{
		// Apontamos o cliente atual como próximo cliente da fila
		produto[contador - 1].proximoProduto = &produto[contador];
		// Colocamos o cliente anterior como o cliente anterior na fila
		produto[contador].produtoAnterior = &produto[contador - 1];
		// printf("\nPonteiro desse cliente: %p\n", cliente[contador - 1].proximoCliente);
	}
	// Definimos para o último proximoProduto o próximo como null
	produto[contador].proximoProduto = NULL;
}

// Geramos o código do cliente de acordo com o CPF
int generateCdCliente(double cpfCliente)
{

	// Tamanho do CPF
	int tamanhoCpf = 0;
	// Transformamos o CPF em um inteiro e removemos os 2 ultimos numeros dele
	int cpfEmInt = (int)(cpfCliente / 100);
	// Criamos o fator de exponenciação
	double expo = 1;
	// Criamos o contador de quantas vezes dividimos o cpf
	int contadorDivisao = 0;
	// Criamos o valor inteiro a retornar;
	int valorCdCliente;

	// Recuperamos o valor da exponenciacao do CPF
	for (size_t i = 0; cpfEmInt > 0; i++)
	{
		cpfEmInt /= 10;
		tamanhoCpf++;
	}

	// Geramos o multiplo para gerarmos o int do CPF
	for (size_t i = 0; i <= tamanhoCpf; i++)
	{
		expo = expo * 10;
	}

	// Concatenamos o valor do CPF de acordo com a divisão
	while (contadorDivisao < 7)
	{
		valorCdCliente = (int)(cpfCliente / expo);
		contadorDivisao++;
		expo = expo / 10;
	}
	return valorCdCliente;
}

// Geramos o código do produto de acordo com a marca modelo e randNum
int generateCdProduto(char marcaProduto[20], char modeloProduto[20])
{
	char ASCIIModeloString[6],
			ASCIIMarcaString[6],
			randomString1[4],
			randomString2[4],
			randomString3[4];

	int ASCIIMarca, ASCIIModelo,
			cdProduto,
			random1, random2, random3;

	srand(time(0));
	for (size_t i = 0; i < 10; i++)
	{
		int num = (rand() % (10 - 1 + 1)) + 1;
		if (i == 0)
		{
			random1 = num;
		}
		else if (i == 1)
		{
			random2 = num;
		}
		else if (i == 2)
		{
			random3 = num;
		}
	}
	ASCIIMarca = (int)marcaProduto[0];
	ASCIIModelo = (int)modeloProduto[0];

	sprintf(ASCIIModeloString, "%d", ASCIIModelo);
	sprintf(ASCIIMarcaString, "%d", ASCIIMarca);

	sprintf(randomString1, "%d", random1);
	sprintf(randomString2, "%d", random2);
	sprintf(randomString3, "%d", random3);

	strcat(ASCIIMarcaString, ASCIIModeloString);
	strcat(ASCIIMarcaString, randomString1);
	strcat(ASCIIMarcaString, randomString2);
	strcat(ASCIIMarcaString, randomString3);

	cdProduto = atoi(ASCIIMarcaString);
	return cdProduto;
}

// Listamos a fila de clientes
void listarFilaClientes(struct listagemCLientes *listagemCLientes)
{
	if (listagemCLientes->primeiroCliente == NULL)
	{
		printf("Listagem de clientes vazia");
	}
	else
	{
		struct cliente *clienteAuxiliar = listagemCLientes->primeiroCliente;
		while (clienteAuxiliar)
		{
			listarClientes(clienteAuxiliar);
			clienteAuxiliar = clienteAuxiliar->proximoCliente;
		}
	}
};

// Criamos a listagem de clientes
struct listagemCLientes *criarListagemDeClientes()
{
	struct listagemCLientes *fila = (struct listagemCLientes *)malloc(sizeof(struct listagemCLientes));
	fila->primeiroCliente = NULL;
	fila->ultimoCliente = NULL;
	return fila;
};

// Inserimos o cliente na listagem
void inserirClienteNaListagem(struct listagemCLientes *listagemCLientes, struct cliente *cliente)
{
	if (listagemCLientes->ultimoCliente == NULL)
	{
		listagemCLientes->primeiroCliente = cliente;
	}
	listagemCLientes->ultimoCliente = cliente;
}

// Geramos a string do telefone
void mascaraTelefone(char telefone[20], struct cliente *cliente)
{
	// Criamos um telefone de retorno
	char telefoneEditado[20];
	char telNulo[] = "Desconhecido";
	if (telefone[0] != '\0')
	{
		int nonDigitRemoved = 0;

		// Remoção de caracteres não digitos
		for (size_t i = 0; i < strlen(telefone); i++)
		{
			if (telefone[i] < '0' || telefone[i] > '9')
			{
				nonDigitRemoved++;
			}
			// Removemos os caracteres especiais do array
			telefone[i] = telefone[i + nonDigitRemoved];
		}

		// Populamos os valores corretos dos telefones
		telefoneEditado[0] = (char)40;
		telefoneEditado[1] = telefone[0];
		telefoneEditado[2] = telefone[1];
		telefoneEditado[3] = (char)41;
		telefoneEditado[4] = (char)32;
		telefoneEditado[5] = telefone[2];
		telefoneEditado[6] = telefone[3];
		telefoneEditado[7] = telefone[4];
		telefoneEditado[8] = telefone[5];
		telefoneEditado[9] = (char)45;
		telefoneEditado[10] = telefone[6];
		telefoneEditado[11] = telefone[7];
		telefoneEditado[12] = telefone[8];
		telefoneEditado[13] = telefone[9];
		telefoneEditado[14] = NULL;
		strcpy(cliente->tel.telefone, telefoneEditado);
	}
	else
	{
		strcpy(cliente->tel.telefone, telNulo);
	}
	// Colocamos o novo valor na string do usuario

	return;
};

// Geramos a string do celular
void mascaraCelular(char celular[20], struct cliente *cliente)
{
	char celularEditado[20];
	char celNulo[] = "Desconhecido";
	if (celular[0] != '\0')
	{
		int nonDigitRemoved = 0;
		// Remoção de caracteres não digitos
		for (size_t i = 0; i < strlen(celular); i++)
		{
			if (celular[i] < '0' || celular[i] > '9')
			{
				nonDigitRemoved++;
			}
			// Removemos os caracteres especiais do array
			celular[i] = celular[i + nonDigitRemoved];
		}
		// Populamos os valores corretos dos celulares
		celularEditado[0] = (char)40;
		celularEditado[1] = celular[0];
		celularEditado[2] = celular[1];
		celularEditado[3] = (char)41;
		celularEditado[4] = (char)32;

		celularEditado[5] = celular[2];

		celularEditado[6] = (char)32;

		celularEditado[7] = celular[3];
		celularEditado[8] = celular[4];
		celularEditado[9] = celular[5];
		celularEditado[10] = celular[6];
		celularEditado[11] = (char)45;
		celularEditado[12] = celular[7];
		celularEditado[13] = celular[8];
		celularEditado[14] = celular[9];
		celularEditado[15] = celular[10];
		celularEditado[16] = celular[11];
		celularEditado[17] = NULL;
		strcpy(cliente->tel.celular, celularEditado);
	}
	else
	{
		strcpy(cliente->tel.celular, celNulo);
	}
	// Colocamos o novo valor na string do usuario
	return;
};