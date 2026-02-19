#ifndef TEXTOS_TESTES_H
#define TEXTOS_TESTES_H

typedef struct {
    char *texto;
    char *padrao;
} CasoTeste;

CasoTeste teste_curto();
CasoTeste teste_longo();
CasoTeste teste_nao_existente();
CasoTeste teste_pior();

void liberar_caso(CasoTeste caso);

void executar_teste(
    char *nome_algoritmo,
    char *nome_teste,
    CasoTeste caso,
    void (*algoritmo)(char *, char *)
);

void executar_testes(
    char *nome_algoritmo,
    void (*algoritmo)(char *, char *)
);

#endif