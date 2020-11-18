#include <stdio.h>;
#include <string.h>;
#include <stdlib.h>;

void main()
{
  char marca[7],
      modelo[7],
      ASCIIModeloString[5],
      ASCIIMarcaString[5];
  int ASCIIMarca, ASCIIModelo,
   cdProduto,
   random1, random2, random3;
  
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
  strcat(ASCIIMarcaString,ASCIIModeloString);
  cdProduto = atoi(ASCIIMarcaString);
  printf("\nCodigo do produto: %d", cdProduto);
}