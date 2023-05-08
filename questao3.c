#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int peso;
    struct no * prox;
}NO;

NO * pilhaA = NULL;
NO * pilhaB = NULL;
NO * pilhaC = NULL;

void push(NO **pilha, int peso){
    NO * novo = malloc(sizeof(NO));
    novo->peso = peso;
    novo->prox = *pilha;
    *pilha = novo;
}

int pop(NO **pilha){
    if(*pilha == NULL){
        printf("Pilha vazia!\n");
        return -1;
    }else{
        NO * temp = *pilha;
        int valor = temp->peso;
        *pilha = (*pilha)->prox;
        free(temp);
        return valor;
    }
}

void moverCaixas(NO **origem, NO **destino){
    while(*origem != NULL){
        int peso = pop(origem);
        push(destino, peso);
    }
}

int main(){
    push(&pilhaA, 5);
    push(&pilhaA, 3);
    push(&pilhaA, 7);
    push(&pilhaA, 5);
    push(&pilhaA, 3);
    push(&pilhaA, 3);
    push(&pilhaA, 7);
    
    while(pilhaA != NULL){
        int peso = pop(&pilhaA);
        if(peso > 7){
            moverCaixas(&pilhaA, &pilhaB);
            moverCaixas(&pilhaC, &pilhaA);
            push(&pilhaA, peso);
        }else if(peso > 5){
            moverCaixas(&pilhaA, &pilhaC);
            moverCaixas(&pilhaB, &pilhaA);
            push(&pilhaA, peso);
        }else{
            push(&pilhaA, peso);
        }
    }
    
    printf("Caixas empilhadas com sucesso na pilha A!\n");
    return 0;
}
