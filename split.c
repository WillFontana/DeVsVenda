#include <stdio.h>;
#include <string.h>;
#include <stdlib.h>;

void main()
{
  double cpf = 10672401959;
  int counter = 0;
  int cpfDouble = (int)(cpf / 100);
  double expo = 1;
  for (size_t i = 0; cpfDouble > 0; i++)
  {
    cpfDouble /= 10;
    counter++;
  }
  for (size_t i = 0; i <= counter; i++)
  {
    expo = expo * 10;
  }

  int contadorDivisao = 0;
  int valorCpfAgora;

  while (contadorDivisao < 7)
  {
    valorCpfAgora = (int)(cpf / expo);
    contadorDivisao++;
    expo = expo / 10;
  }
  printf("\nValor do CPF: %d", valorCpfAgora);
}