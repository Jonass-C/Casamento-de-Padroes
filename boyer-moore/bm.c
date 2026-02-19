#include <stdio.h>
#include <string.h>
#include "../benchmark/benchmark.h"

#define MAX_CHARS 256
#define MAX(a, b) ((a) > (b) ? (a) : (b)) 

void tabelaBomSufixo(char *padrao, int m, int goodSuffix[]) {
    int i, j;
    int border[m + 1];

    for (i = 0; i <= m; i++) {
        goodSuffix[i] = 0;
    }

    i = m;
    j = m + 1;
    border[i] = j;

    while (i > 0) {

        while (j <= m && padrao[i - 1] != padrao[j - 1]) {
            if (goodSuffix[j] == 0) {
                goodSuffix[j] = j - i;
            }
            j = border[j];
        }

        i--;
        j--;
        border[i] = j;
    }

    j = border[0];

    for (i = 0; i <= m; i++) {
        if (goodSuffix[i] == 0) {
            goodSuffix[i] = j;
        }
        if (i == j) {
            j = border[j];
        }
    }
}

void boyerMoore(char *texto, char *padrao) {
    int n = strlen(texto);
    int m = strlen(padrao);
    long long comparacoes = 0;

    if (m == 0 || m > n) {
        return;
    }

    int badChar[MAX_CHARS];

    for (int i = 0; i < MAX_CHARS; i++) {
        badChar[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        badChar[(unsigned char)padrao[i]] = i;
    }

    int goodSuffix[m + 1];
    tabelaBomSufixo(padrao, m, goodSuffix);

    int shift = 0;
    while (shift <= (n - m)) {
        int j = m - 1;

        while (j >= 0) {
            comparacoes++;

            if (padrao[j] != texto[shift + j]) {
                break;
            }

            j--;
        }

        if (j < 0) {
            printf("\nPadrão encontrado na posição: %d", shift);
            shift += goodSuffix[0];
        } else {
            int badShift = j - badChar[(unsigned char)texto[shift + j]];
            int goodShift = goodSuffix[j + 1];

            shift += MAX(1, MAX(badShift, goodShift));
        }
    }

    printf("\n\nComparações: %lld\n", comparacoes);
}

int main () {
    executar_testes("Boyer-Moore", boyerMoore);
}