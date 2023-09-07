//Faca um programa que leia dois valores inteiros e chame uma funcao que receba estes 2 valores de entrada e retorne o maior valor na primeira variavel e o menor valor na segunda variavel. Escreva o conteudo das 2 variaveis na tela.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void maiormenor(int num1, int num2) {

    int maior, menor;

    if (num1 > num2) {
        maior = num1;
        menor = num2;
    } else {
        maior = num2;
        menor = num1;
    }

    printf("O maior valor é: %d\n", maior);
    printf("O menor valor é: %d\n", menor);

}

int main() {

    int x, y;

    printf("Digite o primeiro numero: ");
    scanf("%i", &x);
    printf("Digite o segundo numero: ");
    scanf("%i", &y);

    maiormenor(x,y);

    return 0;
}
