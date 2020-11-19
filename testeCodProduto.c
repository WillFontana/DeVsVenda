#include <stdio.h>;
#include <string.h>;
#include <stdlib.h>;

void main()
{
  char marca[20],
      modelo[20],
      ASCIIModeloString[6],
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
    int num = (rand() % (30 - 1 + 1)) + 1;
    printf("Numero %d", num);
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

  printf("Numeros aletatorios gerados: %d, %d, %d", random1, random2, random3);

  printf("\nDigite a marca: ");
  fflush(stdin);
  gets(marca);
  printf("\nMarca: %s", marca);
  printf("\nPrimeira letra da marca: %c", marca[0]);
  ASCIIMarca = (int)marca[0];
  printf("\nASCII da marca: %d", ASCIIMarca);

  printf("\n\nDigite o modelo: ");
  fflush(stdin);
  gets(modelo);
  printf("\nModelo: %s", modelo);
  printf("\nPrimeira letra do modelo: %c", modelo[0]);
  ASCIIModelo = (int)modelo[0];
  printf("\nASCII do modelo: %d", ASCIIModelo);

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
  printf("\nCodigo do produto: %d", cdProduto);
}