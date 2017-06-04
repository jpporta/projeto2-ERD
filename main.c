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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "ST.h"


int main(int argc, char *argv[]) {
  int numb, i, numero = 0, maxi;
  char palavra[100], num[10], l;
  char arquivoIn[20], arquivoOut[20], word[100], max[5];
  Tno *raiz = NULL;
  Ti *res;
  int n,w,r,s,b,p;
  FILE *in, *out;

  n = w = r = s = b = p = 0;
  //---------------Pega argumentos----------------------
  if (argc > 1) { 
      for(i = 1; i < argc; i++){
        l = argv[i][1];
        switch (l){
          case 'n':
             n = 1;
             //strcpy(num, &argv[1][2]);
             n = atoi(&argv[1][2]); // transforma n em int
             break;
          case 'w':
            w = 1;
            strcpy(arquivoOut, &argv[i][2]);
            out = fopen(arquivoOut, "w");
            break;
          case 'r':
            if(!w){
              r = 1;
              strcpy(arquivoIn, &argv[i][2]);
              in = fopen(arquivoIn, "r");
            }
            break;
          case 's':
            s = 1;
            strcpy(word, &argv[i][2]);
            break;
          case 'b':
            b = 1;
            break;
          case 'p':
            p = 1;
            //strcpy(max, &argv[i][2]);
            maxi = atoi(&argv[i][2]);
            break;
        }
      }
      //argumentos opicionais
  
  } else {
    printf("Argumentos insuficientes\n");
    exit(0);
  }

  // RECEPCAO PALAVRAS
  if(r){

     i = 0;
    l = fgetc(in);      // pega argumento da entrada <in.txt
    while (!feof(in)) { // enquanto n for o final de arquivo continua o loop
      if ((l > 64 && l < 91) ||
          (l > 96 && l < 123)) { // Se for letra maiúscula ou minúscula.
        palavra[i] = l;          // coloca em um vetor.
        i++;
      } else {
        palavra[i] = '\0'; // caso n for letra finaliza a palavra com /0.

        if (strlen(palavra) >
            0) // se a palavra n for apenas o /0 coloca ela na árvore
          insere(&raiz, palavra, &numero, 0);

        i = 0;
      }
      l = fgetc(in); // pega proximo caracter e continua loop.
    }
    fclose(in);
  }
  else{ //CASO SEJA PARA LER UM ARQUIVO EXTERNO ---------- OP: r
    i = 0;
    l = fgetc(stdin);      // pega argumento da entrada <in.txt
    while (!feof(stdin)) { // enquanto n for o final de arquivo continua o loop
      if ((l > 64 && l < 91) ||
          (l > 96 && l < 123)) { // Se for letra maiúscula ou minúscula.
        palavra[i] = l;          // coloca em um vetor.
        i++;
      } else {
        palavra[i] = '\0'; // caso n for letra finaliza a palavra com /0.

        if (strlen(palavra) > 0) // se a palavra n for apenas o /0 coloca ela na árvore
          insere(&raiz, palavra, &numero, 0);

        i = 0;
      }
      l = fgetc(stdin); // pega proximo caracter e continua loop.
    }
  }
  // FIM RECEPCAO E INSERCAO

  if(n){ // Se n for verdade
    if (numero < numb)
      numb = numero;
    res = mais_frequente(n, raiz);
    for (i = 0; i < n; i++) {
      printaItem((res + i));
      if(w) // se w escreve no arquivo
        printaArq((res + i), out);
    }
    free(res);
  }
  if(s){
    achaItem(raiz, word);
  }
  if(w) fclose(out); // se w fecha o arquivo
  freeEveryOne(&raiz);
  return 0;
}
