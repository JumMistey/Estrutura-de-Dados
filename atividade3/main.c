#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <nome_do_arquivo>\n", argv[0]);
        return 1;
    }

    FILE *arquivo_entrada = fopen(argv[1], "r");
    if (arquivo_entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    int numero, quantidade_numeros = 0;
    while (fscanf(arquivo_entrada, "%d", &numero) == 1) {
        quantidade_numeros++;
    }

    fseek(arquivo_entrada, 0, SEEK_SET);

    int *numeros = malloc(quantidade_numeros * sizeof(int));
    if (numeros == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    int i = 0;
    while (fscanf(arquivo_entrada, "%d", &numero) == 1) {
        numeros[i++] = numero;
    }

    fclose(arquivo_entrada);

    qsort(numeros, quantidade_numeros, sizeof(int), comparar);

    FILE *arquivo_saida = fopen("saida.txt", "w");
    if (arquivo_saida == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        free(numeros);
        return 1;
    }

    for (int j = 0; j < quantidade_numeros; j++) {
        fprintf(arquivo_saida, "%d\n", numeros[j]);
    }

    fclose(arquivo_saida);

    free(numeros);

    printf("Processo concluído. Verifique o arquivo 'saida.txt'.\n");

    return 0;
}