#include "ST.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insere(no **r, char *word) {
  if (*r == NULL) {
    *r = (no *)malloc(sizeof(no));
    (*r)->vez = 1;
    (*r)->esq = (*r)->dir = NULL;
    strcpy((*r)->palavra, word);
  }
  if (strcmp((*r)->palavra, word) == 0)
    (*r)->vez++;
  else if (strcmp((*r)->palavra, word) < 0)
    insere(&(*r)->esq, word);
  else
    insere(&(*r)->dir, word);
}
void printa(no *r) {
  if (r) {
    printa(r->esq);
    printf("%s", r->palavra);
    printa(r->dir);
  }
}
