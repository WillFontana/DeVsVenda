#include <stdio.h>;
#include <string.h>;
#include <stdlib.h>;

int main()
{
  int clientesCadastrados = 0;

  FILE *pFile;

  pFile = fopen("clientes_bd.csv", "r");
  if (!pFile)
  {
    printf("Nao foi possivel ler o arquivo");
    return 0;
  }
  else
  {
    printf("Lendo o arquivo.....\n");
    char c;
    char *dado = calloc(255, 1);
    char *texto = calloc(255, 1);
    do
    {
      c = fgetc(pFile);
      if (c != ';')
      {
        if (c == '\n')
        {
          clientesCadastrados++;
          printf("\nClientes cadastrados: %d\n", clientesCadastrados);
        }
        else
        {
          texto[strlen(texto)] = c;
          texto[strlen(texto) + 1] = '\0';
        }
      }
      else
      {
        char *field = strtok(texto, ":");
        while (field != NULL)
        {
          // Nome do usuário
          if (strcmp(strlwr(field), "nome") == 0)
          {
            field = strtok(NULL, ":");
            printf("Nome do usuario: %s\n", field);
            field = strtok(NULL, ":");

          }
          // CPF do usuario
          else if (strcmp(strlwr(field), "cpf") == 0)
          {
            field = strtok(NULL, ":");
            double value = atof(field);
            printf("CPF do usuario: %0.0lf\n", value);
          }
          // Compras do usuário
          else if (strcmp(strlwr(field), "compras") == 0)
          {
            field = strtok(NULL, ":");
            int value = atoi(field);
            printf("Compras realizadas: %d\n", value);
          }
          // Sexo do usuário
          else if (strcmp(strlwr(field), "sexo") == 0)
          {
            field = strtok(NULL, ":");
            printf("Sexo do usuario: %s\n", field);
          }
          // Telefone do usuário
          else if (strcmp(strlwr(field), "telefone") == 0)
          {
            field = strtok(NULL, ":");
            printf("Telefone do usuario: %s\n", field);
          }
          // Celular do usuário
          else if (strcmp(strlwr(field), "celular") == 0)
          {
            field = strtok(NULL, ":");
            printf("Celular do usuario: %s\n", field);
          }
          else
          {
            field = strtok(NULL, ":");
          }
        }

        texto = strtok(texto, ":");
        strcpy(dado, texto);
        free(texto);
        texto = calloc(255, 1);
      }
    } while (c != EOF);
  }
  fclose(pFile);
}