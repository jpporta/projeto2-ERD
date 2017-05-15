#include "item.h"
#include "st.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insere(Tno **r, char *word) {
  if (*r == NULL) {
    *r = (Tno *)malloc(sizeof(Tno));
    addItem(&(*r)->i, word);
  }
  if (strcmp((*r)->palavra, word) == 0)
    (*r)->vez++;
  else if (strcmp((*r)->palavra, word) < 0)
    insere(&(*r)->esq, word);
  else
    insere(&(*r)->dir, word);
}
void printa(Tno *r) {
  if (r) {
    printa(r->esq);
    printf("%s", r->palavra);
    printa(r->dir);
  }
}
