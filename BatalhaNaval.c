#include <stdio.h>

int main() {
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < 10; i++) 
    {
        for (int j = 0; j < 10; j++) 
        {
            tabuleiro[i][j] = 0;
        }
    }

    // --- POSICIONAMENTO DOS 4 NAVIOS (3 CASAS CADA) ---

    // 1. VERTICAL (Coluna A, Linhas 1 a 3)
    for (int i = 0; i < 3; i++) 
    {
        tabuleiro[i][0] = 3;
    }

    // 2. HORIZONTAL (Coluna J, colunas J a H)
    for (int i = 7; i < 10; i++) 
    {
        tabuleiro[0][i] = 3;
    }

    // 3. DIAGONAL (Começa na Linha 2, Coluna D)
    for (int j = 0; j < 3; j++) 
    {
        tabuleiro[1 + j][3 + j] = 3; // Ocupa [1][3], [2][4], [3][5]
    }

    // 4. DIAGONAL (Começa na Linha 7, Coluna B)
    for (int j = 0; j < 3; j++) 
    {
        tabuleiro[6 + j][1 + j] = 3; // Ocupa [6][1], [7][2], [8][3]
    }
    // 5. DIAGONAL INVERTIDA  (Sobe para a direita)
    // Começa na Linha 9, Coluna E. O 'i' diminui enquanto o 'j' aumenta.
    for (int j = 0; j < 3; j++) 
    {
        tabuleiro[8 - j][4 + j] = 3; 
    }

    // --- IMPRESSÃO ---
    printf("\n   --BATALHA NAVAL-- ATUALIZAÇÃO \n\n   ");
    for (int j = 0; j < 10; j++) 
    {
        printf("%c ", linha[j]);
    }
    printf("\n");

    for (int i = 0; i < 10; i++) 
    {
        printf("%2d ", i + 1);
        for (int j = 0; j < 10; j++) 
        {
            if (tabuleiro[i][j] == 3) 
            {
                printf("3 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }

    return 0;
}
