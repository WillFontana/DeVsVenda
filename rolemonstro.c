#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{

  int vetor1[7] = {3, 6, 8, 10, 20, 1, 8};
  int vetor2[7];
  int posicoesVetores[7];
  int contador = 0;
  vetor2[0] = vetor1[0];
  for (size_t i = 0; i < 7; i++)
  {
    // printf("O valor de vetor1[%d] eh %d\n",i, vetor1[i]);
    if (vetor2[contador] < vetor1[i])
    {
      for (size_t j = 0; j <= contador; j++)
      {

        if (vetor1[i] != vetor2[j])
        {
          printf("J: %d e contador: %d\n", j, contador);
          if (contador = j)
          {
            vetor2[contador] = vetor1[i];
          }
        }
      }
    }
  }

  for (size_t k = 0; k < 7; k++)
  {
    printf("\nO valor do vetor2[%d] eh %d\n", k, vetor2[k]);
  }

  return;
}