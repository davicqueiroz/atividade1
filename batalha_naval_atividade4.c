#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void inicializarTabuleiro(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = '~';  // '~' representa água
        }
    }
}

void exibirTabuleiro(char tabuleiro[TAM][TAM]) {
    printf("\n  ");
    for (int j = 0; j < TAM; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAM; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void habilidadeCruz(char tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM)
        tabuleiro[linha][coluna] = 'X';

    if (linha - 1 >= 0)
        tabuleiro[linha - 1][coluna] = 'X';
    if (linha + 1 < TAM)
        tabuleiro[linha + 1][coluna] = 'X';
    if (coluna - 1 >= 0)
        tabuleiro[linha][coluna - 1] = 'X';
    if (coluna + 1 < TAM)
        tabuleiro[linha][coluna + 1] = 'X';
}

void habilidadeOctaedro(char tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = linha - 1; i <= linha + 1; i++) {
        for (int j = coluna - 1; j <= coluna + 1; j++) {
            if (i >= 0 && i < TAM && j >= 0 && j < TAM) {
                tabuleiro[i][j] = 'O';
            }
        }
    }
}

void habilidadeCone(char tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = linha; i >= 0; i--) {  // Vai para cima
        tabuleiro[i][coluna] = 'C';
    }
}

int main() {
    char tabuleiro[TAM][TAM];
    int escolha, linha, coluna;
    char continuar;

    inicializarTabuleiro(tabuleiro);

    do {
        exibirTabuleiro(tabuleiro);

        printf("\nEscolha uma habilidade para aplicar:\n");
        printf("1 - Habilidade Cruz (+)\n");
        printf("2 - Habilidade Octaedro (3x3)\n");
        printf("3 - Habilidade Cone (linha reta para cima)\n");
        printf("Digite sua escolha (1-3): ");
        scanf("%d", &escolha);

        printf("Digite a linha (0 a %d): ", TAM - 1);
        scanf("%d", &linha);
        printf("Digite a coluna (0 a %d): ", TAM - 1);
        scanf("%d", &coluna);

        if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM) {
            printf("Posição inválida! Tente novamente.\n");
            continue;
        }

        switch (escolha) {
            case 1:
                habilidadeCruz(tabuleiro, linha, coluna);
                break;
            case 2:
                habilidadeOctaedro(tabuleiro, linha, coluna);
                break;
            case 3:
                habilidadeCone(tabuleiro, linha, coluna);
                break;
            default:
                printf("Escolha inválida!\n");
                continue;
        }

        printf("\nDeseja aplicar outra habilidade? (S/N): ");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');

    printf("\nTabuleiro final:\n");
    exibirTabuleiro(tabuleiro);

    printf("\nObrigado por jogar!\n");

    return 0;
}
