#include <stdio.h>

int main() {
    float sensores[5][24];
    int i, j;
    float somaSensor;
    float mediaSensor;
    float maior;
    int sensorMaior;
    int horarioMaior;
    float somaGeral = 0;
    float mediaGeral;
    float limite;
    int acimaLimite = 0;

    // Receber as 120 temperaturas
    for (i = 0; i < 5; i++) {
        printf("\nSensor %d\n", i);

        for (j = 1; j <= 24; j++) {
            printf("Temperatura as %dh: ", j);
            scanf("%f", &sensores[i][j]);
        }
    }

    // Inicializa o maior valor
    maior = sensores[0][0];
    sensorMaior = 0;
    horarioMaior = 0;

    printf("\n RESULTADOS \n");

    // Percorre toda a matriz
    for (i = 0; i < 5; i++) {
        somaSensor = 0;

        for (j = 0; j < 24; j++) {
            somaSensor += sensores[i][j];
            somaGeral += sensores[i][j];

            // Verifica maior temperatura
            if (sensores[i][j] > maior) {
                maior = sensores[i][j];
                sensorMaior = i;
                horarioMaior = j;
            }
        }

        // Media do sensor
        mediaSensor = somaSensor / 24;
        printf("\nMedia do Sensor %d: %.2f C", i, mediaSensor);
    }

    // Media geral
    mediaGeral = somaGeral / 120;

    printf("\n\nMaior temperatura: %.2f C", maior);
    printf("\nSensor responsavel: %d", sensorMaior);
    printf("\nHorario: %dh", horarioMaior);
    printf("\nMedia geral: %.2f C", mediaGeral);

    printf("\n\nDigite um limite de temperatura: ");
    scanf("%f", &limite);

    // Conta temperaturas acima do limite
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 24; j++) {
            if (sensores[i][j] > limite) {
                acimaLimite++;
            }
        }
    }

    printf("\nQuantidade de leituras acima de %.2f C: %d\n",limite, acimaLimite);

    return 0;
}