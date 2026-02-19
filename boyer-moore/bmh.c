#include <limits.h>
#include <stdio.h>
#include <string.h>
#include "../benchmark/benchmark.h"

#define MAX_CHARS 256
#define MAX(a, b) ((a) > (b) ? (a) : (b))

void boyerMooreHorspool(char *texto, char *padrao) {
    int n = strlen(texto);
    int m = strlen(padrao);
    long long comparacoes = 0;

    if (m == 0 || m > n) {
        return;
    }

    int tabelaShift[MAX_CHARS];

    for (int i = 0; i < MAX_CHARS; i++) {
        tabelaShift[i] = m;
    }

    for (int i = 0; i < m - 1; i++) {
        tabelaShift[(unsigned char)padrao[i]] = m - 1 - i;
    }

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
        }

        shift += tabelaShift[(unsigned char)texto[shift + m - 1]];
    }

    printf("\n\nComparações: %lld\n", comparacoes);
}

int main () {
    executar_testes("Boyer-Moore-Horspool", boyerMooreHorspool);
}