#include <stdio.h>

// --- DEFINIÇÕES GLOBAIS ---
#define TAB_TAM 10       // Tabuleiro 10x10

// Definições para o Octaedro 3x3
#define HABILIDADE_OCT_L 3 
#define HABILIDADE_OCT_C 3 

// Definições para a Cruz 3x5
#define HABILIDADE_CRUZ_L 3 
#define HABILIDADE_CRUZ_C 5 

// Definições para o NOVO Cone 3x5
#define HABILIDADE_CONE_L 3 
#define HABILIDADE_CONE_C 5 

#define CHAR_EFEITO '5'   // CARACTERE UNIFICADO: Octaedro, Cruz e Cone usam '5'
#define CHAR_NAVIO '3'
#define CHAR_AGUA '0'

int main() {
    
    char tabuleiro[TAB_TAM][TAB_TAM];
    
    // --- 1. INICIALIZAÇÃO DO TABULEIRO ---
    for (int i = 0; i < TAB_TAM; i++) {
        for (int j = 0; j < TAB_TAM; j++) {
            tabuleiro[i][j] = CHAR_AGUA; 
        }
    }
    
    // --- 2. POSICIONAMENTO DOS NAVIOS ---
    int tamanho_diagonal = 3;
    
    // Navios Verticais, Horizontais e Diagonais
    tabuleiro[3][7] = CHAR_NAVIO; tabuleiro[3][8] = CHAR_NAVIO; tabuleiro[3][9] = CHAR_NAVIO; 
    tabuleiro[5][4] = CHAR_NAVIO; tabuleiro[6][4] = CHAR_NAVIO; tabuleiro[7][4] = CHAR_NAVIO;

    for (int k = 0; k < tamanho_diagonal; k++) {
        tabuleiro[0 + k][0 + k] = CHAR_NAVIO;
        tabuleiro[0 + k][8 - k] = CHAR_NAVIO;
    }
    
    
    // --- 3. HABILIDADE 1: OCTAEDRO (3x3) ---
    
    
    int matriz_oct[HABILIDADE_OCT_L][HABILIDADE_OCT_C];
    int centro_oct_l = HABILIDADE_OCT_L / 2; // 1
    int centro_oct_c = HABILIDADE_OCT_C / 2; // 1
    
    // Constrói a matriz OCTAEDRO (Lógica mantida)
    for (int i = 0; i < HABILIDADE_OCT_L; i++) {
        for (int j = 0; j < HABILIDADE_OCT_C; j++) {
            int diff_l = i - centro_oct_l;
            int dist_l = (diff_l < 0) ? -diff_l : diff_l; 
            int diff_c = j - centro_oct_c;
            int dist_c = (diff_c < 0) ? -diff_c : diff_c; 
            
            if (dist_l + dist_c <= centro_oct_l) { 
                matriz_oct[i][j] = 1; 
            } else {
                matriz_oct[i][j] = 0;
            }
        }
    }
    
    // Origem do Octaedro 
    int origem_oct_l = 8; 
    int origem_oct_c = 2;
    
    // Sobrepõe o Octaedro
    for (int i = 0; i < HABILIDADE_OCT_L; i++) {
        for (int j = 0; j < HABILIDADE_OCT_C; j++) {
            
            int tab_l = origem_oct_l + (i - centro_oct_l);
            int tab_c = origem_oct_c + (j - centro_oct_c);

            if (tab_l >= 0 && tab_l < TAB_TAM && tab_c >= 0 && tab_c < TAB_TAM && matriz_oct[i][j] == 1) {
                if (tabuleiro[tab_l][tab_c] != CHAR_NAVIO) {
                    tabuleiro[tab_l][tab_c] = CHAR_EFEITO;
                }
            }
        }
    }

    
    // --- 4. HABILIDADE 2: CRUZ (3x5) ---
  
    
    int matriz_cruz_grande[HABILIDADE_CRUZ_L][HABILIDADE_CRUZ_C];
    int centro_cruz_l = HABILIDADE_CRUZ_L / 2; // 1
    int centro_cruz_c = HABILIDADE_CRUZ_C / 2; // 2

    // Constrói a matriz CRUZ (Lógica mantida)
    for (int i = 0; i < HABILIDADE_CRUZ_L; i++) {
        for (int j = 0; j < HABILIDADE_CRUZ_C; j++) {
            if (i == centro_cruz_l || j == centro_cruz_c) {
                matriz_cruz_grande[i][j] = 1; 
            } else {
                matriz_cruz_grande[i][j] = 0; 
            }
        }
    }

    // Origem da Cruz 
    int origem_cruz_l = 5; 
    int origem_cruz_c = 7;
    
    // Sobrepõe a Cruz
    for (int i = 0; i < HABILIDADE_CRUZ_L; i++) {
        for (int j = 0; j < HABILIDADE_CRUZ_C; j++) {
            
            int tab_l = origem_cruz_l + (i - centro_cruz_l);
            int tab_c = origem_cruz_c + (j - centro_cruz_c);

            if (tab_l >= 0 && tab_l < TAB_TAM && tab_c >= 0 && tab_c < TAB_TAM && matriz_cruz_grande[i][j] == 1) {
                if (tabuleiro[tab_l][tab_c] != CHAR_NAVIO) {
                    tabuleiro[tab_l][tab_c] = CHAR_EFEITO; 
                }
            }
        }
    }

 
    // --- 5. HABILIDADE 3: CONE (3x5) ---
   

    int matriz_cone[HABILIDADE_CONE_L][HABILIDADE_CONE_C];
    int centro_cone_c = HABILIDADE_CONE_C / 2; // Coluna central: 2

    // Constrói a matriz CONE (3x5)
    for (int i = 0; i < HABILIDADE_CONE_L; i++) { // Linhas (0 a 2)
        for (int j = 0; j < HABILIDADE_CONE_C; j++) { // Colunas (0 a 4)
            

            int diff_c = j - centro_cone_c;
            int dist_c = (diff_c < 0) ? -diff_c : diff_c; 

            // Lógica do Cone 3x5: 
            if (dist_c <= i) { 
                matriz_cone[i][j] = 1; 
            } else {
                matriz_cone[i][j] = 0; 
            }
        }
    }

    // Origem do Cone 
    int origem_cone_l = 9;
    int origem_cone_c = 6;
    
    // Sobrepõe o Cone
    for (int i = 0; i < HABILIDADE_CONE_L; i++) {
        for (int j = 0; j < HABILIDADE_CONE_C; j++) {
            
            int tab_l = origem_cone_l + (i - centro_cone_c); // Note que o cone é 3x5, o centro usado é 2
            int tab_c = origem_cone_c + (j - centro_cone_c);

            if (tab_l >= 0 && tab_l < TAB_TAM && tab_c >= 0 && tab_c < TAB_TAM && matriz_cone[i][j] == 1) {
                if (tabuleiro[tab_l][tab_c] != CHAR_NAVIO) {
                    tabuleiro[tab_l][tab_c] = CHAR_EFEITO; 
                }
            }
        }
    }


    // --- 6. EXIBIÇÃO DO TABULEIRO ---
    printf("\n===== TABULEIRO COMPLETO =====\n");
    
    // Imprime o cabeçalho das colunas (A a J)
    printf("  ");
    for (int c = 0; c < TAB_TAM; c++){
        printf(" %c", 'A' + c);
    }
    printf("\n");

    // Imprime o tabuleiro
    for (int i = 0; i < TAB_TAM; i++) {
        printf("%d ", i); 
        for (int j = 0; j < TAB_TAM; j++) {
            printf(" %c", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}