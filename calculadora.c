#include <stdio.h>
#include <stdlib.h>

int main(){
    
    char item[50];
    int potencia;
    int quantidade;
    float horasDia;
    int diasMes;
    char continuar;
    int contador = 1;
    
    do {
        printf("Item %i\n", contador);
        printf("\n");
        printf ("Insira o nome do item (Sem usar a tecla espaco): ");
        scanf ("%49s", item);
        
        printf ("Insira a potencia (Watts): ");
        scanf ("%i", &potencia);
        
        printf ("Insira a quantidade desse mesmo item na instalacao: ");
        scanf ("%i", &quantidade);
        
        printf ("Quantas horas por dia esse equipamento funcionara (Digite um valor entre 1 e 24): ");
        scanf ("%f", &horasDia);
        
        printf ("Quantos dias no mes esse equipamento funcionara (Digite um valor entre 1 e 30):  ");
        scanf ("%i", &diasMes);
        
        printf("Deseja inserir outro item? (s/n): ");
        scanf(" %c", &continuar);
        
        printf("\n");
        
        contador++;
    }
    while (continuar == 's' || continuar == 'S');

    return 0;
}
