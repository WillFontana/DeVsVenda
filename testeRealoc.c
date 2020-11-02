#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct testeRealoc
{
  int idade;
};

typedef struct testeRealoc teste;

struct testeRealocSegundo
{
  char nome[15];
};

typedef struct testeRealocSegundo testeSegundo;

void aloca(struct estrutura *estrutura, int valor)
{
  estrutura = realloc(estrutura, valor * sizeof(estrutura));
  if (estrutura == NULL)
  {
    printf("Impossivel realocar");
  }
  return;
}

void main()
{
  teste *Pessoas;
  testeSegundo *Cpfs;

  Pessoas = (teste *)malloc(1 * sizeof(teste));
  Cpfs = (testeSegundo *)malloc(1 * sizeof(testeSegundo));

  Pessoas[1].idade = 64;
  printf("Insira o primeiro nome: ");
  fflush(stdin);
  gets(Cpfs[1].nome);

  aloca(Pessoas, 2);
  aloca(Cpfs, 2);

  Pessoas[2].idade = 45;
  printf("Insira o segundo nome: ");
  fflush(stdin);
  gets(Cpfs[2].nome);
  
  for (size_t i = 1; i <= 2; i++)
  {
    printf("O pessoa %d tem %d anos e cpf igual a %s.\n", i, Pessoas[i].idade, Cpfs[i].nome);
  }

  return;
}