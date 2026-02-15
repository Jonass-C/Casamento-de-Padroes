#include <stdio.h>
#include <stdlib.h>

/*!
 * @brief Hashing ABERTO, usando o método da DIVISÃO e não permitindo números negativos.
 */

#define BUCKETS 7

typedef struct No {
	int chave;
	struct No *prox;
} No;

typedef struct {
	No *tabela[BUCKETS];
} TabelaHash;

// somente para ter todos os nós nulos
void inicializar(TabelaHash *h) {
	for (int i = 0; i < BUCKETS; i++) {
		h->tabela[i] = NULL;
	}
}

// função do slide: h(k) = (k % 13) ou h(k) = k mod m, onde m = buckets e k é a chave

int funcaoHash (int chave) {
	return chave % BUCKETS;
}

int buscar(TabelaHash *h, int chave) {
	int indice = funcaoHash(chave);
	No *atual = h->tabela[indice];

	while (atual != NULL) {
		if (atual->chave == chave) {
			return 1;
		}
		atual = atual->prox;
	}
	return 0;
}

void inserir(TabelaHash *h, int chave) {
	if (buscar(h, chave)) {
		printf("Chave %d já existe. Pulando inserção\n");
		return;
	}

	int indice = funcaoHash(chave);

	No *novoNo = (No*) malloc(sizeof(No));
	if (novoNo == NULL) {
		printf("Erro de alocação\n");
		exit(1);
	}

	novoNo->chave = chave;
	novoNo->prox = h->tabela[indice];
	h->tabela[indice] = novoNo;
}

void mostrar(TabelaHash *h) {
	printf("\n");
	for (int i = 0; i < BUCKETS; i++) {
		printf("[%d]: ", i);
		No *atual = h->tabela[i];
		while (atual != NULL) {
			printf("%d -> ", atual->chave);
			atual = atual->prox;
		}
		printf("NULL\n");
	}
	printf("\n");
}

void liberarTabela(TabelaHash *h) {
	for (int i = 0; i < BUCKETS; i++) {
		No *atual = h->tabela[i];
		while (atual != NULL) {
			No *temp = atual;
			atual = atual->prox;
			free(temp);
		}
		h->tabela[i] = NULL;
	}
}

void encontrarChave(TabelaHash *th, int i) {
	if (buscar(th, i)) {
		printf("Chave %d encontrada!\n", i);
	}
	else {
		printf("Chave %d não encontrada!\n", i);
	}
}

int main() {
	TabelaHash th;
	inicializar(&th);

	inserir(&th, 10);
	inserir(&th, 24);
	inserir(&th, 17);
	inserir(&th, 12);
	inserir(&th, 22);
	inserir(&th, 32);
	inserir(&th, 5);
	inserir(&th, 15);
	inserir(&th, 28);
	inserir(&th, 42);
	inserir(&th, 48);
	inserir(&th, 48);

	mostrar(&th);

	encontrarChave(&th, 17);
	encontrarChave(&th, 49);

	liberarTabela(&th);

}