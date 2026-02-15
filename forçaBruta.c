#include <stdio.h>
#include <string.h>

void forcaBruta(char *texto, char *padrao) {
    int n = strlen(texto);
    int m = strlen(padrao);

    if (m == 0 || m > n) {
        return;
    }

    for (int i = 0; i <= n - m; i++) {
        int j;

        for (j = 0; j < m; j++) {
            if (texto[i + j] != padrao[j]) {
                break;
            }
        }

        if (j == m) {
            printf("\nPadrão encontrado na posição %d\n", i);
        }
    }
}

int main () {
    char texto[] = "ABBABAACaaaaaaaaaaaaABAABCABAC";
    char padrao[] = "ABAA";

    forcaBruta(texto, padrao);

    return 0;
}