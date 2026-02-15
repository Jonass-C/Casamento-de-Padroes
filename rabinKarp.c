#include <stdio.h>
#include <string.h>

#define BASE 256
#define MOD 101

void rabinKarp(char *texto, char *padrao) {
    int n = strlen(texto);
    int m = strlen(padrao);

    if (m == 0 || m > n) {
        return;
    }

    int hashTexto = 0;
    int hashPadrao = 0;
    int h = 1;

    for (int i = 0; i < m - 1; i++) {
        h = (h * BASE) % MOD;
    }

    for (int i = 0; i < m; i++) {
        hashPadrao = (BASE * hashPadrao + padrao[i]) % MOD;
        hashTexto = (BASE * hashTexto + texto[i]) % MOD;
    }

    for (int i = 0; i <= n - m; i++) {
        if (hashPadrao == hashTexto) {
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
        if (i < n - m) {
            hashTexto = (BASE * (hashTexto - texto[i] * h) + texto[i + m]) % MOD;

            if (hashTexto < 0) {
                hashTexto += MOD;
            }
        }
    }
}

int main () {
    char texto[] = "ABBABAACaaaaaaaaaaaaABAABCABAC";
    char padrao[] = "ABAA";

    rabinKarp(texto, padrao);

    return 0;
}