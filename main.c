/*
Integrante 1 - Nome: JOÃO PEDRO PORTA RA: 16039778 
Integrante 2 - Nome: MARCELO DIB COUTINHO RA: 16023673 
Integrante 3 - Nome: RAFAEL FIORAMONTE RA: 16032708 
Resultados obtidos: _______________________________________________________ 
Projeto básico: _____ % concluído - Obs: _____________________________________ 
( ) Opcional 1 - Obs: ______________________________________________________ 
( ) Opcional 2 - Obs: ______________________________________________________ 
( ) Opcional 3 - Obs: ______________________________________________________
( ) Opcional 4 - Obs: ______________________________________________________
*/
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
  if (argc > 1) { 
    strcpy(num, &argv[1][2]);
    n = atoi(num); // transforma n em int
    if(argc > 2){
      for(i = 2; i < argc; i++){
        l = argv[i][1];
        switch (l){
          case 'w':
            break;
          case 'r':
            break;
          case 's':
            break;
          case 'b':
            break;
          case 'p':
            break;
        }
      }
      //argumentos opicionais
    }
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
