#include "item.h"
#include "st.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// insere no a arvore
void insere(Tno **r, char *word) {
  int i;
  if (*r == NULL) {
    *r = (Tno *)malloc(sizeof(Tno));
    addItem(&(*r)->i, word);
  } else {
    i = compara(&(*r)->i, word);
    if (i > 0)
      insere(&(*r)->esq, word);
    else if (i < 0)
      insere(&(*r)->dir, word);
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
