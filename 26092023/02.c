#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {

    int matriz1[4][4];
    int matriz2[4][4];
    int matriz3[4][4];
    int x, y, z;
    
    for (x = 0; x < 4; x++) {
        for (y = 0; y < 4; y++) {
            printf("Digite numeros para preencher a primeira matriz: ");
            scanf("%d",&matriz1[x][y]);
        }
    }   

    for (x = 0; x < 4; x++) {
        for (y = 0; y < 4; y++) {
            printf("Digite numeros para preencher a segunda matriz: ");
            scanf("%d",&matriz2[x][y]);
        }
    }   

    for (x = 0; x < 4; x++) {
        for (y = 0; y < 4; y++) {
            matriz3[x][y] = 0;
            for (z = 0; z < 4; z++) {
                matriz3[x][y] += matriz1[x][z] * matriz2[z][y];
            }
        }
    }

    printf("\n");  
    printf("---------MATRIZ 1---------");
    for (x = 0; x < 4; x++) {
        printf("\n");  
        for (y = 0; y < 4; y++) {
            printf("%d |", matriz1[x][y]);
        }
    }


    printf("\n");  
    printf("---------MATRIZ 2---------");
    for (x = 0; x < 4; x++) {
        printf("\n");  
        for (y = 0; y < 4; y++) {
            printf("%d |", matriz2[x][y]);
        }
    }

    printf("\n");  
    printf("---------MATRIZ 3---------");
    for (x = 0; x < 4; x++) {
        printf("\n");  
        for (y = 0; y < 4; y++) {
            printf("%d |", matriz3[x][y]);
        }
    }

    printf("\n");  

    return 0;
}
