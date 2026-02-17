#include <stdio.h>
#include <string.h>

#define MAX_CHARS 256
#define MAX(a, b) ((a) > (b) ? (a) : (b))

void boyerMooreHorspoolSunday(char *texto, char *padrao) {
    int n = strlen(texto);
    int m = strlen(padrao);

    if (m == 0 || m > n) {
        return;
    }

    int sundayShift[MAX_CHARS];

    for (int i = 0; i < MAX_CHARS; i++) {
        sundayShift[i] = m + 1;
    }

    for (int i = 0; i < m; i++) {
        sundayShift[(unsigned char)padrao[i]] = m - i;
    }

    int shift = 0;
    while (shift <= n - m) {
        int j = m - 1;

        while (j >= 0 && padrao[j] == texto[shift + j]) {
            j--;
        }

        if (j < 0) {
            printf("\nPadrão encontrado na posição: %d\n", shift);
        }

        if (shift + m >= n) {
            break;
        }

        shift += sundayShift[(unsigned char)texto[shift + m]];
    }
}

int main () {
    char texto[] = "ABBABAACaaaaaaaaaaaaABAABCABAC";
    char padrao[] = "ABAA";

    boyerMooreHorspoolSunday(texto, padrao);

    return 0;
}