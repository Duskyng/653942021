// 3) Escreva uma funcao que dado um numero real passado como parametro, retorne a parte inteira e a parte fracionaria deste numero. Escreva um programa que chama esta funcao. Prototipo:

#include<stdio.h>
#include<stdlib.h>

int main() {

    float num, inteiro;
    int x = 0, aux;

    printf("Digite um numero real: ");
    scanf("%f", &num);

    aux = num - x;

    if (aux > 1) {
        x++;
    }

    inteiro = aux;
    printf("%0.f\n", inteiro);
    
    printf("%f\n", num - inteiro);

    return 0;
}
