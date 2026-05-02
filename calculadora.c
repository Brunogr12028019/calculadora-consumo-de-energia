#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char  item[20][50];
    int   potencia[20];
    int   quantidade[20];
    float horasDia[20];
    int   diasMes[20];
    float consumoMesItem[20];
    float consumoMesTotalItem[20];
    float consumoMesTotalGeral = 0;
    char  continuar;
    int   contador = 0;

    do {
        printf("Item %d\n", contador + 1);
        printf("\n");

        printf("Insira o nome do item (sem espacos): ");
        scanf("%49s", item[contador]);

        printf("Insira a potencia (Watts): ");
        scanf("%i", &potencia[contador]);

        printf("Insira a quantidade na instalacao: ");
        scanf("%i", &quantidade[contador]);

        printf("Horas por dia (1 a 24): ");
        scanf("%f", &horasDia[contador]);

        printf("Dias no mes (1 a 30): ");
        scanf("%i", &diasMes[contador]);

        consumoMesItem[contador]      = (potencia[contador] * horasDia[contador] * diasMes[contador]) / 1000.0;
        consumoMesTotalItem[contador] = consumoMesItem[contador] * quantidade[contador];

        contador++;

        if (contador < 20) {
            printf("Deseja inserir outro item? (s/n): ");
            scanf(" %c", &continuar);
        } else {
            printf("Limite de 20 itens atingido.\n");
            continuar = 'n';
        }

        printf("\n");

    } while (continuar == 's' || continuar == 'S');

    /* Soma o total geral */
    for (int i = 0; i < contador; i++) {
        consumoMesTotalGeral = consumoMesTotalGeral + consumoMesTotalItem[i];
    }

    printf("\n");

   
    printf("  ┌──────────────────────────┬────────────────────────┬────────────────────────┐\n");
    printf("  │  Item                    │  kWh/mes (unitario)    │  kWh/mes (total)       │\n");
    printf("  ├──────────────────────────┼────────────────────────┼────────────────────────┤\n");

    
    for (int i = 0; i < contador; i++) {
        int tamanho = strlen(item[i]);
        int espacos = 24 - tamanho;
        if (espacos < 0) espacos = 0;

        printf("  │  %s", item[i]);
        for (int s = 0; s < espacos; s++) printf(" ");  /* completa até 24 chars */
        printf("│  %-20.2f  │  %-20.2f  │\n",
               consumoMesItem[i],
               consumoMesTotalItem[i]);
    }

    
    printf("  ├──────────────────────────┴────────────────────────┼────────────────────────┤\n");
    printf("  │  TOTAL GERAL                                      │  %-20.2f  │\n", consumoMesTotalGeral);
    printf("  └───────────────────────────────────────────────────┴────────────────────────┘\n");

    printf("\n");

    return 0;
}