#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no* prox;
} NO;

typedef struct pilha {
    NO* topo;
    int tamanho;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = NULL;
    p->tamanho = 0;
}

void push(Pilha* p, int valor) {
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = p->topo;
    p->topo = novo;
    p->tamanho++;
}

int pop(Pilha* p) {
    if (p->tamanho == 0) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        NO* topo_antigo = p->topo;
        int valor = topo_antigo->valor;
        p->topo = topo_antigo->prox;
        free(topo_antigo);
        p->tamanho--;
        return valor;
    }
}

void mover(Pilha* origem, Pilha* destino) {
    while (origem->tamanho > 0) {
        int valor = pop(origem);
        push(destino, valor);
    }
}

void empilhar(Pilha* a, Pilha* b, Pilha* c, int peso) {
    if (a->tamanho == 0 || a->topo->valor >= peso) {
        push(a, peso);
    } else if (b->tamanho > 0 && b->topo->valor >= peso) {
        mover(a, c);
        push(a, peso);
        mover(b, a);
        mover(c, a);
    } else if (c->tamanho > 0 && c->topo->valor >= peso) {
        mover(a, b);
        push(a, peso);
        mover(c, a);
        mover(b, a);
    } else {
        printf("Impossível empilhar a caixa de %d toneladas\n", peso);
    }
}

void imprimir_pilha(Pilha* p) {
    NO* atual = p->topo;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    Pilha a, b, c;
    inicializar(&a);
    inicializar(&b);
    inicializar(&c);

    empilhar(&a, &b, &c, 5);
    empilhar(&a, &b, &c, 3);
    empilhar(&a, &b, &c, 7);
    empilhar(&a, &b, &c, 5);
    empilhar(&a, &b, &c, 3);
    empilhar(&a, &b, &c, 5);
    empilhar(&a, &b, &c, 3);
    empilhar(&a, &b, &c, 5);
    empilhar(&a, &b, &c, 3);

    printf("Pilha A: ");
    imprimir_pilha(&a);
    printf("Pilha B: ");
    imprimir_pilha(&b);
    printf("Pilha C: ");
    imprimir_pilha(&c);

    return 0;
}
