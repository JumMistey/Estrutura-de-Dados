#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

int main(int argc, char* argv[]){

    No* H = no('A', NULL);
    No* n2 = no('B', NULL);
    No* n3 = no('C', NULL);
    No* n4 = no('D', NULL);
    No* n5 = no('E', NULL);
    
    //No* H = no('A', no('B', no('C', no('D'))))

    No* Hc = listar_copiar(H);

    H->proximo_no->valor = 'X';
    Hc->valor = 'U';

    inserir_no(H, n2);
    inserir_no(H, n3);
    inserir_no(H, n4);
    inserir_no(H, n5);

    imprimir_lista(H);
    imprimir_lista(Hc);

    exit(0);
}