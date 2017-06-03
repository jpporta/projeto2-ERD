#include "item.h"
#include "ST.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int n, i, numero = 0;
  char palavra[100], num[10], l;
  Tno *raiz = NULL;
  Ti *p;
  //---------------Pega argumentos----------------------
  if (argc == 2) { // argc = nº de argumentos, ./prog = argumento 1, -nNUMERO =
                   // argumento 2. <in.txt NÃO É ARGUMENTO
    i = 2; // argumentos ficam em uma matriz, -nNUMERO é o 2º argumento então
           // ficará na 2ª linha da matriz argv[].
    // i = 2 para ignorar o "-n" do argumento e pegar a parte do NUMERO.
    while ('\0' != argv[1][i]) {
      num[i - 2] =
          argv[1]
              [i]; // passa a string de argumento após o -n para uma string num.
      i++;
    }
    num[i - 2] = '\0';
    n = atoi(num); // transforma n em int
  } else {
    printf("Argumentos insuficientes\n");
    exit(0);
  }

  // RECEPCAO PALAVRAS
  i = 0;
  l = fgetc(stdin);      // pega argumento da entrada <in.txt
  while (!feof(stdin)) { // enquanto n for o final de arquivo continua o loop
    if ((l > 64 && l < 91) ||
        (l > 96 && l < 123)) { // Se for letra maiúscula ou minúscula.
      palavra[i] = l;          // coloca em um vetor.
      i++;
    } else {
      palavra[i] = '\0'; // caso n for letra finaliza a palavra com /0.

      if (strlen(palavra) >
          0) // se a palavra n for apenas o /0 coloca ela na árvore
        insere(&raiz, palavra, &numero);

      i = 0;
    }
    l = fgetc(stdin); // pega proximo caracter e continua loop.
  }
  // FIM RECEPCAO E INSERCAO

  if (numero < n)
    n = numero;
  p = mais_frequente(n, raiz);
  for (i = 0; i < n; i++) {
    printaItem((p + i));
  }
  freeEveryOne(&raiz);
  free(p);
  return 0;
}
