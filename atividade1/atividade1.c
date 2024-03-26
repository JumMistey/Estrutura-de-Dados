#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

   int quant_n   = argc - 1;
   int soma_n    = 0;
   float media_n = 0;
   int menor_n   = atoi(argv[1]);
   int maior_n   = atoi(argv[1]);
   int vetor_n[quant_n];

   for( int i = 1; i <= quant_n; i++){

    int n = atoi(argv[i]);
    vetor_n[i-1] = n;
    soma_n += n;

   }

   for( int i = 1; i<= quant_n ; i++){

    int n = atoi(argv[i]);
    soma_n += n;

    if(menor_n > n){
        menor_n = n;
    }

    if(n > maior_n){
        maior_n = n;
    }

   }
   
   media_n = (float) soma_n / quant_n;

   printf("Total de numeros: %d\n", quant_n);
   printf("Media dos valores: %.2f\n", media_n);
   printf("Menor numero: %d\n", menor_n);
   printf("Maior numero: %d\n", maior_n);

    for(int i = 0; i < quant_n-1; i++){
        for(int j = i; j < quant_n; j++){
            if(vetor_n[i] > vetor_n[j]){
                int aux = vetor_n[j];
                vetor_n[j] = vetor_n[i];
                vetor_n[i] = aux;
            }
        }

    }

   for(int i = 0; i < quant_n; i++){
    printf("%d", vetor_n[i]);
   }

    exit(0);
}