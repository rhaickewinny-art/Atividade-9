#include "inventario.h"
#include <stdlib.h>

// Definição da struct: só este arquivo a conhece
struct Inventario {
    Entidade **vetor;
    int total;
    int capacidade;
};

Inventario *inventarioCriar(int capacidade) {
    if (capacidade <= 0) return NULL;

    Inventario *inv = (Inventario *)malloc(sizeof(Inventario));
    if (inv == NULL) return NULL;

    inv->vetor = (Entidade **)malloc(sizeof(Entidade *) * capacidade);
    if (inv->vetor == NULL) {
        free(inv);
        return NULL;
    }
    inv->total = 0;
    inv->capacidade = capacidade;
    return inv;
}

void inventarioDestruir(Inventario *inv) {
    if (inv == NULL) return;
    for (int i = 0; i < inv->total; i++) {
        entidadeDestruir(inv->vetor[i]);
    }
    free(inv->vetor);
    free(inv);
}

bool inventarioAdicionar(Inventario *inv, Entidade *e) {
    if (inv == NULL || e == NULL) return false;
    if (inv->total >= inv->capacidade) return false;
    inv->vetor[inv->total++] = e;
    return true;
}

Entidade *inventarioObter(Inventario *inv, int indice) {
    if (inv == NULL || indice < 0 || indice >= inv->total) return NULL;
    return inv->vetor[indice];
}

void inventarioRemover(Inventario *inv, int indice) {
    if (inv == NULL || indice < 0 || indice >= inv->total) return;
    entidadeDestruir(inv->vetor[indice]);
    for (int i = indice; i < inv->total - 1; i++) {
        inv->vetor[i] = inv->vetor[i + 1];
    }
    inv->total--;
}

int inventarioTotal(Inventario *inv) {
    return (inv == NULL) ? 0 : inv->total;
}

// ---- Exercício 1 ----
bool inventarioEstaCheio(Inventario *inv) {
    if (inv == NULL) return false;
    return inv->total == inv->capacidade;
}

// ---- Exercício 2 ----
int inventarioContarPorTipo(Inventario *inv, TipoEntidade tipo) {
    if (inv == NULL) return 0;
    int contador = 0;
    for (int i = 0; i < inv->total; i++) {
        if (inv->vetor[i]->tipo == tipo) contador++;
    }
    return contador;
}
