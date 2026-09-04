#include <stdio.h>

// Selection Sort

void selectionSort(int vetor[], int qtd,long long &comparacoes,long long &trocas) {

    int aux;

    for (int i = 0; i < qtd - 1; i++) {

        for (int j = i + 1; j < qtd; j++) {

            comparacoes++;

            if (vetor[j] < vetor[i]) {

                aux = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = aux;

                trocas++;
            }
        }
    }
}


// Insertion Sort

void insertionSort(int vetor[], int qtd,long long &comparacoes,long long &movimentacoes) {

    int aux;
    int j;

    for (int i = 1; i < qtd; i++) {

        aux = vetor[i];
        j = i - 1;

        while (j >= 0) {

            comparacoes++;

            if (aux < vetor[j]) {

                vetor[j + 1] = vetor[j];
                movimentacoes++;

                j--;
            }
            else {
                break;
            }
        }

        vetor[j + 1] = aux;
    }
}


// Copia um vetor para outro

void copiarArray(int origem[], int destino[], int qtd) {

    for (int i = 0; i < qtd; i++) {
        destino[i] = origem[i];
    }
}


int main() {

    // Vetores usados nos testes

    int array10[10] = {
        42, 7, 89, 15, 3,
        64, 28, 91, 11, 50
    };

    int array20[20] = {
        73, 12, 45, 8, 91,
        34, 67, 23, 5, 88,
        16, 52, 39, 77, 2,
        61, 29, 94, 10, 48
    };

    int array1000[1000];

    // Gera os valores do vetor de 1000

    for (int i = 0; i < 1000; i++) {
        array1000[i] = (i * 37 + 17) % 10000;
    }


    // Teste com 10 elementos

    int vetor10Selection[10];
    int vetor10Insertion[10];

    copiarArray(array10, vetor10Selection, 10);
    copiarArray(array10, vetor10Insertion, 10);

    long long selectionComp10 = 0;
    long long selectionTrocas10 = 0;

    long long insertionComp10 = 0;
    long long insertionMov10 = 0;

    selectionSort(
        vetor10Selection,
        10,
        selectionComp10,
        selectionTrocas10
    );

    insertionSort(
        vetor10Insertion,
        10,
        insertionComp10,
        insertionMov10
    );


    // Teste com 20 elementos

    int vetor20Selection[20];
    int vetor20Insertion[20];

    copiarArray(array20, vetor20Selection, 20);
    copiarArray(array20, vetor20Insertion, 20);

    long long selectionComp20 = 0;
    long long selectionTrocas20 = 0;

    long long insertionComp20 = 0;
    long long insertionMov20 = 0;

    selectionSort(
        vetor20Selection,
        20,
        selectionComp20,
        selectionTrocas20
    );

    insertionSort(
        vetor20Insertion,
        20,
        insertionComp20,
        insertionMov20
    );


    // Teste com 1000 elementos

    int vetor1000Selection[1000];
    int vetor1000Insertion[1000];

    copiarArray(array1000, vetor1000Selection, 1000);
    copiarArray(array1000, vetor1000Insertion, 1000);

    long long selectionComp1000 = 0;
    long long selectionTrocas1000 = 0;

    long long insertionComp1000 = 0;
    long long insertionMov1000 = 0;

    selectionSort(
        vetor1000Selection,
        1000,
        selectionComp1000,
        selectionTrocas1000
    );

    insertionSort(
        vetor1000Insertion,
        1000,
        insertionComp1000,
        insertionMov1000
    );


    // Resultados

    printf("\n");
    printf("                    RESULTADOS DOS TESTES\n");

    printf("\n");
    printf("Array 10 elementos:\n");

    printf("Selection Sort - Comparacoes:      %lld\n", selectionComp10);
    printf("Selection Sort - Trocas:           %lld\n", selectionTrocas10);

    printf("Insertion Sort - Comparacoes:      %lld\n", insertionComp10);
    printf("Insertion Sort - Movimentacoes:    %lld\n", insertionMov10);


    printf("\n");
    printf("Array 20 elementos:\n");

    printf("Selection Sort - Comparacoes:      %lld\n", selectionComp20);
    printf("Selection Sort - Trocas:           %lld\n", selectionTrocas20);

    printf("Insertion Sort - Comparacoes:      %lld\n", insertionComp20);
    printf("Insertion Sort - Movimentacoes:    %lld\n", insertionMov20);


    printf("\n");
    printf("Array 1000 elementos:\n");

    printf("Selection Sort - Comparacoes:      %lld\n", selectionComp1000);
    printf("Selection Sort - Trocas:           %lld\n", selectionTrocas1000);

    printf("Insertion Sort - Comparacoes:      %lld\n", insertionComp1000);
    printf("Insertion Sort - Movimentacoes:    %lld\n", insertionMov1000);

    return 0;
}