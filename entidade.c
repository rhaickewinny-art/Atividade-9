#include "entidade.h"
#include <stdlib.h>

#define RAIO_ENTIDADE 15.0f

Entidade *entidadeCriar(TipoEntidade tipo, Vector2 pos) {
    Entidade *e = (Entidade *)malloc(sizeof(Entidade));
    if (e == NULL) return NULL;

    e->tipo = tipo;
    e->pos = pos;

    switch (tipo) {
        case ENTIDADE_JOGADOR:
            e->vida = 100;
            e->extra.dano = 0;
            break;
        case ENTIDADE_INIMIGO:
            e->vida = 60;
            e->extra.dano = 1;
            break;
        case ENTIDADE_ITEM:
            e->vida = 1;
            e->extra.valor = 10;
            break;
    }
    return e;
}

void entidadeDestruir(Entidade *e) {
    free(e);
}

bool entidadeColidiu(const Entidade *a, const Entidade *b) {
    return CheckCollisionCircles(a->pos, RAIO_ENTIDADE, b->pos, RAIO_ENTIDADE);
}

void entidadeAplicarDano(Entidade *e, int dano) {
    e->vida -= dano;
}

void entidadeDesenhar(const Entidade *e) {
    Color cor = BLUE;
    if (e->tipo == ENTIDADE_INIMIGO) cor = RED;
    else if (e->tipo == ENTIDADE_ITEM) cor = GOLD;
    DrawCircleV(e->pos, RAIO_ENTIDADE, cor);
}
