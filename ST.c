#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "ST.h"


//-------------------------------------------------------------------
void freeEveryOne(Tno **raiz, int tudo) {
  if (*raiz == NULL)
    return;
  freeEveryOne(&((*raiz)->esq), tudo);
  freeEveryOne(&((*raiz)->dir), tudo);
  if (tudo) {
    free((*raiz)->i);
    free(*raiz);
  }
}

// insere no a arvore
void insere(Tno **r, char *word, int *numero, long int altura) {
  int i;
  if (*r == NULL) {
    *r = (Tno *)malloc(sizeof(Tno));
    addItem(&(*r)->i, word);
    *numero = *numero + 1;
    (*r)->esq = NULL;
    (*r)->dir = NULL;
    (*r)->altura = altura + 1;
  } else {
    i = compara(&(*r)->i, word);
    if (i > 0)
      insere(&(*r)->esq, word, numero, (*r)->altura);
    else if (i < 0)
      insere(&(*r)->dir, word, numero, (*r)->altura);
    else
      adicionaVez(&((*r)->i));
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
//------------------------------------------------------------------
// Printar Arvore
void printa_esq(Tno *r, int n, int alt, char *p) {
  if (r && alt <= n) {
    p[alt - 2] = 'e';
    for (int i = 1; i < alt - 1; i++) {
      if (p[i - 1] == 'd')
        printf("   ");
      else
        printf("|  ");
    }
    printf("|- %s (altura %i)\n", r->i->palavra, alt);

    printa_esq(r->esq, n, alt + 1, p);

    printa_dir(r->dir, n, alt + 1, p);
  }
}
void printa_dir(Tno *r, int n, int alt, char *p) {
  if (r && alt <= n) {
    p[alt - 2] = 'd';
    for (int i = 1; i < alt - 1; i++) {

      if (p[i - 1] == 'd')
        printf("   ");
      else
        printf("|  ");
    }
    printf("|- %s (altura %i)\n", r->i->palavra, alt);

    printa_esq(r->esq, n, alt + 1, p);

    printa_dir(r->dir, n, alt + 1, p);
  }
}
void printa_altura(Tno *r, int n) {

  char *p;
  p = malloc(n * sizeof(char));

  printf("%s\n", r->i->palavra);
  printa_esq(r->esq, n, 2, p);
  printa_dir(r->dir, n, 2, p);

  free(p);
}

// Usado quando opcao S esta ativa, escontra palavra e printa ela
void achaItem(Tno *raiz, char *word) {
  int i;
  if (raiz != NULL) {
    i = compara(&(raiz->i), word);
    if (i == 0) {
      printaItemPlus((raiz->i), raiz->altura);
      return;
    }
    if (i < 0) {
      achaItem(raiz->dir, word);
      return;
    }
    achaItem(raiz->esq, word);
  } else {
    printf("Nao encontrado\n");
  }
}

// --------------------------------------------------------------
// Balancear arvore

long int altura(Tno *raiz) {
  int E = 0;
  int D = 0;

  if (raiz->esq)
    E = altura(raiz->esq);
  if (raiz->dir)
    D = altura(raiz->dir);

  return D > E ? ++D : ++E;
}

int balancea(Tno *raiz) {
  int bal = 0;

  if (raiz->esq)
    bal += altura(raiz->esq);
  if (raiz->dir)
    bal -= altura(raiz->dir);

  return bal;
}

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
