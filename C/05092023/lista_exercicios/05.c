//5) Crie um programa que contenha um array de float contendo 10 elementos. Imprima o enderec¸o de cada posicao desse array.

#include <stdio.h>

int main() {
    float array[10];

    // Solicite ao usuário inserir valores no array
    for (int x = 0; x < 10; x++) {
        printf("Digite um valor para a posição %d: ", x);
        scanf("%f", &array[x]);
    }

    // Imprima os endereços de cada posição do array
    for (int x = 0; x < 10; x++) {
        printf("Endereço do elemento %d: %p\n", x, (void *)&array[x]);
    }

    return 0;
}
