#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

No* no(char valor, No* proximo_no){
    No* no = malloc(sizeof(No));
    no->valor = valor;
    no->proximo_no = proximo_no;
    return no;
}

void inserir_no(No* H, No* no){
    if(H != NULL){
        if(H->proximo_no == NULL){
            H->proximo_no = no;
        }
        else{
            inserir_no(H->proximo_no, no);
        }
    }
}

void imprimir_lista(No* H){
    if(H != NULL){
        printf("%c", H->valor);
        imprimir_lista(H->proximo_no);
    }
}

No* copiar_lista(No* H){
    if(H != NULL){
        return no(H->valor,listar_copiar(H->proximo_no));
    }
    return NULL;
}