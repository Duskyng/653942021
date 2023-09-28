#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {

    int vetor1[10];
    int vetor2[10];
    int vetor3[20];
    int x;

    for (x = 0; x < 10; x++) {
        printf("Digite um numero para preencher o primeiro vetor: ");
        scanf("%d",&vetor1[x]);
    }
    
    for (x = 0; x < 10; x++) {
        printf("Digite um numero para preencher o segundo vetor: ");
        scanf("%d",&vetor2[x]);
    }

    for (x = 0; x < 10; x++) {
        vetor3[x] = vetor1[x];
    }


    for (x = 0; x < 10; x++) {
        vetor3[10 + x] = vetor2[x];
    }

    printf("Vetor 1");
    printf("\n");
    for (x = 0; x < 10; x++) {
        printf("| %d |", vetor1[x]);
    }
    
    printf("\n");    

    printf("Vetor 2");    
    printf("\n");
    for (x = 0; x < 10; x++) {
        printf("| %d |", vetor2[x]);
    }

    printf("\n");    

    printf("Vetor 3");
    printf("\n");
    for (x = 0; x < 20; x++) {
        printf("| %d |", vetor3[x]);
    }

    printf("\n");    

    return 0;

}
