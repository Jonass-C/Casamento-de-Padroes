#include <stdio.h>
#include <string.h>

void arrayLPS (char *padrao, int *lps) {
    int m = strlen(padrao);

    if (m == 0) {
        return;
    }

    lps[0] = 0;
    int j = 0;
    int i = 1;

    while (i < m) {
        if (padrao[i] == padrao[j]) {
            j++;
            lps[i] = j;
            i++;
        }
        else {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmp (char *texto, char *padrao) {
    int n = strlen(texto);
    int m = strlen(padrao);

    if (m == 0 || m > n) {
        return;
    }

    int lps[m];
    arrayLPS(padrao, lps);

    int i = 0;
    int j = 0;

    while (i < n) {
        if (padrao[j] == texto[i]) {
            i++;
            j++;
        }

        if (j == m) {
            printf("\nPadrão encontrado na posição: %d\n", i - j);
            j = lps[j - 1];
        }
        else if (i < n && padrao[j] != texto[i]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }
}

int main () {
    char texto[] = "ABABDABACDABABCABAB";
    char padrao[] = "ABABCABAB";

    kmp(texto, padrao);

    return 0;
}