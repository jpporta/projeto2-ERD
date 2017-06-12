#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ST.h"
#include "STb.h"

//altura devolve altura da arvore
long int altura(Tno *raiz) {
  int E = 0;
  int D = 0;

  if (raiz->esq)
    E = altura(raiz->esq);
  if (raiz->dir)
    D = altura(raiz->dir);

  return D > E ? ++D : ++E;
}

/*
    balancea verifica qual lado esta desbanceado
    e devolve:
        0 - Balanceado
        1 - Balanceado, com 1 a mais para esquerda
        -1 - Balanceado, com 1 a mais para direira
        
        2 - Desbalanceado para esquerda
        -2 - Desbalanceado para direita
*/

int balancea(Tno *raiz) {
  int bal = 0;

  if (raiz->esq)
    bal += altura(raiz->esq);
  if (raiz->dir)
    bal -= altura(raiz->dir);

  return bal;
}

//====================================================
//Processos para rotacionar a arvore
Tno *rodaEsqEsq(Tno *raiz) {
  Tno *a = raiz;
  Tno *b = a->esq;

  a->esq = b->dir;
  b->dir = a;

  return (b);
}

Tno *rodaEsqDir(Tno *raiz) {
  Tno *a = raiz;
  Tno *b = a->esq;
  Tno *c = b->dir;

  a->esq = c->dir;
  b->dir = c->esq;
  c->esq = b;
  c->dir = a;

  return (c);
}

Tno *rodaDirEsq(Tno *raiz) {
  Tno *a = raiz;
  Tno *b = a->dir;
  Tno *c = b->esq;

  a->dir = c->esq;
  b->esq = c->dir;
  c->dir = b;
  c->esq = a;

  return (c);
}

Tno *rodaDirDir(Tno *raiz) {
  Tno *a = raiz;
  Tno *b = a->dir;

  a->dir = b->esq;
  b->esq = a;

  return (b);
}
// Final dos processos de rotacao
//======================================

//======================================
/*
    Main do processo de balanceamento, ele 
    que decide qual processo de rotacao utilizar
*/

Tno *balanceando(Tno *raiz) {
  Tno *novaRaiz = NULL;

  // Balanceando os filhos
  if (raiz->esq)
    raiz->esq = balanceando(raiz->esq);
  if (raiz->dir)
    raiz->dir = balanceando(raiz->dir);

  int bal = balancea(raiz);

  if (bal >= 2) {
    // Pesando para esquerda

    if (balancea(raiz->esq) <= -1)
      novaRaiz = rodaEsqDir(raiz);
    else
      novaRaiz = rodaEsqEsq(raiz);

  } else if (bal <= -2) {
    // Pesando para direita

    if (balancea(raiz->dir) >= 1)
      novaRaiz = rodaDirEsq(raiz);
    else
      novaRaiz = rodaDirDir(raiz);

  } else {
    // 	Balanceado
    novaRaiz = raiz;
  }

  return (novaRaiz);
}
