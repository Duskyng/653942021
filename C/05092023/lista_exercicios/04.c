/*
4) Faca um programa que possua uma funcao para ler 2 notas e retorna-las por parametro (chamar uma funcao dedicada a ler 2 notas validas e que devolver os 2 numeros lidos);
• calcular a media simples e a media ponderada e retorna-las por parametro, onde a segunda nota tem peso 2 media ponderada = (n1 + n2 ∗ 2)/3;
*/

#include<stdio.h>
#include<stdlib.h>

float inputNotas(float x, float y) {

    printf("Digite a primera nota: ");
    scanf("%f", &x);
    printf("A primeira nota e: %f\n", x);
    
    printf("Digite a segunda nota: ");
    scanf("%f", &y);
    printf("A segunda nota e: %f\n", y);

    return x, y;
}

float calculoMedia(float x, float y) {

    float media;

    media = x + y;

    return media;
}

int main() {

    float nota1, nota2, media;

    nota1, nota2 = inputNotas(nota1, nota2);
    media = calculoMedia(nota1, nota2);

    printf("O valor da primeira nota e: ");
    printf("O valor da segunda nota e: ");

    return 0;
}
