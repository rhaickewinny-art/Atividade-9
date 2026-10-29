#ifndef ENTIDADE_H
#define ENTIDADE_H

#include "raylib.h"
#include <stdbool.h>

typedef enum {
    ENTIDADE_JOGADOR,
    ENTIDADE_INIMIGO,
    ENTIDADE_ITEM
} TipoEntidade;

// Módulo comum (não é TAD): a struct é visível para quem inclui este .h
typedef struct {
    TipoEntidade tipo;
    Vector2 pos;
    int vida;
    union {
        int dano;   // usado por ENTIDADE_INIMIGO
        int valor;  // usado por ENTIDADE_ITEM
    } extra;
} Entidade;

Entidade *entidadeCriar(TipoEntidade tipo, Vector2 pos);
void      entidadeDestruir(Entidade *e);
bool      entidadeColidiu(const Entidade *a, const Entidade *b);
void      entidadeAplicarDano(Entidade *e, int dano);
void      entidadeDesenhar(const Entidade *e);

#endif
