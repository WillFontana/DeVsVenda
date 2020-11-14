/*
 * Integrantes
 * Carlos Henrique Moreira Diniz ---- 2000118
 * Luana Maria Albertoni ---- 2012683
 * Willyan Fontana do Prado ---- 2008381
*/

#include <stdio.h>;
#include <string.h>;
#include <stdlib.h>;

// Definimos a estrutura dos clientes
struct contato
{
    char telefone[20], // Telefone fixo do cliente
    celular[20];	 // Celular do cliente
};
struct cliente
{
    int cdCliente,				 // Codigo do cliente
    comprasRealizadas; // Compras realizadas
    char nomeCliente[50],	 // Nome do Cliente
    sexoCliente[2],		 // Sexo do Cliente
    emailCliente[50];	 // Email do Cliente
    double cpfCliente;		 // CPF do cliente
    struct contato tel;
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
    int cdProduto;				//codigo do produto
    char nomeProduto[50]; //nome do produto
    double valorProduto;	// valor do produto
    struct modelo model;	// variações do produto
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

// Interações do cliente
void cadastraCliente(struct cliente *cliente, int contador), // Cadastro de cliente
listarClientes(struct cliente *cliente);								 // Listagem de cliente
// ---------------------

// Interações do produto
void cadastraProdutos(struct produto *produto, int contador), // Cadastro de produtos
listarProdutos(struct produto *produto);									// Listagem de produtos
// ---------------------

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

void main()
{
    printf("---{ Iniciando o sistema! }---\n");
    // Declaração das variáveis de controle gerais
    char promptSimNao[2];	 // Resposta do usuário (Qualquer caractere diferente de s é considerado não pelo sistema);
    int filaClientes = 0,	 // Contador de clientes
    filaProdutos = 0,	 // Contador de produtos
    contadorPadrao,		 // Contador padrão para laços
    ableToProceed = 0, // Controle para habilitar procedência de etapas
    produtosNaCompra,	 // Quantia de produtos diferentes vendidos
    escolhaMenu;			 // Escolha do menu

    client *clientes; // Definimos nossa tabela de clientes
    // typecast
    clientes = (client *)calloc(1, sizeof(client)); // Alocamos espaço para o cliente
    if (clientes == NULL)
    {
        printf("Erro ao alocar espaco para os clientes");
        return;
    }

    product *produtos;
    produtos = (product *)calloc(1, sizeof(product)); // Alocamos espaço para o produto
    if (produtos == NULL)
    {
        printf("Erro ao alocar espaco para os produtos");
        return;
    }
		// Biririririririri
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
                            filaProdutos++;
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
                            // Importamos os clientes
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
                            filaClientes++;
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
                            // Importamos os clientes
                        }
                    }
                }
                else
                {
                    for (size_t i = 0; i < filaClientes; i++)
                    {
                        listarClientes(&clientes[i]);
                    }
                }
                break;
            case 5: // Cadastro direto de produtos
                do
                {
                    cadastraProdutos(&produtos[filaProdutos], filaProdutos);
                    filaProdutos++;
                    printf("Cadastrar um novo produto(S/n) ? ");
                    fflush(stdin);
                    strlwr(gets(promptSimNao));
                    fflush(stdin);
                } while (promptCompare(promptSimNao) == 1);
                break;
            case 6: // Cadastro direto de cliente
                do
                {
                    cadastraCliente(&clientes[filaClientes], filaClientes);
                    filaClientes++;
                    printf("Cadastrar um novo cliente(S/n) ? ");
                    fflush(stdin);
                    strlwr(gets(promptSimNao));
                    fflush(stdin);
                } while (promptCompare(promptSimNao) == 1);
                break;
            case 7: // Realização de compras
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
                            filaClientes++;
                            printf("Cadastrar um novo cliente(S/n) ? ");
                            fflush(stdin);
                            strlwr(gets(promptSimNao));
                            fflush(stdin);
                        } while (promptCompare(promptSimNao) == 1);
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
                            filaProdutos++;
                            printf("Cadastrar um novo produto(S/n) ? ");
                            fflush(stdin);
                            strlwr(gets(promptSimNao));
                            fflush(stdin);
                        } while (promptCompare(promptSimNao) == 1);
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
                            printf("\nDeseja adicionar mais um produto? ");
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
                            printf("para o cliente %s (S/n) ?", carrinho->comprador->nomeCliente);
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
    } while (escolhaMenu != 8);
    free(clientes);
    free(produtos);
    free(carrinho);
}

// Manipulação de clientes
void cadastraCliente(struct cliente *cliente, int contador)
{
    // Código do cliente
    cliente->cdCliente = contador;
    cliente->comprasRealizadas = 0;
    // Nome do cliente:
    printf("\nInsira o nome do cliente: ");
    fflush(stdin);
    gets(cliente->nomeCliente);
    // CPF do cliente:
    printf("\nInsira o cpf do cliente: ");
    fflush(stdin);
    scanf("%lf", &cliente->cpfCliente);
    do
    {
        printf("\nInsira o email do cliente: ");
        fflush(stdin);
        gets(cliente->emailCliente);
    } while (validaEmail(cliente->emailCliente) == 0);
    // Telefone do cliente
    printf("\nInsira o telefone fixo do cliente: ");
    fflush(stdin);
    gets(cliente->tel.telefone);
    // Celular do cliente
    printf("\nInsira o celular do cliente: ");
    fflush(stdin);
    gets(cliente->tel.celular);
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
    // Telefone do cliente
    printf("\n\n# Celular do cliente: %s", cliente->tel.celular);
    // Sexo do cliente:
    printf("\n\n# Sexo do cliente (F/M/O): %s", cliente->sexoCliente);
    printf("\n#########################\n\n");
    return;
}

// Manipulação de produtos
void cadastraProdutos(struct produto *produto, int contador)
{
    // Código do produto
    produto->cdProduto = contador;
    // Nome do produto
    printf("\nInsira o nome do produto: ");
    fflush(stdin);
    gets(produto->nomeProduto);
    // Marca do produto
    printf("\nInsira a marca do produto: ");
    fflush(stdin);
    gets(produto->model.marcaproduto);
    // Modelo do produto
    printf("\nInsira o modelo do produto: ");
    fflush(stdin);
    gets(produto->model.modeloproduto);
    // Valor do produto
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

// Realização da compra
void realizaCompra(struct compra *compra, int produtosNaCompra)
{
    // printf("\nPonteiro compra: %p", compra);
    compra->qtVenda1 = 0;
    compra->qtVenda2 = 0;
    compra->prcntDescontoCompra = 0;
    char promptSimNao[2];
    double valor_produto1 = compra->produtosAComprar.mercadoria1->valorProduto;
    printf("Valor do produto: %0.2lf\n", valor_produto1);
    fflush(stdin);
    double valor_produto2,
            subTotalProduto2,
            subTotalProduto1;
    // Validação da quantidade mínima de produtos a serem vendidos
    do
    {
        printf("Quantas unidades do produto %s o cliente deseja levar?\n", compra->produtosAComprar.mercadoria1->nomeProduto);
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
    printf("O produto %s possui desconto  (S/n) ?", compra->produtosAComprar.mercadoria1->nomeProduto);
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
            printf("Quantas unidades do produto %s o cliente deseja levar?\n", compra->produtosAComprar.mercadoria2->nomeProduto);
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
        printf("O produto %s possui desconto?", compra->produtosAComprar.mercadoria2->nomeProduto);
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
    printf("Foram vendidos:\n%d unidades do produto %s no valor de %0.2lf", compra->qtVenda1, compra->produtosAComprar.mercadoria1->nomeProduto, compra->subTotalProduto1);
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
