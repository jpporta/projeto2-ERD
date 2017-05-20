#include "item.h"
#include "st.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int n, i;
  char palavra[50], num[10], l;
  Tno *raiz = NULL;

  if (argc == 2) {
    strcpy(num, &(argv[1][2]));
    // ignorando outros codigos, precisa ser alterado depois
    n = atoi(num); // transforma n em int
  }

  setbuf(stdin, NULL);

  l = fgetc(stdin);
  i = 0;
  while (!feof(stdin)) {
    if ((l > 64 && l < 91) || (l > 96 && l < 123)) {
      palavra[i] = l;
      i++;
    } else {
      palavra[i] = '\0';
      i = 0;
      insere(&raiz, palavra);
    }
    l = fgetc(stdin);
    if (l == EOF) {
      palavra[i] = '\0';
      i = 0;
      insere(&raiz, palavra);
    }
  }
  printa(raiz);
}
