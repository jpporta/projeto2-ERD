#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "ST.h"


// insere no a arvore
void insere(Tno **r, char *word, int *numero) {
  int i;
  if (*r == NULL) {
    *r = (Tno *)malloc(sizeof(Tno));
    addItem(&(*r)->i, word);
    *numero = *numero + 1;
    (*r)->esq = NULL;
    (*r)->dir = NULL;
  } else {
    i = compara(&(*r)->i, word);
    if (i > 0)
      insere(&(*r)->esq, word, numero);
    else if (i < 0)
      insere(&(*r)->dir, word, numero);
  }
}

Ti *mais_frequente(int n, Tno *r) {
  int i;
  Ti *p;
  p = malloc(n * sizeof(Ti));
  for (i = 0; i < n; i++) {
    strcpy(p[i].palavra, "NULL");
    p[i].vez = 0;
  }
  percorre_arvore(r, p, n);
  return p;
}
void percorre_arvore(Tno *r, Ti *p, int n) {
  if (r) {
    if (r->esq)
      percorre_arvore(r->esq, p, n);

    OrganizaItem(r->i, p, n);
    if (r->dir)
      percorre_arvore(r->dir, p, n);
  }
}
void OrganizaItem(Ti *i, Ti *p, int n) {
  int k, j;
  Ti aux, aux2;
  aux2 = *i;
  for (k = 0; k < n; k++) {
    if (aux2.vez > (p + k)->vez) {
      for (j = k; j < n; j++) {
        aux = *(p + j);
        *(p + j) = aux2;
        aux2 = aux;
      }
      break;
    } else {
      if (aux2.vez == (p + k)->vez) {
        if (strcmp(aux2.palavra, (p + k)->palavra) < 0) {
          aux = *(p + k);
          *(p + k) = aux2;
          aux2 = aux;
        }
      }
    }
  }
}
void printa(Tno *r) {
  if (r) {
    if (r->esq)
      printa(r->esq);
    printaItem(r->i);
    if (r->dir)
      printa(r->dir);
  }
}
void freeEveryOne(Tno **raiz) {
  if (*raiz == NULL) return;
  freeEveryOne(&((*raiz)->esq));
  freeEveryOne(&((*raiz)->dir));
  free((*raiz)->i);
  free(*raiz);
}
