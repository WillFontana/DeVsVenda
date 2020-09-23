#include <stdio.h>
#include <string.h>

void cadastroCliente(int *cdClient, char *nomeCliente[50], double *cpfCliente, char *sexoCliente[50], double *telefoneCliente, char *emailCliente[50], int *comprasRealizadas, int *vIndiceCliente);
void cadastroProduto(int *cdProduto, char *nomeProduto[30], char *marcaProduto[50], char *modeloProduto[50], double *valorProduto, int *vIndiceProduto);

int main()
{
    // variaveis de controles
    int constante = 50;
    int constante2 = 50;
    int vIndiceCliente = 1;                // Controle qtd de clientes
    int vIndiceProduto = 1;                // Controle qtd de produtos
    char promptCompare[3][3] = {"s", "n"}; // Controle de respostas
    char promptSimNao[2];                  // Desisão binaria do usuario (S ou N)
    int selecaoMenu;                       // Controle da decisão do usuário no menu de navegação

    // Variaveis de clientes;
    int cdCliente[constante];             // Codigo do cliente
    char nomeCliente[constante][30];      // Nome Cliente
    double cpfCliente[constante];         // Cpf do cliente
    char sexoCliente[50][2] = {'F', 'M'}; // Sexo do Cliente
    double telefoneCliente[constante];    // Telefone do CLiente
    char emailCliente[constante][20];     // Email do Cliente
    int comprasRealizadas[constante];

    // Variaveis de Produto
    int cdProduto[constante2];        // Codigo do Produto
    char nomeProduto[constante2][30]; // Nome Produto
    char marcaProduto[constante2][50];    // Marca do Produto
    char modeloProduto[constante2][50];   // Modelo do Produto
    double valorProduto[constante2];  // Valor do Produto

    printf("Bem vindo ao MVP do Sr. Oswaldo!\n");
    do
    {
        printf("############# Menu de controle ##############\n");
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
        case 1:
            // Verificamos se existem produtos cadastrados
            if (vIndiceProduto == 1)
            {
                printf("Parece que nao existem produtos cadastrados\n");
                printf("Cadastrar um Produto agora (S/n)? ");
                strlwr(gets(promptSimNao));
                fflush(stdin);
                // Iniciamos o cadastro de produtos
                if (strcmp(promptSimNao, promptCompare[0]) == 0)
                {

                    do
                    {
                        cdProduto[vIndiceProduto] = vIndiceProduto;
                        cadastroProduto(cdProduto[vIndiceProduto], nomeProduto[vIndiceProduto], marcaProduto[vIndiceProduto], modeloProduto[vIndiceProduto], &valorProduto[vIndiceProduto], vIndiceProduto);
                        vIndiceProduto++;
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
                    printf("# Codigo de cadastro: %d\n", cdCProduto[i]);
                    printf("# Nome do Produto: %s\n", nomeProduto[i]);
                    printf("# Marca do Produto: %s\n", marcaProduto[i]);
                    printf("# Modelo do Produto: %s \n", modeloProduto[i]);
                    printf("# Valor do Produto: %0.0lf\n", valorProduto[i]);
                    printf("##########\n\n");
                }
            }

            break;

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

        case 5:

            // Verificamos se existem produtos cadastrados
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

        case 4:
            // Verificamos se existem Compras cadastrados
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
void cadastroProduto(int *cdProduto, char *nomeProduto[30], char *marcaProduto, char *modeloProduto, double *valorProduto, int *vIndiceProduto);
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