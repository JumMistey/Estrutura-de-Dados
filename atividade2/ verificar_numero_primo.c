#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    int num = atoi(argv[1]);

    if(num <= 1){
        printf("false");
        exit(0);
    }

    if((num != 2) && (num % 2 == 0)){
        printf("false");
        exit(0);
    }

    for(int i = 3; i < num; i += 2){
        if(num % i == 0){
            printf("false");
            exit(0);
        }
    }
    
    printf("true");

    exit(0);
}

