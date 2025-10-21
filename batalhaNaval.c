#include <stdio.h>

int main() {
    // Nível Novato - Posicionamento dos Navios
    
    // Declaração do tabuleiro 10x10.
    char tabuleiro[10][10];

    // Inicializa e preenche o tabuleiro com 0
    printf("===== TABULEIRO DE BATALHA NAVAL =====\n");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = '0' ; 
        }
    }
 
    char novo_valor = '3'; //Localização dos navios

    //O primeiro número é o eixo X e o segundo o eixo Y
    tabuleiro[3][6] = novo_valor; 
    tabuleiro[3][7] = novo_valor; 
    tabuleiro[3][8] = novo_valor; 
    tabuleiro[5][4] = novo_valor;
    tabuleiro[6][4] = novo_valor;
    tabuleiro[7][4] = novo_valor;


    // Imprime o cabeçalho das colunas (A a J)
    printf("  ");
    for (int c = 0; c < 10; c++){
        printf(" %c", 'A' +c);
    }
    printf("\n");

    // Imprime o tabuleiro (linhas e conteúdo)
    for (int i = 0; i < 10; i++) {
        printf("%d ", i); // Número da linha
        for (int j = 0; j < 10; j++) {
            printf(" %c", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
