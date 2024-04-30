#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    float y;
} Ponto*

int main(int argc, char* argv[]){
    if (argc != 2){
        printf("Uso: %s dados.csv\n", argv[0]);
        return 1;
    }

    FILE *arquivo = fopen(argv[1], "r");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    int num_registros = 0;
    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo) != NULL){
        num_registros++;
    }

    rewind(arquivo);

    Ponto *pontos = malloc(num_registros * sizeof(Ponto));
    if(pontos == NULL){
        printf("Erro de alocação de memória.\n");
        fclose(arquivo);
        return 1;
    }

    for(int i = 0; i < num_registros; i++){
        fscanf(arquivo, "%d,%f", &pontos[i].x, &pontos[i].y);
    }

    float media_x = 0;
    float media_y = 0;

    for(int i = 0; i < num_registros; i++){
         media_x += pontos[i].x;
         media_y += pontos[i].y;
    }
    media_x /= num_registros;
    media_y /= num_registros;

    float soma_numerador = 0;
    float soma_denominador = 0;
    for(int i = 0; i < num_registros; i++){
         soma_numerador += (pontos[i].x - media_x) * (pontos[i].y - media_y);
         soma_denominador += (pontos[i].x - media_x) * (pontos[i].x - media_x);
    }

    float inclinacao = soma_numerador / soma_denominador;
    float intercepcao = media_y - inclinacao * media_x;

    printf("y = %.2fx + %.2f\n", inclinacao, intercepcao);

    free(pontos);

    fclose(arquivo);

    return 0;

}