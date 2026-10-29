#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <stdbool.h>
#include "entidade.h"

// Tipo opaco: a struct é definida apenas em inventario.c
typedef struct Inventario Inventario;

Inventario *inventarioCriar(int capacidade);
void        inventarioDestruir(Inventario *inv);   // libera entidades + vetor + struct
bool        inventarioAdicionar(Inventario *inv, Entidade *e);
Entidade   *inventarioObter(Inventario *inv, int indice);
void        inventarioRemover(Inventario *inv, int indice);
int         inventarioTotal(Inventario *inv);

// Exercício 1
bool        inventarioEstaCheio(Inventario *inv);

// Exercício 2
int         inventarioContarPorTipo(Inventario *inv, TipoEntidade tipo);

#endif
