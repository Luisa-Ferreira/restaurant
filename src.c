#include <stdio.h>

int main(void) {
  int fila[4] = {0, 0, 0, 0};
  int tempoMesas[4] = {0, 0, 0, 0};
  int mesas[4] = {0, 0, 0, 0};
  int pessoas = 0, horas = 14;
  int horaEntrada = 14, horaFecho = 23;
  int horaChegada = 0 ;
  int denovo = 0, count = 0;

  do {

    int mesaDisponivel = 0;
    printf("----------\nFila: ");

    for (int i = 0; i <= 3; i++) {

      if (fila[i] != 0) {
        printf("%d-", fila[i]);
      }
    }

    printf("\nHora Atual: %d\n----------\n\n", horas);

    for (int tables = 0; tables <= 3; tables++) {
      printf("Mesa %d: %d\n", tables + 1, mesas[tables]);
    }

    printf("\nQuantas pessoas chegaram?\n");
    scanf("%d", &pessoas);

    do {
      printf("Que horas chegaram?\n");
      scanf("%d", &horas);
      printf("\n");

      if (horas >= horaFecho) {
        denovo = 1;
      }

    } while (horas < horaEntrada || horas < horaChegada);

    
    for (int i = 0; i <= 3; i++) {
      int limpar = horas - tempoMesas[i];
      if (limpar >= 2) {
        tempoMesas[i] = 0;
        mesas[i] = 0;
      }
    }

    // verificar se ha uma mesa livre
    for (int i = 0; i <= 3; i++) {

      if (mesas[i] == 0 && fila[i] != 0) {
        mesas[i] = fila[i];
        tempoMesas[i] = horas;
        fila[i] = 0;
      }

      if (fila[0] > 0 && mesas[i] == 0) {
        mesas[i] = fila[0];
        tempoMesas[i] = horas;
        fila[0] = 0;
      }

      if (mesas[i] == 0 && pessoas != 0) {
        mesas[i] = pessoas;
        tempoMesas[i] = horas;
        horaChegada = horas;
        mesaDisponivel = 1;
        break;
      }
    }

    if (!mesaDisponivel) {
      for (int i = 0; i <= 3; i++) {
        if (fila[i] == 0) {
          fila[i] = pessoas;
          count++;
          break;
        }
      }
    }
  } while (denovo == 0);
}