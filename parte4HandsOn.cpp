#include <stdio.h>

int main() {
    float temperatura[10];
    float soma = 0;
    float media;
    float maior, menor;
    int indiceMaior, indiceMenor;
    int acimaMedia = 0;
    int i;

    // Receber as 10 temperaturas
    for (i = 1; i <= 10; i++) {
        printf("Digite a temperatura %d: ", i);
        scanf("%f", &temperatura[i]);
    }

    // Inicializa maior e menor
    maior = temperatura[0];
    menor = temperatura[0];
    indiceMaior = 0;
    indiceMenor = 0;

    for (i = 0; i < 10; i++) {
        printf("\nIndice %d: %.1f", i, temperatura[i]);
        soma += temperatura[i];

        if (temperatura[i] > maior) {
            maior = temperatura[i];
            indiceMaior = i;
        }

        if (temperatura[i] < menor) {
            menor = temperatura[i];
            indiceMenor = i;
        }
    }

    // Calcula a média
    media = soma / 10;

    // Conta valores acima da média
    for (i = 0; i < 10; i++) {
        if (temperatura[i] > media) {
            acimaMedia++;
        }
    }

    printf("\n\nMedia: %.2f", media);
    printf("\nMaior temperatura: %.2f", maior);
    printf("\nIndice do maior: %d", indiceMaior);
    printf("\nMenor temperatura: %.2f", menor);
    printf("\nIndice do menor: %d", indiceMenor);
    printf("\nValores acima da media: %d", acimaMedia);

    printf("\n\nOperacoes de percurso: aproximadamente 30");

    return 0;
}