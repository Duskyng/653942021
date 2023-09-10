//Considere a seguinte declaracao: int A, *B, **C, ***D; Escreva um programa que leia a variavel a e calcule e exiba o dobro, o triplo e o quadruplo desse valor utilizando apenas os ponteiros B, C e D. O ponteiro B deve ser usada para calcular o dobro, C o triplo e D o quadruplo.

#include<stdio.h>
#include<stdlib.h>

int main() {

    int A = 0, *B = &A, **C = &B, ***D = &C;

    printf("Digite um valor para \"A\": ");
    scanf("%i", &A);

    printf("O dobro de \"A\" e %d\n", (*B * 2));
    printf("O triplo de \"A\" e %d\n", (**C * 3));
    printf("O quadruplo de \"A\" e %d\n", (***D * 4));

    return 0;

}
