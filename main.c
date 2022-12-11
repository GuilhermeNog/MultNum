#include <stdio.h>
#include <stdlib.h>

typedef struct NoLista{
    int dado;
    struct NoLista *prox;
}List;

List* inicializar(int dado) {
    List *n = malloc(sizeof(List));
    n->dado = dado;
    n->prox = NULL;

    return n;
}

List *inserir(List *num, int dado){
    List *aux = inicializar(dado);
    aux->prox = num;
}

long long multiplicar(List *prim, List *seg){
    long long num1 = 0, num2 = 0;

    while (prim) {
        num1 = prim->dado + num1 * 10;
        prim = prim->prox;
    }
    while (seg) {
        num2 = seg->dado + num2 * 10;
        seg = seg->prox;
    }
    return num1 * num2;
}

void imprimir(List* list){
    int cont = 1;
    while(list != NULL){
        printf("%d ", list->dado);
        list = list->prox;
        cont++;
    }
}

int main() {
    List *num, *num2, *aux, *aux2, *auxL1, *auxL2;
    auxL1 = inicializar(46);
    auxL2 = inicializar(21);
    num = auxL1;
    num2 = auxL2;
    num = inserir(num, 17);
    num2 = inserir(num2, 26);
    aux = num;
    aux2 = num2;

    imprimir(aux);
    printf("\n");
    imprimir(aux2);
    printf("\n");

    long long resultado = multiplicar(num, num2);
    printf("Resultado: %lli \n", resultado);
}
