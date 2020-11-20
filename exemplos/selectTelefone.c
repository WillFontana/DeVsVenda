#include <stdio.h>;
#include <string.h>;
#include <stdlib.h>;

void main()
{
  char telefone[20];
  char celular[20];
  char telefoneEditado[20];
  char celularEditado[20];
  printf("Insira o telefone (com DD): ");
  fflush(stdin);
  gets(telefone);
  if (telefone[0] != '\0')
  {
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
  }

  printf("Insira o celular (com DD): ");
  fflush(stdin);
  gets(celular);

  if (celular[0] != '\0')
  {
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
  }

  printf("Telefone do cliente: %s", telefoneEditado);
  printf("\nCelular do cliente: %s", celularEditado);
}