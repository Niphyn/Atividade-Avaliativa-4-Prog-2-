#include <stdio.h>
#include <stdlib.h>
#include "Vetor.h"

int main(){

    int qtd,tipo_vetor = 0;

    Vetor *vetor;

    printf("Informe o  tamanho do vetor a ser criado: ");
    scanf("%d",&qtd);

    vetor = criar(qtd,tipo_vetor);

    preencher(vetor);

    imprimir(vetor);

    printf("\nMedia: %.3f",calcular(vetor,'m'));

    printf("\nVariancia: %.3f",calcular(vetor,'v'));

    printf("\nDesvio Padrão: %.3f",calcular(vetor,'d'));

    liberar(vetor);

    return 0;
}