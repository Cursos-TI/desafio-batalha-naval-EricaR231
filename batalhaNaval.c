#include <stdio.h>
#include <stdlib.h>

#define TAM 10

// ---------- Função para imprimir tabuleiro ----------
void imprimir_tabuleiro(int t[TAM][TAM], char letras[]) {

    printf("\n      ");
    for (int i = 0; i < TAM; i++)
        printf(" %c ", letras[i]);
    printf("\n");

    printf("    -----------------------------------------\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d | ", i);
        for (int j = 0; j < TAM; j++)
            printf("%2d ", t[i][j]);
        printf("\n");
    }
}


// ---------- Função para copiar navios para a matriz ----------
void copiar_navios(int destino[TAM][TAM], int origem[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            destino[i][j] = origem[i][j];
}


int main() {

    char letras[10] = {'A','B','C','D','E','F','G','H','I','J'};

    int tabuleiroNavios[TAM][TAM] = {0};  // posição fixa dos navios

    // ----------------- POSICIONAR NAVIOS -----------------
    int navio1[3] = {3,3,3};
    int navio2[3] = {3,3,3};
    int navio3[3] = {3,3,3};
    int navio4[3] = {3,3,3};

    // Navio horizontal
    for (int i = 0; i < 3; i++)
        tabuleiroNavios[2][4 + i] = navio1[i];

    // Navio vertical
    for (int i = 0; i < 3; i++)
        tabuleiroNavios[5 + i][7] = navio2[i];

    // Diagonais
    for (int i = 0; i < 3; i++) {
        tabuleiroNavios[3 - i][2 - i] = navio3[i];
        tabuleiroNavios[9 - i][7 - i] = navio4[i];
    }

    // ------------------------------------------------------

    int escolha;

    do {

        printf("\nEscolha uma habilidade:\n");
        printf("1 - Cone\n");
        printf("2 - Cruz\n");
        printf("3 - Octaedro\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &escolha);

        if (escolha == 0) break;

        // Cria um tabuleiro novo com navios
        int T[TAM][TAM];
        copiar_navios(T, tabuleiroNavios);

        int centroL = 7;
        int centroC = 2;

        // ------------------------ CONE ------------------------
        if (escolha == 1) {
            printf("\n>>> Habilidade CONE selecionada!\n");

            for (int i = 0; i < 3; i++) {

                int L = centroL + i;

                if (i == 0) {
                    T[L][centroC] = 5;
                }
                else if (i == 1) {
                    T[L][centroC] = 5;
                    T[L][centroC - 1] = 5;
                    T[L][centroC + 1] = 5;
                }
                else if (i == 2) {
                    for (int c = centroC - 2; c <= centroC + 2; c++)
                        T[L][c] = 5;
                }
            }
        }

        // ------------------------ CRUZ ------------------------
        else if (escolha == 2) {
            printf("\n>>> Habilidade CRUZ selecionada!\n");

            for (int i = -2; i <= 2; i++) {

                int L = centroL + i;
                int C = centroC + i;

                // vertical
                if (centroL + i >= 0 && centroL + i < 10)
                    T[centroL + i][centroC] = 5;

                // horizontal
                if (centroC + i >= 0 && centroC + i < 10)
                    T[centroL][centroC + i] = 5;
            }
        }

        // ------------------------ OCTAEDRO ------------------------
        else if (escolha == 3) {
            printf("\n>>> Habilidade OCTAEDRO selecionada!\n");

            for (int i = -2; i <= 2; i++) {
                for (int j = -2; j <= 2; j++) {

                    if (abs(i) + abs(j) <= 2) {

                        int L = centroL + i;
                        int C = centroC + j;

                        if (L >= 0 && L < TAM && C >= 0 && C < TAM)
                            T[L][C] = 5;
                    }
                }
            }
        }

        // Imprime tabuleiro resultante
        imprimir_tabuleiro(T, letras);

    } while (escolha != 0);

    printf("\nSaindo...\n");
    return 0;
}
