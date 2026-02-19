#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../textosTestes.h"

/**
 * @brief Arquivo criado para gerar os testes de cada algoritmo.
 */

// Tamanhos utilizados nos testes
#define TAM_PEQUENO 100000
#define TAM_MEDIO 1000000
#define TAM_GRANDE 10000000
#define PADRAO_CURTO "ipsum"
#define PADRAO_LONGO "tempor incididunt ut labore"
#define PADRAO_NAO_EXISTENTE "XYZ123ZYX"
#define PADRAO_PIOR_CASO "AAAAAAAAAB"

// Variável a ser utilizada nos testes
size_t TAM_ATUAL = TAM_PEQUENO;

// Texto base
const char *lorem =
"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod "
"tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim "
"veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea "
"commodo consequat. Duis aute irure dolor in reprehenderit in voluptate "
"velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat "
"cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id "
"est laborum. Curabitur pretium tincidunt lacus. Nulla gravida orci a odio. "
"Nullam varius, turpis et commodo pharetra, est eros bibendum elit, nec "
"luctus magna felis sollicitudin mauris. Integer in mauris eu nibh euismod "
"gravida. Duis ac tellus et risus vulputate vehicula. Donec lobortis risus "
"a elit. Etiam tempor. Ut ullamcorper, ligula eu tempor congue, eros est "
"euismod turpis, id tincidunt sapien risus a quam. Maecenas fermentum "
"consequat mi. Donec fermentum. Pellentesque malesuada nulla a mi. Duis "
"sapien sem, aliquet nec, commodo eget, consequat quis, neque. Aliquam "
"faucibus, elit ut dictum aliquet, felis nisl adipiscing sapien, sed "
"malesuada diam lacus eget erat. Cras mollis scelerisque nunc. Nullam "
"arcu. Aliquam consequat. Curabitur augue lorem, dapibus quis, laoreet "
"et, pretium ac, nisi. Aenean magna nisl, mollis quis, molestie eu, "
"feugiat in, nisi. Aenean diam id mauris pellentesque aliquet. "
"Nulla facilisi. Aenean et risus. Vestibulum volutpat pretium libero.";

// Gera texto repetindo o Lorem
static char* gerar_lorem(size_t tamanho) {
    char *texto = malloc(tamanho + 1);
    size_t len_base = strlen(lorem);
    size_t pos = 0;

    while (pos < tamanho) {
        for (size_t i = 0; i < len_base && pos < tamanho; i++) {
            texto[pos++] = lorem[i];
        }
    }

    texto[tamanho] = '\0';
    return texto;
}

// Gera pior caso
static char* gerar_pior(size_t tamanho) {
    char *texto = malloc(tamanho + 1);

    for (size_t i = 0; i < tamanho - 1; i++)
        texto[i] = 'A';

    texto[tamanho - 1] = 'B';
    texto[tamanho] = '\0';

    return texto;
}

// Testes com texto do tamanho escolhido (TAM_ATUAL)
CasoTeste teste_curto() {
    CasoTeste caso;
    caso.texto = gerar_lorem(TAM_ATUAL);
    caso.padrao = strdup(PADRAO_CURTO);
    return caso;
}

CasoTeste teste_longo() {
    CasoTeste caso;
    caso.texto = gerar_lorem(TAM_ATUAL);
    caso.padrao = strdup(PADRAO_LONGO);
    return caso;
}

CasoTeste teste_nao_existente() {
    CasoTeste caso;
    caso.texto = gerar_lorem(TAM_ATUAL);
    caso.padrao = strdup(PADRAO_NAO_EXISTENTE);
    return caso;
}

CasoTeste teste_pior() {
    CasoTeste caso;
    caso.texto = gerar_pior(TAM_ATUAL);
    caso.padrao = strdup(PADRAO_PIOR_CASO);
    return caso;
}

// Liberar memória
void liberar_caso(CasoTeste caso) {
    free(caso.texto);
    free(caso.padrao);
}

// Executa cada teste individualmente, acrescentando o cabeçalho de informações
void executar_teste(
    char *nome_algoritmo,
    char *nome_teste,
    CasoTeste caso,
    void (*algoritmo)(char *, char *)
) {
    printf("\n---------------------------------------\n");
    printf("Algoritmo: %s\n", nome_algoritmo);
    printf("Tamanho do texto: %zu caracteres\n", TAM_ATUAL);
    printf("Teste: %s\n", nome_teste);
    printf("---------------------------------------\n");

    clock_t inicio = clock();

    algoritmo(caso.texto, caso.padrao);

    clock_t fim = clock();

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo de execucao: %f segundos\n", tempo);
    printf("=====================================\n");

    liberar_caso(caso);
}

// Executa todos os casos de teste para o algoritmo informado
void executar_testes(
    char *nome_algoritmo,
    void (*algoritmo)(char *, char *)
) {
    executar_teste(nome_algoritmo, "Padrão Curto", teste_curto(), algoritmo);
    executar_teste(nome_algoritmo, "Padrão Longo", teste_longo(), algoritmo);
    executar_teste(nome_algoritmo, "Não Existente", teste_nao_existente(), algoritmo);
    executar_teste(nome_algoritmo, "Pior Caso", teste_pior(), algoritmo);
}