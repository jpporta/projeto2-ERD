#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addItem(Ti **i, char *word) {
  (*i) = (Ti *)malloc(sizeof(Ti));
  strcpy((*r)->palavra, word);
  (*i)->vez = 1;
  (*i)->esq = NULL;
  (*i)->dir = NULL;
}
