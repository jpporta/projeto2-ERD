#include "item.h"
#include "st.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int n;
  char palavra[50], num[10];
  Tno *raiz = NULL;

  strcpy(num, &(argv[1][2]));
  // ignorando outros codigos, precisa ser alterado depois
  n = atoi(num); // transforma n em int

  fflush(stdin);
  while (scanf("%49[a-zA-Z]", palavra) != EOF) {
    insere(&raiz, palavra);
  }
  printa(raiz);
}
