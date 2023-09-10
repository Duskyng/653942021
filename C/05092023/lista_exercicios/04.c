/*
4) Faca um programa que possua uma funcao para ler 2 notas e retorna-las por parametro (chamar uma funcao dedicada a ler 2 notas validas e que devolver os 2 numeros lidos);
• calcular a media simples e a media ponderada e retorna-las por parametro, onde a segunda nota tem peso 2 media ponderada = (n1 + n2 ∗ 2)/3;
*/

#include<stdio.h>
#include<stdlib.h>

void inputNotas(float *nota1, float *nota2) {

    printf("Digite a primera nota: ");
    scanf("%f", nota1);
    
    printf("Digite a segunda nota: ");
    scanf("%f", nota2);

}

void calculoMedia(float *nota1, float *nota2, float *mediaSimples, float *mediaPonderada) {

    *mediaSimples = (*nota1 + *nota2) / 2;
    *mediaPonderada = (*nota1 + *nota2 * 2)/3;

}

int main() {

    float nota1, nota2, mediaSimples, mediaPonderada;

    inputNotas(&nota1, &nota2);
    calculoMedia(&nota1, &nota2, &mediaSimples, &mediaPonderada);

    printf("O valor da primeira nota e: %.2f\n", nota1);
    printf("O valor da segunda nota e: %.2f\n", nota2);

    printf("A media simples e: %.2f\n", mediaSimples );
    printf("A media ponderada e: %.2f\n", mediaPonderada);

    return 0;
}
