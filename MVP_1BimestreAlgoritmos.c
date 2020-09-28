#include <stdio.h>
#include <string.h>

void cadastroCliente(int *cdClient, char *nomeCliente[50], double *cpfCliente, char *sexoCliente[50], double *telefoneCliente, char *emailCliente[50], int *comprasRealizadas, int *vIndiceCliente);
void cadastroProduto(int *cdProduto, char *nomeProduto[50], char *marcaProduto[50], char *modeloProduto[50], double *valorProduto, int *vIndiceProduto);

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
  int qtComprasARealizar[constante];     // Quantidades de compras que o usuario deseja fazer
  int cdCompra[constante];               // Identificação da compra do produto
  int relacaoCliente[constante];         // Relação da compra com o  usuario
  int relacaoProduto[constante];         // Relação da compra com o produto
  int qtVenda[constante];                // Quantidade de produtos vendidos
  double subTotalCompra[constante];      // Subtotal padrao do produto
  double prcntDescontoCompra[constante]; // Porcentagem do desconto
  double valorTotalVenda[constante];     // Valor final da venda

  printf("Bem vindo ao MVP do Sr. Oswaldo!\n");
  do
  {
    // Menu de escolha do sistema
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
      { // Se ha registro de cadastro de produtos
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
        // Se o usuario escolhe cadastrar um cliente
        if (strcmp(promptSimNao, promptCompare[0]) == 0)
        {

          do
          {
            cdCliente[vIndiceCliente] = vIndiceCliente;
            comprasRealizadas[vIndiceCliente] = 0;
            // Função para cadastro dos clientes
            cadastroCliente(cdCliente[vIndiceCliente], nomeCliente[vIndiceCliente], &cpfCliente[vIndiceCliente], sexoCliente[vIndiceCliente], &telefoneCliente[vIndiceCliente], emailCliente[vIndiceCliente], comprasRealizadas[vIndiceCliente], vIndiceCliente);
            vIndiceCliente++;
            // Após cadastro perguntar se o usuaro deseja cadastrar um novo cliente
            printf("Cadastrar um novo cliente(S/n)? ");
            strlwr(gets(promptSimNao));
            fflush(stdin);
            // Se a resposta for sim, ele irá repetir o "do"
          } while (strcmp(promptSimNao, promptCompare[0]) == 0);
        }
      }
      else
      { //Se ha registro de cadastro de clientes:
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
        // Por fim verificamos se o usuário quer cadastrar outro produto
        printf("Cadastrar um novo Produto(S/n)? ");
        strlwr(gets(promptSimNao));
        fflush(stdin);
      } while (strcmp(promptSimNao, promptCompare[0]) == 0);
      break;
      // Iniciar o cadastro de clientes
    case 4:
      do
      {
        //Setamos o codigo do cliente
        cdCliente[vIndiceCliente] = vIndiceCliente;
        //Setamos um registro de compra para o cliente
        comprasRealizadas[vIndiceCliente] = 0;
        // Chamamos a função de cadastro de cliente
        cadastroCliente(cdCliente[vIndiceCliente], nomeCliente[vIndiceCliente], &cpfCliente[vIndiceCliente], sexoCliente[vIndiceCliente], &telefoneCliente[vIndiceCliente], emailCliente[vIndiceCliente], comprasRealizadas[vIndiceCliente], vIndiceCliente);
        // Aumentamos a quantidade de clientes no sistema
        vIndiceCliente++;
        // Verificar se o usuário quer cadastrar outro cliente
        printf("Cadastrar um novo cliente(S/n)? ");
        strlwr(gets(promptSimNao));
        fflush(stdin);
      } while (strcmp(promptSimNao, promptCompare[0]) == 0);
      break;
      // Iniciar o cadastro de vendas
    case 5:
      if (vIndiceCliente == 1)
      {
        // Caso não existam produtos verificamos se o usuario quer cadastrar algum
        printf("\n\nNao eh possivel realizar uma venda pois nao existem clientes cadastrados\n");
        printf("Cadastrar um Cliente agora (S/n)? ");
        strlwr(gets(promptSimNao));
        fflush(stdin);
        // Iniciamos o cadastro de clientes
        if (strcmp(promptSimNao, promptCompare[0]) == 0)
        {
          do
          {
            //Setamos o codigo do cliente
            cdCliente[vIndiceCliente] = vIndiceCliente;
            //Setamos um registro de compra para o cliente
            comprasRealizadas[vIndiceCliente] = 0;
            // Chamamos a função de cadastro de cliente
            cadastroCliente(cdCliente[vIndiceCliente], nomeCliente[vIndiceCliente], &cpfCliente[vIndiceCliente], sexoCliente[vIndiceCliente], &telefoneCliente[vIndiceCliente], emailCliente[vIndiceCliente], comprasRealizadas[vIndiceCliente], vIndiceCliente);
            // Aumentamos a quantidade de clientes no sistema
            vIndiceCliente++;
            // Verificar se o usuário quer cadastrar outro cliente
            printf("Cadastrar um novo cliente(S/n)? ");
            strlwr(gets(promptSimNao));
            fflush(stdin);
          } while (strcmp(promptSimNao, promptCompare[0]) == 0);
        }
      }
      else if (vIndiceProduto == 1)
      {
        // Caso não exista produtos verificamos se o usuário deseja cadastrar um Produto
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
        //Setamos um registro de compra para o cliente
        cdCompra[vIndiceCompra] = vIndiceCompra;
        //Chamamos o codigo do produto que deseja registrar venda
        printf("Por favor insira o codigo de cadastro do produto: ");
        scanf("%d", &relacaoProduto[vIndiceCompra]);
        fflush(stdin);
        contadorPadrao = 1;
        while (contadorPadrao < vIndiceProduto)
        {
          if (relacaoProduto[vIndiceCompra] == cdProduto[contadorPadrao])
          {
            printf("Produto encontrado: %s\n", nomeProduto[contadorPadrao]);
            ableToProceed = 1;
            contadorPadrao = vIndiceProduto + 1;
          }
          else
          {
            ableToProceed = 0;
            contadorPadrao++;
          }
        }
        if (ableToProceed < 1)
        {
          printf("Nao foram encontrados produtos com o codigo inserido!\n");
          // Chamamos para o usuario escolher se deseja listar os produtos a fim de encontrar um codigo valido
          printf("Deseja listar todos os produtos cadastrados (S/n)? \n");
          strlwr(gets(promptSimNao));
          fflush(stdin);
          if (strcmp(promptSimNao, promptCompare[0]) == 0)
          {
            /* Listar todos os produtos */
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
          else
          {
            printf("Retornando ao menu inicial!\n");
          }
        }
        else
        {
          //Chamamos por um código de cliente
          printf("Agora por favor informe o codigo do cadastro do cliente: ");
          scanf("%d", &relacaoCliente[vIndiceCompra]);
          fflush(stdin);
          contadorPadrao = 1;
          while (contadorPadrao < vIndiceCliente)
          {
            if (relacaoCliente[vIndiceCompra] == cdCliente[contadorPadrao])
            {
              printf("Cliente encontrado: %s com cpf: %0.0lf\n", nomeCliente[contadorPadrao], cpfCliente[contadorPadrao]);
              ableToProceed = 1;
              contadorPadrao = vIndiceCliente + 1;
            }
            else
            {
              ableToProceed = 0;
              contadorPadrao++;
            }
          }
          // Condição para o caso do usuário digitar um codigo inexistente
          if (ableToProceed < 1)
          {
            //Usuário escolhe se deseja listar os clientes cadastrados
            printf("Nao foram encontrados clientes com o codigo inserido!\n");
            printf("Deseja listar todos os produtos cadastrados (S/n)? \n");
            strlwr(gets(promptSimNao));
            fflush(stdin);
            // Se o usuario deseja listar:
            if (strcmp(promptSimNao, promptCompare[0]) == 0)
            {
              /* Listando todos os clientes */
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
            // Se o usuario não quiser listar os produtos
            else
            {
              printf("Retornando ao menu inicial!\n");
            }
          }
          // Condição para o usuario realizar a venda:
          else
          {
            ableToProceed = 0;
            do
            {
              // Agregar informações a partir do produto selecionado
              subTotalCompra[vIndiceCompra] = valorProduto[relacaoProduto[vIndiceCompra]];
              printf("Valor do produto: %0.2lf\n", subTotalCompra[vIndiceCompra]);
              // Perguntar ao usuario se o produto tem desconto
              printf("Produto com desconto (S/n)? ");
              strlwr(gets(promptSimNao));
              fflush(stdin);
              // Pedir ao usuário a porcentagem de desconto do produto
              if (strcmp(promptSimNao, promptCompare[0]) == 0)
              {
                printf("Insira a porcentagem de desconto: ");
                scanf("%lf", &prcntDescontoCompra[vIndiceCompra]);
                prcntDescontoCompra[vIndiceCompra] = prcntDescontoCompra[vIndiceCompra] / 100;
                prcntDescontoCompra[vIndiceCompra] = subTotalCompra[vIndiceCompra] - (subTotalCompra[vIndiceCompra] * prcntDescontoCompra[vIndiceCompra]);
                valorTotalVenda[vIndiceCompra] = prcntDescontoCompra[vIndiceCompra];
              }
              // Definir o valor total a partir do subtotal
              else
              {
                valorTotalVenda[vIndiceCompra] = subTotalCompra[vIndiceCompra];
              }
              // Pedir ao usuário a quantidade de produtos
              qtComprasARealizar[vIndiceCompra] = 1;
              printf("Qual a quantia do produto a serem vendidos (pelo menos 1)? ");
              scanf("%d", &qtComprasARealizar[vIndiceCompra]);
              fflush(stdin);
              // Se o usuário digitar um valor menor ou igual a 0
              while (qtComprasARealizar[vIndiceCompra] <= 0)
              {
                printf("A quantia minima para a venda eh 1\n");
                printf("Por favor insira a quantidade do produto a ser vendida: ");
                scanf("%d", &qtComprasARealizar[vIndiceCompra]);
                fflush(stdin);
              }
              // Calcular o valor total em relação a quantidade de produtos vendidos
              fflush(stdin);
              valorTotalVenda[vIndiceCompra] = valorTotalVenda[vIndiceCompra] * qtComprasARealizar[vIndiceCompra];
              // Imprimir dados da Venda
              printf("Serao vendidos: %d %s da marca %s", qtComprasARealizar[vIndiceCompra], nomeProduto[relacaoProduto[vIndiceCompra]], marcaProduto[relacaoProduto[vIndiceCompra]]);
              printf("\nPara o cliente: %s", nomeCliente[relacaoCliente[vIndiceCompra]]);
              printf("\nCom o valor final da compra de: %0.2lf", valorTotalVenda[vIndiceCompra]);
              // Finalizar venda
              printf("\nFinalizar venda (S/n)?");
              strlwr(gets(promptSimNao));
              fflush(stdin);
              // Se sim
              if (strcmp(promptSimNao, promptCompare[0]) == 0)
              {
                ableToProceed = 1;
              }
              // Se não
              else
              {
                printf("Revisando pedido");
                ableToProceed = 0;
              }
            } while (ableToProceed < 1);
            comprasRealizadas[relacaoCliente[vIndiceCompra]]++;
            vIndiceCompra++;
            printf("Compra realizada com sucesso!");
          }
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
  int ValidacaoDeEtapa = 0;
  char confirmEmailArroba[250] = {"@"};
  char confirmEmailPontoCom[250] = {".com"};

  // Recebemos os principais dados dos clientes
  printf("\n###########");
  printf("\nIniciando cadastro!");
  printf("\nInsira o nome do cliente: ");
  gets(nomeCliente);
  fflush(stdin);

  printf("Insira o cpf do cliente: ");
  scanf("%lf", cpfCliente);
  fflush(stdin);

  do // Validacao do sexo do cliente cadastrado
  {
    printf("Insira o sexo do cliente (F/M): ");
    gets(sexoCliente);
    fflush(stdin);

    if (strlen(sexoCliente) > 1)
    {
      printf("\nO sexo inserido nao eh valido\n\n");
      ValidacaoDeEtapa = 0;
    }
    else
    {
      ValidacaoDeEtapa = 1;
    }

  } while (ValidacaoDeEtapa < 1);

  ValidacaoDeEtapa = 0;

  printf("Insira o telefone do cliente: ");
  scanf("%lf", telefoneCliente);
  fflush(stdin);

  do // Validacao do email do cliente cadastrado
  {
    printf("Insira o email do cliente: ");
    gets(emailCliente);
    fflush(stdin);

    // Se o @ e o .com não existir invalida o email
    if (strstr(emailCliente, confirmEmailArroba) == NULL && strstr(emailCliente, confirmEmailPontoCom) == NULL)
    {
      printf("\nO email inserido nao eh valido\n\n");
      ValidacaoDeEtapa = 0;
    }
    // Se o @ existir e o .com não existir invalida o email
    else if (strstr(emailCliente, confirmEmailArroba) != NULL && strstr(emailCliente, confirmEmailPontoCom) == NULL)
    {
      printf("\nO email inserido nao eh valido\n\n");
      ValidacaoDeEtapa = 0;
    }
    // Se o @ não existir e o .com existir invalida o email
    else if (strstr(emailCliente, confirmEmailArroba) == NULL && strstr(emailCliente, confirmEmailPontoCom) != NULL)
    {
      printf("\nO email inserido nao eh valido\n\n");
      ValidacaoDeEtapa = 0;
    }
    // Se houver @ e .com o email é valido
    else
    {
      ValidacaoDeEtapa = 1;
    }

  } while (ValidacaoDeEtapa < 1);

  // Imprimindo os dados do cliente cadastrado
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
  int ValidacaoDeEtapa = 0;

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

  do
  { // Validação do valor do produto
    printf("\nInsira o valor do Produto: ");
    scanf("%lf", valorProduto);
    fflush(stdin);

    // condição para se o usuário insere um valor menor ou igual que 0
    if (*valorProduto <= 0)
    {
      printf("\nO valor inserido deve ser maior do que 0!\n\n");
      ValidacaoDeEtapa = 0;
    }
    // condição para se o usuario insere um valor maior ou igual a 1
    else
    {
      ValidacaoDeEtapa = 1;
    }

  } while (ValidacaoDeEtapa < 1);

  // imprimindo os dados do produto cadastrado
  printf("\n\n##########\n");
  printf("# Produto cadastrado com sucesso !!!\n");
  printf("# Codigo de cadastro do Produto: %d\n", cdProduto);
  printf("# Produto cadastrado: %s\n", nomeProduto);
  printf("# Marca cadastrada: %s\n", marcaProduto);
  printf("# Modelo cadastrado: %s \n", modeloProduto);
  printf("# Valor cadastrado: %0.0lf\n", *valorProduto);
  printf("##########\n\n");
}