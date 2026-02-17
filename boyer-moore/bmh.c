#include <stdio.h>
#include <string.h>

#define MAX_CHARS 256
#define MAX(a, b) ((a) > (b) ? (a) : (b))

void boyerMooreHorspool(char *texto, char *padrao) {
    int n = strlen(texto);
    int m = strlen(padrao);

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

        while (j >= 0 && padrao[j] == texto[shift + j]) {
            j--;
        }

        if (j < 0) {
            printf("\nPadrão encontrado na posição: %d\n", shift);
        }

        shift += tabelaShift[(unsigned char)texto[shift + m - 1]];
    }
}

int main () {
    char texto[] = "ABBABAACaaaaaaaaaaaaABAABCABAC";
    char padrao[] = "ABAA";

    boyerMooreHorspool(texto, padrao);

    return 0;
}