#include <stdio.h>

int main() {
    
    char tabuleiro[10][10];
    char navio_char = '3'; // Caractere usado para marcar todas as partes do navio

    printf("===== TABULEIRO DE BATALHA NAVAL =====\n");

    // Inicializa o tabuleiro com o caractere '0'
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = '0' ; 
        }
    }
    
    // --- POSICIONAMENTO 1: Navio Horizontal (3, G-I) ---
    tabuleiro[3][6] = navio_char; 
    tabuleiro[3][7] = navio_char; 
    tabuleiro[3][8] = navio_char; 
    
    // --- POSICIONAMENTO 2: Navio Vertical (D, 5-7) ---
    tabuleiro[5][4] = navio_char;
    tabuleiro[6][4] = navio_char;
    tabuleiro[7][4] = navio_char;

    // --- POSICIONAMENTO 3: Navio Diagonal Padrão (A0, B1, C2) ---
    int tamanho_diagonal = 3;
    int linha_inicial_diag1 = 0;   // Linha 0
    int coluna_inicial_diag1 = 0;  // Coluna A

    for (int k = 0; k < tamanho_diagonal; k++) {
        int linha = linha_inicial_diag1 + k;
        int coluna = coluna_inicial_diag1 + k;
        tabuleiro[linha][coluna] = navio_char;
    }
    
    // --- POSICIONAMENTO 4 NOVO: Navio Diagonal Contrária (I0, H1, G2) ---
    // A linha aumenta (0 -> 2), mas a coluna DIMINUI (8 -> 6)
    int linha_inicial_diag2 = 0;   // Linha 0
    int coluna_inicial_diag2 = 8;  // Coluna I

    for (int k = 0; k < tamanho_diagonal; k++) {
        int linha = linha_inicial_diag2 + k; // Linha: 0, 1, 2
        int coluna = coluna_inicial_diag2 - k; // Coluna: 8, 7, 6
        
        // Posiciona o navio
        tabuleiro[linha][coluna] = navio_char;
    }
    // -------------------------------------------------------------------

    // Imprime o cabeçalho das colunas (A a J)
    printf("  ");
    for (int c = 0; c < 10; c++){
        printf(" %c", 'A' + c);
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
