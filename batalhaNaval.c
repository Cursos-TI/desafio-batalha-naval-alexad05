#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5 // Tamanho das matrizes de habilidade

int main() {
    // Inicializa o tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas do navio horizontal (linha, coluna)
    int navio_horizontal_linha = 2;
    int navio_horizontal_coluna = 3;

    // Coordenadas do navio vertical (linha, coluna)
    int navio_vertical_linha = 5;
    int navio_vertical_coluna = 1;

    // Coordenadas do navio diagonal 1 (linha, coluna)
    int navio_diagonal1_linha = 0;
    int navio_diagonal1_coluna = 0;

    // Coordenadas do navio diagonal 2 (linha, coluna)
    int navio_diagonal2_linha = 0;
    int navio_diagonal2_coluna = TAMANHO_TABULEIRO - 1;

    // Posiciona o navio horizontal no tabuleiro (valor 3)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio_horizontal_linha][navio_horizontal_coluna + i] = 3;
    }

    // Posiciona o navio vertical no tabuleiro (valor 3)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio_vertical_linha + i][navio_vertical_coluna] = 3;
    }

    // Posiciona o navio diagonal 1 no tabuleiro (valor 3)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio_diagonal1_linha + i][navio_diagonal1_coluna + i] = 3;
    }

    // Posiciona o navio diagonal 2 no tabuleiro (valor 3)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio_diagonal2_linha + i][navio_diagonal2_coluna - i] = 3;
    }

    // Matriz de habilidade Cone
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    // Matriz de habilidade Cruz
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    // Matriz de habilidade Octaedro
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Ponto de origem das habilidades no tabuleiro
    int cone_linha = 1;
    int cone_coluna = 1;

    int cruz_linha = 7;
    int cruz_coluna = 4;

    int octaedro_linha = 4;
    int octaedro_coluna = 7;

    // Aplica a habilidade Cone no tabuleiro
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (cone[i][j] == 1) {
                int tabuleiro_linha = cone_linha + i - TAMANHO_HABILIDADE / 2;
                int tabuleiro_coluna = cone_coluna + j - TAMANHO_HABILIDADE / 2;

                if (tabuleiro_linha >= 0 && tabuleiro_linha < TAMANHO_TABULEIRO && tabuleiro_coluna >= 0 && tabuleiro_coluna < TAMANHO_TABULEIRO) {
                    tabuleiro[tabuleiro_linha][tabuleiro_coluna] = 5;
                }
            }
        }
    }
    // Aplica a habilidade Cruz no tabuleiro
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (cruz[i][j] == 1) {
                int tabuleiro_linha = cruz_linha + i - TAMANHO_HABILIDADE / 2;
                int tabuleiro_coluna = cruz_coluna + j - TAMANHO_HABILIDADE / 2;

                if (tabuleiro_linha >= 0 && tabuleiro_linha < TAMANHO_TABULEIRO && tabuleiro_coluna >= 0 && tabuleiro_coluna < TAMANHO_TABULEIRO) {
                    tabuleiro[tabuleiro_linha][tabuleiro_coluna] = 5;
                }
            }
        }
    }
    // Aplica a habilidade Octaedro no tabuleiro
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (octaedro[i][j] == 1) {
                int tabuleiro_linha = octaedro_linha + i - TAMANHO_HABILIDADE / 2;
                int tabuleiro_coluna = octaedro_coluna + j - TAMANHO_HABILIDADE / 2;

                if (tabuleiro_linha >= 0 && tabuleiro_linha < TAMANHO_TABULEIRO && tabuleiro_coluna >= 0 && tabuleiro_coluna < TAMANHO_TABULEIRO) {
                    tabuleiro[tabuleiro_linha][tabuleiro_coluna] = 5;
                }
            }
        }
    }

    // Exibe o tabuleiro no console
    printf("Tabuleiro da Batalha Naval com Habilidades:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}