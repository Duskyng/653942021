//Considere a seguinte declaracao: int A, *B, **C, ***D; Escreva um programa que leia a variavel a e calcule e exiba o dobro, o triplo e o quadruplo desse valor utilizando apenas os ponteiros B, C e D. O ponteiro B deve ser usada para calcular o dobro, C o triplo e D o quadruplo.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {

    int A;
    int *B, **C, ***D;

    printf("Digite um valor para \"A\": ");
    scanf("%i", &A);

    *B = A;
    **C = *B;
    ***D = **C;

    printf("%d\n", *B);
    printf("%d\n", *C);
    printf("%d\n", *D);

    return 0;

}