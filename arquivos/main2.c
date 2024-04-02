#include <stdio.h>
#include <stdlib.h>

int main(int arc, char*argv[]){

    char txt[100];
    FILE *arq_txt;

    arq_txt = fopen("arq.txt", "r");
 
    if(arq_txt == NULL){
        printf("Erro ao abrir arquivo");
        exit(1);
    }

    while(fscanf(arq_txt, "%[^\n]\n", &txt) != EOF){
        printf("%s\n", txt);
    }

    fscanf(arq_txt, "%s", &txt);

    printf("txt = %s", txt);

    fclose(arq_txt);

    exit(0);
}