  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  typedef struct Boleto {
      int id;
      char nome_conta[30];
      char cod_barras[48];
      int dia_vencimento, mes_vencimento;
      float valor;
      struct Boleto *prox;
  } Boleto;

  Boleto *cadastrarBoleto(Boleto *lista, int id, const char *nome_conta, const char *cod_barras, int dia_vencimento, int mes_vencimento, float valor) {
      Boleto *novoBoleto = (Boleto *)malloc(sizeof(Boleto));
      if (novoBoleto == NULL) {
          printf("Erro de alocação de memória.\n");
          return lista;
      }

      novoBoleto->id = id;
      strcpy(novoBoleto->nome_conta, nome_conta);
      strcpy(novoBoleto->cod_barras, cod_barras);
      novoBoleto->dia_vencimento = dia_vencimento;
      novoBoleto->mes_vencimento = mes_vencimento;
      novoBoleto->valor = valor;
      novoBoleto->prox = NULL;

      if (lista == NULL) {
          return novoBoleto;
      } else {
          Boleto *temp = lista;
          while (temp->prox != NULL) {
              temp = temp->prox;
          }
          temp->prox = novoBoleto;
          return lista;
      }
  }

  void liberarBoletos(Boleto *lista) {
      Boleto *temp;
      while (lista != NULL) {
          temp = lista;
          lista = lista->prox;
          free(temp);
      }
  }

  void imprimirBoletos(Boleto *lista) {
      printf("Lista de Boletos:\n");
      printf("ID\tConta\tCódigo de Barras\tVencimento\tValor\n");
      while (lista != NULL) {
          printf("%d\t%s\t%s\t%d/%d\t%.2f\n", lista->id, lista->nome_conta, lista->cod_barras, lista->dia_vencimento, lista->mes_vencimento, lista->valor);
          lista = lista->prox;
      }
  }

  int main() {
      Boleto *listaBoletos = NULL;

      // Exemplo de cadastro de boletos
      listaBoletos = cadastrarBoleto(listaBoletos, 1, "LUZ", "123456789012345678901234567890123456789012345678", 10, 3, 100.34);
      listaBoletos = cadastrarBoleto(listaBoletos, 2, "ÁGUA", "987654321098765432109876543210987654321098765432", 5, 3, 150.50);
      listaBoletos = cadastrarBoleto(listaBoletos, 3, "TELEFONE", "246801357924680135792468013579246801357924680135", 15, 3, 80.00);

      // Exibir os boletos cadastrados
      imprimirBoletos(listaBoletos);

      // Liberar memória alocada
      liberarBoletos(listaBoletos);

      return 0;
  }
