#include <stdio.h>

int main(){

    char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10] = {0};

   // --- POSICIONAR NAVIOS ---
    int navio1[3]; // navio horizontal
    int navio2[3]; // navio vertical
    int navio3[3]; // navio diagonal
    int navio4[3]; // navio diagonal

    // Coordenadas iniciais
    int linha1 = 2; // linha do navio horizontal
    int col1 = 4;

    int linha2 = 5; // linha do navio vertical
    int col2 = 7;

    int linha3 = 3; // linha do navio diagonal principal
    int col3 = 2;

    int linha4 = 7; // linha navio diagonal secundária
    int col4 = 5;

    // Preenche os vetores com valor 3 (parte do navio)
    for (int i = 0; i < 3; i++) {
        navio1[i] = 3;
        navio2[i] = 3;
        navio3[i] = 3;
        navio4[i] = 3;
    }

    // Posiciona o navio 1 na horizontal no tabuleiro
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha1][col1 + i] = navio1[i];
    }

    // Posiciona o navio 2 na vertical no tabuleiro
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha2 + i][col2] = navio2[i];
    }

    // Posiciona o navio 3 e 4 na diagonal no tabuleiro
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha3 - i][col3 - i] = navio3[i];
        tabuleiro[linha4 - i][col4 - i] = navio4[i];

    }

    // --- EXIBE O TABULEIRO ---
    printf("## Tabuleiro de Batalha Naval! ##\n\n");

    // Cabeçalho das colunas com letras
    printf("     ");
    for (int j = 0; j < 10; j++) {
        printf(" %c ", letras[j]);
    }
    printf("\n");

    // Linha separadora
    printf("   -----------------------------------------\n");

    // Linhas do tabuleiro com números (0–9)
    for (int i = 0; i < 10; i++) {
        printf("%2d | ", i); // número da linha
        for (int j = 0; j < 10; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}