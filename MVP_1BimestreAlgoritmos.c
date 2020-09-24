#include <stdio.h>
#include <string.h>

void cadastroCliente(int *cdClient, char *nomeCliente[50], double *cpfCliente, char *sexoCliente[50], double *telefoneCliente, char *emailCliente[50], int *comprasRealizadas, int *vIndiceCliente);
void cadastroProduto(int *cdProduto, char *nomeProduto[50], char *marcaProduto[50], char *modeloProduto[50], double *valorProduto, int *vIndiceProduto);

void realizarCompra(int *cdCompra, double *relacaoCpfCliente, int *relacaoProduto, int *qtVenda, int *subTotalCompra, double *prcntDescontoCompra, double *valorTotalVenda, char *promptSimNao, char *promptCompare);

int main()
{
    // variaveis de controles
    int ableToProceed = 1;                 // Validação de etapas
    int constante = 50;                    // Limite de cadastro
    int vIndiceCliente = 1;                // Controle qtd de clientes
    int vIndiceProduto = 1;                // Controle qtd de produtos
    int vIndiceCompra = 1;                 // Controle de compras
    char promptCompare[3][3] = {"s", "n"}; // Controle de respostas
    char promptSimNao[2];                  // Desisão binaria do usuario (S ou N)
    int selecaoMenu;                       // Controle da decisão do usuário no menu de navegação
    int contadorPadrao;                    // Contador padrão

    // Variaveis de clientes;
    int cdCliente[constante];             // Codigo do cliente
    char nomeCliente[constante][30];      // Nome Cliente
    double cpfCliente[constante];         // Cpf do cliente
    char sexoCliente[50][2] = {'F', 'M'}; // Sexo do Cliente
    double telefoneCliente[constante];    // Telefone do CLiente
    char emailCliente[constante][20];     // Email do Cliente
    int comprasRealizadas[constante];

    // Variaveis de produto
    int cdProduto[constante];          // Codigo do Produto
    char nomeProduto[constante][30];   // Nome Produto
    char marcaProduto[constante][50];  // Marca do Produto
    char modeloProduto[constante][50]; // Modelo do Produto
    double valorProduto[constante];    // Valor do Produto

    // Variaveis de compra
    int qtComprasARealizar;                // Quantidades de compras que o usuario deseja fazer
    int cdCompra[constante];               // Identificação da compra do produto
    double relacaoCpfCliente[constante];   // Relação da compra com o  usuario
    int relacaoProduto[constante];         // Relação da compra com o produto
    int qtVenda[constante];                // Quantidade de produtos vendidos
    double subTotalCompra[constante];      // Subtotal padrao do produto
    double prcntDescontoCompra[constante]; // Porcentagem do desconto
    double valorTotalVenda[constante];     // Valor final da venda

    printf("Bem vindo ao MVP do Sr. Oswaldo!\n");
    do
    {
        printf("\n############# Menu de controle ##############\n");
        printf("#############################################\n\n");
        printf("       --- { O que deseja fazer? }---\n\n");
        printf("1 Vizualizar Produdos");
        printf("\t|\t2 Vizualizar Clientes\n");
        printf("3 Cadastrar Produtos");
        printf("\t|\t4 Cadastrar Clientes\n");
        printf("5 Realizar venda");
        printf("\t|\t6 Finzalizar o programa\n");
        printf("Escolha uma opcao: -- ");
        scanf("%d", &selecaoMenu);

        fflush(stdin);
        switch (selecaoMenu)
        {
        // Cases de listagem -------------

        // Listar todos os produtos cadastrados
        case 1:
            // Verificamos se existem produtos cadastrados
            if (vIndiceProduto == 1)
            {
                // Caso não existam produtos verificamos se o cliente quer cadastrar algum
                printf("Parece que nao existem produtos cadastrados\n");
                printf("Cadastrar um Produto agora (S/n)? ");
                strlwr(gets(promptSimNao));
                fflush(stdin);
                // Iniciamos o cadastro de produtos
                if (strcmp(promptSimNao, promptCompare[0]) == 0)
                {
                    do
                    {
                        // Setamos o codigo do produto
                        cdProduto[vIndiceProduto] = vIndiceProduto;
                        // Chamamos a função de cadastro de produtos
                        cadastroProduto(cdProduto[vIndiceProduto], nomeProduto[vIndiceProduto], marcaProduto[vIndiceProduto], modeloProduto[vIndiceProduto], &valorProduto[vIndiceProduto], vIndiceProduto);
                        // Aumentamos a quantidade de produtos no sistema
                        vIndiceProduto++;
                        // Por fim verificamos se o cliente quer cadastrar outro produto
                        printf("Cadastrar um novo Produto(S/n)? ");
                        strlwr(gets(promptSimNao));
                        fflush(stdin);
                    } while (strcmp(promptSimNao, promptCompare[0]) == 0);
                }
            }
            else
            {
                for (int i = 1; i < vIndiceProduto; i++)
                {
                    printf("\n\n##########\n");
                    printf("#\n");
                    printf("# Codigo de cadastro: %d\n", cdProduto[i]);
                    printf("# Nome do Produto: %s\n", nomeProduto[i]);
                    printf("# Marca do Produto: %s\n", marcaProduto[i]);
                    printf("# Modelo do Produto: %s \n", modeloProduto[i]);
                    printf("# Valor do Produto: %0.0lf\n", valorProduto[i]);
                    printf("##########\n\n");
                }
            }
            break;
            // Listar todos os clientes cadastrados
        case 2:
            // Verificamos se existem clientes cadastrados
            if (vIndiceCliente == 1)
            {
                printf("Parece que nao existem clientes cadastrados\n");
                printf("Cadastrar um cliente agora (S/n)? ");
                strlwr(gets(promptSimNao));
                fflush(stdin);
                // Iniciamos o cadastro de clientes
                if (strcmp(promptSimNao, promptCompare[0]) == 0)
                {

                    do
                    {
                        cdCliente[vIndiceCliente] = vIndiceCliente;
                        comprasRealizadas[vIndiceCliente] = 0;
                        cadastroCliente(cdCliente[vIndiceCliente], nomeCliente[vIndiceCliente], &cpfCliente[vIndiceCliente], sexoCliente[vIndiceCliente], &telefoneCliente[vIndiceCliente], emailCliente[vIndiceCliente], comprasRealizadas[vIndiceCliente], vIndiceCliente);
                        vIndiceCliente++;
                        printf("Cadastrar um novo cliente(S/n)? ");
                        strlwr(gets(promptSimNao));
                        fflush(stdin);
                    } while (strcmp(promptSimNao, promptCompare[0]) == 0);
                }
            }
            else
            {
                for (int i = 1; i < vIndiceCliente; i++)
                {
                    printf("\n\n##########\n");
                    printf("#\n");
                    printf("# Codigo de cadastro: %d\n", cdCliente[i]);
                    printf("# Nome cadastrado: %s\n", nomeCliente[i]);
                    printf("# Cpf cadastrado: %0.0lf\n", cpfCliente[i]);
                    printf("# Sexo cadastrado: %s \n", sexoCliente[i]);
                    printf("# Telefone de cadastro: %0.0lf\n", telefoneCliente[i]);
                    printf("# Email de cadastro: %s\n", emailCliente[i]);
                    printf("# Compras realizadas: %d\n", comprasRealizadas[i]);
                    printf("##########\n\n");
                }
            }
            break;
            //  -------------

            // Cases de cadastro -------------
            // Iniciar o cadastro de produtos
        case 3:
            do
            {
                // Setamos o codigo do produto
                cdProduto[vIndiceProduto] = vIndiceProduto;
                // Chamamos a função de cadastro de produtos
                cadastroProduto(cdProduto[vIndiceProduto], nomeProduto[vIndiceProduto], marcaProduto[vIndiceProduto], modeloProduto[vIndiceProduto], &valorProduto[vIndiceProduto], vIndiceProduto);
                // Aumentamos a quantidade de produtos no sistema
                vIndiceProduto++;
                // Por fim verificamos se o cliente quer cadastrar outro produto
                printf("Cadastrar um novo Produto(S/n)? ");
                strlwr(gets(promptSimNao));
                fflush(stdin);
            } while (strcmp(promptSimNao, promptCompare[0]) == 0);
            break;
            // Iniciar o cadastro de clientes
        case 4:
            do
            {
                cdCliente[vIndiceCliente] = vIndiceCliente;
                comprasRealizadas[vIndiceCliente] = 0;
                cadastroCliente(cdCliente[vIndiceCliente], nomeCliente[vIndiceCliente], &cpfCliente[vIndiceCliente], sexoCliente[vIndiceCliente], &telefoneCliente[vIndiceCliente], emailCliente[vIndiceCliente], comprasRealizadas[vIndiceCliente], vIndiceCliente);
                vIndiceCliente++;
                printf("Cadastrar um novo cliente(S/n)? ");
                strlwr(gets(promptSimNao));
                fflush(stdin);
            } while (strcmp(promptSimNao, promptCompare[0]) == 0);
            break;
        case 5:
            if (vIndiceCliente == 1)
            {
                // Caso não existam produtos verificamos se o cliente quer cadastrar algum
                printf("\n\nNao eh possivel realizar uma venda pois nao existem clientes cadastrados\n");
                printf("Cadastrar um Cliente agora (S/n)? ");
                strlwr(gets(promptSimNao));
                fflush(stdin);
                // Iniciamos o cadastro de clientes
                if (strcmp(promptSimNao, promptCompare[0]) == 0)
                {
                    do
                    {
                        cdCliente[vIndiceCliente] = vIndiceCliente;
                        comprasRealizadas[vIndiceCliente] = 0;
                        cadastroCliente(cdCliente[vIndiceCliente], nomeCliente[vIndiceCliente], &cpfCliente[vIndiceCliente], sexoCliente[vIndiceCliente], &telefoneCliente[vIndiceCliente], emailCliente[vIndiceCliente], comprasRealizadas[vIndiceCliente], vIndiceCliente);
                        vIndiceCliente++;
                        printf("Cadastrar um novo cliente(S/n)? ");
                        strlwr(gets(promptSimNao));
                        fflush(stdin);
                    } while (strcmp(promptSimNao, promptCompare[0]) == 0);
                }
            }
            else if (vIndiceProduto == 1)
            {
                printf("\n\nNao eh possivel realizar uma venda pois nao existem produtos cadastrados\n");
                printf("Cadastrar um Produto agora (S/n)? ");
                strlwr(gets(promptSimNao));
                fflush(stdin);
                // Iniciamos o cadastro de produtos
                if (strcmp(promptSimNao, promptCompare[0]) == 0)
                {
                    do
                    {
                        // Setamos o codigo do produto
                        cdProduto[vIndiceProduto] = vIndiceProduto;
                        // Chamamos a função de cadastro de produtos
                        cadastroProduto(cdProduto[vIndiceProduto], nomeProduto[vIndiceProduto], marcaProduto[vIndiceProduto], modeloProduto[vIndiceProduto], &valorProduto[vIndiceProduto], vIndiceProduto);
                        // Aumentamos a quantidade de produtos no sistema
                        vIndiceProduto++;
                        // Por fim verificamos se o cliente quer cadastrar outro produto
                        printf("Cadastrar um novo Produto(S/n)? ");
                        strlwr(gets(promptSimNao));
                        fflush(stdin);
                    } while (strcmp(promptSimNao, promptCompare[0]) == 0);
                }
            }
            else
            {
                printf("Deseja realizar multiplas vendas (S/n)? ");
                strlwr(gets(promptSimNao));
                fflush(stdin);
                if (strcmp(promptSimNao, promptCompare[0]) == 0)
                {
                    printf("Insira a quantidade de compras desejadas: -- ");
                    scanf("%d", &qtComprasARealizar);
                    fflush(stdin);
                    contadorPadrao = 0;
                    while (contadorPadrao < qtComprasARealizar)
                    {
                        cdCompra[vIndiceProduto] = vIndiceCompra;
                        realizarCompra(cdCompra[vIndiceCompra], &relacaoCpfCliente[vIndiceCompra], &relacaoProduto[vIndiceCompra], qtVenda[vIndiceCompra], &subTotalCompra[vIndiceCompra], &prcntDescontoCompra[vIndiceCompra], &valorTotalVenda[vIndiceCompra], promptSimNao, promptCompare);
                        // Aumentamos a quantidade de compras realizadas
                        vIndiceCompra++;
                        contadorPadrao++;
                    }
                }
                else
                {
                    cdCompra[vIndiceCompra] = vIndiceCompra;
                    printf("Por favor insira o codigo de cadastro do produto: ");
                    scanf("%d", &relacaoProduto[vIndiceCompra]);
                    contadorPadrao = 0;
                    for (size_t i = 0; i < vIndiceProduto; i++)
                    {
                        if (relacaoProduto[vIndiceCompra] == cdProduto[i])
                        {
                            printf("Produto encontrado: %s", nomeProduto[i]);
                            ableToProceed = 1;
                            i = vIndiceProduto;
                        }
                    }

                    if (ableToProceed > 1)
                    {
                        printf("Nao foram encontrados produtos com o codigo inserido!\n");
                        printf("Deseja listar todos os produtos cadastrados (S/n)? \n");
                        strlwr(gets(promptSimNao));
                        fflush(stdin);
                        if (strcmp(promptSimNao, promptCompare[0]) == 0)
                        {
                            /* Listar todos os produtos */
                        }
                        else
                        {
                            printf("Retornando ao menu inicial!\n");
                        }
                    }
                    else
                    {
                    }

                    vIndiceCompra++;
                    contadorPadrao++;
                }
            }
            break;
        default:
            break;
        }
    } while (selecaoMenu != 6);

    printf("Finalizando sistema");
}

// Função de cadastro de clientes
void cadastroCliente(int *cdClient, char *nomeCliente[50], double *cpfCliente, char *sexoCliente[50], double *telefoneCliente, char *emailCliente[50], int *comprasRealizadas, int *vIndiceCliente)
{
    // Recebemos os principais dados dos clientes
    printf("\n###########");
    printf("\nIniciando cadastro!");
    printf("\nInsira o nome do cliente: ");
    gets(nomeCliente);
    fflush(stdin);

    printf("Insira o cpf do cliente: ");
    scanf("%lf", cpfCliente);
    fflush(stdin);

    printf("Insira o sexo do cliente (F/M): ");
    gets(sexoCliente);
    fflush(stdin);

    printf("Insira o telefone do cliente: ");
    scanf("%lf", telefoneCliente);
    fflush(stdin);

    printf("Insira o email do cliente: ");
    gets(emailCliente);
    fflush(stdin);

    printf("\n\n##########\n");
    printf("# Cliente cadastrado com sucesso !!!\n");
    printf("# Codigo de cadastro: %d\n", cdClient);
    printf("# Nome cadastrado: %s\n", nomeCliente);
    printf("# Cpf cadastrado: %0.0lf\n", *cpfCliente);
    printf("# Sexo cadastrado: %s \n", sexoCliente);
    printf("# Telefone de cadastro: %0.0lf\n", *telefoneCliente);
    printf("# Email de cadastro: %s\n", emailCliente);
    printf("##########\n\n");
}

//Função de cadastro de produtos
void cadastroProduto(int *cdProduto, char *nomeProduto[50], char *marcaProduto[50], char *modeloProduto[50], double *valorProduto, int *vIndiceProduto)
{
    // Recebendo dados do Produto
    printf("\n###########");
    printf("\nIniciando cadastro de Produto!");
    printf("\nInsira o nome do Produto: ");
    gets(nomeProduto);
    fflush(stdin);

    printf("\nInsira o marca do Produto: ");
    gets(marcaProduto);
    fflush(stdin);

    printf("\nInsira o modelo do Produto: ");
    gets(modeloProduto);
    fflush(stdin);

    printf("Insira o valor do Produto: ");
    scanf("%lf", valorProduto);
    fflush(stdin);

    printf("\n\n##########\n");
    printf("# Produto cadastrado com sucesso !!!\n");
    printf("# Codigo de cadastro do Produto: %d\n", cdProduto);
    printf("# Produto cadastrado: %s\n", nomeProduto);
    printf("# Marca cadastrada: %s\n", marcaProduto);
    printf("# Modelo cadastrado: %s \n", modeloProduto);
    printf("# Valor cadastrado: %0.0lf\n", *valorProduto);
    printf("##########\n\n");
}

// Função de realizalção de venda
void realizarCompra(int *cdCompra, double *relacaoCpfCliente, int *relacaoProduto, int *qtVenda, int *subTotalCompra, double *prcntDescontoCompra, double *valorTotalVenda, char *promptSimNao, char *promptCompare)
{
}